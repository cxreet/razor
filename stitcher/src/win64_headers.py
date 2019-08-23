import os
import mmap
import argparse
import inspect
import string
import traceback
from struct import *

IMAGE_NUMBEROF_DIRECTORY_ENTRIES = 16
IMAGE_SIZEOF_SHORT_NAME = 8

# Image DOS signature
IMAGE_DOS_SIGNATURE = 0x5a4d

# Image NT signature
IMAGE_NT_SIGNATURE = 0x00004550

# Image File Machine
IMAGE_FILE_MACHINE_UNKNOWN  = 0
IMAGE_FILE_MACHINE_I386     = 0x014c
IMAGE_FILE_MACHINE_ALPHA    = 0x0184
IMAGE_FILE_MACHINE_POWERPC  = 0x01f0
IMAGE_FILE_MACHINE_AMD64    = 0x8664

# Image File Characteristics
IMAGE_FILE_RELOCS_STRIPPED          = 0x0001
IMAGE_FILE_EXECUTABLE_IMAGE         = 0x0002
IMAGE_FILE_LINE_NUMS_STRIPPED       = 0x0004
IMAGE_FILE_LOCAL_SYMS_STRIPPED      = 0x0008
IMAGE_FILE_AGGRESIVE_WS_TRIM        = 0x0010
IMAGE_FILE_LARGE_ADDRESS_AWARE      = 0x0020
IMAGE_FILE_BYTES_REVERSED_LO        = 0x0080
IMAGE_FILE_32BIT_MACHINE            = 0x0100  # 32 bit word machine.
IMAGE_FILE_DEBUG_STRIPPED           = 0x0200  # Debugging info stripped from file in .DBG file
IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP  = 0x0400  # If Image is on removable media, copy and run from the swap file.
IMAGE_FILE_NET_RUN_FROM_SWAP        = 0x0800  # If Image is on Net, copy and run from the swap file.
IMAGE_FILE_SYSTEM                   = 0x1000  # System File.
IMAGE_FILE_DLL                      = 0x2000  # File is a DLL.
IMAGE_FILE_UP_SYSTEM_ONLY           = 0x4000  # File should only be run on a UP machine
IMAGE_FILE_BYTES_REVERSED_HI        = 0x8000  # Bytes of machine word are reversed.

# Image Optional Header Magic
IMAGE_NT_OPTIONAL_HDR32_MAGIC   = 0x10b
IMAGE_NT_OPTIONAL_HDR64_MAGIC   = 0x20b
IMAGE_ROM_OPTIONAL_HDR_MAGIC    = 0x107

# Directory Entries
IMAGE_DIRECTORY_ENTRY_EXPORT            = 0    # Export Directory
IMAGE_DIRECTORY_ENTRY_IMPORT            = 1    # Import Directory
IMAGE_DIRECTORY_ENTRY_RESOURCE          = 2    # Resource Directory
IMAGE_DIRECTORY_ENTRY_EXCEPTION         = 3    # Exception Directory
IMAGE_DIRECTORY_ENTRY_SECURITY          = 4    # Security Directory
IMAGE_DIRECTORY_ENTRY_BASERELOC         = 5    # Base Relocation Table
IMAGE_DIRECTORY_ENTRY_DEBUG             = 6    # Debug Directory
IMAGE_DIRECTORY_ENTRY_ARCHITECTURE      = 7    # Architecture Specific Data
IMAGE_DIRECTORY_ENTRY_GLOBALPTR         = 8    # RVA of GP
IMAGE_DIRECTORY_ENTRY_TLS               = 9    # TLS Directory
IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG       = 10   # Load Configuration Directory
IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT      = 11   # Bound Import Directory in headers
IMAGE_DIRECTORY_ENTRY_IAT               = 12   # Import Address Table
IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT      = 13   # Delay Load Import Descriptors
IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR    = 14   # COM Runtime descriptor

# Image Section Characteristics
IMAGE_SCN_CNT_CODE                      = 0x00000020 # Section contains code.
IMAGE_SCN_CNT_INITIALIZED_DATA          = 0x00000040 # Section contains initialized data.
IMAGE_SCN_CNT_UNINITIALIZED_DATA        = 0x00000080 # Section contains uninitialized data.
# ....
IMAGE_SCN_LNK_NRELOC_OVFL               = 0x01000000 # Section contains extended relocations.
IMAGE_SCN_MEM_DISCARDABLE               = 0x02000000 # Section can be discarded.
IMAGE_SCN_MEM_NOT_CACHED                = 0x04000000 # Section is not cachable.
IMAGE_SCN_MEM_NOT_PAGED                 = 0x08000000 # Section is not pageable.
IMAGE_SCN_MEM_SHARED                    = 0x10000000 # Section is shareable.
IMAGE_SCN_MEM_EXECUTE                   = 0x20000000 # Section is executable.
IMAGE_SCN_MEM_READ                      = 0x40000000 # Section is readable.
IMAGE_SCN_MEM_WRITE                     = 0x80000000 # Section is writeable.

def align(value_to_align, alignment):
    return ((value_to_align + alignment - 1) / alignment) * alignment

# check whether a string is printable, which means it has printable-char and tailing zeros
def str_printable(mystring):
    find_zero = False
    find_non_zero = False

    for char in mystring:
        if find_zero:
            if char == '\x00':
                continue
            else:
                return False
        else:
            if char in string.printable:
                continue
            elif char == '\x00':
                find_zero = True
            else:
                return False

    if all(c == '\x00' for c in mystring):
        return False
    else:
        return True

def all_zero_string(mystring):
    if all(c == '\x00' for c in mystring):
        return True
    else:
        return False

# print any types, including:
#
# int
# str
# list
# or customized class
#
def myprint(value):
    if type(value) == int or type(value) == long:
        print hex(value)
    elif type(value) == str:
        if str_printable(value):
            print "\"" + value.rstrip('\x00') + "\""
        else:
            length = len(value)
            for index in xrange(0, length):
                print hex(unpack("<B", value[index])[0]),
            print ""
    elif type(value) == list:
        for ele in value:
            myprint(ele)
    elif inspect.isclass(type(value)):
        printit(value)

# print an object with attributes
def printit(obj):
    if obj.init != True:
        print "the object is not initialized yet!"
        exit(1)

    if obj.print_level == 0:
        print obj.print_level * "\t" + obj.obj_name + ":"
    else:
        print ""

    for i in xrange(0, obj.keys_num):
        attr_name = obj.keys[i]
        attr_value = getattr(obj, attr_name)
        print (obj.print_level + 1) * "\t", 
        print attr_name, "\t",
        myprint(attr_value)

def get_string(filename, offset):
    fd = os.open(filename, os.O_RDONLY)
    os.lseek(fd, offset, os.SEEK_SET)
    string = ""
    while True:
        char = os.read(fd, 1)
        if char == '\x00':
            os.close(fd)
            return string
        string += char

def myunpack(obj, raw_data):
    tmp = unpack(obj.fmt, raw_data)
    for i in xrange(0, obj.keys_num):
        setattr(obj, obj.keys[i], tmp[i])

def get_fmt_new(cls):
    fmt = "<"
    keys = []
    for element in cls.FMT:
        assert ("," in element)
        tmps = element.split(",")
        next_fmt = tmps[0].strip()
        next_name = tmps[1].strip()
        cur_fmt_size = calcsize(fmt)
        fmt = fmt + next_fmt
        keys.append(next_name)
        setattr(cls, next_name + "_offset", cur_fmt_size)
    setattr(cls, "fmt", fmt)
    setattr(cls, "fmt_size", calcsize(fmt))
    setattr(cls, "keys", keys)
    setattr(cls, "keys_num", len(keys))
    setattr(cls, "begin_foff", None)
    setattr(cls, "end_foff", None)
    return cls

@get_fmt_new
class IMAGE_DOS_HEADER(object):
    obj_name = "DOS header"
    print_level = 0
    FMT = [ 
            "H, e_magic",   # 00000000: 4D 5A,      magic number
            "H, e_cblp",	# 00000002: 90 00,      bytes on last page of file
            "H, e_cp",	# 00000004: 03 00,      pages in file
            "H, e_crlc",	# 00000006: 00 00,      relocations
            "H, e_cparhdr", # 00000008: 04 00,      Size of header in paragraphs
            "H, e_minalloc",# 0000000A: 00 00,      Minimum extra paragraphs needed
            "H, e_maxalloc",# 0000000C: FF FF,      Maximum extra paragraphs needed
            "H, e_ss",      # 0000000E: 00 00,      Initial (relative) SS value
            "H, e_sp",      # 00000010: B8 00,      Initial SP value
            "H, e_csum",    # 00000012: 00 00,      Checksum
            "H, e_ip",      # 00000014: 00 00,      Initial IP value
            "H, e_cs",      # 00000016: 00 00,      Initial (relative) CS value
            "H, e_lfarlc",  # 00000018: 40 00,      File address of relocation table
            "H, e_ovno",    # 0000001A: 00 00,      Overlay number
            "8s, e_res",    # 0000001C: 00 00 00 00,    Reserved words
                            # 00000020: 00 00 00 00,
            "H, e_oemid",   # 00000024: 00 00,      OEM identifier (for e_oeminfo)
            "H, e_oeminfo", # 00000026: 00 00,      OEM information", e_oemid specific
            "20s, e_res2",  # 00000028: 00 00 00 00,    Reserved words
                            # 0000002C: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
            "I, e_lfanew",  # 0000003C: F8 00 00 00,    File address of new exe header
    ]

    def __init__(self, binname):
        self.init = True

        fd = os.open(binname, os.O_RDONLY)
        self.begin_foff = os.lseek(fd, 0, os.SEEK_CUR)

        raw_dos_header = os.read(fd, self.fmt_size)

        self.end_foff = os.lseek(fd, 0, os.SEEK_CUR)
        os.close(fd)

        myunpack(self, raw_dos_header)
        assert (self.e_magic == IMAGE_DOS_SIGNATURE)

@get_fmt_new
class IMAGE_FILE_HEADER(object):
    obj_name = "File header"
    print_level = 1
    FMT = [
            "H, Machine",   # the running platform
            "H, NumberOfSections", #
            "I, TimeDataStamp",    #
            "I, PointerToSymbolTable",
            "I, NumberOfSymbols",
            "H, SizeOfOptionalHeader",
            "H, Characteristics"
    ]

    def __init__(self, raw_file_header, start_foff):
        self.init = True
        myunpack(self, raw_file_header)

        assert (self.Machine == IMAGE_FILE_MACHINE_AMD64)
        assert (self.Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE)

        self.begin_foff = start_foff
        self.end_foff = start_foff + self.fmt_size

@get_fmt_new
class IMAGE_DATA_DIRECTORY(object):
    obj_name = "Data Directory"
    print_level = 2
    FMT = [
            "I, VirtualAddress",
            "I, Size",
    ]

    def __init__(self, raw_directory_data, start_foff):
        self.init = True
        myunpack(self, raw_directory_data)
        self.begin_foff = start_foff
        self.end_foff = start_foff + self.fmt_size

@get_fmt_new
class IMAGE_OPTIONAL_HEADER64(object):

    obj_name = "Optional Header"
    print_level = 1

    data_directory_fmt_size = IMAGE_DATA_DIRECTORY.fmt_size
    FMT = [
            "H, Magic",
            "B, MajorLinkerVersion",
            "B, MinorLinkerVersion",
            "I, SizeOfCode",
            "I, SizeOfInitializedData",
            "I, SizeofUninitializedData",
            "I, AddressOfEntryPoint",
            "I, BaseOfCode",
            "Q, ImageBase",
            "I, SectionAlignment",
            "I, FileAlignment",
            "H, MajorOperatingSystemVersion",
            "H, MinorOperatingSystemVersion",
            "H, MajorImageVersion",
            "H, MinorImageVersion",
            "H, MajorSubsystemVersion",
            "H, MinorSubsystemVersion",
            "I, Win32VersionValue",
            "I, SizeOfImage",
            "I, SizeOfHeaders",
            "I, CheckSum",
            "H, Subsystem",
            "H, DllCharacteristics",
            "Q, SizeOfStackReserve",
            "Q, SizeOfStackCommit",
            "Q, SizeOfHeapReserve",
            "Q, SizeOfHeapCommit",
            "I, LoaderFlags",
            "I, NumberOfRvaAndSizes",
            "%ds, DataDirectory" % (data_directory_fmt_size * 
                IMAGE_NUMBEROF_DIRECTORY_ENTRIES),
    ]

    def __init__(self, raw_optional_header, start_foff):
        self.init = True

        myunpack(self, raw_optional_header)
        assert (self.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC)

        self.begin_foff = start_foff
        self.end_foff = start_foff + self.fmt_size

        tmp_array = []
        for index in xrange(0, IMAGE_NUMBEROF_DIRECTORY_ENTRIES):
            raw_directory_data = self.DataDirectory[self.data_directory_fmt_size * index:
                                                    self.data_directory_fmt_size * (index + 1)]
            tmp_array.append(IMAGE_DATA_DIRECTORY(raw_directory_data, self.begin_foff + self.data_directory_fmt_size * index))
        self.DataDirectory = tmp_array

@get_fmt_new
class IMAGE_NT_HEADER(object):
    obj_name = "NT header"
    print_level = 0
    file_header_fmt_size = IMAGE_FILE_HEADER.fmt_size
    optional_header_fmt_size = IMAGE_OPTIONAL_HEADER64.fmt_size
    FMT = [
            "I, Signature",             # PE signature
            "%ds, FileHeader" % file_header_fmt_size,          # file header
            "%ds, OptionalHeader" % optional_header_fmt_size,     # optional header
    ]

    def __init__(self, binname, e_lfanew):
        self.init = True

        fd = os.open(binname, os.O_RDONLY)
        os.lseek(fd, e_lfanew, os.SEEK_SET)
        self.begin_foff = os.lseek(fd, 0, os.SEEK_CUR)
        raw_nt_header = os.read(fd, self.fmt_size) # 64-bit only
        self.end_foff = os.lseek(fd, 0, os.SEEK_CUR)
        os.close(fd)

        myunpack(self, raw_nt_header)

        assert (self.Signature == IMAGE_NT_SIGNATURE)

        self.FileHeader = IMAGE_FILE_HEADER(self.FileHeader, self.begin_foff + calcsize("<I"))
        self.OptionalHeader = IMAGE_OPTIONAL_HEADER64(self.OptionalHeader, self.FileHeader.end_foff)

@get_fmt_new
class IMAGE_SECTION_HEADER(object):
    obj_name = "Section header"
    print_level = 0

    FMT = [
            "%ds, Name" % IMAGE_SIZEOF_SHORT_NAME,
            #"I, PhysicalAddress",
            "I, VirtualSize",
            "I, VirtualAddress",
            "I, SizeOfRawData",
            "I, PointerToRawData",
            "I, PointerToRelocations",
            "I, PointerToLinenumbers",
            "H, NumberOfRelocations",
            "H, NumberOfLinenumbers",
            "I, Characteristics",
    ]
            
    def __init__(self, raw_section_header, start_foff):
        self.init = True
        myunpack(self, raw_section_header)
        self.begin_foff = start_foff
        self.end_foff = start_foff + self.fmt_size

    @property
    def PhysicalAddress(self):
        return self.VirtualSize
    @PhysicalAddress.setter
    def PhysicalAddress(self, x):
        self.VirtualSize = x

class IMAGE_SECTION_HEADERS(object):
    obj_name = "Section Headers"
    print_level = 1

    def __init__(self, binname, start_foff, section_number):
        self.init = True
        fd = os.open(binname, os.O_RDONLY)
        os.lseek(fd, start_foff, os.SEEK_SET)
        self.begin_foff = start_foff

        section_header_fmt_size = IMAGE_SECTION_HEADER.fmt_size
        self.section_headers = []

        for index in xrange(0, section_number):
            raw_section_header = os.read(fd, section_header_fmt_size)
            section_header = IMAGE_SECTION_HEADER(raw_section_header, self.begin_foff + index * section_header_fmt_size)
            self.section_headers.append(section_header)

        self.end_foff = os.lseek(fd, 0, os.SEEK_CUR)

        os.close(fd)

    def __getitem__(self, index):
        return self.section_headers[index]

    def get(self):
        return self.section_headers

@get_fmt_new
class IMAGE_IMPORT_BY_NAME(object):
    obj_name = "import by name"
    print_level = 2

    FMT = [
            "H, Hint",
            "B, Name1",
    ]

    def __init__(self, binname, start_foff):
        self.init = True
        fd = os.open(binname, os.O_RDONLY)
        os.lseek(fd, start_foff, os.SEEK_SET)
        self.begin_foff = start_foff

        self.Hint = unpack("<H", os.read(fd, 2))[0]
        self.Name1 = get_string(binname, os.lseek(fd, 0, os.SEEK_CUR))

        self.end_foff = start_foff + calcsize("<H",) + len(self.Name1)
        os.close(fd)

@get_fmt_new
class IMAGE_THUNK_DATA(object):
    obj_name = "Image Thunk Data"
    print_level = 1

    FMT = [
            "Q, AddressOfData",     # TODO: I for 32-bit
    ]

    def __init__(self, raw_thunk_data, start_foff, pefile):
        self.init = True
        myunpack(self, raw_thunk_data)

        self.begin_foff = start_foff
        self.end_foff = start_foff + self.fmt_size

        if (self.AddressOfData & (1 << 63)) == 0:
            self.is_import_by_name = True
            self.import_by_name = IMAGE_IMPORT_BY_NAME(pefile.binname, pefile.rva2foff(self.AddressOfData))
        else:
            self.is_import_by_name = False

    @property
    def Function(self):
        return self.AddressOfData
    @Function.setter
    def Function(self, x):
        self.AddressOfData = x

    @property
    def Ordinal(self):
        return self.AddressOfData
    @Ordinal.setter
    def Ordinal(self, x):
        self.AddressOfData = x

    @property
    def ForwarderString(self):
        return self.AddressOfData
    @ForwarderString.setter
    def ForwarderString(self, x):
        self.AddressOfData = x

class IMAGE_THUNK_DATA_TABLE(object):
    obj_name = "Image Thunk_Data_Table"
    print_level = 1

    def __init__(self, pefile, start_foff):
        self.init = True
        fd = os.open(pefile.binname, os.O_RDONLY)
        os.lseek(fd, start_foff, os.SEEK_SET)
        self.begin_foff = os.lseek(fd, 0, os.SEEK_CUR)

        cur_foff = self.begin_foff

        thunk_data_fmt_size = IMAGE_THUNK_DATA.fmt_size
        raw_thunk_data = os.read(fd, thunk_data_fmt_size)

        self.thunk_data_table = []

        while all_zero_string(raw_thunk_data) != True:
            thunk_data = IMAGE_THUNK_DATA(raw_thunk_data, cur_foff, pefile)
            self.thunk_data_table.append(thunk_data)
            raw_thunk_data = os.read(fd, thunk_data_fmt_size)
            cur_foff += thunk_data_fmt_size

        self.end_foff = os.lseek(fd, 0, os.SEEK_CUR)
        os.close(fd)

    def get(self):
        return self.thunk_data_table

@get_fmt_new
class IMAGE_IMPORT_DESCRIPTOR(object):
    obj_name = "import descriptor"
    print_level = 0

    FMT = [
            "I, Characteristics",
            "I, TimeDataStamp",
            "I, ForwarderChain",
            "I, Name1",
            "I, FirstThunk",
    ]

    def __init__(self, pefile, raw_import_descriptor, start_foff):
        self.init = True
        myunpack(self, raw_import_descriptor)
        self.begin_foff = start_foff
        self.end_foff = start_foff + self.fmt_size
        first_thunk_foff = pefile.rva2foff(self.FirstThunk)
        self.thunk_data_table = IMAGE_THUNK_DATA_TABLE(pefile, first_thunk_foff).get()

    @property
    def OriginalFirstThunk(self):
        return self.Characteristics
    @OriginalFirstThunk.setter
    def OriginalFirstThunk(self, x):
        self.Characteristics = x

class IMAGE_IMPORT_TABLE(object):
    obj_name = "Import Table"
    print_level = 0

    def __init__(self, pefile):
        data_directory_import = pefile.nt_header.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT]
        #printit(data_directory_import)
        import_table_foff = pefile.rva2foff(data_directory_import.VirtualAddress)

        import_descriptor_fmt_size = IMAGE_IMPORT_DESCRIPTOR.fmt_size

        fd = os.open(pefile.binname, os.O_RDONLY)
        os.lseek(fd, import_table_foff, os.SEEK_SET)
        raw_import_descriptor = os.read(fd, import_descriptor_fmt_size)

        self.begin_foff = import_table_foff
        self.import_table = []

        cur_foff = self.begin_foff

        while all_zero_string(raw_import_descriptor) != True:
            import_descriptor = IMAGE_IMPORT_DESCRIPTOR(pefile, raw_import_descriptor, cur_foff)
            self.import_table.append(import_descriptor)
            raw_import_descriptor = os.read(fd, import_descriptor_fmt_size)
            cur_foff += import_descriptor_fmt_size

        self.end_foff = cur_foff
        os.close(fd)

    def get(self):
        return self.import_table

@get_fmt_new
class IMAGE_EXPORT_DIRECTORY(object):
    obj_name = "Export Directory"
    print_level = 0

    FMT = [
            "I, Characteristics",
            "I, TimeDateStamp",
            "H, MajorVersion",
            "H, MinorVersion",
            "I, Name",
            "I, Base",
            "I, NumberOfFunctions",
            "I, NumberOfNames",
            "I, AddressOfFunctions",
            "I, AddressOfNames",
            "I, AddressOfNameOrdinals",
    ]

    def __init__(self, pefile):
        self.init = True
        data_directory_export = pefile.nt_header.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT]
        export_table_foff = pefile.rva2foff(data_directory_export.VirtualAddress)

        fd = os.open(pefile.binname, os.O_RDONLY)
        os.lseek(fd, export_table_foff, os.SEEK_SET)
        raw_export_directory = os.read(fd, self.fmt_size)

        self.begin_foff = export_table_foff
        self.end_foff = export_table_foff + self.fmt_size

        os.close(fd)

        myunpack(self, raw_export_directory)

class IMAGE_EXPORT_ADDRESS_TABLE(object):
    obj_name = "Export Address Table"
    print_level = 1

    def __init__(self, export_directory, pefile):
        self.init = True

        self.export_address_table = []

        table_foff = pefile.rva2foff(export_directory.AddressOfFunctions)
        fd = os.open(pefile.binname, os.O_RDONLY)
        os.lseek(fd, table_foff, os.SEEK_SET)
        self.begin_foff = table_foff
        self.end_foff = table_foff + export_directory.NumberOfFunctions * 4

        for index in xrange(0, export_directory.NumberOfFunctions):
            self.export_address_table.append(unpack("<I", os.read(fd, 4))[0])

        os.close(fd)

    def get(self):
        return self.export_address_table

class IMAGE_EXPORT_NAME_TABLE(object):
    obj_name = "Export Name Table"
    print_level = 1

    def __init__(self, export_directory, pefile):
        self.init = True

        self.export_name_table = []

        table_foff = pefile.rva2foff(export_directory.AddressOfNames)
        fd = os.open(pefile.binname, os.O_RDONLY)
        os.lseek(fd, table_foff, os.SEEK_SET)

        self.begin_foff = table_foff
        self.end_foff = table_foff + export_directory.NumberOfNames * 4

        for index in xrange(0, export_directory.NumberOfNames):
            rva = unpack("<I", os.read(fd, 4))[0]
            offset = pefile.rva2foff(rva)
            self.export_name_table.append(get_string(pefile.binname, offset))

        os.close(fd)

    def get(self):
        return self.export_name_table


class IMAGE_EXPORT_ORDINAL_TABLE(object):
    obj_name = "Export Ordinal Table"
    print_level = 1

    def __init__(self, export_directory, pefile):
        self.init = True

        self.export_ordinal_table = []

        table_foff = pefile.rva2foff(export_directory.AddressOfNameOrdinals)
        fd = os.open(pefile.binname, os.O_RDONLY)
        os.lseek(fd, table_foff, os.SEEK_SET)

        self.begin_foff = table_foff
        self.end_foff = table_foff + export_directory.NumberOfNames * 2

        for index in xrange(0, export_directory.NumberOfNames):
            ordinal = unpack("<H", os.read(fd, 2))[0]
            self.export_ordinal_table.append(ordinal)

        os.close(fd)

    def get(self):
        return self.export_ordinal_table

class IMAGE_EXPORT_TABLE(object):
    obj_name = "Export Table"
    print_level = 0

    def __init__(self, pefile):
        self.init = True
        self.export_directory = IMAGE_EXPORT_DIRECTORY(pefile)
        self.export_address_table = IMAGE_EXPORT_ADDRESS_TABLE(self.export_directory, pefile).get()
        self.export_name_table = IMAGE_EXPORT_NAME_TABLE(self.export_directory, pefile).get()
        self.export_ordinal_table = IMAGE_EXPORT_ORDINAL_TABLE(self.export_directory, pefile).get()


@get_fmt_new
class IMAGE_BASE_RELOCATION(object):
    obj_name = "Base Relocation"
    print_level = 1

    FMT = [
            "I, VirtualAddress",
            "I, SizeOfBlock",
    ]

    def __init__(self, raw_base_relocation, start_foff):
        self.init = True
        myunpack(self, raw_base_relocation)
        self.NumberOfRelocations = (self.SizeOfBlock - self.fmt_size) / 2

        self.relocations = []

        self.begin_foff = start_foff
        self.end_foff = start_foff + self.fmt_size


class IMAGE_RELOCATION_TABLE(object):
    obj_name = "Relocation Table"
    print_level = 0

    def __init__(self, pefile):
        self.init = True
        base_relocation_fmt_size = IMAGE_BASE_RELOCATION.fmt_size

        data_directory_basereloc = pefile.nt_header.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC]
        relocation_table_foff = pefile.rva2foff(data_directory_basereloc.VirtualAddress)
        fd = os.open(pefile.binname, os.O_RDONLY)
        os.lseek(fd, relocation_table_foff, os.SEEK_SET)
        cur_foff = relocation_table_foff
        raw_base_relocation = os.read(fd, base_relocation_fmt_size)
        base_relocation = IMAGE_BASE_RELOCATION(raw_base_relocation, cur_foff)

        self.begin_foff = relocation_table_foff
        self.relocation_table = []


        while base_relocation.VirtualAddress != 0:
            cur_foff += base_relocation_fmt_size
            for index in xrange(0, base_relocation.NumberOfRelocations):
                base_relocation.relocations.append(unpack("<H", os.read(fd, 2))[0])
            self.relocation_table.append(base_relocation)
            raw_base_relocation = os.read(fd, base_relocation_fmt_size)
            base_relocation = IMAGE_BASE_RELOCATION(raw_base_relocation, cur_foff)

        self.end_foff = os.lseek(fd, 0, os.SEEK_CUR)
        os.close(fd)

    def get(self):
        return self.relocation_table

@get_fmt_new
class EXCEPTION_ENTRY(object):
    obj_name = "Exception Entry"
    print_level = 1

    FMT = [
            "I, BeginAddress",
            "I, EndAddress",
            "I, UnwindInfoAddress",
    ]

    def __init__(self, raw_exception_entry, start_foff):
        self.init = True
        myunpack(self, raw_exception_entry)

        self.begin_foff = start_foff
        self.end_foff = start_foff + self.fmt_size

class IMAGE_EXCEPTION_TABLE(object):
    obj_name = "Function Table"
    print_level = 0

    def __init__(self, pefile):
        self.init = True

        data_directory_except = pefile.nt_header.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXCEPTION]
        exception_table_foff = pefile.rva2foff(data_directory_except.VirtualAddress)
        fd = os.open(pefile.binname, os.O_RDONLY)
        os.lseek(fd, exception_table_foff, os.SEEK_SET)

        exception_table_size = data_directory_except.Size
        exception_entry_fmt_size = EXCEPTION_ENTRY.fmt_size
        exception_entry_num = exception_table_size / exception_entry_fmt_size

        self.begin_foff = exception_table_foff
        self.end_foff = exception_table_foff + exception_entry_num * exception_entry_fmt_size
        self.exception_table = []

        cur_foff = exception_table_foff

        for index in xrange(0, exception_entry_num):
            raw_exception_entry = os.read(fd, exception_entry_fmt_size)
            exception_entry = EXCEPTION_ENTRY(raw_exception_entry, cur_foff)
            self.exception_table.append(exception_entry)
            cur_foff += exception_entry_fmt_size

        os.close(fd)
    
    def get(self):
        return self.exception_table

class PE_FILE(object):
    def __init__(self, binname):
        self.binname = binname
        self.binsize = os.path.getsize(binname)

        self.dos_header = IMAGE_DOS_HEADER(binname)
        self.nt_header = IMAGE_NT_HEADER(binname, self.dos_header.e_lfanew)

        self.check_image_data_directory()

        section_headers_start_foff = self.dos_header.e_lfanew + self.nt_header.fmt_size
        self.section_headers = IMAGE_SECTION_HEADERS(binname, section_headers_start_foff, self.nt_header.FileHeader.NumberOfSections)
        if self.has_IMPORT:
            self.import_table = IMAGE_IMPORT_TABLE(self).get()
        if self.has_EXPORT:
            self.export_table = IMAGE_EXPORT_TABLE(self)
        if self.has_BASERELOC:
            self.relocation_table = IMAGE_RELOCATION_TABLE(self).get()
        if self.has_EXCEPTION:
            self.exception_table = IMAGE_EXCEPTION_TABLE(self).get()

    def append_section(self, section_size, section_content):
        # let's check whether we can add one more section header to the section header table
        section_headers_end = self.section_headers.end_foff
        first_section = self.section_headers[0]
        first_section_begin = first_section.PointerToRawData
        if first_section_begin - section_headers_end < IMAGE_SECTION_HEADER.fmt_size:
            print "no enough space between the section headers and the first section \
                    to insert one more section header"
            exit(1)
        else:
            fd = os.open(self.binname, os.O_RDONLY)
            os.lseek(fd, section_headers_end, os.SEEK_SET)
            if all_zero_string(os.read(fd, IMAGE_SECTION_HEADER.fmt_size)) == False:
                print "seems the content (0x40 bytes) after the section header table is not simple padding"
                os.close(fd)
                exit(1)
            os.close(fd)

        # ok, thanks to the file alignment padding, we are good to insert one more section header
        # let's do the insertion
        number_of_sections = self.nt_header.FileHeader.NumberOfSections
        last_section = number_of_sections - 1
        last_section_header = self.section_headers[last_section]
        file_alignment = self.nt_header.OptionalHeader.FileAlignment
        section_alignment = self.nt_header.OptionalHeader.SectionAlignment

        original_size = self.binsize
        original_size_aligned = align(original_size, file_alignment)

        last_section_end = last_section_header.PointerToRawData + \
                           last_section_header.SizeOfRawData
        last_section_end_aligned = align(last_section_end, file_alignment)
        pointer_to_raw_data = max(original_size_aligned, last_section_end_aligned)

        Name = ".mytext"
        Name += (8 - len(Name)) * '\x00'
        virtual_size = section_size
        virtual_address = align(last_section_header.VirtualAddress + 
                                last_section_header.VirtualSize,
                                section_alignment)
        size_of_raw_data = align(section_size, file_alignment)
        pointer_to_relocations = 0
        pointer_to_linenumbers = 0
        number_of_relocations = 0
        number_of_linenumbers = 0
        characteristics = IMAGE_SCN_MEM_READ | IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE

        new_section_header = pack(IMAGE_SECTION_HEADER.fmt, Name,
                                                            virtual_size,
                                                            virtual_address,
                                                            size_of_raw_data,
                                                            pointer_to_raw_data,
                                                            pointer_to_relocations,
                                                            pointer_to_linenumbers,
                                                            number_of_relocations,
                                                            number_of_linenumbers,
                                                            characteristics)
        virtual_size_aligned = align(virtual_size, section_alignment)

        # write the new section header after orignal section header table
        fd = os.open(self.binname, os.O_RDWR)
        os.lseek(fd, section_headers_end, os.SEEK_SET)
        os.write(fd, new_section_header)

        # update the section number
        os.lseek(fd, 
                self.nt_header.FileHeader.begin_foff + IMAGE_FILE_HEADER.NumberOfSections_offset,
                os.SEEK_SET)
        os.write(fd, pack("<H", number_of_sections + 1))
        print "update the section number from", number_of_sections, "to", number_of_sections + 1

        # udpate the size of image
        os.lseek(fd, 
                self.nt_header.OptionalHeader.begin_foff + IMAGE_OPTIONAL_HEADER64.SizeOfImage_offset,
                os.SEEK_SET)
        os.write(fd, pack("<I", virtual_size_aligned + virtual_address))
        print "update the image size from", hex(self.nt_header.OptionalHeader.SizeOfImage),\
                "to", hex(virtual_size_aligned + virtual_address)

        # enlarge the file
        binmap = mmap.mmap(fd, 0, access=mmap.ACCESS_WRITE)
        expect_file_size = pointer_to_raw_data + size_of_raw_data
        binmap.resize(expect_file_size)
        binmap.close()
        print "update the file size from", hex(self.binsize), "to", hex(expect_file_size)

        #size_diff = self.binsize - pointer_to_raw_data + 1

        # update the entry point
        os.lseek(fd, 
                self.nt_header.OptionalHeader.begin_foff + IMAGE_OPTIONAL_HEADER64.AddressOfEntryPoint_offset,
                os.SEEK_SET)
        os.write(fd, pack("<I", virtual_address))
        print "update the entry point address from", hex(self.nt_header.OptionalHeader.AddressOfEntryPoint), \
                "to", hex(virtual_address)

        # write the new code in
        os.lseek(fd, pointer_to_raw_data, os.SEEK_SET)
        os.write(fd, section_content)
        
        os.close(fd)

    def check_image_data_directory(self):
        data_directory = self.nt_header.OptionalHeader.DataDirectory
        
        Data_Directory_Names = [
                "EXPORT",
                "IMPORT",
                "RESOURCE",
                "EXCEPTION",
                "SECURITY",
                "BASERELOC",
                "DEBUG",
                "ARCHITECTURE",
                "GLOBALPTR",
                "TLS",
                "LOAD_CONFIG",
                "BOUND_IMPORT",
                "IAT",
                "DELAY_IMPORT",
                "COM_DESCRIPTOR",
                "UNKNOWN",
        ]

        for index in xrange(0, IMAGE_NUMBEROF_DIRECTORY_ENTRIES):
            if data_directory[index].VirtualAddress == 0 or \
               data_directory[index].Size == 0:
                setattr(self, "has_" + Data_Directory_Names[index], False)
            else:
                setattr(self, "has_" + Data_Directory_Names[index], True)

    def rva2foff(self, rva):
        #print "rva2foff from", hex(rva),
        for section_header in self.section_headers:
            if rva >= section_header.VirtualAddress:
                if rva < section_header.VirtualAddress + section_header.SizeOfRawData:
                    rva2 = rva - section_header.VirtualAddress
                    #print "to", hex(section_header.PointerToRawData + rva2)
                    return section_header.PointerToRawData + rva2
                else:
                    continue
            break

        return None

    def print_import_table(self):
        for import_descriptor in self.import_table:
            printit(import_descriptor)
            name_foff = self.rva2foff(import_descriptor.Name1)
            print "\tDLL name: " + get_string(self.binname, name_foff)
            for thunk_data in import_descriptor.thunk_data_table:
                printit(thunk_data)
                if thunk_data.is_import_by_name:
                    printit(thunk_data.import_by_name)

    def print_export_table(self):
        export_directory = self.export_table.export_directory
        printit(export_directory)
        name_foff = self.rva2foff(export_directory.Name)
        print "\tDLL name: " + get_string(self.binname, name_foff)
        
        base = self.export_table.export_directory.Base
        export_address_table = self.export_table.export_address_table
        export_name_table = self.export_table.export_name_table
        export_ordinal_table = self.export_table.export_ordinal_table

        for index in xrange(0, export_directory.NumberOfFunctions):
            print "\t\t", index + base, "\t", hex(export_address_table[index]),
            if index in export_ordinal_table:
                print "\t", export_name_table[export_ordinal_table.index(index)],
            print ""

    def print_relocation_table(self):
        relocation_table = self.relocation_table
        print "Relocation Table"
        for base_relocation in relocation_table:
            printit(base_relocation)
            print "\t\t\tWith", len(base_relocation.relocations), "fixups"
            index = 0
            for relocation in base_relocation.relocations:
                print "\t\t\t", index, "\tType:", hex(relocation >> 12), "\tOffset:", hex(relocation & 0xfff)
                index += 1

    def print_exception_table(self):
        exception_table = self.exception_table
        print "Exception Table"
        index = 0
        for exception_entry in exception_table:
            print "\t\t", index
            printit(exception_entry)
            index += 1

    def print_me(self):
        printit(self.dos_header)
        printit(self.nt_header)
        myprint(self.section_headers.get())
        if self.has_IMPORT:
            self.print_import_table()
        if self.has_EXPORT:
            self.print_export_table()
        if self.has_BASERELOC:
            self.print_relocation_table()
        if self.has_EXCEPTION:
            self.print_exception_table()

def test():
    parser = argparse.ArgumentParser()
    parser.add_argument("binfile", nargs="?")
    args = parser.parse_args()

    binname = args.binfile
    pefile = PE_FILE(binname)
    pefile.print_me()
    buf =  ""
    buf += "\xfc\x48\x83\xe4\xf0\xe8\xc0\x00\x00\x00\x41\x51\x41"
    buf += "\x50\x52\x51\x56\x48\x31\xd2\x65\x48\x8b\x52\x60\x48"
    buf += "\x8b\x52\x18\x48\x8b\x52\x20\x48\x8b\x72\x50\x48\x0f"
    buf += "\xb7\x4a\x4a\x4d\x31\xc9\x48\x31\xc0\xac\x3c\x61\x7c"
    buf += "\x02\x2c\x20\x41\xc1\xc9\x0d\x41\x01\xc1\xe2\xed\x52"
    buf += "\x41\x51\x48\x8b\x52\x20\x8b\x42\x3c\x48\x01\xd0\x8b"
    buf += "\x80\x88\x00\x00\x00\x48\x85\xc0\x74\x67\x48\x01\xd0"
    buf += "\x50\x8b\x48\x18\x44\x8b\x40\x20\x49\x01\xd0\xe3\x56"
    buf += "\x48\xff\xc9\x41\x8b\x34\x88\x48\x01\xd6\x4d\x31\xc9"
    buf += "\x48\x31\xc0\xac\x41\xc1\xc9\x0d\x41\x01\xc1\x38\xe0"
    buf += "\x75\xf1\x4c\x03\x4c\x24\x08\x45\x39\xd1\x75\xd8\x58"
    buf += "\x44\x8b\x40\x24\x49\x01\xd0\x66\x41\x8b\x0c\x48\x44"
    buf += "\x8b\x40\x1c\x49\x01\xd0\x41\x8b\x04\x88\x48\x01\xd0"
    buf += "\x41\x58\x41\x58\x5e\x59\x5a\x41\x58\x41\x59\x41\x5a"
    buf += "\x48\x83\xec\x20\x41\x52\xff\xe0\x58\x41\x59\x5a\x48"
    buf += "\x8b\x12\xe9\x57\xff\xff\xff\x5d\x48\xba\x01\x00\x00"
    buf += "\x00\x00\x00\x00\x00\x48\x8d\x8d\x01\x01\x00\x00\x41"
    buf += "\xba\x31\x8b\x6f\x87\xff\xd5\xbb\xf0\xb5\xa2\x56\x41"
    buf += "\xba\xa6\x95\xbd\x9d\xff\xd5\x48\x83\xc4\x28\x3c\x06"
    buf += "\x7c\x0a\x80\xfb\xe0\x75\x05\xbb\x47\x13\x72\x6f\x6a"
    buf += "\x00\x59\x41\x89\xda\xff\xd5\x6e\x6f\x74\x65\x70\x61"
    buf += "\x64\x2e\x65\x78\x65\x00"
    pefile.append_section(0x2000, buf)


if __name__ == "__main__":
    test()
