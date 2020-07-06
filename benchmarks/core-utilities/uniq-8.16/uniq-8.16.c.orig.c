typedef long __time_t;
typedef long __syscall_slong_t;
typedef __time_t time_t;
struct timespec {
   __time_t tv_sec ;
   __syscall_slong_t tv_nsec ;
};
typedef unsigned long size_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __uid_t uid_t;
struct stat {
   __dev_t st_dev ;
   __ino_t st_ino ;
   __nlink_t st_nlink ;
   __mode_t st_mode ;
   __uid_t st_uid ;
   __gid_t st_gid ;
   int __pad0 ;
   __dev_t st_rdev ;
   __off_t st_size ;
   __blksize_t st_blksize ;
   __blkcnt_t st_blocks ;
   struct timespec st_atim ;
   struct timespec st_mtim ;
   struct timespec st_ctim ;
   __syscall_slong_t __glibc_reserved[3] ;
};
typedef __ino_t ino_t;
typedef __dev_t dev_t;
struct di_set;
struct di_set;
struct hash_tuning {
   float shrink_threshold ;
   float shrink_factor ;
   float growth_threshold ;
   float growth_factor ;
   _Bool is_n_buckets ;
};
typedef struct hash_tuning Hash_tuning;
struct hash_table;
struct hash_table;
typedef struct hash_table Hash_table;
struct ino_map;
struct ino_map;
typedef size_t hashint;
struct di_ent {
   dev_t dev ;
   struct hash_table *ino_set ;
};
struct di_set {
   struct hash_table *dev_map ;
   struct ino_map *ino_map ;
   struct di_ent *probe ;
};
typedef unsigned long uintmax_t;
struct dev_ino {
   ino_t st_ino ;
   dev_t st_dev ;
};
struct cycle_check_state {
   struct dev_ino dev_ino ;
   uintmax_t chdir_counter ;
   int magic ;
};
typedef long __off64_t;
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;
struct _IO_marker {
   struct _IO_marker *_next ;
   struct _IO_FILE *_sbuf ;
   int _pos ;
};
struct _IO_FILE {
   int _flags ;
   char *_IO_read_ptr ;
   char *_IO_read_end ;
   char *_IO_read_base ;
   char *_IO_write_base ;
   char *_IO_write_ptr ;
   char *_IO_write_end ;
   char *_IO_buf_base ;
   char *_IO_buf_end ;
   char *_IO_save_base ;
   char *_IO_backup_base ;
   char *_IO_save_end ;
   struct _IO_marker *_markers ;
   struct _IO_FILE *_chain ;
   int _fileno ;
   int _flags2 ;
   __off_t _old_offset ;
   unsigned short _cur_column ;
   signed char _vtable_offset ;
   char _shortbuf[1] ;
   _IO_lock_t *_lock ;
   __off64_t _offset ;
   void *__pad1 ;
   void *__pad2 ;
   void *__pad3 ;
   void *__pad4 ;
   size_t __pad5 ;
   int _mode ;
   char _unused2[(15UL * sizeof(int ) - 4UL * sizeof(void *)) - sizeof(size_t )] ;
};
typedef __off_t off_t;
struct cd_buf {
   int fd ;
};
typedef long __ssize_t;
typedef __ssize_t ssize_t;
struct allocator;
struct allocator;
struct allocator {
   void *(*allocate)(size_t  ) ;
   void *(*reallocate)(void * , size_t  ) ;
   void (*free)(void * ) ;
   void (*die)(size_t  ) ;
};
typedef long ptrdiff_t;
enum canonicalize_mode_t {
    CAN_EXISTING = 0,
    CAN_ALL_BUT_LAST = 1,
    CAN_MISSING = 2,
    CAN_NOLINKS = 4
} ;
typedef enum canonicalize_mode_t canonicalize_mode_t;
typedef unsigned int __socklen_t;
typedef __socklen_t socklen_t;
typedef unsigned short sa_family_t;
struct sockaddr {
   sa_family_t sa_family ;
   char sa_data[14] ;
};
struct addrinfo {
   int ai_flags ;
   int ai_family ;
   int ai_socktype ;
   int ai_protocol ;
   socklen_t ai_addrlen ;
   struct sockaddr *ai_addr ;
   char *ai_canonname ;
   struct addrinfo *ai_next ;
};
struct __locale_data;
struct __locale_data;
struct __locale_struct {
   struct __locale_data *__locales[13] ;
   unsigned short const   *__ctype_b ;
   int const   *__ctype_tolower ;
   int const   *__ctype_toupper ;
   char const   *__names[13] ;
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
struct base64_decode_context {
   unsigned int i ;
   char buf[4] ;
};
enum backup_type {
    no_backups = 0,
    simple_backups = 1,
    numbered_existing_backups = 2,
    numbered_backups = 3
} ;
struct dirent {
   __ino_t d_ino ;
   __off_t d_off ;
   unsigned short d_reclen ;
   unsigned char d_type ;
   char d_name[256] ;
};
struct __dirstream;
struct __dirstream;
typedef struct __dirstream DIR;
enum numbered_backup_result {
    BACKUP_IS_SAME_LENGTH = 0,
    BACKUP_IS_LONGER = 1,
    BACKUP_IS_NEW = 2
} ;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
struct argv_iterator;
struct argv_iterator;
enum argv_iter_err {
    AI_ERR_OK = 1,
    AI_ERR_EOF = 2,
    AI_ERR_MEM = 3,
    AI_ERR_READ = 4
} ;
struct argv_iterator {
   FILE *fp ;
   size_t item_idx ;
   char *tok ;
   size_t buf_len ;
   char **arg_list ;
   char **p ;
};
enum quoting_style {
    literal_quoting_style = 0,
    shell_quoting_style = 1,
    shell_always_quoting_style = 2,
    c_quoting_style = 3,
    c_maybe_quoting_style = 4,
    escape_quoting_style = 5,
    locale_quoting_style = 6,
    clocale_quoting_style = 7,
    custom_quoting_style = 8
} ;
enum strtol_error {
    LONGINT_OK = 0,
    LONGINT_OVERFLOW = 1,
    LONGINT_INVALID_SUFFIX_CHAR = 2,
    LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3,
    LONGINT_INVALID = 4
} ;
typedef enum strtol_error strtol_error;
struct option {
   char const   *name ;
   int has_arg ;
   int *flag ;
   int val ;
};
typedef long intmax_t;
typedef void *iconv_t;
typedef __nlink_t nlink_t;
struct I_ring {
   int ir_data[4] ;
   int ir_default_val ;
   unsigned int ir_front ;
   unsigned int ir_back ;
   _Bool ir_empty ;
};
typedef struct I_ring I_ring;
struct _ftsent;
struct _ftsent;
union __anonunion_fts_cycle_25 {
   struct hash_table *ht ;
   struct cycle_check_state *state ;
};
struct __anonstruct_FTS_24 {
   struct _ftsent *fts_cur ;
   struct _ftsent *fts_child ;
   struct _ftsent **fts_array ;
   dev_t fts_dev ;
   char *fts_path ;
   int fts_rfd ;
   int fts_cwd_fd ;
   size_t fts_pathlen ;
   size_t fts_nitems ;
   int (*fts_compar)(struct _ftsent  const  ** , struct _ftsent  const  ** ) ;
   int fts_options ;
   struct hash_table *fts_leaf_optimization_works_ht ;
   union __anonunion_fts_cycle_25 fts_cycle ;
   I_ring fts_fd_ring ;
};
typedef struct __anonstruct_FTS_24 FTS;
struct _ftsent {
   struct _ftsent *fts_cycle ;
   struct _ftsent *fts_parent ;
   struct _ftsent *fts_link ;
   DIR *fts_dirp ;
   long fts_number ;
   void *fts_pointer ;
   char *fts_accpath ;
   char *fts_path ;
   int fts_errno ;
   int fts_symfd ;
   size_t fts_pathlen ;
   FTS *fts_fts ;
   ptrdiff_t fts_level ;
   size_t fts_namelen ;
   nlink_t fts_n_dirs_remaining ;
   unsigned short fts_info ;
   unsigned short fts_flags ;
   unsigned short fts_instr ;
   struct stat fts_statp[1] ;
   char fts_name[1] ;
};
typedef struct _ftsent FTSENT;
typedef unsigned int uint32_t;
typedef uint32_t ucs4_t;
typedef int __pid_t;
typedef __pid_t pid_t;
typedef int __sig_atomic_t;
typedef __sig_atomic_t sig_atomic_t;
struct __anonstruct_slaves_entry_t_50 {
   sig_atomic_t volatile   used ;
   pid_t volatile   child ;
};
typedef struct __anonstruct_slaves_entry_t_50 slaves_entry_t;
union __anonunion_51 {
   int __in ;
   int __i ;
};
union __anonunion_52 {
   int __in ;
   int __i ;
};
union __anonunion_53 {
   int __in ;
   int __i ;
};
union __anonunion_54 {
   int __in ;
   int __i ;
};
union __anonunion_55 {
   int __in ;
   int __i ;
};
union __anonunion_56 {
   int __in ;
   int __i ;
};
union __anonunion_57 {
   int __in ;
   int __i ;
};
union __anonunion_58 {
   int __in ;
   int __i ;
};
typedef int wchar_t;
typedef int nl_item;
typedef unsigned int wint_t;
enum __anonenum_arg_type_27 {
    TYPE_NONE = 0,
    TYPE_SCHAR = 1,
    TYPE_UCHAR = 2,
    TYPE_SHORT = 3,
    TYPE_USHORT = 4,
    TYPE_INT = 5,
    TYPE_UINT = 6,
    TYPE_LONGINT = 7,
    TYPE_ULONGINT = 8,
    TYPE_LONGLONGINT = 9,
    TYPE_ULONGLONGINT = 10,
    TYPE_DOUBLE = 11,
    TYPE_LONGDOUBLE = 12,
    TYPE_CHAR = 13,
    TYPE_WIDE_CHAR = 14,
    TYPE_STRING = 15,
    TYPE_WIDE_STRING = 16,
    TYPE_POINTER = 17,
    TYPE_COUNT_SCHAR_POINTER = 18,
    TYPE_COUNT_SHORT_POINTER = 19,
    TYPE_COUNT_INT_POINTER = 20,
    TYPE_COUNT_LONGINT_POINTER = 21,
    TYPE_COUNT_LONGLONGINT_POINTER = 22
} ;
typedef enum __anonenum_arg_type_27 arg_type;
union __anonunion_a_29 {
   signed char a_schar ;
   unsigned char a_uchar ;
   short a_short ;
   unsigned short a_ushort ;
   int a_int ;
   unsigned int a_uint ;
   long a_longint ;
   unsigned long a_ulongint ;
   long long a_longlongint ;
   unsigned long long a_ulonglongint ;
   float a_float ;
   double a_double ;
   long double a_longdouble ;
   int a_char ;
   wint_t a_wide_char ;
   char const   *a_string ;
   wchar_t const   *a_wide_string ;
   void *a_pointer ;
   signed char *a_count_schar_pointer ;
   short *a_count_short_pointer ;
   int *a_count_int_pointer ;
   long *a_count_longint_pointer ;
   long long *a_count_longlongint_pointer ;
};
struct __anonstruct_argument_28 {
   arg_type type ;
   union __anonunion_a_29 a ;
};
typedef struct __anonstruct_argument_28 argument;
struct __anonstruct_arguments_30 {
   size_t count ;
   argument *arg ;
   argument direct_alloc_arg[7] ;
};
typedef struct __anonstruct_arguments_30 arguments;
struct __anonstruct_char_directive_31 {
   char const   *dir_start ;
   char const   *dir_end ;
   int flags ;
   char const   *width_start ;
   char const   *width_end ;
   size_t width_arg_index ;
   char const   *precision_start ;
   char const   *precision_end ;
   size_t precision_arg_index ;
   char conversion ;
   size_t arg_index ;
};
typedef struct __anonstruct_char_directive_31 char_directive;
struct __anonstruct_char_directives_32 {
   size_t count ;
   char_directive *dir ;
   size_t max_width_length ;
   size_t max_precision_length ;
   char_directive direct_alloc_dir[7] ;
};
typedef struct __anonstruct_char_directives_32 char_directives;
typedef unsigned short fpucw_t;
struct saved_cwd {
   int desc ;
   char *name ;
};
typedef long __suseconds_t;
struct timeval {
   __time_t tv_sec ;
   __suseconds_t tv_usec ;
};
struct fs_res {
   dev_t dev ;
   int resolution ;
   _Bool exact ;
};
struct passwd {
   char *pw_name ;
   char *pw_passwd ;
   __uid_t pw_uid ;
   __gid_t pw_gid ;
   char *pw_gecos ;
   char *pw_dir ;
   char *pw_shell ;
};
struct group {
   char *gr_name ;
   char *gr_passwd ;
   __gid_t gr_gid ;
   char **gr_mem ;
};
typedef unsigned char uint8_t;
union __anonunion___value_23 {
   unsigned int __wch ;
   char __wchb[4] ;
};
struct __anonstruct___mbstate_t_22 {
   int __count ;
   union __anonunion___value_23 __value ;
};
typedef struct __anonstruct___mbstate_t_22 __mbstate_t;
typedef __mbstate_t mbstate_t;
struct mbchar {
   char const   *ptr ;
   size_t bytes ;
   _Bool wc_valid ;
   wchar_t wc ;
   char buf[24] ;
};
struct mbiter_multi {
   char const   *limit ;
   _Bool in_shift ;
   mbstate_t state ;
   _Bool next_done ;
   struct mbchar cur ;
};
typedef struct mbiter_multi mbi_iterator_t;
typedef uintmax_t randint;
struct randint_source;
struct randint_source;
union __anonunion_tmp_21 {
   unsigned int align ;
   char buf[4096] ;
};
struct tm {
   int tm_sec ;
   int tm_min ;
   int tm_hour ;
   int tm_mday ;
   int tm_mon ;
   int tm_year ;
   int tm_wday ;
   int tm_yday ;
   int tm_isdst ;
   long tm_gmtoff ;
   char const   *tm_zone ;
};
struct __anonstruct___sigset_t_9 {
   unsigned long __val[1024UL / (8UL * sizeof(unsigned long ))] ;
};
typedef struct __anonstruct___sigset_t_9 __sigset_t;
typedef __sigset_t sigset_t;
struct sched_param {
   int __sched_priority ;
};
struct __anonstruct_posix_spawnattr_t_50 {
   short __flags ;
   pid_t __pgrp ;
   sigset_t __sd ;
   sigset_t __ss ;
   struct sched_param __sp ;
   int __policy ;
   int __pad[16] ;
};
typedef struct __anonstruct_posix_spawnattr_t_50 posix_spawnattr_t;
struct __spawn_action;
struct __spawn_action;
struct __anonstruct_posix_spawn_file_actions_t_51 {
   int __allocated ;
   int __used ;
   struct __spawn_action *__actions ;
   int __pad[16] ;
};
typedef struct __anonstruct_posix_spawn_file_actions_t_51 posix_spawn_file_actions_t;
struct numname {
   int num ;
   char const   name[8] ;
};
typedef unsigned long uint64_t;
typedef uint64_t u64;
struct sha512_ctx {
   u64 state[8] ;
   u64 total[2] ;
   size_t buflen ;
   u64 buffer[32] ;
};
struct sha256_ctx {
   uint32_t state[8] ;
   uint32_t total[2] ;
   size_t buflen ;
   uint32_t buffer[32] ;
};
struct sha1_ctx {
   uint32_t A ;
   uint32_t B ;
   uint32_t C ;
   uint32_t D ;
   uint32_t E ;
   uint32_t total[2] ;
   uint32_t buflen ;
   uint32_t buffer[32] ;
};
typedef int __clockid_t;
typedef __clockid_t clockid_t;
struct timezone {
   int tz_minuteswest ;
   int tz_dsttime ;
};
enum __anonenum_state_14 {
    INITIAL_STATE = 0,
    FD_STATE = 1,
    FD_POST_CHDIR_STATE = 2,
    FORKING_STATE = 3,
    ERROR_STATE = 4,
    FINAL_STATE = 5
} ;
union __anonunion_val_15 {
   int fd ;
   int errnum ;
   pid_t child ;
};
struct savewd {
   enum __anonenum_state_14 state ;
   union __anonunion_val_15 val ;
};
union __anonunion_52___0 {
   int __in ;
   int __i ;
};
union __anonunion_53___0 {
   int __in ;
   int __i ;
};
union __anonunion_54___0 {
   int __in ;
   int __i ;
};
typedef int __int32_t;
struct __exit_status {
   short e_termination ;
   short e_exit ;
};
struct __anonstruct_ut_tv_15 {
   __int32_t tv_sec ;
   __int32_t tv_usec ;
};
struct utmpx {
   short ut_type ;
   __pid_t ut_pid ;
   char ut_line[32] ;
   char ut_id[4] ;
   char ut_user[32] ;
   char ut_host[256] ;
   struct __exit_status ut_exit ;
   __int32_t ut_session ;
   struct __anonstruct_ut_tv_15 ut_tv ;
   __int32_t ut_addr_v6[4] ;
   char __glibc_reserved[20] ;
};
typedef struct utmpx STRUCT_UTMP;
struct obstack;
struct obstack;
struct _obstack_chunk {
   char *limit ;
   struct _obstack_chunk *prev ;
   char contents[4] ;
};
union __anonunion_temp_26 {
   long tempint ;
   void *tempptr ;
};
struct obstack {
   long chunk_size ;
   struct _obstack_chunk *chunk ;
   char *object_base ;
   char *next_free ;
   char *chunk_limit ;
   union __anonunion_temp_26 temp ;
   int alignment_mask ;
   struct _obstack_chunk *(*chunkfun)(void * , long  ) ;
   void (*freefun)(void * , struct _obstack_chunk * ) ;
   void *extra_arg ;
   unsigned int use_extra_arg : 1 ;
   unsigned int maybe_empty_object : 1 ;
   unsigned int alloc_failed : 1 ;
};
struct Tokens {
   size_t n_tok ;
   char **tok ;
   size_t *tok_len ;
   struct obstack o_data ;
   struct obstack o_tok ;
   struct obstack o_tok_len ;
};
struct tokenbuffer {
   size_t size ;
   char *buffer ;
};
typedef struct tokenbuffer token_buffer;
typedef size_t word;
struct randread_source;
struct randread_source;
typedef unsigned long uint_least64_t;
typedef struct timezone * __restrict  __timezone_ptr_t;
typedef uint_least64_t isaac_word;
struct isaac_state {
   isaac_word m[1 << 8] ;
   isaac_word a ;
   isaac_word b ;
   isaac_word c ;
};
union __anonunion_data_31 {
   isaac_word w[1 << 8] ;
   unsigned char b[(unsigned long )(1 << 8) * sizeof(isaac_word )] ;
};
struct isaac {
   size_t buffered ;
   struct isaac_state state ;
   union __anonunion_data_31 data ;
};
union __anonunion_buf_30 {
   char c[2UL * ((unsigned long )(1 << 8) * sizeof(isaac_word ))] ;
   struct isaac isaac ;
};
struct randread_source {
   FILE *source ;
   void (*handler)(void const   * ) ;
   void const   *handler_arg ;
   union __anonunion_buf_30 buf ;
};
struct sparse_ent_ {
   size_t index ;
   size_t val ;
};
typedef Hash_table sparse_map;
struct randint_source {
   struct randread_source *source ;
   randint randnum ;
   randint randmax ;
};
struct quoting_options;
struct quoting_options;
struct quoting_options {
   enum quoting_style style ;
   int flags ;
   unsigned int quote_these_too[255UL / (sizeof(int ) * 8UL) + 1UL] ;
   char const   *left_quote ;
   char const   *right_quote ;
};
struct slotvec {
   size_t size ;
   char *val ;
};
typedef struct mbchar mbchar_t;
struct mbuiter_multi {
   _Bool in_shift ;
   mbstate_t state ;
   _Bool next_done ;
   struct mbchar cur ;
};
typedef struct mbuiter_multi mbui_iterator_t;
typedef long long_time_t;
struct __anonstruct_textint_27 {
   _Bool negative ;
   long value ;
   size_t digits ;
};
typedef struct __anonstruct_textint_27 textint;
struct __anonstruct_table_28 {
   char const   *name ;
   int type ;
   int value ;
};
typedef struct __anonstruct_table_28 table;
struct __anonstruct_relative_time_31 {
   long year ;
   long month ;
   long day ;
   long hour ;
   long minutes ;
   long_time_t seconds ;
   long ns ;
};
typedef struct __anonstruct_relative_time_31 relative_time;
struct __anonstruct_parser_control_32 {
   char const   *input ;
   long day_ordinal ;
   int day_number ;
   int local_isdst ;
   long time_zone ;
   int meridian ;
   textint year ;
   long month ;
   long day ;
   long hour ;
   long minutes ;
   struct timespec seconds ;
   relative_time rel ;
   _Bool timespec_seen ;
   _Bool rels_seen ;
   size_t dates_seen ;
   size_t days_seen ;
   size_t local_zones_seen ;
   size_t dsts_seen ;
   size_t times_seen ;
   size_t zones_seen ;
   table local_time_zone_table[3] ;
};
typedef struct __anonstruct_parser_control_32 parser_control;
union YYSTYPE;
union YYSTYPE;
union YYSTYPE {
   long intval ;
   textint textintval ;
   struct timespec timespec ;
   relative_time rel ;
};
typedef union YYSTYPE YYSTYPE;
typedef unsigned char yytype_uint8;
typedef signed char yytype_int8;
typedef short yytype_int16;
union yyalloc {
   yytype_int16 yyss_alloc ;
   YYSTYPE yyvs_alloc ;
};
enum nproc_query {
    NPROC_ALL = 0,
    NPROC_CURRENT = 1,
    NPROC_CURRENT_OVERRIDABLE = 2
} ;
typedef unsigned long __cpu_mask;
struct __anonstruct_cpu_set_t_24 {
   __cpu_mask __bits[1024UL / (8UL * sizeof(__cpu_mask ))] ;
};
typedef struct __anonstruct_cpu_set_t_24 cpu_set_t;
struct mount_entry {
   char *me_devname ;
   char *me_mountdir ;
   char *me_type ;
   dev_t me_dev ;
   unsigned int me_dummy : 1 ;
   unsigned int me_remote : 1 ;
   unsigned int me_type_malloced : 1 ;
   struct mount_entry *me_next ;
};
struct mntent {
   char *mnt_fsname ;
   char *mnt_dir ;
   char *mnt_type ;
   char *mnt_opts ;
   int mnt_freq ;
   int mnt_passno ;
};
struct mode_change;
struct mode_change;
struct mode_change {
   char op ;
   char flag ;
   mode_t affected ;
   mode_t value ;
   mode_t mentioned ;
};
typedef unsigned long longword;
struct md5_ctx {
   uint32_t A ;
   uint32_t B ;
   uint32_t C ;
   uint32_t D ;
   uint32_t total[2] ;
   uint32_t buflen ;
   uint32_t buffer[32] ;
};
enum __anonenum_mbs_align_t_1 {
    MBS_ALIGN_LEFT = 0,
    MBS_ALIGN_RIGHT = 1,
    MBS_ALIGN_CENTER = 2
} ;
typedef enum __anonenum_mbs_align_t_1 mbs_align_t;
typedef unsigned long uintptr_t;
struct preliminary_header {
   void *next ;
   char room[sizeof(int )] ;
};
struct header {
   void *next ;
   char room[((((sizeof(struct preliminary_header ) + 16UL) - 1UL) / 16UL) * 16UL - sizeof(struct preliminary_header )) + sizeof(int )] ;
};
struct __pthread_internal_list {
   struct __pthread_internal_list *__prev ;
   struct __pthread_internal_list *__next ;
};
typedef struct __pthread_internal_list __pthread_list_t;
struct __pthread_mutex_s {
   int __lock ;
   unsigned int __count ;
   int __owner ;
   unsigned int __nusers ;
   int __kind ;
   short __spins ;
   short __elision ;
   __pthread_list_t __list ;
};
union __anonunion_pthread_mutex_t_11 {
   struct __pthread_mutex_s __data ;
   char __size[40] ;
   long __align ;
};
typedef union __anonunion_pthread_mutex_t_11 pthread_mutex_t;
union __anonunion_pthread_mutexattr_t_12 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_mutexattr_t_12 pthread_mutexattr_t;
typedef int pthread_once_t;
typedef pthread_mutex_t gl_recursive_lock_t;
struct linebuffer {
   size_t size ;
   size_t length ;
   char *buffer ;
};
union __anonunion_memory_double_1 {
   long double value ;
   unsigned int word[((sizeof(long double ) + sizeof(unsigned int )) - 1UL) / sizeof(unsigned int )] ;
};
typedef union __anonunion_memory_double_1 memory_double;
struct ino_map_ent {
   ino_t ino ;
   size_t mapped_ino ;
};
struct ino_map {
   struct hash_table *map ;
   size_t next_mapped_ino ;
   struct ino_map_ent *probe ;
};
union __anonunion_id_23 {
   uid_t u ;
   gid_t g ;
};
struct userid {
   union __anonunion_id_23 id ;
   struct userid *next ;
   char name[] ;
};
struct lconv {
   char *decimal_point ;
   char *thousands_sep ;
   char *grouping ;
   char *int_curr_symbol ;
   char *currency_symbol ;
   char *mon_decimal_point ;
   char *mon_thousands_sep ;
   char *mon_grouping ;
   char *positive_sign ;
   char *negative_sign ;
   char int_frac_digits ;
   char frac_digits ;
   char p_cs_precedes ;
   char p_sep_by_space ;
   char n_cs_precedes ;
   char n_sep_by_space ;
   char p_sign_posn ;
   char n_sign_posn ;
   char int_p_cs_precedes ;
   char int_p_sep_by_space ;
   char int_n_cs_precedes ;
   char int_n_sep_by_space ;
   char int_p_sign_posn ;
   char int_n_sign_posn ;
};
struct heap;
struct heap;
struct heap {
   void **array ;
   size_t capacity ;
   size_t count ;
   int (*compare)(void const   * , void const   * ) ;
};
struct hash_entry {
   void *data ;
   struct hash_entry *next ;
};
struct hash_table {
   struct hash_entry *bucket ;
   struct hash_entry  const  *bucket_limit ;
   size_t n_buckets ;
   size_t n_buckets_used ;
   size_t n_entries ;
   Hash_tuning const   *tuning ;
   size_t (*hasher)(void const   * , size_t  ) ;
   _Bool (*comparator)(void const   * , void const   * ) ;
   void (*data_freer)(void * ) ;
   struct hash_entry *free_entry_list ;
};
struct F_triple {
   char *name ;
   ino_t st_ino ;
   dev_t st_dev ;
};
typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;
struct termios {
   tcflag_t c_iflag ;
   tcflag_t c_oflag ;
   tcflag_t c_cflag ;
   tcflag_t c_lflag ;
   cc_t c_line ;
   cc_t c_cc[32] ;
   speed_t c_ispeed ;
   speed_t c_ospeed ;
};
typedef long long xtime_t;
struct __anonstruct___fsid_t_1 {
   int __val[2] ;
};
typedef struct __anonstruct___fsid_t_1 __fsid_t;
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsfilcnt_t;
typedef long __fsword_t;
struct Active_dir {
   dev_t dev ;
   ino_t ino ;
   FTSENT *fts_ent ;
};
struct statfs {
   __fsword_t f_type ;
   __fsword_t f_bsize ;
   __fsblkcnt_t f_blocks ;
   __fsblkcnt_t f_bfree ;
   __fsblkcnt_t f_bavail ;
   __fsfilcnt_t f_files ;
   __fsfilcnt_t f_ffree ;
   __fsid_t f_fsid ;
   __fsword_t f_namelen ;
   __fsword_t f_frsize ;
   __fsword_t f_flags ;
   __fsword_t f_spare[4] ;
};
struct LCO_ent {
   dev_t st_dev ;
   _Bool opt_ok ;
};
struct fs_usage {
   uintmax_t fsu_blocksize ;
   uintmax_t fsu_blocks ;
   uintmax_t fsu_bfree ;
   uintmax_t fsu_bavail ;
   _Bool fsu_bavail_top_bit_set ;
   uintmax_t fsu_files ;
   uintmax_t fsu_ffree ;
};
typedef long __clock_t;
union sigval {
   int sival_int ;
   void *sival_ptr ;
};
typedef union sigval sigval_t;
typedef __clock_t __sigchld_clock_t;
struct __anonstruct__kill_23 {
   __pid_t si_pid ;
   __uid_t si_uid ;
};
struct __anonstruct__timer_24 {
   int si_tid ;
   int si_overrun ;
   sigval_t si_sigval ;
};
struct __anonstruct__rt_25 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   sigval_t si_sigval ;
};
struct __anonstruct__sigchld_26 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   int si_status ;
   __sigchld_clock_t si_utime ;
   __sigchld_clock_t si_stime ;
};
struct __anonstruct__sigfault_27 {
   void *si_addr ;
   short si_addr_lsb ;
};
struct __anonstruct__sigpoll_28 {
   long si_band ;
   int si_fd ;
};
struct __anonstruct__sigsys_29 {
   void *_call_addr ;
   int _syscall ;
   unsigned int _arch ;
};
union __anonunion__sifields_22 {
   int _pad[128UL / sizeof(int ) - 4UL] ;
   struct __anonstruct__kill_23 _kill ;
   struct __anonstruct__timer_24 _timer ;
   struct __anonstruct__rt_25 _rt ;
   struct __anonstruct__sigchld_26 _sigchld ;
   struct __anonstruct__sigfault_27 _sigfault ;
   struct __anonstruct__sigpoll_28 _sigpoll ;
   struct __anonstruct__sigsys_29 _sigsys ;
};
struct __anonstruct_siginfo_t_21 {
   int si_signo ;
   int si_errno ;
   int si_code ;
   union __anonunion__sifields_22 _sifields ;
};
typedef struct __anonstruct_siginfo_t_21 siginfo_t;
union __anonunion___sigaction_handler_41 {
   void (*sa_handler)(int  ) ;
   void (*sa_sigaction)(int  , siginfo_t * , void * ) ;
};
struct sigaction {
   union __anonunion___sigaction_handler_41 __sigaction_handler ;
   __sigset_t sa_mask ;
   int sa_flags ;
   void (*sa_restorer)(void) ;
};
typedef void (*sa_handler_t)(int  );
struct __anonstruct_actions_entry_t_50 {
   void (* volatile  action)(void) ;
};
typedef struct __anonstruct_actions_entry_t_50 actions_entry_t;
enum __anonenum_fadvice_t_19 {
    FADVISE_NORMAL = 0,
    FADVISE_SEQUENTIAL = 2,
    FADVISE_NOREUSE = 5,
    FADVISE_DONTNEED = 4,
    FADVISE_WILLNEED = 3,
    FADVISE_RANDOM = 1
} ;
typedef enum __anonenum_fadvice_t_19 fadvice_t;
struct exclude;
struct exclude;
struct patopts {
   char const   *pattern ;
   int options ;
};
struct exclude_pattern {
   struct patopts *exclude ;
   size_t exclude_alloc ;
   size_t exclude_count ;
};
enum exclude_type {
    exclude_hash = 0,
    exclude_pattern = 1
} ;
union __anonunion_v_29 {
   Hash_table *table ;
   struct exclude_pattern pat ;
};
struct exclude_segment {
   struct exclude_segment *next ;
   enum exclude_type type ;
   int options ;
   union __anonunion_v_29 v ;
};
struct exclude {
   struct exclude_segment *head ;
   struct exclude_segment *tail ;
};
enum countmode {
    count_occurrences = 0,
    count_none = 1
} ;
enum delimit_method {
    DM_NONE = 0,
    DM_PREPEND = 1,
    DM_SEPARATE = 2
} ;
enum Skip_field_option_type {
    SFO_NONE = 0,
    SFO_OBSOLETE = 1,
    SFO_NEW = 2
} ;
extern  __attribute__((__nothrow__)) int snprintf(char * __restrict  __s , size_t __maxlen ,
                                                  char const   * __restrict  __format 
                                                  , ...) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__nonnull__(1), __leaf__)) strtod)(char const   * __restrict  __nptr ,
                                                                                                char ** __restrict  __endptr ) ;
 __attribute__((__noreturn__)) void xalloc_die(void) ;
char *last_component(char const   *name )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2), __leaf__)) memcpy)(void * __restrict  __dest ,
                                                                                                 void const   * __restrict  __src ,
                                                                                                 size_t __n ) ;
extern  __attribute__((__nothrow__)) int *( __attribute__((__leaf__)) __errno_location)(void)  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) stat)(char const   * __restrict  __file ,
                                                                                             struct stat * __restrict  __buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2), __leaf__)) fstat)(int __fd ,
                                                                                            struct stat *__buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) chmod)(char const   *__file ,
                                                                                            __mode_t __mode ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) fchmod)(int __fd ,
                                                                             __mode_t __mode ) ;
extern int close(int __fd ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) chown)(char const   *__file ,
                                                                                            __uid_t __owner ,
                                                                                            __gid_t __group ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) fchown)(int __fd ,
                                                                             __uid_t __owner ,
                                                                             __gid_t __group ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) lchown)(char const   *__file ,
                                                                                             __uid_t __owner ,
                                                                                             __gid_t __group ) ;
char const   diacrit_base[256] ;
char const   diacrit_diac[256] ;
char const   diacrit_base[256]  = 
  {      (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )'A',      (char const   )'B',      (char const   )'C', 
        (char const   )'D',      (char const   )'E',      (char const   )'F',      (char const   )'G', 
        (char const   )'H',      (char const   )'I',      (char const   )'J',      (char const   )'K', 
        (char const   )'L',      (char const   )'M',      (char const   )'N',      (char const   )'O', 
        (char const   )'P',      (char const   )'Q',      (char const   )'R',      (char const   )'S', 
        (char const   )'T',      (char const   )'U',      (char const   )'V',      (char const   )'W', 
        (char const   )'X',      (char const   )'Y',      (char const   )'Z',      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )'a',      (char const   )'b',      (char const   )'c', 
        (char const   )'d',      (char const   )'e',      (char const   )'f',      (char const   )'g', 
        (char const   )'h',      (char const   )'i',      (char const   )'j',      (char const   )'k', 
        (char const   )'l',      (char const   )'m',      (char const   )'n',      (char const   )'o', 
        (char const   )'p',      (char const   )'q',      (char const   )'r',      (char const   )'s', 
        (char const   )'t',      (char const   )'u',      (char const   )'v',      (char const   )'w', 
        (char const   )'x',      (char const   )'y',      (char const   )'z',      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )'A',      (char const   )'A',      (char const   )'A',      (char const   )'A', 
        (char const   )'A',      (char const   )'A',      (char const   )'A',      (char const   )'C', 
        (char const   )'E',      (char const   )'E',      (char const   )'E',      (char const   )'E', 
        (char const   )'I',      (char const   )'I',      (char const   )'I',      (char const   )'I', 
        (char const   )0,      (char const   )'N',      (char const   )'O',      (char const   )'O', 
        (char const   )'O',      (char const   )'O',      (char const   )'O',      (char const   )0, 
        (char const   )'O',      (char const   )'U',      (char const   )'U',      (char const   )'U', 
        (char const   )'U',      (char const   )'Y',      (char const   )0,      (char const   )0, 
        (char const   )'a',      (char const   )'a',      (char const   )'a',      (char const   )'a', 
        (char const   )'a',      (char const   )'a',      (char const   )'a',      (char const   )'c', 
        (char const   )'e',      (char const   )'e',      (char const   )'e',      (char const   )'e', 
        (char const   )'i',      (char const   )'i',      (char const   )'i',      (char const   )'i', 
        (char const   )0,      (char const   )'n',      (char const   )'o',      (char const   )'o', 
        (char const   )'o',      (char const   )'o',      (char const   )'o',      (char const   )0, 
        (char const   )'o',      (char const   )'u',      (char const   )'u',      (char const   )'u', 
        (char const   )'u',      (char const   )'y',      (char const   )0,      (char const   )'y'};
char const   diacrit_diac[256]  = 
  {      (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )4,      (char const   )0, 
        (char const   )3,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )6,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )6, 
        (char const   )5,      (char const   )8,      (char const   )1,      (char const   )7, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )5, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )5, 
        (char const   )0,      (char const   )6,      (char const   )3,      (char const   )2, 
        (char const   )4,      (char const   )6,      (char const   )5,      (char const   )0, 
        (char const   )9,      (char const   )3,      (char const   )2,      (char const   )4, 
        (char const   )5,      (char const   )2,      (char const   )0,      (char const   )0, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )6, 
        (char const   )5,      (char const   )8,      (char const   )1,      (char const   )7, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )5, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )5, 
        (char const   )0,      (char const   )6,      (char const   )3,      (char const   )2, 
        (char const   )4,      (char const   )6,      (char const   )5,      (char const   )0, 
        (char const   )9,      (char const   )3,      (char const   )2,      (char const   )4, 
        (char const   )5,      (char const   )2,      (char const   )0,      (char const   )0};
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) __assert_fail)(char const   *__assertion ,
                                                                                                   char const   *__file ,
                                                                                                   unsigned int __line ,
                                                                                                   char const   *__function ) ;
extern int ( __attribute__((__nonnull__(1))) creat)(char const   *__file , mode_t __mode ) ;
extern void error(int __status , int __errnum , char const   *__format  , ...) ;
char const   *quote(char const   *name ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) gettext)(char const   *__msgid )  __attribute__((__format_arg__(1))) ;
void close_stdout(void) ;
extern struct _IO_FILE *stdout ;
extern struct _IO_FILE *stderr ;
extern  __attribute__((__noreturn__)) void _exit(int __status ) ;
int close_stream(FILE *stream ) ;
int volatile   exit_failure ;
char *quotearg_colon(char const   *arg ) ;
static char const   *file_name  ;
static _Bool ignore_EPIPE  ;
void close_stdout(void) 
{ 
  char const   *write_error ;
  char const   *tmp ;
  char *tmp___0 ;
  int *tmp___1 ;
  int *tmp___2 ;
  int tmp___3 ;
  int *tmp___4 ;
  int tmp___5 ;
  char *__cil_tmp10 ;

  {
  {
  tmp___3 = close_stream(stdout);
  }
  if (tmp___3 != 0) {
    if (ignore_EPIPE) {
      {
      tmp___4 = __errno_location();
      }
      if (! (*tmp___4 == 32)) {
        goto _L;
      }
    } else {
      _L: 
      {
      tmp = (char const   *)gettext("write error");
      write_error = tmp;
      }
      if (file_name) {
        {
        tmp___0 = quotearg_colon(file_name);
        tmp___1 = __errno_location();
        error(0, *tmp___1, "%s: %s", tmp___0, write_error);
        }
      } else {
        {
        tmp___2 = __errno_location();
        error(0, *tmp___2, "%s", write_error);
        }
      }
      {
      _exit((int )exit_failure);
      }
    }
  }
  {
  tmp___5 = close_stream(stderr);
  }
  if (tmp___5 != 0) {
    {
    _exit((int )exit_failure);
    }
  }
  return;
}
}
extern struct _IO_FILE *stdin ;
int rpl_fflush(FILE *stream ) ;
int ( __attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp , off_t offset , int whence ) ;
static char const   *file_name___0  ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) ferror_unlocked)(FILE *__stream ) ;
int ( __attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp ) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) __fpending)(FILE *__fp ) ;
int close_stream(FILE *stream ) 
{ 
  _Bool some_pending ;
  size_t tmp ;
  _Bool prev_fail ;
  int tmp___0 ;
  _Bool fclose_fail ;
  int tmp___1 ;
  int *tmp___2 ;
  int *tmp___3 ;

  {
  {
  tmp = __fpending(stream);
  some_pending = (_Bool )(tmp != 0UL);
  tmp___0 = ferror_unlocked(stream);
  prev_fail = (_Bool )(tmp___0 != 0);
  tmp___1 = rpl_fclose(stream);
  fclose_fail = (_Bool )(tmp___1 != 0);
  }
  if (prev_fail) {
    goto _L___0;
  } else
  if (fclose_fail) {
    if (some_pending) {
      goto _L___0;
    } else {
      {
      tmp___3 = __errno_location();
      }
      if (*tmp___3 != 9) {
        _L___0: 
        if (! fclose_fail) {
          {
          tmp___2 = __errno_location();
          *tmp___2 = 0;
          }
        }
        return (-1);
      }
    }
  }
  return (0);
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) chdir)(char const   *__path ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) fchdir)(int __fd ) ;
extern int ( __attribute__((__nonnull__(2))) openat)(int __fd , char const   *__file ,
                                                     int __oflag  , ...) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1), __leaf__)) memchr)(void const   *__s ,
                                                                                               int __c ,
                                                                                               size_t __n )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1), __leaf__)) memrchr)(void const   *__s ,
                                                                                                int __c ,
                                                                                                size_t __n )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1,2), __leaf__)) strspn)(char const   *__s ,
                                                                                                  char const   *__accept )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1), __leaf__)) strlen)(char const   *__s )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) ssize_t ( __attribute__((__nonnull__(1,2), __leaf__)) readlink)(char const   * __restrict  __path ,
                                                                                                     char * __restrict  __buf ,
                                                                                                     size_t __len ) ;
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) abort)(void) ;
struct allocator  const  stdlib_allocator ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2), __leaf__)) memmove)(void *__dest ,
                                                                                                  void const   *__src ,
                                                                                                  size_t __n ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) strchr)(char const   *__s ,
                                                                                               int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) lstat)(char const   * __restrict  __file ,
                                                                                              struct stat * __restrict  __buf ) ;
void *xmalloc(size_t n )  __attribute__((__malloc__, __alloc_size__(1))) ;
void *xrealloc(void *p , size_t n )  __attribute__((__alloc_size__(2))) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) strdup)(char const   *__s )  __attribute__((__malloc__)) ;
extern int getaddrinfo(char const   * __restrict  __name , char const   * __restrict  __service ,
                       struct addrinfo  const  * __restrict  __req , struct addrinfo ** __restrict  __pai ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) freeaddrinfo)(struct addrinfo *__ai ) ;
extern  __attribute__((__nothrow__)) char const   *( __attribute__((__leaf__)) gai_strerror)(int __ecode ) ;
static int last_cherror  ;
static struct addrinfo hints  ;
extern  __attribute__((__nothrow__)) __locale_t ( __attribute__((__leaf__)) newlocale)(int __category_mask ,
                                                                                       char const   *__locale ,
                                                                                       __locale_t __base ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__nonnull__(1,3),
__leaf__)) strtold_l)(char const   * __restrict  __nptr , char ** __restrict  __endptr ,
                      __locale_t __loc ) ;
static locale_t volatile   c_locale_cache  ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__nonnull__(1,3), __leaf__)) strtod_l)(char const   * __restrict  __nptr ,
                                                                                                    char ** __restrict  __endptr ,
                                                                                                    __locale_t __loc ) ;
static locale_t volatile   c_locale_cache___0  ;
int c_tolower(int c )  __attribute__((__const__)) ;
int c_strcasecmp(char const   *s1 , char const   *s2 )  __attribute__((__pure__)) ;
int c_strcasecmp(char const   *s1 , char const   *s2 )  __attribute__((__pure__)) ;
int c_strcasecmp(char const   *s1 , char const   *s2 ) 
{ 
  register unsigned char const   *p1 ;
  register unsigned char const   *p2 ;
  unsigned char c1 ;
  unsigned char c2 ;

  {
  p1 = (unsigned char const   *)s1;
  p2 = (unsigned char const   *)s2;
  if ((unsigned long )p1 == (unsigned long )p2) {
    return (0);
  }
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    {
    c1 = (unsigned char )c_tolower((int )*p1);
    c2 = (unsigned char )c_tolower((int )*p2);
    }
    if ((int )c1 == 0) {
      goto while_break;
    }
    p1 ++;
    p2 ++;
    if (! ((int )c1 == (int )c2)) {
      goto while_break;
    }
  }
  while_break: /* CIL Label */ ;
  }
  return ((int )c1 - (int )c2);
}
}
int c_tolower(int c )  __attribute__((__const__)) ;
int c_tolower(int c ) 
{ 
  int tmp ;

  {
  if (c >= 65) {
    if (c <= 90) {
      tmp = (c - 65) + 97;
    } else {
      tmp = c;
    }
  } else {
    tmp = c;
  }
  return (tmp);
}
}
char *last_component(char const   *name )  __attribute__((__pure__)) ;
char *last_component(char const   *name ) 
{ 
  char const   *base ;
  char const   *p ;
  _Bool saw_slash ;

  {
  base = name + 0;
  saw_slash = (_Bool)0;
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    if (! ((int const   )*base == 47)) {
      goto while_break;
    }
    base ++;
  }
  while_break: /* CIL Label */ ;
  }
  p = base;
  {
  while (1) {
    while_continue___0: /* CIL Label */ ;
    if (! *p) {
      goto while_break___0;
    }
    if ((int const   )*p == 47) {
      saw_slash = (_Bool)1;
    } else
    if (saw_slash) {
      base = p;
      saw_slash = (_Bool)0;
    }
    p ++;
  }
  while_break___0: /* CIL Label */ ;
  }
  return ((char *)base);
}
}
__inline static unsigned char to_uchar(char ch ) 
{ 


  {
  return ((unsigned char )ch);
}
}
static char const   b64str[64]  = 
  {      (char const   )'A',      (char const   )'B',      (char const   )'C',      (char const   )'D', 
        (char const   )'E',      (char const   )'F',      (char const   )'G',      (char const   )'H', 
        (char const   )'I',      (char const   )'J',      (char const   )'K',      (char const   )'L', 
        (char const   )'M',      (char const   )'N',      (char const   )'O',      (char const   )'P', 
        (char const   )'Q',      (char const   )'R',      (char const   )'S',      (char const   )'T', 
        (char const   )'U',      (char const   )'V',      (char const   )'W',      (char const   )'X', 
        (char const   )'Y',      (char const   )'Z',      (char const   )'a',      (char const   )'b', 
        (char const   )'c',      (char const   )'d',      (char const   )'e',      (char const   )'f', 
        (char const   )'g',      (char const   )'h',      (char const   )'i',      (char const   )'j', 
        (char const   )'k',      (char const   )'l',      (char const   )'m',      (char const   )'n', 
        (char const   )'o',      (char const   )'p',      (char const   )'q',      (char const   )'r', 
        (char const   )'s',      (char const   )'t',      (char const   )'u',      (char const   )'v', 
        (char const   )'w',      (char const   )'x',      (char const   )'y',      (char const   )'z', 
        (char const   )'0',      (char const   )'1',      (char const   )'2',      (char const   )'3', 
        (char const   )'4',      (char const   )'5',      (char const   )'6',      (char const   )'7', 
        (char const   )'8',      (char const   )'9',      (char const   )'+',      (char const   )'/'};
static signed char const   b64[256]  = 
  {      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )62, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )63, 
        (signed char const   )52,      (signed char const   )53,      (signed char const   )54,      (signed char const   )55, 
        (signed char const   )56,      (signed char const   )57,      (signed char const   )58,      (signed char const   )59, 
        (signed char const   )60,      (signed char const   )61,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )0,      (signed char const   )1,      (signed char const   )2, 
        (signed char const   )3,      (signed char const   )4,      (signed char const   )5,      (signed char const   )6, 
        (signed char const   )7,      (signed char const   )8,      (signed char const   )9,      (signed char const   )10, 
        (signed char const   )11,      (signed char const   )12,      (signed char const   )13,      (signed char const   )14, 
        (signed char const   )15,      (signed char const   )16,      (signed char const   )17,      (signed char const   )18, 
        (signed char const   )19,      (signed char const   )20,      (signed char const   )21,      (signed char const   )22, 
        (signed char const   )23,      (signed char const   )24,      (signed char const   )25,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )26,      (signed char const   )27,      (signed char const   )28, 
        (signed char const   )29,      (signed char const   )30,      (signed char const   )31,      (signed char const   )32, 
        (signed char const   )33,      (signed char const   )34,      (signed char const   )35,      (signed char const   )36, 
        (signed char const   )37,      (signed char const   )38,      (signed char const   )39,      (signed char const   )40, 
        (signed char const   )41,      (signed char const   )42,      (signed char const   )43,      (signed char const   )44, 
        (signed char const   )45,      (signed char const   )46,      (signed char const   )47,      (signed char const   )48, 
        (signed char const   )49,      (signed char const   )50,      (signed char const   )51,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1};
char const   *simple_backup_suffix ;
void (*argmatch_die)(void) ;
ptrdiff_t __xargmatch_internal(char const   *context , char const   *arg , char const   * const  *arglist ,
                               char const   *vallist , size_t valsize , void (*exit_fn)(void) ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) getenv)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) memcmp)(void const   *__s1 ,
                                                                                               void const   *__s2 ,
                                                                                               size_t __n )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2), __leaf__)) strcpy)(char * __restrict  __dest ,
                                                                                                 char const   * __restrict  __src ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1), __leaf__)) pathconf)(char const   *__path ,
                                                                                                int __name ) ;
extern int ( __attribute__((__nonnull__(1))) closedir)(DIR *__dirp ) ;
extern struct dirent *( __attribute__((__nonnull__(1))) readdir)(DIR *__dirp ) ;
char const   *simple_backup_suffix  =    "~";
static char const   * const  backup_args[9]  = 
  {      (char const   */* const  */)"none",      (char const   */* const  */)"off",      (char const   */* const  */)"simple",      (char const   */* const  */)"never", 
        (char const   */* const  */)"existing",      (char const   */* const  */)"nil",      (char const   */* const  */)"numbered",      (char const   */* const  */)"t", 
        (char const   */* const  */)((void *)0)};
static enum backup_type  const  backup_types[8]  = 
  {      (enum backup_type  const  )0,      (enum backup_type  const  )0,      (enum backup_type  const  )1,      (enum backup_type  const  )1, 
        (enum backup_type  const  )2,      (enum backup_type  const  )2,      (enum backup_type  const  )3,      (enum backup_type  const  )3};
extern __ssize_t getdelim(char ** __restrict  __lineptr , size_t * __restrict  __n ,
                          int __delimiter , FILE * __restrict  __stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) feof)(FILE *__stream ) ;
ptrdiff_t argmatch(char const   *arg , char const   * const  *arglist , char const   *vallist ,
                   size_t valsize )  __attribute__((__pure__)) ;
void argmatch_invalid(char const   *context , char const   *value , ptrdiff_t problem ) ;
void argmatch_valid(char const   * const  *arglist , char const   *vallist , size_t valsize ) ;
extern int fprintf(FILE * __restrict  __stream , char const   * __restrict  __format 
                   , ...) ;
extern int putc_unlocked(int __c , FILE *__stream ) ;
extern int fputs_unlocked(char const   * __restrict  __s , FILE * __restrict  __stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) strncmp)(char const   *__s1 ,
                                                                                                char const   *__s2 ,
                                                                                                size_t __n )  __attribute__((__pure__)) ;
char *quotearg_n_style(int n , enum quoting_style s , char const   *arg ) ;
char const   *quote_n(int n , char const   *name ) ;
 __attribute__((__noreturn__)) void usage(int status ) ;
static void __argmatch_die(void) 
{ 


  {
  {
  usage(1);
  }
  return;
}
}
void (*argmatch_die)(void)  =    & __argmatch_die;
ptrdiff_t argmatch(char const   *arg , char const   * const  *arglist , char const   *vallist ,
                   size_t valsize )  __attribute__((__pure__)) ;
ptrdiff_t argmatch(char const   *arg , char const   * const  *arglist , char const   *vallist ,
                   size_t valsize ) 
{ 
  size_t i ;
  size_t arglen ;
  ptrdiff_t matchind ;
  _Bool ambiguous ;
  int tmp ;
  size_t tmp___0 ;
  int tmp___1 ;

  {
  {
  matchind = (ptrdiff_t )-1;
  ambiguous = (_Bool)0;
  arglen = strlen(arg);
  i = (size_t )0;
  }
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    if (! *(arglist + i)) {
      goto while_break;
    }
    {
    tmp___1 = strncmp((char const   *)*(arglist + i), arg, arglen);
    }
    if (! tmp___1) {
      {
      tmp___0 = strlen((char const   *)*(arglist + i));
      }
      if (tmp___0 == arglen) {
        return ((ptrdiff_t )i);
      } else
      if (matchind == -1L) {
        matchind = (ptrdiff_t )i;
      } else
      if ((unsigned long )vallist == (unsigned long )((void *)0)) {
        ambiguous = (_Bool)1;
      } else {
        {
        tmp = memcmp((void const   *)(vallist + valsize * (size_t )matchind), (void const   *)(vallist + valsize * i),
                     valsize);
        }
        if (tmp) {
          ambiguous = (_Bool)1;
        }
      }
    }
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
  if (ambiguous) {
    return ((ptrdiff_t )-2);
  } else {
    return (matchind);
  }
}
}
void argmatch_invalid(char const   *context , char const   *value , ptrdiff_t problem ) 
{ 
  char const   *format ;
  char *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char const   *tmp___2 ;
  char *tmp___3 ;
  char *__cil_tmp10 ;
  char *__cil_tmp11 ;

  {
  if (problem == -1L) {
    {
    tmp = gettext("invalid argument %s for %s");
    tmp___1 = tmp;
    }
  } else {
    {
    tmp___0 = gettext("ambiguous argument %s for %s");
    tmp___1 = tmp___0;
    }
  }
  {
  format = (char const   *)tmp___1;
  tmp___2 = quote_n(1, context);
  tmp___3 = quotearg_n_style(0, (enum quoting_style )6, value);
  error(0, 0, format, tmp___3, tmp___2);
  }
  return;
}
}
void argmatch_valid(char const   * const  *arglist , char const   *vallist , size_t valsize ) 
{ 
  size_t i ;
  char const   *last_val ;
  char *tmp ;
  char const   *tmp___0 ;
  char const   *tmp___1 ;
  int tmp___2 ;
  char *__cil_tmp10 ;

  {
  {
  last_val = (char const   *)((void *)0);
  tmp = gettext("Valid arguments are:");
  fputs_unlocked((char const   */* __restrict  */)tmp, (FILE */* __restrict  */)stderr);
  i = (size_t )0;
  }
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    if (! *(arglist + i)) {
      goto while_break;
    }
    if (i == 0UL) {
      {
      tmp___0 = quote((char const   *)*(arglist + i));
      fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"\n  - %s",
              tmp___0);
      last_val = vallist + valsize * i;
      }
    } else {
      {
      tmp___2 = memcmp((void const   *)last_val, (void const   *)(vallist + valsize * i),
                       valsize);
      }
      if (tmp___2) {
        {
        tmp___0 = quote((char const   *)*(arglist + i));
        fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)"\n  - %s",
                tmp___0);
        last_val = vallist + valsize * i;
        }
      } else {
        {
        tmp___1 = quote((char const   *)*(arglist + i));
        fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)", %s",
                tmp___1);
        }
      }
    }
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
  {
  putc_unlocked('\n', stderr);
  }
  return;
}
}
ptrdiff_t __xargmatch_internal(char const   *context , char const   *arg , char const   * const  *arglist ,
                               char const   *vallist , size_t valsize , void (*exit_fn)(void) ) 
{ 
  ptrdiff_t res ;
  ptrdiff_t tmp ;

  {
  {
  tmp = argmatch(arg, arglist, vallist, valsize);
  res = tmp;
  }
  if (res >= 0L) {
    return (res);
  }
  {
  argmatch_invalid(context, arg, res);
  argmatch_valid(arglist, vallist, valsize);
  (*exit_fn)();
  }
  return ((ptrdiff_t )-1);
}
}
extern  __attribute__((__nothrow__)) ssize_t ( __attribute__((__nonnull__(2,3), __leaf__)) readlinkat)(int __fd ,
                                                                                                       char const   * __restrict  __path ,
                                                                                                       char * __restrict  __buf ,
                                                                                                       size_t __len ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__warn_unused_result__,
__leaf__)) realloc)(void *__ptr , size_t __size ) ;
struct allocator  const  stdlib_allocator  =    {(void *(*)(size_t  ))(& malloc), (void *(*)(void * , size_t  ))(& realloc), (void (*)(void * ))(& free),
    (void (*)(size_t  ))((void *)0)};
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) rpmatch)(char const   *__response ) ;
extern __ssize_t getline(char ** __restrict  __lineptr , size_t * __restrict  __n ,
                         FILE * __restrict  __stream ) ;
__inline static void *xnmalloc(size_t n , size_t s )  __attribute__((__malloc__, __alloc_size__(1,2))) ;
__inline static void *xnmalloc(size_t n , size_t s )  __attribute__((__malloc__, __alloc_size__(1,2))) ;
__inline static void *xnmalloc(size_t n , size_t s ) 
{ 
  int tmp ;
  void *tmp___0 ;

  {
  if (sizeof(ptrdiff_t ) <= sizeof(size_t )) {
    tmp = -1;
  } else {
    tmp = -2;
  }
  if ((size_t )tmp / s < n) {
    {
    xalloc_die();
    }
  }
  {
  tmp___0 = xmalloc(n * s);
  }
  return (tmp___0);
}
}
extern  __attribute__((__nothrow__)) unsigned short const   **( __attribute__((__leaf__)) __ctype_b_loc)(void)  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) uintmax_t ( __attribute__((__leaf__)) strtoumax)(char const   * __restrict  __nptr ,
                                                                                      char ** __restrict  __endptr ,
                                                                                      int __base ) ;
strtol_error xstrtoul(char const   *s , char **ptr , int strtol_base , unsigned long *val ,
                      char const   *valid_suffixes ) ;
extern  __attribute__((__nothrow__)) unsigned long ( __attribute__((__nonnull__(1),
__leaf__)) strtoul)(char const   * __restrict  __nptr , char ** __restrict  __endptr ,
                    int __base ) ;
static strtol_error bkm_scale___0(unsigned long *x , int scale_factor ) 
{ 


  {
  if (0xffffffffffffffffUL / (unsigned long )scale_factor < *x) {
    *x = 0xffffffffffffffffUL;
    return ((strtol_error )1);
  }
  *x *= (unsigned long )scale_factor;
  return ((strtol_error )0);
}
}
static strtol_error bkm_scale_by_power___0(unsigned long *x , int base , int power ) 
{ 
  strtol_error err ;
  strtol_error tmp ;
  int tmp___0 ;

  {
  err = (strtol_error )0;
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    tmp___0 = power;
    power --;
    if (! tmp___0) {
      goto while_break;
    }
    {
    tmp = bkm_scale___0(x, base);
    err = (strtol_error )((unsigned int )err | (unsigned int )tmp);
    }
  }
  while_break: /* CIL Label */ ;
  }
  return (err);
}
}
strtol_error xstrtoul(char const   *s , char **ptr , int strtol_base , unsigned long *val ,
                      char const   *valid_suffixes ) 
{ 
  char *t_ptr ;
  char **p ;
  unsigned long tmp ;
  strtol_error err ;
  char const   *q ;
  unsigned char ch ;
  unsigned short const   **tmp___0 ;
  int *tmp___1 ;
  char *tmp___2 ;
  int *tmp___3 ;
  int *tmp___4 ;
  int base ;
  int suffixes ;
  strtol_error overflow ;
  char *tmp___5 ;
  char *tmp___6 ;

  {
  err = (strtol_error )0;
  if (0 <= strtol_base) {
    if (! (strtol_base <= 36)) {
      {
      __assert_fail("0 <= strtol_base && strtol_base <= 36", "/home/khheo/project/program-reduce/benchmark/coreutils-8.16/lib/xstrtol.c",
                    96U, "xstrtoul");
      }
    }
  } else {
    {
    __assert_fail("0 <= strtol_base && strtol_base <= 36", "/home/khheo/project/program-reduce/benchmark/coreutils-8.16/lib/xstrtol.c",
                  96U, "xstrtoul");
    }
  }
  if (ptr) {
    p = ptr;
  } else {
    p = & t_ptr;
  }
  q = s;
  ch = (unsigned char )*q;
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    {
    tmp___0 = __ctype_b_loc();
    }
    if (! ((int const   )*(*tmp___0 + (int )ch) & 8192)) {
      goto while_break;
    }
    q ++;
    ch = (unsigned char )*q;
  }
  while_break: /* CIL Label */ ;
  }
  if ((int )ch == 45) {
    return ((strtol_error )4);
  }
  {
  tmp___1 = __errno_location();
  *tmp___1 = 0;
  tmp = strtoul((char const   */* __restrict  */)s, (char **/* __restrict  */)p, strtol_base);
  }
  if ((unsigned long )*p == (unsigned long )s) {
    if (valid_suffixes) {
      if (*(*p)) {
        {
        tmp___2 = strchr(valid_suffixes, (int )*(*p));
        }
        if (tmp___2) {
          tmp = 1UL;
        } else {
          return ((strtol_error )4);
        }
      } else {
        return ((strtol_error )4);
      }
    } else {
      return ((strtol_error )4);
    }
  } else {
    {
    tmp___4 = __errno_location();
    }
    if (*tmp___4 != 0) {
      {
      tmp___3 = __errno_location();
      }
      if (*tmp___3 != 34) {
        return ((strtol_error )4);
      }
      err = (strtol_error )1;
    }
  }
  if (! valid_suffixes) {
    *val = tmp;
    return (err);
  }
  if ((int )*(*p) != 0) {
    {
    base = 1024;
    suffixes = 1;
    tmp___5 = strchr(valid_suffixes, (int )*(*p));
    }
    if (! tmp___5) {
      *val = tmp;
      return ((strtol_error )((unsigned int )err | 2U));
    }
    {
    tmp___6 = strchr(valid_suffixes, '0');
    }
    if (tmp___6) {
      {
      if ((int )*(*(p + 0) + 1) == 105) {
        goto case_105;
      }
      if ((int )*(*(p + 0) + 1) == 66) {
        goto case_66;
      }
      if ((int )*(*(p + 0) + 1) == 68) {
        goto case_66;
      }
      goto switch_break;
      case_105: /* CIL Label */ 
      if ((int )*(*(p + 0) + 2) == 66) {
        suffixes += 2;
      }
      goto switch_break;
      case_66: /* CIL Label */ 
      case_68: /* CIL Label */ 
      base = 1000;
      suffixes ++;
      goto switch_break;
      switch_break: /* CIL Label */ ;
      }
    }
    {
    if ((int )*(*p) == 98) {
      goto case_98;
    }
    if ((int )*(*p) == 66) {
      goto case_66___0;
    }
    if ((int )*(*p) == 99) {
      goto case_99;
    }
    if ((int )*(*p) == 69) {
      goto case_69;
    }
    if ((int )*(*p) == 71) {
      goto case_71;
    }
    if ((int )*(*p) == 103) {
      goto case_71;
    }
    if ((int )*(*p) == 107) {
      goto case_107;
    }
    if ((int )*(*p) == 75) {
      goto case_107;
    }
    if ((int )*(*p) == 77) {
      goto case_77;
    }
    if ((int )*(*p) == 109) {
      goto case_77;
    }
    if ((int )*(*p) == 80) {
      goto case_80;
    }
    if ((int )*(*p) == 84) {
      goto case_84;
    }
    if ((int )*(*p) == 116) {
      goto case_84;
    }
    if ((int )*(*p) == 119) {
      goto case_119;
    }
    if ((int )*(*p) == 89) {
      goto case_89;
    }
    if ((int )*(*p) == 90) {
      goto case_90;
    }
    goto switch_default;
    case_98: /* CIL Label */ 
    {
    overflow = bkm_scale___0(& tmp, 512);
    }
    goto switch_break___0;
    case_66___0: /* CIL Label */ 
    {
    overflow = bkm_scale___0(& tmp, 1024);
    }
    goto switch_break___0;
    case_99: /* CIL Label */ 
    overflow = (strtol_error )0;
    goto switch_break___0;
    case_69: /* CIL Label */ 
    {
    overflow = bkm_scale_by_power___0(& tmp, base, 6);
    }
    goto switch_break___0;
    case_71: /* CIL Label */ 
    case_103: /* CIL Label */ 
    {
    overflow = bkm_scale_by_power___0(& tmp, base, 3);
    }
    goto switch_break___0;
    case_107: /* CIL Label */ 
    case_75: /* CIL Label */ 
    {
    overflow = bkm_scale_by_power___0(& tmp, base, 1);
    }
    goto switch_break___0;
    case_77: /* CIL Label */ 
    case_109: /* CIL Label */ 
    {
    overflow = bkm_scale_by_power___0(& tmp, base, 2);
    }
    goto switch_break___0;
    case_80: /* CIL Label */ 
    {
    overflow = bkm_scale_by_power___0(& tmp, base, 5);
    }
    goto switch_break___0;
    case_84: /* CIL Label */ 
    case_116: /* CIL Label */ 
    {
    overflow = bkm_scale_by_power___0(& tmp, base, 4);
    }
    goto switch_break___0;
    case_119: /* CIL Label */ 
    {
    overflow = bkm_scale___0(& tmp, 2);
    }
    goto switch_break___0;
    case_89: /* CIL Label */ 
    {
    overflow = bkm_scale_by_power___0(& tmp, base, 8);
    }
    goto switch_break___0;
    case_90: /* CIL Label */ 
    {
    overflow = bkm_scale_by_power___0(& tmp, base, 7);
    }
    goto switch_break___0;
    switch_default: /* CIL Label */ 
    *val = tmp;
    return ((strtol_error )((unsigned int )err | 2U));
    switch_break___0: /* CIL Label */ ;
    }
    err = (strtol_error )((unsigned int )err | (unsigned int )overflow);
    *p += suffixes;
    if (*(*p)) {
      err = (strtol_error )((unsigned int )err | 2U);
    }
  }
  *val = tmp;
  return (err);
}
}
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1), __leaf__)) strtol)(char const   * __restrict  __nptr ,
                                                                                              char ** __restrict  __endptr ,
                                                                                              int __base ) ;
extern  __attribute__((__nothrow__)) intmax_t ( __attribute__((__leaf__)) strtoimax)(char const   * __restrict  __nptr ,
                                                                                     char ** __restrict  __endptr ,
                                                                                     int __base ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) strndup)(char const   *__string ,
                                                                                                size_t __n )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) ferror)(FILE *__stream ) ;
int memcoll(char *s1 , size_t s1len , char *s2 , size_t s2len ) ;
char *quotearg_n_style_mem(int n , enum quoting_style s , char const   *arg , size_t argsize ) ;
int xmemcoll(char *s1 , size_t s1len , char *s2 , size_t s2len ) ;
static void collate_error(int collation_errno , char const   *s1 , size_t s1len ,
                          char const   *s2 , size_t s2len ) 
{ 
  char *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  char *tmp___3 ;
  char *__cil_tmp11 ;
  char *__cil_tmp12 ;
  char *__cil_tmp13 ;

  {
  {
  tmp = gettext("string comparison failed");
  error(0, collation_errno, (char const   *)tmp);
  tmp___0 = gettext("Set LC_ALL=\'C\' to work around the problem.");
  error(0, 0, (char const   *)tmp___0);
  tmp___1 = quotearg_n_style_mem(1, (enum quoting_style )6, s2, s2len);
  tmp___2 = quotearg_n_style_mem(0, (enum quoting_style )6, s1, s1len);
  tmp___3 = gettext("The strings compared were %s and %s.");
  error((int )exit_failure, 0, (char const   *)tmp___3, tmp___2, tmp___1);
  }
  return;
}
}
int xmemcoll(char *s1 , size_t s1len , char *s2 , size_t s2len ) 
{ 
  int diff ;
  int tmp ;
  int collation_errno ;
  int *tmp___0 ;

  {
  {
  tmp = memcoll(s1, s1len, s2, s2len);
  diff = tmp;
  tmp___0 = __errno_location();
  collation_errno = *tmp___0;
  }
  if (collation_errno) {
    {
    collate_error(collation_errno, (char const   *)s1, s1len, (char const   *)s2,
                  s2len);
    }
  }
  return (diff);
}
}
void *x2realloc(void *p , size_t *pn ) ;
__inline static void *x2nrealloc(void *p , size_t *pn , size_t s ) 
{ 
  size_t n ;
  void *tmp ;

  {
  n = *pn;
  if (! p) {
    if (! n) {
      n = 128UL / s;
      n += (size_t )(! n);
    }
  } else {
    if (0xaaaaaaaaaaaaaaaaUL / s <= n) {
      {
      xalloc_die();
      }
    }
    n += (n + 1UL) / 2UL;
  }
  {
  *pn = n;
  tmp = xrealloc(p, n * s);
  }
  return (tmp);
}
}
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) calloc)(size_t __nmemb ,
                                                                               size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1), __leaf__)) memset)(void *__s ,
                                                                                               int __c ,
                                                                                               size_t __n ) ;
void *xmalloc(size_t n )  __attribute__((__malloc__, __alloc_size__(1))) ;
void *xmalloc(size_t n ) 
{ 
  void *p ;
  void *tmp ;

  {
  {
  tmp = malloc(n);
  p = tmp;
  }
  if (! p) {
    if (n != 0UL) {
      {
      xalloc_die();
      }
    }
  }
  return (p);
}
}
void *xrealloc(void *p , size_t n )  __attribute__((__alloc_size__(2))) ;
void *xrealloc(void *p , size_t n ) 
{ 


  {
  if (! n) {
    if (p) {
      {
      free(p);
      }
      return ((void *)0);
    }
  }
  {
  p = realloc(p, n);
  }
  if (! p) {
    if (n) {
      {
      xalloc_die();
      }
    }
  }
  return (p);
}
}
void *x2realloc(void *p , size_t *pn ) 
{ 
  void *tmp ;

  {
  {
  tmp = x2nrealloc(p, pn, (size_t )1);
  }
  return (tmp);
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) gethostname)(char *__name ,
                                                                                                  size_t __len ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) getcwd)(char *__buf ,
                                                                               size_t __size ) ;
FILE *freopen_safer(char const   *name , char const   *mode , FILE *f ) ;
 __attribute__((__noreturn__)) void xalloc_die(void) ;
void xalloc_die(void) 
{ 
  char *tmp ;
  char *__cil_tmp2 ;

  {
  {
  tmp = gettext("memory exhausted");
  error((int )exit_failure, 0, "%s", tmp);
  abort();
  }
}
}
extern  __attribute__((__nothrow__)) __uid_t ( __attribute__((__leaf__)) geteuid)(void) ;
static _Bool initialized  ;
static _Bool can_write  ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) strcmp)(char const   *__s1 ,
                                                                                               char const   *__s2 )  __attribute__((__pure__)) ;
static unsigned char const   nonspacing_table_data[1728]  = 
  {      (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )128, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255, 
        (unsigned char const   )0,      (unsigned char const   )32,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )248,      (unsigned char const   )3,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )254,      (unsigned char const   )255, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )191, 
        (unsigned char const   )182,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )15,      (unsigned char const   )0,      (unsigned char const   )255,      (unsigned char const   )7, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )248,      (unsigned char const   )255,      (unsigned char const   )255, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )1,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )192,      (unsigned char const   )191, 
        (unsigned char const   )159,      (unsigned char const   )61,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )128,      (unsigned char const   )2,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )255,      (unsigned char const   )255, 
        (unsigned char const   )255,      (unsigned char const   )7,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )192,      (unsigned char const   )255,      (unsigned char const   )1,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )248,      (unsigned char const   )15,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )192,      (unsigned char const   )251, 
        (unsigned char const   )239,      (unsigned char const   )62,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )14, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )7,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )20, 
        (unsigned char const   )254,      (unsigned char const   )33,      (unsigned char const   )254,      (unsigned char const   )0, 
        (unsigned char const   )12,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )2,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )16, 
        (unsigned char const   )30,      (unsigned char const   )32,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )12,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )6,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )16, 
        (unsigned char const   )134,      (unsigned char const   )57,      (unsigned char const   )2,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )35,      (unsigned char const   )0, 
        (unsigned char const   )6,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )16, 
        (unsigned char const   )190,      (unsigned char const   )33,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )12,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )2,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )144, 
        (unsigned char const   )30,      (unsigned char const   )32,      (unsigned char const   )64,      (unsigned char const   )0, 
        (unsigned char const   )12,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )4,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )1,      (unsigned char const   )32,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )192, 
        (unsigned char const   )193,      (unsigned char const   )61,      (unsigned char const   )96,      (unsigned char const   )0, 
        (unsigned char const   )12,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )16, 
        (unsigned char const   )0,      (unsigned char const   )48,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )12,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )30,      (unsigned char const   )32,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )12,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )4,      (unsigned char const   )92,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )242,      (unsigned char const   )7, 
        (unsigned char const   )128,      (unsigned char const   )127,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )242,      (unsigned char const   )27, 
        (unsigned char const   )0,      (unsigned char const   )63,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )3, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )160,      (unsigned char const   )2, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )254,      (unsigned char const   )127, 
        (unsigned char const   )223,      (unsigned char const   )224,      (unsigned char const   )255,      (unsigned char const   )254, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )31, 
        (unsigned char const   )64,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )224,      (unsigned char const   )253,      (unsigned char const   )102, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )195, 
        (unsigned char const   )1,      (unsigned char const   )0,      (unsigned char const   )30,      (unsigned char const   )0, 
        (unsigned char const   )100,      (unsigned char const   )32,      (unsigned char const   )0,      (unsigned char const   )32, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )224, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )28,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )28,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )12,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )12,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )176,      (unsigned char const   )63, 
        (unsigned char const   )64,      (unsigned char const   )254,      (unsigned char const   )15,      (unsigned char const   )32, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )56,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )2,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )135,      (unsigned char const   )1,      (unsigned char const   )4,      (unsigned char const   )14, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )128,      (unsigned char const   )1, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )64,      (unsigned char const   )127, 
        (unsigned char const   )229,      (unsigned char const   )31,      (unsigned char const   )248,      (unsigned char const   )159, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )15,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )208,      (unsigned char const   )23, 
        (unsigned char const   )4,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )248,      (unsigned char const   )15,      (unsigned char const   )0, 
        (unsigned char const   )3,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )60,      (unsigned char const   )3,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )64,      (unsigned char const   )163,      (unsigned char const   )3,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )240,      (unsigned char const   )207,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )247,      (unsigned char const   )255, 
        (unsigned char const   )253,      (unsigned char const   )33,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255, 
        (unsigned char const   )127,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )240, 
        (unsigned char const   )0,      (unsigned char const   )248,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )124,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )31,      (unsigned char const   )252,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )255,      (unsigned char const   )255, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )1,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )128,      (unsigned char const   )3,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )128, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )255, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )252,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )6, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )128,      (unsigned char const   )7,      (unsigned char const   )48, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )3,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )68,      (unsigned char const   )8,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )96,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )16,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )3,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )192,      (unsigned char const   )63,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )128,      (unsigned char const   )255,      (unsigned char const   )3,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )7,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )200,      (unsigned char const   )19, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )126,      (unsigned char const   )102,      (unsigned char const   )0, 
        (unsigned char const   )8,      (unsigned char const   )16,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )157,      (unsigned char const   )193, 
        (unsigned char const   )2,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )32,      (unsigned char const   )33,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )64, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )255,      (unsigned char const   )255,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )127,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )128, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )14, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )32, 
        (unsigned char const   )110,      (unsigned char const   )240,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )135, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )2,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )255, 
        (unsigned char const   )127,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )3,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )120,      (unsigned char const   )38, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )128,      (unsigned char const   )3,      (unsigned char const   )248,      (unsigned char const   )255, 
        (unsigned char const   )231,      (unsigned char const   )15,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )60,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )28,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0, 
        (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0,      (unsigned char const   )0};
static signed char const   nonspacing_table_ind[240]  = 
  {      (signed char const   )0,      (signed char const   )1,      (signed char const   )2,      (signed char const   )3, 
        (signed char const   )4,      (signed char const   )5,      (signed char const   )6,      (signed char const   )7, 
        (signed char const   )8,      (signed char const   )9,      (signed char const   )-1,      (signed char const   )10, 
        (signed char const   )11,      (signed char const   )12,      (signed char const   )13,      (signed char const   )-1, 
        (signed char const   )14,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )15,      (signed char const   )-1, 
        (signed char const   )16,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )17, 
        (signed char const   )18,      (signed char const   )19,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )20,      (signed char const   )-1,      (signed char const   )21, 
        (signed char const   )22,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )23,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )24,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )25,      (signed char const   )26,      (signed char const   )-1,      (signed char const   )-1, 
        (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1,      (signed char const   )-1};
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) atexit)(void (*__func)(void) ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) kill)(__pid_t __pid ,
                                                                           int __sig ) ;
extern __pid_t waitpid(__pid_t __pid , int *__stat_loc , int __options ) ;
static slaves_entry_t static_slaves[32]  ;
static slaves_entry_t * volatile  slaves  =    (slaves_entry_t */* volatile  */)(static_slaves);
static int volatile   slaves_count  =    (int volatile   )0;
static size_t slaves_allocated  =    sizeof(static_slaves) / sizeof(static_slaves[0]);
static _Bool cleanup_slaves_registered  =    (_Bool)0;
extern size_t fwrite(void const   * __restrict  __ptr , size_t __size , size_t __n ,
                     FILE * __restrict  __s ) ;
extern int printf(char const   * __restrict  __format  , ...) ;
char const   version_etc_copyright[47] ;
void version_etc_arn(FILE *stream , char const   *command_name , char const   *package ,
                     char const   *version , char const   * const  *authors , size_t n_authors ) ;
void version_etc_va(FILE *stream , char const   *command_name , char const   *package ,
                    char const   *version , va_list authors ) ;
void version_etc(FILE *stream , char const   *command_name , char const   *package ,
                 char const   *version  , ...)  __attribute__((__sentinel__)) ;
void version_etc_arn(FILE *stream , char const   *command_name , char const   *package ,
                     char const   *version , char const   * const  *authors , size_t n_authors ) 
{ 
  char *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  char *tmp___3 ;
  char *tmp___4 ;
  char *tmp___5 ;
  char *tmp___6 ;
  char *tmp___7 ;
  char *tmp___8 ;
  char *tmp___9 ;
  char *tmp___10 ;
  char *__cil_tmp19 ;
  char *__cil_tmp20 ;
  char *__cil_tmp21 ;
  char *__cil_tmp22 ;
  char *__cil_tmp23 ;
  char *__cil_tmp24 ;
  char *__cil_tmp25 ;
  char *__cil_tmp26 ;
  char *__cil_tmp27 ;
  char *__cil_tmp28 ;
  char *__cil_tmp29 ;
  char *__cil_tmp30 ;

  {
  if (command_name) {
    {
    fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)"%s (%s) %s\n",
            command_name, package, version);
    }
  } else {
    {
    fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)"%s %s\n",
            package, version);
    }
  }
  {
  tmp = gettext("(C)");
  fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)(version_etc_copyright),
          tmp, 2012);
  tmp___0 = gettext("\nLicense GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\n\n");
  fputs_unlocked((char const   */* __restrict  */)tmp___0, (FILE */* __restrict  */)stream);
  }
  {
  if (n_authors == 0UL) {
    goto case_0;
  }
  if (n_authors == 1UL) {
    goto case_1;
  }
  if (n_authors == 2UL) {
    goto case_2;
  }
  if (n_authors == 3UL) {
    goto case_3;
  }
  if (n_authors == 4UL) {
    goto case_4;
  }
  if (n_authors == 5UL) {
    goto case_5;
  }
  if (n_authors == 6UL) {
    goto case_6;
  }
  if (n_authors == 7UL) {
    goto case_7;
  }
  if (n_authors == 8UL) {
    goto case_8;
  }
  if (n_authors == 9UL) {
    goto case_9;
  }
  goto switch_default;
  case_0: /* CIL Label */ 
  {
  abort();
  }
  case_1: /* CIL Label */ 
  {
  tmp___1 = gettext("Written by %s.\n");
  fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)tmp___1,
          *(authors + 0));
  }
  goto switch_break;
  case_2: /* CIL Label */ 
  {
  tmp___2 = gettext("Written by %s and %s.\n");
  fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)tmp___2,
          *(authors + 0), *(authors + 1));
  }
  goto switch_break;
  case_3: /* CIL Label */ 
  {
  tmp___3 = gettext("Written by %s, %s, and %s.\n");
  fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)tmp___3,
          *(authors + 0), *(authors + 1), *(authors + 2));
  }
  goto switch_break;
  case_4: /* CIL Label */ 
  {
  tmp___4 = gettext("Written by %s, %s, %s,\nand %s.\n");
  fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)tmp___4,
          *(authors + 0), *(authors + 1), *(authors + 2), *(authors + 3));
  }
  goto switch_break;
  case_5: /* CIL Label */ 
  {
  tmp___5 = gettext("Written by %s, %s, %s,\n%s, and %s.\n");
  fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)tmp___5,
          *(authors + 0), *(authors + 1), *(authors + 2), *(authors + 3), *(authors + 4));
  }
  goto switch_break;
  case_6: /* CIL Label */ 
  {
  tmp___6 = gettext("Written by %s, %s, %s,\n%s, %s, and %s.\n");
  fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)tmp___6,
          *(authors + 0), *(authors + 1), *(authors + 2), *(authors + 3), *(authors + 4),
          *(authors + 5));
  }
  goto switch_break;
  case_7: /* CIL Label */ 
  {
  tmp___7 = gettext("Written by %s, %s, %s,\n%s, %s, %s, and %s.\n");
  fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)tmp___7,
          *(authors + 0), *(authors + 1), *(authors + 2), *(authors + 3), *(authors + 4),
          *(authors + 5), *(authors + 6));
  }
  goto switch_break;
  case_8: /* CIL Label */ 
  {
  tmp___8 = gettext("Written by %s, %s, %s,\n%s, %s, %s, %s,\nand %s.\n");
  fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)tmp___8,
          *(authors + 0), *(authors + 1), *(authors + 2), *(authors + 3), *(authors + 4),
          *(authors + 5), *(authors + 6), *(authors + 7));
  }
  goto switch_break;
  case_9: /* CIL Label */ 
  {
  tmp___9 = gettext("Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, and %s.\n");
  fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)tmp___9,
          *(authors + 0), *(authors + 1), *(authors + 2), *(authors + 3), *(authors + 4),
          *(authors + 5), *(authors + 6), *(authors + 7), *(authors + 8));
  }
  goto switch_break;
  switch_default: /* CIL Label */ 
  {
  tmp___10 = gettext("Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, %s, and others.\n");
  fprintf((FILE */* __restrict  */)stream, (char const   */* __restrict  */)tmp___10,
          *(authors + 0), *(authors + 1), *(authors + 2), *(authors + 3), *(authors + 4),
          *(authors + 5), *(authors + 6), *(authors + 7), *(authors + 8));
  }
  goto switch_break;
  switch_break: /* CIL Label */ ;
  }
  return;
}
}
void version_etc_va(FILE *stream , char const   *command_name , char const   *package ,
                    char const   *version , va_list authors ) 
{ 
  size_t n_authors ;
  char const   *authtab[10] ;
  char const   *tmp ;
  void *__cil_tmp9 ;

  {
  n_authors = (size_t )0;
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    if (n_authors < 10UL) {
      {
      tmp = __builtin_va_arg(authors, char const   *);
      authtab[n_authors] = tmp;
      }
      if (! ((unsigned long )tmp != (unsigned long )((void *)0))) {
        goto while_break;
      }
    } else {
      goto while_break;
    }
    n_authors ++;
  }
  while_break: /* CIL Label */ ;
  }
  {
  version_etc_arn(stream, command_name, package, version, (char const   * const  *)(authtab),
                  n_authors);
  }
  return;
}
}
void version_etc(FILE *stream , char const   *command_name , char const   *package ,
                 char const   *version  , ...)  __attribute__((__sentinel__)) ;
void version_etc(FILE *stream , char const   *command_name , char const   *package ,
                 char const   *version  , ...) 
{ 
  va_list authors ;

  {
  {
  __builtin_va_start(authors, version);
  version_etc_va(stream, command_name, package, version, authors);
  __builtin_va_end(authors);
  }
  return;
}
}
char const   version_etc_copyright[47]  = 
  {      (char const   )'C',      (char const   )'o',      (char const   )'p',      (char const   )'y', 
        (char const   )'r',      (char const   )'i',      (char const   )'g',      (char const   )'h', 
        (char const   )'t',      (char const   )' ',      (char const   )'%',      (char const   )'s', 
        (char const   )' ',      (char const   )'%',      (char const   )'d',      (char const   )' ', 
        (char const   )'F',      (char const   )'r',      (char const   )'e',      (char const   )'e', 
        (char const   )' ',      (char const   )'S',      (char const   )'o',      (char const   )'f', 
        (char const   )'t',      (char const   )'w',      (char const   )'a',      (char const   )'r', 
        (char const   )'e',      (char const   )' ',      (char const   )'F',      (char const   )'o', 
        (char const   )'u',      (char const   )'n',      (char const   )'d',      (char const   )'a', 
        (char const   )'t',      (char const   )'i',      (char const   )'o',      (char const   )'n', 
        (char const   )',',      (char const   )' ',      (char const   )'I',      (char const   )'n', 
        (char const   )'c',      (char const   )'.',      (char const   )'\000'};
extern void error_at_line(int __status , int __errnum , char const   *__fname , unsigned int __lineno ,
                          char const   *__format  , ...) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) nl_langinfo)(nl_item __item ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2,3), __leaf__)) fstatat)(int __fd ,
                                                                                                char const   * __restrict  __file ,
                                                                                                struct stat * __restrict  __buf ,
                                                                                                int __flag ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2), __leaf__)) utimensat)(int __fd ,
                                                                                                char const   *__path ,
                                                                                                struct timespec  const  *__times ,
                                                                                                int __flags ) ;
static int utimensat_works_really  ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) futimens)(int __fd ,
                                                                               struct timespec  const  *__times ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) utimes)(char const   *__file ,
                                                                                             struct timeval  const  *__tvp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) futimesat)(int __fd ,
                                                                                char const   *__file ,
                                                                                struct timeval  const  *__tvp ) ;
static int utimensat_works_really___0  ;
static int lutimensat_works_really  ;
static Hash_table *ht  ;
static struct fs_res *new_dst_res  ;
extern void endpwent(void) ;
extern struct passwd *getpwnam(char const   *__name ) ;
extern void endgrent(void) ;
extern struct group *getgrgid(__gid_t __gid ) ;
extern struct group *getgrnam(char const   *__name ) ;
static char const   *E_invalid_user  =    "invalid user";
static char const   *E_invalid_group  =    "invalid group";
static char const   *E_bad_spec  =    "invalid spec";
extern iconv_t iconv_open(char const   *__tocode , char const   *__fromcode ) ;
extern size_t iconv(iconv_t __cd , char ** __restrict  __inbuf , size_t * __restrict  __inbytesleft ,
                    char ** __restrict  __outbuf , size_t * __restrict  __outbytesleft ) ;
char const   *locale_charset(void) ;
static int initialized___0  ;
static int is_utf8  ;
static iconv_t utf8_to_local  ;
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) __ctype_get_mb_cur_max)(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) mbsinit)(mbstate_t const   *__ps )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) mbrtowc)(wchar_t * __restrict  __pwc ,
                                                                                 char const   * __restrict  __s ,
                                                                                 size_t __n ,
                                                                                 mbstate_t * __restrict  __p ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) iswspace)(wint_t __wc ) ;
unsigned int const   is_basic_table[8] ;
#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
extern int ( __attribute__((__nonnull__(1))) open)(char const   *__file , int __oflag 
                                                   , ...) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) mkdir)(char const   *__path ,
                                                                                            __mode_t __mode ) ;
static char const   letters[63]  = 
  {      (char const   )'a',      (char const   )'b',      (char const   )'c',      (char const   )'d', 
        (char const   )'e',      (char const   )'f',      (char const   )'g',      (char const   )'h', 
        (char const   )'i',      (char const   )'j',      (char const   )'k',      (char const   )'l', 
        (char const   )'m',      (char const   )'n',      (char const   )'o',      (char const   )'p', 
        (char const   )'q',      (char const   )'r',      (char const   )'s',      (char const   )'t', 
        (char const   )'u',      (char const   )'v',      (char const   )'w',      (char const   )'x', 
        (char const   )'y',      (char const   )'z',      (char const   )'A',      (char const   )'B', 
        (char const   )'C',      (char const   )'D',      (char const   )'E',      (char const   )'F', 
        (char const   )'G',      (char const   )'H',      (char const   )'I',      (char const   )'J', 
        (char const   )'K',      (char const   )'L',      (char const   )'M',      (char const   )'N', 
        (char const   )'O',      (char const   )'P',      (char const   )'Q',      (char const   )'R', 
        (char const   )'S',      (char const   )'T',      (char const   )'U',      (char const   )'V', 
        (char const   )'W',      (char const   )'X',      (char const   )'Y',      (char const   )'Z', 
        (char const   )'0',      (char const   )'1',      (char const   )'2',      (char const   )'3', 
        (char const   )'4',      (char const   )'5',      (char const   )'6',      (char const   )'7', 
        (char const   )'8',      (char const   )'9',      (char const   )'\000'};
extern int iconv_close(iconv_t __cd ) ;
extern  __attribute__((__nothrow__)) time_t ( __attribute__((__leaf__)) mktime)(struct tm *__tp ) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) strftime)(char * __restrict  __s ,
                                                                                  size_t __maxsize ,
                                                                                  char const   * __restrict  __format ,
                                                                                  struct tm  const  * __restrict  __tp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) tolower)(int __c ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) toupper)(int __c ) ;
extern char **environ ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) sigprocmask)(int __how ,
                                                                                  sigset_t const   * __restrict  __set ,
                                                                                  sigset_t * __restrict  __oset ) ;
extern int posix_spawnp(pid_t *__pid , char const   *__file , posix_spawn_file_actions_t const   *__file_actions ,
                        posix_spawnattr_t const   *__attrp , char * const  *__argv ,
                        char * const  *__envp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) posix_spawnattr_init)(posix_spawnattr_t *__attr ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) posix_spawnattr_destroy)(posix_spawnattr_t *__attr ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) posix_spawnattr_setsigmask)(posix_spawnattr_t * __restrict  __attr ,
                                                                                                 sigset_t const   * __restrict  __sigmask ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) posix_spawnattr_setflags)(posix_spawnattr_t *_attr ,
                                                                                               short __flags ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) posix_spawn_file_actions_init)(posix_spawn_file_actions_t *__file_actions ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) posix_spawn_file_actions_destroy)(posix_spawn_file_actions_t *__file_actions ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) posix_spawn_file_actions_addopen)(posix_spawn_file_actions_t * __restrict  __file_actions ,
                                                                                                       int __fd ,
                                                                                                       char const   * __restrict  __path ,
                                                                                                       int __oflag ,
                                                                                                       mode_t __mode ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) posix_spawn_file_actions_addclose)(posix_spawn_file_actions_t *__file_actions ,
                                                                                                        int __fd ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) posix_spawn_file_actions_adddup2)(posix_spawn_file_actions_t *__file_actions ,
                                                                                                       int __fd ,
                                                                                                       int __newfd ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __libc_current_sigrtmin)(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __libc_current_sigrtmax)(void) ;
extern  __attribute__((__nothrow__)) int sprintf(char * __restrict  __s , char const   * __restrict  __format 
                                                 , ...) ;
static struct numname numname_table[35]  = 
  {      {1, {(char const   )'H', (char const   )'U', (char const   )'P', (char const   )'\000'}}, 
        {2,
      {(char const   )'I', (char const   )'N', (char const   )'T', (char const   )'\000'}}, 
        {3,
      {(char const   )'Q', (char const   )'U', (char const   )'I', (char const   )'T',
       (char const   )'\000'}}, 
        {4, {(char const   )'I', (char const   )'L', (char const   )'L', (char const   )'\000'}}, 
        {5,
      {(char const   )'T', (char const   )'R', (char const   )'A', (char const   )'P',
       (char const   )'\000'}}, 
        {6, {(char const   )'A', (char const   )'B', (char const   )'R', (char const   )'T',
          (char const   )'\000'}}, 
        {8, {(char const   )'F', (char const   )'P', (char const   )'E', (char const   )'\000'}}, 
        {9,
      {(char const   )'K', (char const   )'I', (char const   )'L', (char const   )'L',
       (char const   )'\000'}}, 
        {11, {(char const   )'S', (char const   )'E', (char const   )'G', (char const   )'V',
           (char const   )'\000'}}, 
        {7, {(char const   )'B', (char const   )'U', (char const   )'S', (char const   )'\000'}}, 
        {13,
      {(char const   )'P', (char const   )'I', (char const   )'P', (char const   )'E',
       (char const   )'\000'}}, 
        {14, {(char const   )'A', (char const   )'L', (char const   )'R', (char const   )'M',
           (char const   )'\000'}}, 
        {15, {(char const   )'T', (char const   )'E', (char const   )'R', (char const   )'M',
           (char const   )'\000'}}, 
        {10, {(char const   )'U', (char const   )'S', (char const   )'R', (char const   )'1',
           (char const   )'\000'}}, 
        {12, {(char const   )'U', (char const   )'S', (char const   )'R', (char const   )'2',
           (char const   )'\000'}}, 
        {17, {(char const   )'C', (char const   )'H', (char const   )'L', (char const   )'D',
           (char const   )'\000'}}, 
        {23, {(char const   )'U', (char const   )'R', (char const   )'G', (char const   )'\000'}}, 
        {19,
      {(char const   )'S', (char const   )'T', (char const   )'O', (char const   )'P',
       (char const   )'\000'}}, 
        {20, {(char const   )'T', (char const   )'S', (char const   )'T', (char const   )'P',
           (char const   )'\000'}}, 
        {18, {(char const   )'C', (char const   )'O', (char const   )'N', (char const   )'T',
           (char const   )'\000'}}, 
        {21, {(char const   )'T', (char const   )'T', (char const   )'I', (char const   )'N',
           (char const   )'\000'}}, 
        {22, {(char const   )'T', (char const   )'T', (char const   )'O', (char const   )'U',
           (char const   )'\000'}}, 
        {31, {(char const   )'S', (char const   )'Y', (char const   )'S', (char const   )'\000'}}, 
        {29,
      {(char const   )'P', (char const   )'O', (char const   )'L', (char const   )'L',
       (char const   )'\000'}}, 
        {26, {(char const   )'V', (char const   )'T', (char const   )'A', (char const   )'L',
           (char const   )'R', (char const   )'M', (char const   )'\000'}}, 
        {27, {(char const   )'P', (char const   )'R', (char const   )'O', (char const   )'F',
           (char const   )'\000'}}, 
        {24, {(char const   )'X', (char const   )'C', (char const   )'P', (char const   )'U',
           (char const   )'\000'}}, 
        {25, {(char const   )'X', (char const   )'F', (char const   )'S', (char const   )'Z',
           (char const   )'\000'}}, 
        {6, {(char const   )'I', (char const   )'O', (char const   )'T', (char const   )'\000'}}, 
        {17,
      {(char const   )'C', (char const   )'L', (char const   )'D', (char const   )'\000'}}, 
        {30,
      {(char const   )'P', (char const   )'W', (char const   )'R', (char const   )'\000'}}, 
        {28,
      {(char const   )'W', (char const   )'I', (char const   )'N', (char const   )'C',
       (char const   )'H', (char const   )'\000'}}, 
        {29, {(char const   )'I', (char const   )'O', (char const   )'\000'}}, 
        {16, {(char const   )'S', (char const   )'T', (char const   )'K', (char const   )'F',
           (char const   )'L', (char const   )'T', (char const   )'\000'}}, 
        {0, {(char const   )'E', (char const   )'X', (char const   )'I', (char const   )'T',
          (char const   )'\000'}}};
extern size_t fread_unlocked(void * __restrict  __ptr , size_t __size , size_t __n ,
                             FILE * __restrict  __stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) feof_unlocked)(FILE *__stream ) ;
static unsigned char const   fillbuf[128]  = {      (unsigned char const   )128,      (unsigned char const   )0};
static u64 const   sha512_round_constants[80]  = 
  {      (u64 const   )((1116352408UL << 32) + 3609767458UL),      (u64 const   )((1899447441UL << 32) + 602891725UL),      (u64 const   )((3049323471UL << 32) + 3964484399UL),      (u64 const   )((3921009573UL << 32) + 2173295548UL), 
        (u64 const   )((961987163UL << 32) + 4081628472UL),      (u64 const   )((1508970993UL << 32) + 3053834265UL),      (u64 const   )((2453635748UL << 32) + 2937671579UL),      (u64 const   )((2870763221UL << 32) + 3664609560UL), 
        (u64 const   )((3624381080UL << 32) + 2734883394UL),      (u64 const   )((310598401UL << 32) + 1164996542UL),      (u64 const   )((607225278UL << 32) + 1323610764UL),      (u64 const   )((1426881987UL << 32) + 3590304994UL), 
        (u64 const   )((1925078388UL << 32) + 4068182383UL),      (u64 const   )((2162078206UL << 32) + 991336113UL),      (u64 const   )((2614888103UL << 32) + 633803317UL),      (u64 const   )((3248222580UL << 32) + 3479774868UL), 
        (u64 const   )((3835390401UL << 32) + 2666613458UL),      (u64 const   )((4022224774UL << 32) + 944711139UL),      (u64 const   )((264347078UL << 32) + 2341262773UL),      (u64 const   )((604807628UL << 32) + 2007800933UL), 
        (u64 const   )((770255983UL << 32) + 1495990901UL),      (u64 const   )((1249150122UL << 32) + 1856431235UL),      (u64 const   )((1555081692UL << 32) + 3175218132UL),      (u64 const   )((1996064986UL << 32) + 2198950837UL), 
        (u64 const   )((2554220882UL << 32) + 3999719339UL),      (u64 const   )((2821834349UL << 32) + 766784016UL),      (u64 const   )((2952996808UL << 32) + 2566594879UL),      (u64 const   )((3210313671UL << 32) + 3203337956UL), 
        (u64 const   )((3336571891UL << 32) + 1034457026UL),      (u64 const   )((3584528711UL << 32) + 2466948901UL),      (u64 const   )((113926993UL << 32) + 3758326383UL),      (u64 const   )((338241895UL << 32) + 168717936UL), 
        (u64 const   )((666307205UL << 32) + 1188179964UL),      (u64 const   )((773529912UL << 32) + 1546045734UL),      (u64 const   )((1294757372UL << 32) + 1522805485UL),      (u64 const   )((1396182291UL << 32) + 2643833823UL), 
        (u64 const   )((1695183700UL << 32) + 2343527390UL),      (u64 const   )((1986661051UL << 32) + 1014477480UL),      (u64 const   )((2177026350UL << 32) + 1206759142UL),      (u64 const   )((2456956037UL << 32) + 344077627UL), 
        (u64 const   )((2730485921UL << 32) + 1290863460UL),      (u64 const   )((2820302411UL << 32) + 3158454273UL),      (u64 const   )((3259730800UL << 32) + 3505952657UL),      (u64 const   )((3345764771UL << 32) + 106217008UL), 
        (u64 const   )((3516065817UL << 32) + 3606008344UL),      (u64 const   )((3600352804UL << 32) + 1432725776UL),      (u64 const   )((4094571909UL << 32) + 1467031594UL),      (u64 const   )((275423344UL << 32) + 851169720UL), 
        (u64 const   )((430227734UL << 32) + 3100823752UL),      (u64 const   )((506948616UL << 32) + 1363258195UL),      (u64 const   )((659060556UL << 32) + 3750685593UL),      (u64 const   )((883997877UL << 32) + 3785050280UL), 
        (u64 const   )((958139571UL << 32) + 3318307427UL),      (u64 const   )((1322822218UL << 32) + 3812723403UL),      (u64 const   )((1537002063UL << 32) + 2003034995UL),      (u64 const   )((1747873779UL << 32) + 3602036899UL), 
        (u64 const   )((1955562222UL << 32) + 1575990012UL),      (u64 const   )((2024104815UL << 32) + 1125592928UL),      (u64 const   )((2227730452UL << 32) + 2716904306UL),      (u64 const   )((2361852424UL << 32) + 442776044UL), 
        (u64 const   )((2428436474UL << 32) + 593698344UL),      (u64 const   )((2756734187UL << 32) + 3733110249UL),      (u64 const   )((3204031479UL << 32) + 2999351573UL),      (u64 const   )((3329325298UL << 32) + 3815920427UL), 
        (u64 const   )((3391569614UL << 32) + 3928383900UL),      (u64 const   )((3515267271UL << 32) + 566280711UL),      (u64 const   )((3940187606UL << 32) + 3454069534UL),      (u64 const   )((4118630271UL << 32) + 4000239992UL), 
        (u64 const   )((116418474UL << 32) + 1914138554UL),      (u64 const   )((174292421UL << 32) + 2731055270UL),      (u64 const   )((289380356UL << 32) + 3203993006UL),      (u64 const   )((460393269UL << 32) + 320620315UL), 
        (u64 const   )((685471733UL << 32) + 587496836UL),      (u64 const   )((852142971UL << 32) + 1086792851UL),      (u64 const   )((1017036298UL << 32) + 365543100UL),      (u64 const   )((1126000580UL << 32) + 2618297676UL), 
        (u64 const   )((1288033470UL << 32) + 3409855158UL),      (u64 const   )((1501505948UL << 32) + 4234509866UL),      (u64 const   )((1607167915UL << 32) + 987167468UL),      (u64 const   )((1816402316UL << 32) + 1246189591UL)};
static unsigned char const   fillbuf___0[64]  = {      (unsigned char const   )128,      (unsigned char const   )0};
static uint32_t const   sha256_round_constants[64]  = 
  {      (uint32_t const   )1116352408UL,      (uint32_t const   )1899447441UL,      (uint32_t const   )3049323471UL,      (uint32_t const   )3921009573UL, 
        (uint32_t const   )961987163UL,      (uint32_t const   )1508970993UL,      (uint32_t const   )2453635748UL,      (uint32_t const   )2870763221UL, 
        (uint32_t const   )3624381080UL,      (uint32_t const   )310598401UL,      (uint32_t const   )607225278UL,      (uint32_t const   )1426881987UL, 
        (uint32_t const   )1925078388UL,      (uint32_t const   )2162078206UL,      (uint32_t const   )2614888103UL,      (uint32_t const   )3248222580UL, 
        (uint32_t const   )3835390401UL,      (uint32_t const   )4022224774UL,      (uint32_t const   )264347078UL,      (uint32_t const   )604807628UL, 
        (uint32_t const   )770255983UL,      (uint32_t const   )1249150122UL,      (uint32_t const   )1555081692UL,      (uint32_t const   )1996064986UL, 
        (uint32_t const   )2554220882UL,      (uint32_t const   )2821834349UL,      (uint32_t const   )2952996808UL,      (uint32_t const   )3210313671UL, 
        (uint32_t const   )3336571891UL,      (uint32_t const   )3584528711UL,      (uint32_t const   )113926993UL,      (uint32_t const   )338241895UL, 
        (uint32_t const   )666307205UL,      (uint32_t const   )773529912UL,      (uint32_t const   )1294757372UL,      (uint32_t const   )1396182291UL, 
        (uint32_t const   )1695183700UL,      (uint32_t const   )1986661051UL,      (uint32_t const   )2177026350UL,      (uint32_t const   )2456956037UL, 
        (uint32_t const   )2730485921UL,      (uint32_t const   )2820302411UL,      (uint32_t const   )3259730800UL,      (uint32_t const   )3345764771UL, 
        (uint32_t const   )3516065817UL,      (uint32_t const   )3600352804UL,      (uint32_t const   )4094571909UL,      (uint32_t const   )275423344UL, 
        (uint32_t const   )430227734UL,      (uint32_t const   )506948616UL,      (uint32_t const   )659060556UL,      (uint32_t const   )883997877UL, 
        (uint32_t const   )958139571UL,      (uint32_t const   )1322822218UL,      (uint32_t const   )1537002063UL,      (uint32_t const   )1747873779UL, 
        (uint32_t const   )1955562222UL,      (uint32_t const   )2024104815UL,      (uint32_t const   )2227730452UL,      (uint32_t const   )2361852424UL, 
        (uint32_t const   )2428436474UL,      (uint32_t const   )2756734187UL,      (uint32_t const   )3204031479UL,      (uint32_t const   )3329325298UL};
static unsigned char const   fillbuf___1[64]  = {      (unsigned char const   )128,      (unsigned char const   )0};
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) clock_settime)(clockid_t __clock_id ,
                                                                                    struct timespec  const  *__tp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) settimeofday)(struct timeval  const  *__tv ,
                                                                                   struct timezone  const  *__tz ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) raise)(int __sig ) ;
extern  __attribute__((__nothrow__)) __pid_t fork(void) ;
extern DIR *fdopendir(int __fd ) ;
extern ssize_t write(int __fd , void const   *__buf , size_t __n ) ;
extern ssize_t read(int __fd , void *__buf , size_t __nbytes ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) unlink)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) rmdir)(char const   *__path ) ;
extern void setutxent(void) ;
extern void endutxent(void) ;
extern struct utmpx *getutxent(void) ;
extern int utmpxname(char const   *__file ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2), __leaf__)) strncpy)(char * __restrict  __dest ,
                                                                                                  char const   * __restrict  __src ,
                                                                                                  size_t __n ) ;
extern int fgetc(FILE *__stream ) ;
extern void _obstack_newchunk(struct obstack * , int  ) ;
extern int _obstack_begin(struct obstack * , int  , int  , void *(*)(long  ) , void (*)(void * ) ) ;
extern void obstack_free(struct obstack *obstack , void *block ) ;
extern int getc_unlocked(FILE *__stream ) ;
extern FILE *fopen(char const   * __restrict  __filename , char const   * __restrict  __modes ) ;
extern size_t fread(void * __restrict  __ptr , size_t __size , size_t __n , FILE * __restrict  __stream ) ;
extern __off_t ftello(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) fileno)(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) setvbuf)(FILE * __restrict  __stream ,
                                                                              char * __restrict  __buf ,
                                                                              int __modes ,
                                                                              size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) gettimeofday)(struct timeval * __restrict  __tv ,
                                                                                                   __timezone_ptr_t __tz ) ;
extern  __attribute__((__nothrow__)) __pid_t ( __attribute__((__leaf__)) getpid)(void) ;
extern  __attribute__((__nothrow__)) __pid_t ( __attribute__((__leaf__)) getppid)(void) ;
extern  __attribute__((__nothrow__)) __uid_t ( __attribute__((__leaf__)) getuid)(void) ;
extern  __attribute__((__nothrow__)) __gid_t ( __attribute__((__leaf__)) getgid)(void) ;
#pragma GCC diagnostic ignored "-Wsuggest-attribute=pure"
char const   * const  quoting_style_args[9] ;
enum quoting_style  const  quoting_style_vals[8] ;
int set_char_quoting(struct quoting_options *o , char c , int i ) ;
char *quotearg_char(char const   *arg , char ch ) ;
char *quotearg_char_mem(char const   *arg , size_t argsize , char ch ) ;
struct quoting_options quote_quoting_options ;
__inline static char *xcharalloc(size_t n )  __attribute__((__malloc__, __alloc_size__(1))) ;
__inline static char *xcharalloc(size_t n )  __attribute__((__malloc__, __alloc_size__(1))) ;
__inline static char *xcharalloc(size_t n ) 
{ 
  void *tmp ;
  void *tmp___0 ;
  void *tmp___1 ;

  {
  if (sizeof(char ) == 1UL) {
    {
    tmp = xmalloc(n);
    tmp___1 = tmp;
    }
  } else {
    {
    tmp___0 = xnmalloc(n, sizeof(char ));
    tmp___1 = tmp___0;
    }
  }
  return ((char *)tmp___1);
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) iswprint)(wint_t __wc ) ;
char const   * const  quoting_style_args[9]  = 
  {      (char const   */* const  */)"literal",      (char const   */* const  */)"shell",      (char const   */* const  */)"shell-always",      (char const   */* const  */)"c", 
        (char const   */* const  */)"c-maybe",      (char const   */* const  */)"escape",      (char const   */* const  */)"locale",      (char const   */* const  */)"clocale", 
        (char const   */* const  */)0};
enum quoting_style  const  quoting_style_vals[8]  = 
  {      (enum quoting_style  const  )0,      (enum quoting_style  const  )1,      (enum quoting_style  const  )2,      (enum quoting_style  const  )3, 
        (enum quoting_style  const  )4,      (enum quoting_style  const  )5,      (enum quoting_style  const  )6,      (enum quoting_style  const  )7};
static struct quoting_options default_quoting_options  ;
int set_char_quoting(struct quoting_options *o , char c , int i ) 
{ 
  unsigned char uc ;
  unsigned int *p ;
  struct quoting_options *tmp ;
  int shift ;
  int r ;

  {
  uc = (unsigned char )c;
  if (o) {
    tmp = o;
  } else {
    tmp = & default_quoting_options;
  }
  p = tmp->quote_these_too + (unsigned long )uc / (sizeof(int ) * 8UL);
  shift = (int )((unsigned long )uc % (sizeof(int ) * 8UL));
  r = (int )((*p >> shift) & 1U);
  *p ^= (unsigned int )(((i & 1) ^ r) << shift);
  return (r);
}
}
static struct quoting_options quoting_options_from_style(enum quoting_style style ) 
{ 
  struct quoting_options o ;
  unsigned int tmp ;
  void *__cil_tmp4 ;

  {
  o.style = (enum quoting_style )0;
  o.flags = 0;
  o.quote_these_too[0] = 0U;
  tmp = 1U;
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    if (! (! (tmp >= 8U))) {
      goto while_break;
    }
    o.quote_these_too[tmp] = 0U;
    tmp ++;
  }
  while_break: /* CIL Label */ ;
  }
  o.left_quote = (char const   *)((void *)0);
  o.right_quote = (char const   *)((void *)0);
  if ((unsigned int )style == 8U) {
    {
    abort();
    }
  }
  o.style = style;
  return (o);
}
}
static char const   *gettext_quote(char const   *msgid , enum quoting_style s ) 
{ 
  char const   *translation ;
  char const   *tmp ;
  char const   *locale_code ;
  char const   *tmp___0 ;
  int tmp___1 ;
  char const   *tmp___2 ;
  int tmp___3 ;
  char const   *tmp___4 ;
  char *__cil_tmp12 ;
  char *__cil_tmp13 ;
  char *__cil_tmp14 ;
  char *__cil_tmp15 ;
  char *__cil_tmp16 ;
  char *__cil_tmp17 ;
  char *__cil_tmp18 ;
  char *__cil_tmp19 ;

  {
  {
  tmp = (char const   *)gettext(msgid);
  translation = tmp;
  }
  if ((unsigned long )translation != (unsigned long )msgid) {
    return (translation);
  }
  {
  locale_code = locale_charset();
  tmp___1 = c_strcasecmp(locale_code, "UTF-8");
  }
  if (tmp___1 == 0) {
    if ((int const   )*(msgid + 0) == 96) {
      tmp___0 = "\342\200\230";
    } else {
      tmp___0 = "\342\200\231";
    }
    return (tmp___0);
  }
  {
  tmp___3 = c_strcasecmp(locale_code, "GB18030");
  }
  if (tmp___3 == 0) {
    if ((int const   )*(msgid + 0) == 96) {
      tmp___2 = "\241\ae";
    } else {
      tmp___2 = "\241\257";
    }
    return (tmp___2);
  }
  if ((unsigned int )s == 7U) {
    tmp___4 = "\"";
  } else {
    tmp___4 = "\'";
  }
  return (tmp___4);
}
}
static size_t quotearg_buffer_restyled(char *buffer , size_t buffersize , char const   *arg ,
                                       size_t argsize , enum quoting_style quoting_style ,
                                       int flags , unsigned int const   *quote_these_too ,
                                       char const   *left_quote , char const   *right_quote ) 
{ 
  size_t i ;
  size_t len ;
  char const   *quote_string ;
  size_t quote_string_len ;
  _Bool backslash_escapes ;
  _Bool unibyte_locale ;
  size_t tmp ;
  _Bool elide_outer_quotes ;
  unsigned char c ;
  unsigned char esc ;
  _Bool is_right_quote ;
  int tmp___0 ;
  int tmp___1 ;
  size_t m ;
  _Bool printable ;
  unsigned short const   **tmp___2 ;
  mbstate_t mbstate ;
  wchar_t w ;
  size_t bytes ;
  size_t tmp___3 ;
  size_t j ;
  int tmp___4 ;
  int tmp___5 ;
  size_t ilim ;
  int tmp___6 ;
  size_t tmp___7 ;
  void *__cil_tmp36 ;
  char *__cil_tmp37 ;
  char *__cil_tmp38 ;
  char *__cil_tmp39 ;
  char *__cil_tmp40 ;

  {
  {
  len = (size_t )0;
  quote_string = (char const   *)0;
  quote_string_len = (size_t )0;
  backslash_escapes = (_Bool)0;
  tmp = __ctype_get_mb_cur_max();
  unibyte_locale = (_Bool )(tmp == 1UL);
  elide_outer_quotes = (_Bool )((flags & 2) != 0);
  }
  {
  if ((unsigned int )quoting_style == 4U) {
    goto case_4;
  }
  if ((unsigned int )quoting_style == 3U) {
    goto case_3;
  }
  if ((unsigned int )quoting_style == 5U) {
    goto case_5;
  }
  if ((unsigned int )quoting_style == 6U) {
    goto case_6;
  }
  if ((unsigned int )quoting_style == 7U) {
    goto case_6;
  }
  if ((unsigned int )quoting_style == 8U) {
    goto case_6;
  }
  if ((unsigned int )quoting_style == 1U) {
    goto case_1;
  }
  if ((unsigned int )quoting_style == 2U) {
    goto case_2;
  }
  if ((unsigned int )quoting_style == 0U) {
    goto case_0;
  }
  goto switch_default;
  case_4: /* CIL Label */ 
  quoting_style = (enum quoting_style )3;
  elide_outer_quotes = (_Bool)1;
  case_3: /* CIL Label */ 
  if (! elide_outer_quotes) {
    {
    while (1) {
      while_continue: /* CIL Label */ ;
      if (len < buffersize) {
        *(buffer + len) = (char )'\"';
      }
      len ++;
      goto while_break;
    }
    while_break: /* CIL Label */ ;
    }
  }
  backslash_escapes = (_Bool)1;
  quote_string = "\"";
  quote_string_len = (size_t )1;
  goto switch_break;
  case_5: /* CIL Label */ 
  backslash_escapes = (_Bool)1;
  elide_outer_quotes = (_Bool)0;
  goto switch_break;
  case_6: /* CIL Label */ 
  case_7: /* CIL Label */ 
  case_8: /* CIL Label */ 
  if ((unsigned int )quoting_style != 8U) {
    {
    left_quote = gettext_quote("`", quoting_style);
    right_quote = gettext_quote("\'", quoting_style);
    }
  }
  if (! elide_outer_quotes) {
    quote_string = left_quote;
    {
    while (1) {
      while_continue___0: /* CIL Label */ ;
      if (! *quote_string) {
        goto while_break___0;
      }
      {
      while (1) {
        while_continue___1: /* CIL Label */ ;
        if (len < buffersize) {
          *(buffer + len) = (char )*quote_string;
        }
        len ++;
        goto while_break___1;
      }
      while_break___1: /* CIL Label */ ;
      }
      quote_string ++;
    }
    while_break___0: /* CIL Label */ ;
    }
  }
  {
  backslash_escapes = (_Bool)1;
  quote_string = right_quote;
  quote_string_len = strlen(quote_string);
  }
  goto switch_break;
  case_1: /* CIL Label */ 
  quoting_style = (enum quoting_style )2;
  elide_outer_quotes = (_Bool)1;
  case_2: /* CIL Label */ 
  if (! elide_outer_quotes) {
    {
    while (1) {
      while_continue___2: /* CIL Label */ ;
      if (len < buffersize) {
        *(buffer + len) = (char )'\'';
      }
      len ++;
      goto while_break___2;
    }
    while_break___2: /* CIL Label */ ;
    }
  }
  quote_string = "\'";
  quote_string_len = (size_t )1;
  goto switch_break;
  case_0: /* CIL Label */ 
  elide_outer_quotes = (_Bool)0;
  goto switch_break;
  switch_default: /* CIL Label */ 
  {
  abort();
  }
  switch_break: /* CIL Label */ ;
  }
  i = (size_t )0;
  {
  while (1) {
    while_continue___3: /* CIL Label */ ;
    if (argsize == 0xffffffffffffffffUL) {
      tmp___6 = (int const   )*(arg + i) == 0;
    } else {
      tmp___6 = i == argsize;
    }
    if (tmp___6) {
      goto while_break___3;
    }
    is_right_quote = (_Bool)0;
    if (backslash_escapes) {
      if (quote_string_len) {
        if (i + quote_string_len <= argsize) {
          {
          tmp___0 = memcmp((void const   *)(arg + i), (void const   *)quote_string,
                           quote_string_len);
          }
          if (tmp___0 == 0) {
            if (elide_outer_quotes) {
              goto force_outer_quoting_style;
            }
            is_right_quote = (_Bool)1;
          }
        }
      }
    }
    c = (unsigned char )*(arg + i);
    {
    if ((int )c == 0) {
      goto case_0___0;
    }
    if ((int )c == 63) {
      goto case_63;
    }
    if ((int )c == 7) {
      goto case_7___0;
    }
    if ((int )c == 8) {
      goto case_8___0;
    }
    if ((int )c == 12) {
      goto case_12;
    }
    if ((int )c == 10) {
      goto case_10;
    }
    if ((int )c == 13) {
      goto case_13;
    }
    if ((int )c == 9) {
      goto case_9;
    }
    if ((int )c == 11) {
      goto case_11;
    }
    if ((int )c == 92) {
      goto case_92;
    }
    if ((int )c == 123) {
      goto case_123;
    }
    if ((int )c == 125) {
      goto case_123;
    }
    if ((int )c == 35) {
      goto case_35;
    }
    if ((int )c == 126) {
      goto case_35;
    }
    if ((int )c == 32) {
      goto case_32;
    }
    if ((int )c == 33) {
      goto case_32;
    }
    if ((int )c == 34) {
      goto case_32;
    }
    if ((int )c == 36) {
      goto case_32;
    }
    if ((int )c == 38) {
      goto case_32;
    }
    if ((int )c == 40) {
      goto case_32;
    }
    if ((int )c == 41) {
      goto case_32;
    }
    if ((int )c == 42) {
      goto case_32;
    }
    if ((int )c == 59) {
      goto case_32;
    }
    if ((int )c == 60) {
      goto case_32;
    }
    if ((int )c == 61) {
      goto case_32;
    }
    if ((int )c == 62) {
      goto case_32;
    }
    if ((int )c == 91) {
      goto case_32;
    }
    if ((int )c == 94) {
      goto case_32;
    }
    if ((int )c == 96) {
      goto case_32;
    }
    if ((int )c == 124) {
      goto case_32;
    }
    if ((int )c == 39) {
      goto case_39___0;
    }
    if ((int )c == 37) {
      goto case_37;
    }
    if ((int )c == 43) {
      goto case_37;
    }
    if ((int )c == 44) {
      goto case_37;
    }
    if ((int )c == 45) {
      goto case_37;
    }
    if ((int )c == 46) {
      goto case_37;
    }
    if ((int )c == 47) {
      goto case_37;
    }
    if ((int )c == 48) {
      goto case_37;
    }
    if ((int )c == 49) {
      goto case_37;
    }
    if ((int )c == 50) {
      goto case_37;
    }
    if ((int )c == 51) {
      goto case_37;
    }
    if ((int )c == 52) {
      goto case_37;
    }
    if ((int )c == 53) {
      goto case_37;
    }
    if ((int )c == 54) {
      goto case_37;
    }
    if ((int )c == 55) {
      goto case_37;
    }
    if ((int )c == 56) {
      goto case_37;
    }
    if ((int )c == 57) {
      goto case_37;
    }
    if ((int )c == 58) {
      goto case_37;
    }
    if ((int )c == 65) {
      goto case_37;
    }
    if ((int )c == 66) {
      goto case_37;
    }
    if ((int )c == 67) {
      goto case_37;
    }
    if ((int )c == 68) {
      goto case_37;
    }
    if ((int )c == 69) {
      goto case_37;
    }
    if ((int )c == 70) {
      goto case_37;
    }
    if ((int )c == 71) {
      goto case_37;
    }
    if ((int )c == 72) {
      goto case_37;
    }
    if ((int )c == 73) {
      goto case_37;
    }
    if ((int )c == 74) {
      goto case_37;
    }
    if ((int )c == 75) {
      goto case_37;
    }
    if ((int )c == 76) {
      goto case_37;
    }
    if ((int )c == 77) {
      goto case_37;
    }
    if ((int )c == 78) {
      goto case_37;
    }
    if ((int )c == 79) {
      goto case_37;
    }
    if ((int )c == 80) {
      goto case_37;
    }
    if ((int )c == 81) {
      goto case_37;
    }
    if ((int )c == 82) {
      goto case_37;
    }
    if ((int )c == 83) {
      goto case_37;
    }
    if ((int )c == 84) {
      goto case_37;
    }
    if ((int )c == 85) {
      goto case_37;
    }
    if ((int )c == 86) {
      goto case_37;
    }
    if ((int )c == 87) {
      goto case_37;
    }
    if ((int )c == 88) {
      goto case_37;
    }
    if ((int )c == 89) {
      goto case_37;
    }
    if ((int )c == 90) {
      goto case_37;
    }
    if ((int )c == 93) {
      goto case_37;
    }
    if ((int )c == 95) {
      goto case_37;
    }
    if ((int )c == 97) {
      goto case_37;
    }
    if ((int )c == 98) {
      goto case_37;
    }
    if ((int )c == 99) {
      goto case_37;
    }
    if ((int )c == 100) {
      goto case_37;
    }
    if ((int )c == 101) {
      goto case_37;
    }
    if ((int )c == 102) {
      goto case_37;
    }
    if ((int )c == 103) {
      goto case_37;
    }
    if ((int )c == 104) {
      goto case_37;
    }
    if ((int )c == 105) {
      goto case_37;
    }
    if ((int )c == 106) {
      goto case_37;
    }
    if ((int )c == 107) {
      goto case_37;
    }
    if ((int )c == 108) {
      goto case_37;
    }
    if ((int )c == 109) {
      goto case_37;
    }
    if ((int )c == 110) {
      goto case_37;
    }
    if ((int )c == 111) {
      goto case_37;
    }
    if ((int )c == 112) {
      goto case_37;
    }
    if ((int )c == 113) {
      goto case_37;
    }
    if ((int )c == 114) {
      goto case_37;
    }
    if ((int )c == 115) {
      goto case_37;
    }
    if ((int )c == 116) {
      goto case_37;
    }
    if ((int )c == 117) {
      goto case_37;
    }
    if ((int )c == 118) {
      goto case_37;
    }
    if ((int )c == 119) {
      goto case_37;
    }
    if ((int )c == 120) {
      goto case_37;
    }
    if ((int )c == 121) {
      goto case_37;
    }
    if ((int )c == 122) {
      goto case_37;
    }
    goto switch_default___2;
    case_0___0: /* CIL Label */ 
    if (backslash_escapes) {
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
      {
      while (1) {
        while_continue___4: /* CIL Label */ ;
        if (len < buffersize) {
          *(buffer + len) = (char )'\\';
        }
        len ++;
        goto while_break___4;
      }
      while_break___4: /* CIL Label */ ;
      }
      if (i + 1UL < argsize) {
        if (48 <= (int )*(arg + (i + 1UL))) {
          if ((int const   )*(arg + (i + 1UL)) <= 57) {
            {
            while (1) {
              while_continue___5: /* CIL Label */ ;
              if (len < buffersize) {
                *(buffer + len) = (char )'0';
              }
              len ++;
              goto while_break___5;
            }
            while_break___5: /* CIL Label */ ;
            }
            {
            while (1) {
              while_continue___6: /* CIL Label */ ;
              if (len < buffersize) {
                *(buffer + len) = (char )'0';
              }
              len ++;
              goto while_break___6;
            }
            while_break___6: /* CIL Label */ ;
            }
          }
        }
      }
      c = (unsigned char )'0';
    } else
    if (flags & 1) {
      goto __Cont;
    }
    goto switch_break___0;
    case_63: /* CIL Label */ 
    {
    if ((unsigned int )quoting_style == 2U) {
      goto case_2___0;
    }
    if ((unsigned int )quoting_style == 3U) {
      goto case_3___0;
    }
    goto switch_default___1;
    case_2___0: /* CIL Label */ 
    if (elide_outer_quotes) {
      goto force_outer_quoting_style;
    }
    goto switch_break___1;
    case_3___0: /* CIL Label */ 
    if (flags & 4) {
      if (i + 2UL < argsize) {
        if ((int const   )*(arg + (i + 1UL)) == 63) {
          {
          if ((int const   )*(arg + (i + 2UL)) == 33) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 39) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 40) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 41) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 45) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 47) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 60) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 61) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 62) {
            goto case_33;
          }
          goto switch_default___0;
          case_33: /* CIL Label */ 
          case_39: /* CIL Label */ 
          case_40: /* CIL Label */ 
          case_41: /* CIL Label */ 
          case_45: /* CIL Label */ 
          case_47: /* CIL Label */ 
          case_60: /* CIL Label */ 
          case_61: /* CIL Label */ 
          case_62: /* CIL Label */ 
          if (elide_outer_quotes) {
            goto force_outer_quoting_style;
          }
          c = (unsigned char )*(arg + (i + 2UL));
          i += 2UL;
          {
          while (1) {
            while_continue___7: /* CIL Label */ ;
            if (len < buffersize) {
              *(buffer + len) = (char )'?';
            }
            len ++;
            goto while_break___7;
          }
          while_break___7: /* CIL Label */ ;
          }
          {
          while (1) {
            while_continue___8: /* CIL Label */ ;
            if (len < buffersize) {
              *(buffer + len) = (char )'\"';
            }
            len ++;
            goto while_break___8;
          }
          while_break___8: /* CIL Label */ ;
          }
          {
          while (1) {
            while_continue___9: /* CIL Label */ ;
            if (len < buffersize) {
              *(buffer + len) = (char )'\"';
            }
            len ++;
            goto while_break___9;
          }
          while_break___9: /* CIL Label */ ;
          }
          {
          while (1) {
            while_continue___10: /* CIL Label */ ;
            if (len < buffersize) {
              *(buffer + len) = (char )'?';
            }
            len ++;
            goto while_break___10;
          }
          while_break___10: /* CIL Label */ ;
          }
          goto switch_break___2;
          switch_default___0: /* CIL Label */ 
          goto switch_break___2;
          switch_break___2: /* CIL Label */ ;
          }
        }
      }
    }
    goto switch_break___1;
    switch_default___1: /* CIL Label */ 
    goto switch_break___1;
    switch_break___1: /* CIL Label */ ;
    }
    goto switch_break___0;
    case_7___0: /* CIL Label */ 
    esc = (unsigned char )'a';
    goto c_escape;
    case_8___0: /* CIL Label */ 
    esc = (unsigned char )'b';
    goto c_escape;
    case_12: /* CIL Label */ 
    esc = (unsigned char )'f';
    goto c_escape;
    case_10: /* CIL Label */ 
    esc = (unsigned char )'n';
    goto c_and_shell_escape;
    case_13: /* CIL Label */ 
    esc = (unsigned char )'r';
    goto c_and_shell_escape;
    case_9: /* CIL Label */ 
    esc = (unsigned char )'t';
    goto c_and_shell_escape;
    case_11: /* CIL Label */ 
    esc = (unsigned char )'v';
    goto c_escape;
    case_92: /* CIL Label */ 
    esc = c;
    if (backslash_escapes) {
      if (elide_outer_quotes) {
        if (quote_string_len) {
          goto store_c;
        }
      }
    }
    c_and_shell_escape: 
    if ((unsigned int )quoting_style == 2U) {
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
    }
    c_escape: 
    if (backslash_escapes) {
      c = esc;
      goto store_escape;
    }
    goto switch_break___0;
    case_123: /* CIL Label */ 
    case_125: /* CIL Label */ 
    if (argsize == 0xffffffffffffffffUL) {
      tmp___1 = (int const   )*(arg + 1) == 0;
    } else {
      tmp___1 = argsize == 1UL;
    }
    if (! tmp___1) {
      goto switch_break___0;
    }
    case_35: /* CIL Label */ 
    case_126: /* CIL Label */ 
    if (i != 0UL) {
      goto switch_break___0;
    }
    case_32: /* CIL Label */ 
    case_33___0: /* CIL Label */ 
    case_34: /* CIL Label */ 
    case_36: /* CIL Label */ 
    case_38: /* CIL Label */ 
    case_40___0: /* CIL Label */ 
    case_41___0: /* CIL Label */ 
    case_42: /* CIL Label */ 
    case_59: /* CIL Label */ 
    case_60___0: /* CIL Label */ 
    case_61___0: /* CIL Label */ 
    case_62___0: /* CIL Label */ 
    case_91: /* CIL Label */ 
    case_94: /* CIL Label */ 
    case_96: /* CIL Label */ 
    case_124: /* CIL Label */ 
    if ((unsigned int )quoting_style == 2U) {
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
    }
    goto switch_break___0;
    case_39___0: /* CIL Label */ 
    if ((unsigned int )quoting_style == 2U) {
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
      {
      while (1) {
        while_continue___11: /* CIL Label */ ;
        if (len < buffersize) {
          *(buffer + len) = (char )'\'';
        }
        len ++;
        goto while_break___11;
      }
      while_break___11: /* CIL Label */ ;
      }
      {
      while (1) {
        while_continue___12: /* CIL Label */ ;
        if (len < buffersize) {
          *(buffer + len) = (char )'\\';
        }
        len ++;
        goto while_break___12;
      }
      while_break___12: /* CIL Label */ ;
      }
      {
      while (1) {
        while_continue___13: /* CIL Label */ ;
        if (len < buffersize) {
          *(buffer + len) = (char )'\'';
        }
        len ++;
        goto while_break___13;
      }
      while_break___13: /* CIL Label */ ;
      }
    }
    goto switch_break___0;
    case_37: /* CIL Label */ 
    case_43: /* CIL Label */ 
    case_44: /* CIL Label */ 
    case_45___0: /* CIL Label */ 
    case_46: /* CIL Label */ 
    case_47___0: /* CIL Label */ 
    case_48: /* CIL Label */ 
    case_49: /* CIL Label */ 
    case_50: /* CIL Label */ 
    case_51: /* CIL Label */ 
    case_52: /* CIL Label */ 
    case_53: /* CIL Label */ 
    case_54: /* CIL Label */ 
    case_55: /* CIL Label */ 
    case_56: /* CIL Label */ 
    case_57: /* CIL Label */ 
    case_58: /* CIL Label */ 
    case_65: /* CIL Label */ 
    case_66: /* CIL Label */ 
    case_67: /* CIL Label */ 
    case_68: /* CIL Label */ 
    case_69: /* CIL Label */ 
    case_70: /* CIL Label */ 
    case_71: /* CIL Label */ 
    case_72: /* CIL Label */ 
    case_73: /* CIL Label */ 
    case_74: /* CIL Label */ 
    case_75: /* CIL Label */ 
    case_76: /* CIL Label */ 
    case_77: /* CIL Label */ 
    case_78: /* CIL Label */ 
    case_79: /* CIL Label */ 
    case_80: /* CIL Label */ 
    case_81: /* CIL Label */ 
    case_82: /* CIL Label */ 
    case_83: /* CIL Label */ 
    case_84: /* CIL Label */ 
    case_85: /* CIL Label */ 
    case_86: /* CIL Label */ 
    case_87: /* CIL Label */ 
    case_88: /* CIL Label */ 
    case_89: /* CIL Label */ 
    case_90: /* CIL Label */ 
    case_93: /* CIL Label */ 
    case_95: /* CIL Label */ 
    case_97: /* CIL Label */ 
    case_98: /* CIL Label */ 
    case_99: /* CIL Label */ 
    case_100: /* CIL Label */ 
    case_101: /* CIL Label */ 
    case_102: /* CIL Label */ 
    case_103: /* CIL Label */ 
    case_104: /* CIL Label */ 
    case_105: /* CIL Label */ 
    case_106: /* CIL Label */ 
    case_107: /* CIL Label */ 
    case_108: /* CIL Label */ 
    case_109: /* CIL Label */ 
    case_110: /* CIL Label */ 
    case_111: /* CIL Label */ 
    case_112: /* CIL Label */ 
    case_113: /* CIL Label */ 
    case_114: /* CIL Label */ 
    case_115: /* CIL Label */ 
    case_116: /* CIL Label */ 
    case_117: /* CIL Label */ 
    case_118: /* CIL Label */ 
    case_119: /* CIL Label */ 
    case_120: /* CIL Label */ 
    case_121: /* CIL Label */ 
    case_122: /* CIL Label */ 
    goto switch_break___0;
    switch_default___2: /* CIL Label */ 
    if (unibyte_locale) {
      {
      m = (size_t )1;
      tmp___2 = __ctype_b_loc();
      printable = (_Bool )(((int const   )*(*tmp___2 + (int )c) & 16384) != 0);
      }
    } else {
      {
      memset((void *)(& mbstate), 0, sizeof(mbstate));
      m = (size_t )0;
      printable = (_Bool)1;
      }
      if (argsize == 0xffffffffffffffffUL) {
        {
        argsize = strlen(arg);
        }
      }
      {
      while (1) {
        while_continue___14: /* CIL Label */ ;
        {
        tmp___3 = mbrtowc((wchar_t */* __restrict  */)(& w), (char const   */* __restrict  */)(arg + (i + m)),
                          argsize - (i + m), (mbstate_t */* __restrict  */)(& mbstate));
        bytes = tmp___3;
        }
        if (bytes == 0UL) {
          goto while_break___14;
        } else
        if (bytes == 0xffffffffffffffffUL) {
          printable = (_Bool)0;
          goto while_break___14;
        } else
        if (bytes == 0xfffffffffffffffeUL) {
          printable = (_Bool)0;
          {
          while (1) {
            while_continue___15: /* CIL Label */ ;
            if (i + m < argsize) {
              if (! *(arg + (i + m))) {
                goto while_break___15;
              }
            } else {
              goto while_break___15;
            }
            m ++;
          }
          while_break___15: /* CIL Label */ ;
          }
          goto while_break___14;
        } else {
          if (elide_outer_quotes) {
            if ((unsigned int )quoting_style == 2U) {
              j = (size_t )1;
              {
              while (1) {
                while_continue___16: /* CIL Label */ ;
                if (! (j < bytes)) {
                  goto while_break___16;
                }
                {
                if ((int const   )*(arg + ((i + m) + j)) == 91) {
                  goto case_91___0;
                }
                if ((int const   )*(arg + ((i + m) + j)) == 92) {
                  goto case_91___0;
                }
                if ((int const   )*(arg + ((i + m) + j)) == 94) {
                  goto case_91___0;
                }
                if ((int const   )*(arg + ((i + m) + j)) == 96) {
                  goto case_91___0;
                }
                if ((int const   )*(arg + ((i + m) + j)) == 124) {
                  goto case_91___0;
                }
                goto switch_default___3;
                case_91___0: /* CIL Label */ 
                case_92___0: /* CIL Label */ 
                case_94___0: /* CIL Label */ 
                case_96___0: /* CIL Label */ 
                case_124___0: /* CIL Label */ 
                goto force_outer_quoting_style;
                switch_default___3: /* CIL Label */ 
                goto switch_break___3;
                switch_break___3: /* CIL Label */ ;
                }
                j ++;
              }
              while_break___16: /* CIL Label */ ;
              }
            }
          }
          {
          tmp___4 = iswprint((wint_t )w);
          }
          if (! tmp___4) {
            printable = (_Bool)0;
          }
          m += bytes;
        }
        {
        tmp___5 = mbsinit((mbstate_t const   *)(& mbstate));
        }
        if (tmp___5) {
          goto while_break___14;
        }
      }
      while_break___14: /* CIL Label */ ;
      }
    }
    if (1UL < m) {
      goto _L___0;
    } else
    if (backslash_escapes) {
      if (! printable) {
        _L___0: 
        ilim = i + m;
        {
        while (1) {
          while_continue___17: /* CIL Label */ ;
          if (backslash_escapes) {
            if (! printable) {
              if (elide_outer_quotes) {
                goto force_outer_quoting_style;
              }
              {
              while (1) {
                while_continue___18: /* CIL Label */ ;
                if (len < buffersize) {
                  *(buffer + len) = (char )'\\';
                }
                len ++;
                goto while_break___18;
              }
              while_break___18: /* CIL Label */ ;
              }
              {
              while (1) {
                while_continue___19: /* CIL Label */ ;
                if (len < buffersize) {
                  *(buffer + len) = (char )(48 + ((int )c >> 6));
                }
                len ++;
                goto while_break___19;
              }
              while_break___19: /* CIL Label */ ;
              }
              {
              while (1) {
                while_continue___20: /* CIL Label */ ;
                if (len < buffersize) {
                  *(buffer + len) = (char )(48 + (((int )c >> 3) & 7));
                }
                len ++;
                goto while_break___20;
              }
              while_break___20: /* CIL Label */ ;
              }
              c = (unsigned char )(48 + ((int )c & 7));
            } else {
              goto _L;
            }
          } else
          _L: 
          if (is_right_quote) {
            {
            while (1) {
              while_continue___21: /* CIL Label */ ;
              if (len < buffersize) {
                *(buffer + len) = (char )'\\';
              }
              len ++;
              goto while_break___21;
            }
            while_break___21: /* CIL Label */ ;
            }
            is_right_quote = (_Bool)0;
          }
          if (ilim <= i + 1UL) {
            goto while_break___17;
          }
          {
          while (1) {
            while_continue___22: /* CIL Label */ ;
            if (len < buffersize) {
              *(buffer + len) = (char )c;
            }
            len ++;
            goto while_break___22;
          }
          while_break___22: /* CIL Label */ ;
          }
          i ++;
          c = (unsigned char )*(arg + i);
        }
        while_break___17: /* CIL Label */ ;
        }
        goto store_c;
      }
    }
    switch_break___0: /* CIL Label */ ;
    }
    if (backslash_escapes) {
      goto _L___3;
    } else
    if (elide_outer_quotes) {
      _L___3: 
      if (quote_these_too) {
        if (! (*(quote_these_too + (unsigned long )c / (sizeof(int ) * 8UL)) & (unsigned int const   )(1 << (unsigned long )c % (sizeof(int ) * 8UL)))) {
          goto _L___2;
        }
      } else {
        goto _L___2;
      }
    } else
    _L___2: 
    if (! is_right_quote) {
      goto store_c;
    }
    store_escape: 
    if (elide_outer_quotes) {
      goto force_outer_quoting_style;
    }
    {
    while (1) {
      while_continue___23: /* CIL Label */ ;
      if (len < buffersize) {
        *(buffer + len) = (char )'\\';
      }
      len ++;
      goto while_break___23;
    }
    while_break___23: /* CIL Label */ ;
    }
    store_c: 
    {
    while (1) {
      while_continue___24: /* CIL Label */ ;
      if (len < buffersize) {
        *(buffer + len) = (char )c;
      }
      len ++;
      goto while_break___24;
    }
    while_break___24: /* CIL Label */ ;
    }
    __Cont: 
    i ++;
  }
  while_break___3: /* CIL Label */ ;
  }
  if (len == 0UL) {
    if ((unsigned int )quoting_style == 2U) {
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
    }
  }
  if (quote_string) {
    if (! elide_outer_quotes) {
      {
      while (1) {
        while_continue___25: /* CIL Label */ ;
        if (! *quote_string) {
          goto while_break___25;
        }
        {
        while (1) {
          while_continue___26: /* CIL Label */ ;
          if (len < buffersize) {
            *(buffer + len) = (char )*quote_string;
          }
          len ++;
          goto while_break___26;
        }
        while_break___26: /* CIL Label */ ;
        }
        quote_string ++;
      }
      while_break___25: /* CIL Label */ ;
      }
    }
  }
  if (len < buffersize) {
    *(buffer + len) = (char )'\000';
  }
  return (len);
  force_outer_quoting_style: 
  {
  tmp___7 = quotearg_buffer_restyled(buffer, buffersize, arg, argsize, quoting_style,
                                     flags & -3, (unsigned int const   *)((void *)0),
                                     left_quote, right_quote);
  }
  return (tmp___7);
}
}
static char slot0[256]  ;
static unsigned int nslots  =    1U;
static struct slotvec slotvec0  =    {sizeof(slot0), slot0};
static struct slotvec *slotvec  =    & slotvec0;
static char *quotearg_n_options(int n , char const   *arg , size_t argsize , struct quoting_options  const  *options ) 
{ 
  int e ;
  int *tmp ;
  unsigned int n0 ;
  struct slotvec *sv ;
  size_t n1 ;
  _Bool preallocated ;
  int tmp___0 ;
  struct slotvec *tmp___1 ;
  size_t size ;
  char *val ;
  int flags ;
  size_t qsize ;
  size_t tmp___2 ;
  int *tmp___3 ;

  {
  {
  tmp = __errno_location();
  e = *tmp;
  n0 = (unsigned int )n;
  sv = slotvec;
  }
  if (n < 0) {
    {
    abort();
    }
  }
  if (nslots <= n0) {
    n1 = (size_t )(n0 + 1U);
    preallocated = (_Bool )((unsigned long )sv == (unsigned long )(& slotvec0));
    if (sizeof(ptrdiff_t ) <= sizeof(size_t )) {
      tmp___0 = -1;
    } else {
      tmp___0 = -2;
    }
    if ((size_t )tmp___0 / sizeof(*sv) < n1) {
      {
      xalloc_die();
      }
    }
    if (preallocated) {
      tmp___1 = (struct slotvec *)((void *)0);
    } else {
      tmp___1 = sv;
    }
    {
    sv = (struct slotvec *)xrealloc((void *)tmp___1, n1 * sizeof(*sv));
    slotvec = sv;
    }
    if (preallocated) {
      *sv = slotvec0;
    }
    {
    memset((void *)(sv + nslots), 0, (n1 - (size_t )nslots) * sizeof(*sv));
    nslots = (unsigned int )n1;
    }
  }
  {
  size = (sv + n)->size;
  val = (sv + n)->val;
  flags = (int )(options->flags | 1);
  tmp___2 = quotearg_buffer_restyled(val, size, arg, argsize, (enum quoting_style )options->style,
                                     flags, (unsigned int const   *)(options->quote_these_too),
                                     (char const   *)options->left_quote, (char const   *)options->right_quote);
  qsize = tmp___2;
  }
  if (size <= qsize) {
    size = qsize + 1UL;
    (sv + n)->size = size;
    if ((unsigned long )val != (unsigned long )(slot0)) {
      {
      free((void *)val);
      }
    }
    {
    val = xcharalloc(size);
    (sv + n)->val = val;
    quotearg_buffer_restyled(val, size, arg, argsize, (enum quoting_style )options->style,
                             flags, (unsigned int const   *)(options->quote_these_too),
                             (char const   *)options->left_quote, (char const   *)options->right_quote);
    }
  }
  {
  tmp___3 = __errno_location();
  *tmp___3 = e;
  }
  return (val);
}
}
char *quotearg_n_style(int n , enum quoting_style s , char const   *arg ) 
{ 
  struct quoting_options o ;
  struct quoting_options tmp ;
  char *tmp___0 ;
  void *__cil_tmp7 ;
  void *__cil_tmp8 ;

  {
  {
  tmp = quoting_options_from_style(s);
  o = tmp;
  tmp___0 = quotearg_n_options(n, arg, (size_t )-1, (struct quoting_options  const  *)(& o));
  }
  return (tmp___0);
}
}
char *quotearg_n_style_mem(int n , enum quoting_style s , char const   *arg , size_t argsize ) 
{ 
  struct quoting_options o ;
  struct quoting_options tmp ;
  char *tmp___0 ;
  void *__cil_tmp8 ;
  void *__cil_tmp9 ;

  {
  {
  tmp = quoting_options_from_style(s);
  o = tmp;
  tmp___0 = quotearg_n_options(n, arg, argsize, (struct quoting_options  const  *)(& o));
  }
  return (tmp___0);
}
}
char *quotearg_char_mem(char const   *arg , size_t argsize , char ch ) 
{ 
  struct quoting_options options ;
  char *tmp ;
  void *__cil_tmp6 ;

  {
  {
  options = default_quoting_options;
  set_char_quoting(& options, ch, 1);
  tmp = quotearg_n_options(0, arg, argsize, (struct quoting_options  const  *)(& options));
  }
  return (tmp);
}
}
char *quotearg_char(char const   *arg , char ch ) 
{ 
  char *tmp ;

  {
  {
  tmp = quotearg_char_mem(arg, (size_t )-1, ch);
  }
  return (tmp);
}
}
char *quotearg_colon(char const   *arg ) 
{ 
  char *tmp ;

  {
  {
  tmp = quotearg_char(arg, (char )':');
  }
  return (tmp);
}
}
struct quoting_options quote_quoting_options  =    {(enum quoting_style )6, 0, {0U}, (char const   *)((void *)0), (char const   *)((void *)0)};
char const   *quote_n(int n ,
                      char const   *name ) 
{ 
  char const   *tmp ;

  {
  {
  tmp = (char const   *)quotearg_n_options(n, name, (size_t )-1, (struct quoting_options  const  *)(& quote_quoting_options));
  }
  return (tmp);
}
}
char const   *quote(char const   *name ) 
{ 
  char const   *tmp ;

  {
  {
  tmp = quote_n(0, name);
  }
  return (tmp);
}
}
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) iswalnum)(wint_t __wc ) ;
char const   *program_name ;
void set_program_name(char const   *argv0 ) ;
extern char *program_invocation_name ;
extern char *program_invocation_short_name ;
extern int fputs(char const   * __restrict  __s , FILE * __restrict  __stream ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) strrchr)(char const   *__s ,
                                                                                                int __c )  __attribute__((__pure__)) ;
char const   *program_name  =    (char const   *)((void *)0);
void set_program_name(char const   *argv0 ) 
{ 
  char const   *slash ;
  char const   *base ;
  int tmp ;
  int tmp___0 ;

  {
  if ((unsigned long )argv0 == (unsigned long )((void *)0)) {
    {
    fputs((char const   */* __restrict  */)"A NULL argv[0] was passed through an exec system call.\n",
          (FILE */* __restrict  */)stderr);
    abort();
    }
  }
  {
  slash = (char const   *)strrchr(argv0, '/');
  }
  if ((unsigned long )slash != (unsigned long )((void *)0)) {
    base = slash + 1;
  } else {
    base = argv0;
  }
  if (base - argv0 >= 7L) {
    {
    tmp___0 = strncmp(base - 7, "/.libs/", (size_t )7);
    }
    if (tmp___0 == 0) {
      {
      argv0 = base;
      tmp = strncmp(base, "lt-", (size_t )3);
      }
      if (tmp == 0) {
        argv0 = base + 3;
        program_invocation_short_name = (char *)argv0;
      }
    }
  }
  program_name = argv0;
  program_invocation_name = (char *)argv0;
  return;
}
}
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) frexpl)(long double __x ,
                                                                                     int *__exponent ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) ldexpl)(long double __x ,
                                                                                     int __exponent ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) frexp)(double __x ,
                                                                               int *__exponent ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) ldexp)(double __x ,
                                                                               int __exponent ) ;
static wchar_t const   wide_null_string[7]  = {      (wchar_t const   )'(',      (wchar_t const   )'N',      (wchar_t const   )'U',      (wchar_t const   )'L', 
        (wchar_t const   )'L',      (wchar_t const   )')',      (wchar_t const   )0};
int posix2_version(void) ;
int posix2_version(void) 
{ 
  long v ;
  char const   *s ;
  char const   *tmp ;
  char *e ;
  long i ;
  long tmp___0 ;
  long tmp___1 ;
  long tmp___2 ;
  char *__cil_tmp10 ;

  {
  {
  v = 200809L;
  tmp = (char const   *)getenv("_POSIX2_VERSION");
  s = tmp;
  }
  if (s) {
    if (*s) {
      {
      tmp___0 = strtol((char const   */* __restrict  */)s, (char **/* __restrict  */)(& e),
                       10);
      i = tmp___0;
      }
      if (! *e) {
        v = i;
      }
    }
  }
  if (v < (-0x7FFFFFFF-1)) {
    tmp___2 = (-0x7FFFFFFF-1);
  } else {
    if (v < 2147483647L) {
      tmp___1 = v;
    } else {
      tmp___1 = 2147483647L;
    }
    tmp___2 = tmp___1;
  }
  return ((int )tmp___2);
}
}
extern  __attribute__((__nothrow__)) time_t ( __attribute__((__leaf__)) time)(time_t *__timer ) ;
extern  __attribute__((__nothrow__)) struct tm *( __attribute__((__leaf__)) localtime)(time_t const   *__timer ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2), __leaf__)) stpcpy)(char * __restrict  __dest ,
                                                                                                 char const   * __restrict  __src ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) pipe)(int *__pipedes ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) pipe2)(int *__pipedes ,
                                                                            int __flags ) ;
static int have_pipe2_really  ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) sysconf)(int __name ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2), __leaf__)) setenv)(char const   *__name ,
                                                                                             char const   *__value ,
                                                                                             int __replace ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) unsetenv)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) abs)(int __x )  __attribute__((__const__)) ;
static yytype_uint8 const   yytranslate[278]  = 
  {      (yytype_uint8 const   )0,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )26,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )27, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )25,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )23,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )24,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )1,      (yytype_uint8 const   )2,      (yytype_uint8 const   )3,      (yytype_uint8 const   )4, 
        (yytype_uint8 const   )5,      (yytype_uint8 const   )6,      (yytype_uint8 const   )7,      (yytype_uint8 const   )8, 
        (yytype_uint8 const   )9,      (yytype_uint8 const   )10,      (yytype_uint8 const   )11,      (yytype_uint8 const   )12, 
        (yytype_uint8 const   )13,      (yytype_uint8 const   )14,      (yytype_uint8 const   )15,      (yytype_uint8 const   )16, 
        (yytype_uint8 const   )17,      (yytype_uint8 const   )18,      (yytype_uint8 const   )19,      (yytype_uint8 const   )20, 
        (yytype_uint8 const   )21,      (yytype_uint8 const   )22};
static yytype_int8 const   yypact[114]  = 
  {      (yytype_int8 const   )38,      (yytype_int8 const   )27,      (yytype_int8 const   )77,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )46,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )62,      (yytype_int8 const   )-93,      (yytype_int8 const   )82,      (yytype_int8 const   )-3, 
        (yytype_int8 const   )66,      (yytype_int8 const   )3,      (yytype_int8 const   )74,      (yytype_int8 const   )-4, 
        (yytype_int8 const   )83,      (yytype_int8 const   )84,      (yytype_int8 const   )75,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )71,      (yytype_int8 const   )-93,      (yytype_int8 const   )93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )78,      (yytype_int8 const   )72,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )25, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )21, 
        (yytype_int8 const   )19,      (yytype_int8 const   )79,      (yytype_int8 const   )80,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )81,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )85, 
        (yytype_int8 const   )86,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-6,      (yytype_int8 const   )76, 
        (yytype_int8 const   )17,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )87,      (yytype_int8 const   )69,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )88,      (yytype_int8 const   )89,      (yytype_int8 const   )-1, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )18,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )69,      (yytype_int8 const   )91};
static yytype_uint8 const   yydefact[114]  = 
  {      (yytype_uint8 const   )5,      (yytype_uint8 const   )0,      (yytype_uint8 const   )0,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )3,      (yytype_uint8 const   )85,      (yytype_uint8 const   )87,      (yytype_uint8 const   )84, 
        (yytype_uint8 const   )86,      (yytype_uint8 const   )4,      (yytype_uint8 const   )82,      (yytype_uint8 const   )83, 
        (yytype_uint8 const   )1,      (yytype_uint8 const   )56,      (yytype_uint8 const   )59,      (yytype_uint8 const   )65, 
        (yytype_uint8 const   )68,      (yytype_uint8 const   )73,      (yytype_uint8 const   )62,      (yytype_uint8 const   )81, 
        (yytype_uint8 const   )37,      (yytype_uint8 const   )35,      (yytype_uint8 const   )28,      (yytype_uint8 const   )0, 
        (yytype_uint8 const   )0,      (yytype_uint8 const   )30,      (yytype_uint8 const   )0,      (yytype_uint8 const   )88, 
        (yytype_uint8 const   )0,      (yytype_uint8 const   )0,      (yytype_uint8 const   )31,      (yytype_uint8 const   )6, 
        (yytype_uint8 const   )7,      (yytype_uint8 const   )16,      (yytype_uint8 const   )8,      (yytype_uint8 const   )21, 
        (yytype_uint8 const   )9,      (yytype_uint8 const   )10,      (yytype_uint8 const   )12,      (yytype_uint8 const   )11, 
        (yytype_uint8 const   )49,      (yytype_uint8 const   )13,      (yytype_uint8 const   )52,      (yytype_uint8 const   )74, 
        (yytype_uint8 const   )53,      (yytype_uint8 const   )14,      (yytype_uint8 const   )15,      (yytype_uint8 const   )38, 
        (yytype_uint8 const   )29,      (yytype_uint8 const   )0,      (yytype_uint8 const   )45,      (yytype_uint8 const   )54, 
        (yytype_uint8 const   )57,      (yytype_uint8 const   )63,      (yytype_uint8 const   )66,      (yytype_uint8 const   )69, 
        (yytype_uint8 const   )60,      (yytype_uint8 const   )39,      (yytype_uint8 const   )36,      (yytype_uint8 const   )90, 
        (yytype_uint8 const   )32,      (yytype_uint8 const   )75,      (yytype_uint8 const   )76,      (yytype_uint8 const   )78, 
        (yytype_uint8 const   )79,      (yytype_uint8 const   )80,      (yytype_uint8 const   )77,      (yytype_uint8 const   )55, 
        (yytype_uint8 const   )58,      (yytype_uint8 const   )64,      (yytype_uint8 const   )67,      (yytype_uint8 const   )70, 
        (yytype_uint8 const   )61,      (yytype_uint8 const   )40,      (yytype_uint8 const   )18,      (yytype_uint8 const   )47, 
        (yytype_uint8 const   )90,      (yytype_uint8 const   )0,      (yytype_uint8 const   )0,      (yytype_uint8 const   )22, 
        (yytype_uint8 const   )89,      (yytype_uint8 const   )71,      (yytype_uint8 const   )72,      (yytype_uint8 const   )33, 
        (yytype_uint8 const   )0,      (yytype_uint8 const   )51,      (yytype_uint8 const   )44,      (yytype_uint8 const   )0, 
        (yytype_uint8 const   )0,      (yytype_uint8 const   )34,      (yytype_uint8 const   )43,      (yytype_uint8 const   )48, 
        (yytype_uint8 const   )50,      (yytype_uint8 const   )27,      (yytype_uint8 const   )25,      (yytype_uint8 const   )41, 
        (yytype_uint8 const   )0,      (yytype_uint8 const   )17,      (yytype_uint8 const   )46,      (yytype_uint8 const   )91, 
        (yytype_uint8 const   )19,      (yytype_uint8 const   )90,      (yytype_uint8 const   )0,      (yytype_uint8 const   )23, 
        (yytype_uint8 const   )26,      (yytype_uint8 const   )0,      (yytype_uint8 const   )0,      (yytype_uint8 const   )25, 
        (yytype_uint8 const   )42,      (yytype_uint8 const   )25,      (yytype_uint8 const   )20,      (yytype_uint8 const   )24, 
        (yytype_uint8 const   )0,      (yytype_uint8 const   )25};
static yytype_int8 const   yypgoto[26]  = 
  {      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )20,      (yytype_int8 const   )-68,      (yytype_int8 const   )-27,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )60,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )-93,      (yytype_int8 const   )-92,      (yytype_int8 const   )-93, 
        (yytype_int8 const   )-93,      (yytype_int8 const   )43};
static yytype_int8 const   yydefgoto[26]  = 
  {      (yytype_int8 const   )-1,      (yytype_int8 const   )2,      (yytype_int8 const   )3,      (yytype_int8 const   )4, 
        (yytype_int8 const   )31,      (yytype_int8 const   )32,      (yytype_int8 const   )33,      (yytype_int8 const   )34, 
        (yytype_int8 const   )35,      (yytype_int8 const   )103,      (yytype_int8 const   )104,      (yytype_int8 const   )36, 
        (yytype_int8 const   )37,      (yytype_int8 const   )38,      (yytype_int8 const   )39,      (yytype_int8 const   )40, 
        (yytype_int8 const   )41,      (yytype_int8 const   )42,      (yytype_int8 const   )43,      (yytype_int8 const   )44, 
        (yytype_int8 const   )9,      (yytype_int8 const   )10,      (yytype_int8 const   )11,      (yytype_int8 const   )45, 
        (yytype_int8 const   )46,      (yytype_int8 const   )93};
static yytype_uint8 const   yytable[113]  = 
  {      (yytype_uint8 const   )79,      (yytype_uint8 const   )67,      (yytype_uint8 const   )68,      (yytype_uint8 const   )69, 
        (yytype_uint8 const   )70,      (yytype_uint8 const   )71,      (yytype_uint8 const   )72,      (yytype_uint8 const   )58, 
        (yytype_uint8 const   )73,      (yytype_uint8 const   )100,      (yytype_uint8 const   )107,      (yytype_uint8 const   )74, 
        (yytype_uint8 const   )75,      (yytype_uint8 const   )101,      (yytype_uint8 const   )110,      (yytype_uint8 const   )76, 
        (yytype_uint8 const   )49,      (yytype_uint8 const   )50,      (yytype_uint8 const   )101,      (yytype_uint8 const   )102, 
        (yytype_uint8 const   )113,      (yytype_uint8 const   )77,      (yytype_uint8 const   )59,      (yytype_uint8 const   )78, 
        (yytype_uint8 const   )61,      (yytype_uint8 const   )62,      (yytype_uint8 const   )63,      (yytype_uint8 const   )64, 
        (yytype_uint8 const   )65,      (yytype_uint8 const   )66,      (yytype_uint8 const   )61,      (yytype_uint8 const   )62, 
        (yytype_uint8 const   )63,      (yytype_uint8 const   )64,      (yytype_uint8 const   )65,      (yytype_uint8 const   )66, 
        (yytype_uint8 const   )101,      (yytype_uint8 const   )101,      (yytype_uint8 const   )92,      (yytype_uint8 const   )111, 
        (yytype_uint8 const   )90,      (yytype_uint8 const   )91,      (yytype_uint8 const   )106,      (yytype_uint8 const   )112, 
        (yytype_uint8 const   )88,      (yytype_uint8 const   )111,      (yytype_uint8 const   )5,      (yytype_uint8 const   )6, 
        (yytype_uint8 const   )7,      (yytype_uint8 const   )8,      (yytype_uint8 const   )88,      (yytype_uint8 const   )13, 
        (yytype_uint8 const   )14,      (yytype_uint8 const   )15,      (yytype_uint8 const   )16,      (yytype_uint8 const   )17, 
        (yytype_uint8 const   )18,      (yytype_uint8 const   )19,      (yytype_uint8 const   )20,      (yytype_uint8 const   )21, 
        (yytype_uint8 const   )22,      (yytype_uint8 const   )1,      (yytype_uint8 const   )23,      (yytype_uint8 const   )24, 
        (yytype_uint8 const   )25,      (yytype_uint8 const   )26,      (yytype_uint8 const   )27,      (yytype_uint8 const   )28, 
        (yytype_uint8 const   )29,      (yytype_uint8 const   )79,      (yytype_uint8 const   )30,      (yytype_uint8 const   )51, 
        (yytype_uint8 const   )52,      (yytype_uint8 const   )53,      (yytype_uint8 const   )54,      (yytype_uint8 const   )55, 
        (yytype_uint8 const   )56,      (yytype_uint8 const   )12,      (yytype_uint8 const   )57,      (yytype_uint8 const   )61, 
        (yytype_uint8 const   )62,      (yytype_uint8 const   )63,      (yytype_uint8 const   )64,      (yytype_uint8 const   )65, 
        (yytype_uint8 const   )66,      (yytype_uint8 const   )60,      (yytype_uint8 const   )48,      (yytype_uint8 const   )80, 
        (yytype_uint8 const   )47,      (yytype_uint8 const   )6,      (yytype_uint8 const   )83,      (yytype_uint8 const   )8, 
        (yytype_uint8 const   )81,      (yytype_uint8 const   )82,      (yytype_uint8 const   )26,      (yytype_uint8 const   )84, 
        (yytype_uint8 const   )85,      (yytype_uint8 const   )86,      (yytype_uint8 const   )87,      (yytype_uint8 const   )94, 
        (yytype_uint8 const   )95,      (yytype_uint8 const   )96,      (yytype_uint8 const   )89,      (yytype_uint8 const   )105, 
        (yytype_uint8 const   )97,      (yytype_uint8 const   )98,      (yytype_uint8 const   )99,      (yytype_uint8 const   )0, 
        (yytype_uint8 const   )108,      (yytype_uint8 const   )109,      (yytype_uint8 const   )101,      (yytype_uint8 const   )0, 
        (yytype_uint8 const   )88};
static yytype_int8 const   yycheck[113]  = 
  {      (yytype_int8 const   )27,      (yytype_int8 const   )5,      (yytype_int8 const   )6,      (yytype_int8 const   )7, 
        (yytype_int8 const   )8,      (yytype_int8 const   )9,      (yytype_int8 const   )10,      (yytype_int8 const   )4, 
        (yytype_int8 const   )12,      (yytype_int8 const   )15,      (yytype_int8 const   )102,      (yytype_int8 const   )15, 
        (yytype_int8 const   )16,      (yytype_int8 const   )19,      (yytype_int8 const   )15,      (yytype_int8 const   )19, 
        (yytype_int8 const   )19,      (yytype_int8 const   )20,      (yytype_int8 const   )19,      (yytype_int8 const   )25, 
        (yytype_int8 const   )112,      (yytype_int8 const   )25,      (yytype_int8 const   )19,      (yytype_int8 const   )27, 
        (yytype_int8 const   )5,      (yytype_int8 const   )6,      (yytype_int8 const   )7,      (yytype_int8 const   )8, 
        (yytype_int8 const   )9,      (yytype_int8 const   )10,      (yytype_int8 const   )5,      (yytype_int8 const   )6, 
        (yytype_int8 const   )7,      (yytype_int8 const   )8,      (yytype_int8 const   )9,      (yytype_int8 const   )10, 
        (yytype_int8 const   )19,      (yytype_int8 const   )19,      (yytype_int8 const   )19,      (yytype_int8 const   )107, 
        (yytype_int8 const   )19,      (yytype_int8 const   )20,      (yytype_int8 const   )25,      (yytype_int8 const   )25, 
        (yytype_int8 const   )25,      (yytype_int8 const   )113,      (yytype_int8 const   )19,      (yytype_int8 const   )20, 
        (yytype_int8 const   )21,      (yytype_int8 const   )22,      (yytype_int8 const   )25,      (yytype_int8 const   )5, 
        (yytype_int8 const   )6,      (yytype_int8 const   )7,      (yytype_int8 const   )8,      (yytype_int8 const   )9, 
        (yytype_int8 const   )10,      (yytype_int8 const   )11,      (yytype_int8 const   )12,      (yytype_int8 const   )13, 
        (yytype_int8 const   )14,      (yytype_int8 const   )23,      (yytype_int8 const   )16,      (yytype_int8 const   )17, 
        (yytype_int8 const   )18,      (yytype_int8 const   )19,      (yytype_int8 const   )20,      (yytype_int8 const   )21, 
        (yytype_int8 const   )22,      (yytype_int8 const   )96,      (yytype_int8 const   )24,      (yytype_int8 const   )5, 
        (yytype_int8 const   )6,      (yytype_int8 const   )7,      (yytype_int8 const   )8,      (yytype_int8 const   )9, 
        (yytype_int8 const   )10,      (yytype_int8 const   )0,      (yytype_int8 const   )12,      (yytype_int8 const   )5, 
        (yytype_int8 const   )6,      (yytype_int8 const   )7,      (yytype_int8 const   )8,      (yytype_int8 const   )9, 
        (yytype_int8 const   )10,      (yytype_int8 const   )25,      (yytype_int8 const   )4,      (yytype_int8 const   )27, 
        (yytype_int8 const   )26,      (yytype_int8 const   )20,      (yytype_int8 const   )30,      (yytype_int8 const   )22, 
        (yytype_int8 const   )9,      (yytype_int8 const   )9,      (yytype_int8 const   )19,      (yytype_int8 const   )24, 
        (yytype_int8 const   )3,      (yytype_int8 const   )19,      (yytype_int8 const   )26,      (yytype_int8 const   )20, 
        (yytype_int8 const   )20,      (yytype_int8 const   )20,      (yytype_int8 const   )59,      (yytype_int8 const   )27, 
        (yytype_int8 const   )84,      (yytype_int8 const   )20,      (yytype_int8 const   )20,      (yytype_int8 const   )-1, 
        (yytype_int8 const   )20,      (yytype_int8 const   )20,      (yytype_int8 const   )19,      (yytype_int8 const   )-1, 
        (yytype_int8 const   )25};
static yytype_uint8 const   yystos[114]  = 
  {      (yytype_uint8 const   )0,      (yytype_uint8 const   )23,      (yytype_uint8 const   )29,      (yytype_uint8 const   )30, 
        (yytype_uint8 const   )31,      (yytype_uint8 const   )19,      (yytype_uint8 const   )20,      (yytype_uint8 const   )21, 
        (yytype_uint8 const   )22,      (yytype_uint8 const   )48,      (yytype_uint8 const   )49,      (yytype_uint8 const   )50, 
        (yytype_uint8 const   )0,      (yytype_uint8 const   )5,      (yytype_uint8 const   )6,      (yytype_uint8 const   )7, 
        (yytype_uint8 const   )8,      (yytype_uint8 const   )9,      (yytype_uint8 const   )10,      (yytype_uint8 const   )11, 
        (yytype_uint8 const   )12,      (yytype_uint8 const   )13,      (yytype_uint8 const   )14,      (yytype_uint8 const   )16, 
        (yytype_uint8 const   )17,      (yytype_uint8 const   )18,      (yytype_uint8 const   )19,      (yytype_uint8 const   )20, 
        (yytype_uint8 const   )21,      (yytype_uint8 const   )22,      (yytype_uint8 const   )24,      (yytype_uint8 const   )32, 
        (yytype_uint8 const   )33,      (yytype_uint8 const   )34,      (yytype_uint8 const   )35,      (yytype_uint8 const   )36, 
        (yytype_uint8 const   )39,      (yytype_uint8 const   )40,      (yytype_uint8 const   )41,      (yytype_uint8 const   )42, 
        (yytype_uint8 const   )43,      (yytype_uint8 const   )44,      (yytype_uint8 const   )45,      (yytype_uint8 const   )46, 
        (yytype_uint8 const   )47,      (yytype_uint8 const   )51,      (yytype_uint8 const   )52,      (yytype_uint8 const   )26, 
        (yytype_uint8 const   )4,      (yytype_uint8 const   )19,      (yytype_uint8 const   )20,      (yytype_uint8 const   )5, 
        (yytype_uint8 const   )6,      (yytype_uint8 const   )7,      (yytype_uint8 const   )8,      (yytype_uint8 const   )9, 
        (yytype_uint8 const   )10,      (yytype_uint8 const   )12,      (yytype_uint8 const   )4,      (yytype_uint8 const   )19, 
        (yytype_uint8 const   )46,      (yytype_uint8 const   )5,      (yytype_uint8 const   )6,      (yytype_uint8 const   )7, 
        (yytype_uint8 const   )8,      (yytype_uint8 const   )9,      (yytype_uint8 const   )10,      (yytype_uint8 const   )5, 
        (yytype_uint8 const   )6,      (yytype_uint8 const   )7,      (yytype_uint8 const   )8,      (yytype_uint8 const   )9, 
        (yytype_uint8 const   )10,      (yytype_uint8 const   )12,      (yytype_uint8 const   )15,      (yytype_uint8 const   )16, 
        (yytype_uint8 const   )19,      (yytype_uint8 const   )25,      (yytype_uint8 const   )27,      (yytype_uint8 const   )38, 
        (yytype_uint8 const   )46,      (yytype_uint8 const   )9,      (yytype_uint8 const   )9,      (yytype_uint8 const   )46, 
        (yytype_uint8 const   )24,      (yytype_uint8 const   )3,      (yytype_uint8 const   )19,      (yytype_uint8 const   )26, 
        (yytype_uint8 const   )25,      (yytype_uint8 const   )53,      (yytype_uint8 const   )19,      (yytype_uint8 const   )20, 
        (yytype_uint8 const   )19,      (yytype_uint8 const   )53,      (yytype_uint8 const   )20,      (yytype_uint8 const   )20, 
        (yytype_uint8 const   )20,      (yytype_uint8 const   )36,      (yytype_uint8 const   )20,      (yytype_uint8 const   )20, 
        (yytype_uint8 const   )15,      (yytype_uint8 const   )19,      (yytype_uint8 const   )25,      (yytype_uint8 const   )37, 
        (yytype_uint8 const   )38,      (yytype_uint8 const   )27,      (yytype_uint8 const   )25,      (yytype_uint8 const   )50, 
        (yytype_uint8 const   )20,      (yytype_uint8 const   )20,      (yytype_uint8 const   )15,      (yytype_uint8 const   )37, 
        (yytype_uint8 const   )25,      (yytype_uint8 const   )50};
static yytype_uint8 const   yyr1[92]  = 
  {      (yytype_uint8 const   )0,      (yytype_uint8 const   )28,      (yytype_uint8 const   )29,      (yytype_uint8 const   )29, 
        (yytype_uint8 const   )30,      (yytype_uint8 const   )31,      (yytype_uint8 const   )31,      (yytype_uint8 const   )32, 
        (yytype_uint8 const   )32,      (yytype_uint8 const   )32,      (yytype_uint8 const   )32,      (yytype_uint8 const   )32, 
        (yytype_uint8 const   )32,      (yytype_uint8 const   )32,      (yytype_uint8 const   )32,      (yytype_uint8 const   )32, 
        (yytype_uint8 const   )33,      (yytype_uint8 const   )34,      (yytype_uint8 const   )35,      (yytype_uint8 const   )35, 
        (yytype_uint8 const   )35,      (yytype_uint8 const   )35,      (yytype_uint8 const   )36,      (yytype_uint8 const   )36, 
        (yytype_uint8 const   )36,      (yytype_uint8 const   )37,      (yytype_uint8 const   )37,      (yytype_uint8 const   )38, 
        (yytype_uint8 const   )39,      (yytype_uint8 const   )39,      (yytype_uint8 const   )40,      (yytype_uint8 const   )40, 
        (yytype_uint8 const   )40,      (yytype_uint8 const   )40,      (yytype_uint8 const   )40,      (yytype_uint8 const   )40, 
        (yytype_uint8 const   )40,      (yytype_uint8 const   )41,      (yytype_uint8 const   )41,      (yytype_uint8 const   )41, 
        (yytype_uint8 const   )41,      (yytype_uint8 const   )42,      (yytype_uint8 const   )42,      (yytype_uint8 const   )42, 
        (yytype_uint8 const   )42,      (yytype_uint8 const   )42,      (yytype_uint8 const   )42,      (yytype_uint8 const   )42, 
        (yytype_uint8 const   )42,      (yytype_uint8 const   )42,      (yytype_uint8 const   )43,      (yytype_uint8 const   )44, 
        (yytype_uint8 const   )44,      (yytype_uint8 const   )44,      (yytype_uint8 const   )45,      (yytype_uint8 const   )45, 
        (yytype_uint8 const   )45,      (yytype_uint8 const   )45,      (yytype_uint8 const   )45,      (yytype_uint8 const   )45, 
        (yytype_uint8 const   )45,      (yytype_uint8 const   )45,      (yytype_uint8 const   )45,      (yytype_uint8 const   )45, 
        (yytype_uint8 const   )45,      (yytype_uint8 const   )45,      (yytype_uint8 const   )45,      (yytype_uint8 const   )45, 
        (yytype_uint8 const   )45,      (yytype_uint8 const   )45,      (yytype_uint8 const   )45,      (yytype_uint8 const   )45, 
        (yytype_uint8 const   )45,      (yytype_uint8 const   )45,      (yytype_uint8 const   )45,      (yytype_uint8 const   )46, 
        (yytype_uint8 const   )46,      (yytype_uint8 const   )46,      (yytype_uint8 const   )46,      (yytype_uint8 const   )46, 
        (yytype_uint8 const   )46,      (yytype_uint8 const   )47,      (yytype_uint8 const   )48,      (yytype_uint8 const   )48, 
        (yytype_uint8 const   )49,      (yytype_uint8 const   )49,      (yytype_uint8 const   )50,      (yytype_uint8 const   )50, 
        (yytype_uint8 const   )51,      (yytype_uint8 const   )52,      (yytype_uint8 const   )53,      (yytype_uint8 const   )53};
static yytype_uint8 const   yyr2[92]  = 
  {      (yytype_uint8 const   )0,      (yytype_uint8 const   )2,      (yytype_uint8 const   )1,      (yytype_uint8 const   )1, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )0,      (yytype_uint8 const   )2,      (yytype_uint8 const   )1, 
        (yytype_uint8 const   )1,      (yytype_uint8 const   )1,      (yytype_uint8 const   )1,      (yytype_uint8 const   )1, 
        (yytype_uint8 const   )1,      (yytype_uint8 const   )1,      (yytype_uint8 const   )1,      (yytype_uint8 const   )1, 
        (yytype_uint8 const   )1,      (yytype_uint8 const   )3,      (yytype_uint8 const   )2,      (yytype_uint8 const   )4, 
        (yytype_uint8 const   )6,      (yytype_uint8 const   )1,      (yytype_uint8 const   )2,      (yytype_uint8 const   )4, 
        (yytype_uint8 const   )6,      (yytype_uint8 const   )0,      (yytype_uint8 const   )1,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )1,      (yytype_uint8 const   )2,      (yytype_uint8 const   )1,      (yytype_uint8 const   )1, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )3,      (yytype_uint8 const   )1, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )1,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )3,      (yytype_uint8 const   )5,      (yytype_uint8 const   )3, 
        (yytype_uint8 const   )3,      (yytype_uint8 const   )2,      (yytype_uint8 const   )4,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )3,      (yytype_uint8 const   )1,      (yytype_uint8 const   )3,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )1,      (yytype_uint8 const   )1,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )1,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )1, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )1,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )1,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )1,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )1,      (yytype_uint8 const   )1,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2,      (yytype_uint8 const   )2, 
        (yytype_uint8 const   )2,      (yytype_uint8 const   )1,      (yytype_uint8 const   )1,      (yytype_uint8 const   )1, 
        (yytype_uint8 const   )1,      (yytype_uint8 const   )1,      (yytype_uint8 const   )1,      (yytype_uint8 const   )1, 
        (yytype_uint8 const   )1,      (yytype_uint8 const   )2,      (yytype_uint8 const   )0,      (yytype_uint8 const   )2};
static table const   meridian_table[5]  = {      {"AM", 270, 0}, 
        {"A.M.", 270, 0}, 
        {"PM", 270, 1}, 
        {"P.M.", 270, 1}, 
        {(char const   *)((void *)0), 0, 0}};
static table const   dst_table[1]  = {      {"DST", 259, 0}};
static table const   month_and_day_table[25]  = 
  {      {"JANUARY", 271, 1}, 
        {"FEBRUARY", 271, 2}, 
        {"MARCH", 271, 3}, 
        {"APRIL", 271, 4}, 
        {"MAY", 271, 5}, 
        {"JUNE", 271, 6}, 
        {"JULY", 271, 7}, 
        {"AUGUST", 271, 8}, 
        {"SEPTEMBER", 271, 9}, 
        {"SEPT", 271, 9}, 
        {"OCTOBER", 271, 10}, 
        {"NOVEMBER", 271, 11}, 
        {"DECEMBER", 271, 12}, 
        {"SUNDAY", 267, 0}, 
        {"MONDAY", 267, 1}, 
        {"TUESDAY", 267, 2}, 
        {"TUES", 267, 2}, 
        {"WEDNESDAY", 267, 3}, 
        {"WEDNES", 267, 3}, 
        {"THURSDAY", 267, 4}, 
        {"THUR", 267, 4}, 
        {"THURS", 267, 4}, 
        {"FRIDAY", 267, 5}, 
        {"SATURDAY", 267, 6}, 
        {(char const   *)((void *)0), 0, 0}};
static table const   time_units_table[11]  = 
  {      {"YEAR", 260, 1}, 
        {"MONTH", 261, 1}, 
        {"FORTNIGHT", 265, 14}, 
        {"WEEK", 265, 7}, 
        {"DAY", 265, 1}, 
        {"HOUR", 262, 1}, 
        {"MINUTE", 263, 1}, 
        {"MIN", 263, 1}, 
        {"SECOND", 264, 1}, 
        {"SEC", 264, 1}, 
        {(char const   *)((void *)0), 0, 0}};
static table const   relative_time_table[21]  = 
  {      {"TOMORROW", 266, 1}, 
        {"YESTERDAY", 266, -1}, 
        {"TODAY", 266, 0}, 
        {"NOW", 266, 0}, 
        {"LAST", 272, -1}, 
        {"THIS", 272, 0}, 
        {"NEXT", 272, 1}, 
        {"FIRST", 272, 1}, 
        {"THIRD", 272, 3}, 
        {"FOURTH", 272, 4}, 
        {"FIFTH", 272, 5}, 
        {"SIXTH", 272, 6}, 
        {"SEVENTH", 272, 7}, 
        {"EIGHTH", 272, 8}, 
        {"NINTH", 272, 9}, 
        {"TENTH", 272, 10}, 
        {"ELEVENTH", 272, 11}, 
        {"TWELFTH", 272, 12}, 
        {"AGO", 258, -1}, 
        {"HENCE", 258, 1}, 
        {(char const   *)((void *)0), 0, 0}};
static table const   universal_time_zone_table[4]  = {      {"GMT", 273, 0}, 
        {"UT", 273, 0}, 
        {"UTC", 273, 0}, 
        {(char const   *)((void *)0), 0, 0}};
static table const   time_zone_table[48]  = 
  {      {"WET", 273, 0}, 
        {"WEST", 268, 0}, 
        {"BST", 268, 0}, 
        {"ART", 273, -180}, 
        {"BRT", 273, -180}, 
        {"BRST", 268, -180}, 
        {"NST", 273, -210}, 
        {"NDT", 268, -210}, 
        {"AST", 273, -240}, 
        {"ADT", 268, -240}, 
        {"CLT", 273, -240}, 
        {"CLST", 268, -240}, 
        {"EST", 273, -300}, 
        {"EDT", 268, -300}, 
        {"CST", 273, -360}, 
        {"CDT", 268, -360}, 
        {"MST", 273, -420}, 
        {"MDT", 268, -420}, 
        {"PST", 273, -480}, 
        {"PDT", 268, -480}, 
        {"AKST", 273, -540}, 
        {"AKDT", 268, -540}, 
        {"HST", 273, -600}, 
        {"HAST", 273, -600}, 
        {"HADT", 268, -600}, 
        {"SST", 273, -720}, 
        {"WAT", 273, 60}, 
        {"CET", 273, 60}, 
        {"CEST", 268, 60}, 
        {"MET", 273, 60}, 
        {"MEZ", 273, 60}, 
        {"MEST", 268, 60}, 
        {"MESZ", 268, 60}, 
        {"EET", 273, 120}, 
        {"EEST", 268, 120}, 
        {"CAT", 273, 120}, 
        {"SAST", 273, 120}, 
        {"EAT", 273, 180}, 
        {"MSK", 273, 180}, 
        {"MSD", 268, 180}, 
        {"IST", 273, 330}, 
        {"SGT", 273, 480}, 
        {"KST", 273, 540}, 
        {"JST", 273, 540}, 
        {"GST", 273, 600}, 
        {"NZST", 273, 720}, 
        {"NZDT", 268, 720}, 
        {(char const   *)((void *)0), 0, 0}};
static table const   military_table[26]  = 
  {      {"A", 273, -60}, 
        {"B", 273, -120}, 
        {"C", 273, -180}, 
        {"D", 273, -240}, 
        {"E", 273, -300}, 
        {"F", 273, -360}, 
        {"G", 273, -420}, 
        {"H", 273, -480}, 
        {"I", 273, -540}, 
        {"K", 273, -600}, 
        {"L", 273, -660}, 
        {"M", 273, -720}, 
        {"N", 273, 60}, 
        {"O", 273, 120}, 
        {"P", 273, 180}, 
        {"Q", 273, 240}, 
        {"R", 273, 300}, 
        {"S", 273, 360}, 
        {"T", 'T', 0}, 
        {"U", 273, 480}, 
        {"V", 273, 540}, 
        {"W", 273, 600}, 
        {"X", 273, 660}, 
        {"Y", 273, 720}, 
        {"Z", 273, 0}, 
        {(char const   *)((void *)0), 0, 0}};
extern DIR *( __attribute__((__nonnull__(1))) opendir)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) dirfd)(DIR *__dirp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) access)(char const   *__name ,
                                                                                             int __type ) ;
static int proc_status  =    0;
#pragma GCC diagnostic ignored "-Wtype-limits"
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __sched_cpucount)(size_t __setsize ,
                                                                                       cpu_set_t const   *__setp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) sched_getaffinity)(__pid_t __pid ,
                                                                                        size_t __cpusetsize ,
                                                                                        cpu_set_t *__cpuset ) ;
extern int nanosleep(struct timespec  const  *__requested_time , struct timespec *__remaining ) ;
extern  __attribute__((__nothrow__)) FILE *( __attribute__((__leaf__)) setmntent)(char const   *__file ,
                                                                                  char const   *__mode ) ;
extern  __attribute__((__nothrow__)) struct mntent *( __attribute__((__leaf__)) getmntent)(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) endmntent)(FILE *__stream ) ;
extern int ( __attribute__((__nonnull__(1))) mkstemp)(char *__template ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) getgroups)(int __size ,
                                                                                __gid_t *__list ) ;
extern int getgrouplist(char const   *__user , __gid_t __group , __gid_t *__groups ,
                        int *__ngroups ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) strcoll)(char const   *__s1 ,
                                                                                                char const   *__s2 )  __attribute__((__pure__)) ;
__inline static int strcoll_loop(char const   *s1 , size_t s1size , char const   *s2 ,
                                 size_t s2size ) 
{ 
  int diff ;
  size_t size1 ;
  size_t tmp ;
  size_t size2 ;
  size_t tmp___0 ;
  int *tmp___1 ;
  int *tmp___2 ;
  int tmp___3 ;

  {
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    {
    tmp___1 = __errno_location();
    *tmp___1 = 0;
    diff = strcoll(s1, s2);
    }
    if (diff) {
      tmp___3 = 1;
    } else {
      {
      tmp___2 = __errno_location();
      }
      if (*tmp___2) {
        tmp___3 = 1;
      } else {
        tmp___3 = 0;
      }
    }
    if (tmp___3) {
      goto while_break;
    }
    {
    tmp = strlen(s1);
    size1 = tmp + 1UL;
    tmp___0 = strlen(s2);
    size2 = tmp___0 + 1UL;
    s1 += size1;
    s2 += size2;
    s1size -= size1;
    s2size -= size2;
    }
    if (s1size == 0UL) {
      return (- (s2size != 0UL));
    }
    if (s2size == 0UL) {
      return (1);
    }
  }
  while_break: /* CIL Label */ ;
  }
  return (diff);
}
}
int memcoll(char *s1 , size_t s1len , char *s2 , size_t s2len ) 
{ 
  int diff ;
  int *tmp ;
  char n1 ;
  char n2 ;
  int tmp___0 ;

  {
  if (s1len == s2len) {
    {
    tmp___0 = memcmp((void const   *)s1, (void const   *)s2, s1len);
    }
    if (tmp___0 == 0) {
      {
      tmp = __errno_location();
      *tmp = 0;
      diff = 0;
      }
    } else {
      goto _L;
    }
  } else {
    _L: 
    {
    n1 = *(s1 + s1len);
    n2 = *(s2 + s2len);
    *(s1 + s1len) = (char )'\000';
    *(s2 + s2len) = (char )'\000';
    diff = strcoll_loop((char const   *)s1, s1len + 1UL, (char const   *)s2, s2len + 1UL);
    *(s1 + s1len) = n1;
    *(s2 + s2len) = n2;
    }
  }
  return (diff);
}
}
int memcasecmp(void const   *vs1 , void const   *vs2 , size_t n )  __attribute__((__pure__)) ;
int memcasecmp(void const   *vs1 , void const   *vs2 , size_t n )  __attribute__((__pure__)) ;
int memcasecmp(void const   *vs1 , void const   *vs2 , size_t n ) 
{ 
  size_t i ;
  char const   *s1 ;
  char const   *s2 ;
  unsigned char u1 ;
  unsigned char u2 ;
  int U1 ;
  int tmp ;
  int U2 ;
  int tmp___0 ;
  int diff ;

  {
  s1 = (char const   *)vs1;
  s2 = (char const   *)vs2;
  i = (size_t )0;
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    if (! (i < n)) {
      goto while_break;
    }
    {
    u1 = (unsigned char )*(s1 + i);
    u2 = (unsigned char )*(s2 + i);
    tmp = toupper((int )u1);
    U1 = tmp;
    tmp___0 = toupper((int )u2);
    U2 = tmp___0;
    diff = U1 - U2;
    }
    if (diff) {
      return (diff);
    }
    i ++;
  }
  while_break: /* CIL Label */ ;
  }
  return (0);
}
}
static unsigned char const   fillbuf___2[64]  = {      (unsigned char const   )128,      (unsigned char const   )0};
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) wcwidth)(wchar_t __c ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) iswcntrl)(wint_t __wc ) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1), __leaf__)) strnlen)(char const   *__string ,
                                                                                                 size_t __maxlen )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) wint_t ( __attribute__((__leaf__)) towlower)(wint_t __wc ) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) mbstowcs)(wchar_t * __restrict  __pwcs ,
                                                                                  char const   * __restrict  __s ,
                                                                                  size_t __n ) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) wcstombs)(char * __restrict  __s ,
                                                                                  wchar_t const   * __restrict  __pwcs ,
                                                                                  size_t __n ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2), __leaf__)) mempcpy)(void * __restrict  __dest ,
                                                                                                  void const   * __restrict  __src ,
                                                                                                  size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) wcswidth)(wchar_t const   *__s ,
                                                                               size_t __n ) ;
unsigned int const   is_basic_table[8]  = {      (unsigned int const   )6656,      (unsigned int const   )4294967279U,      (unsigned int const   )4294967294U,      (unsigned int const   )2147483646};
static void *mmalloca_results[257]  ;
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
extern int optind ;
extern int opterr ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) getopt_long)(int ___argc ,
                                                                                  char * const  *___argv ,
                                                                                  char const   *__shortopts ,
                                                                                  struct option  const  *__longopts ,
                                                                                  int *__longind ) ;
static struct option  const  long_options[3]  = {      {"help", 0, (int *)((void *)0), 'h'}, 
        {"version", 0, (int *)((void *)0), 'v'}, 
        {(char const   *)((void *)0), 0, (int *)((void *)0), 0}};
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutex_init)(pthread_mutex_t *__mutex ,
                                                                                                         pthread_mutexattr_t const   *__mutexattr ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_init)(pthread_mutexattr_t *__attr ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_destroy)(pthread_mutexattr_t *__attr ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_settype)(pthread_mutexattr_t *__attr ,
                                                                                                                int __kind ) ;
#pragma weak pthread_mutex_init
#pragma weak pthread_mutex_lock
#pragma weak pthread_mutex_unlock
#pragma weak pthread_mutex_destroy
#pragma weak pthread_rwlock_init
#pragma weak pthread_rwlock_rdlock
#pragma weak pthread_rwlock_wrlock
#pragma weak pthread_rwlock_unlock
#pragma weak pthread_rwlock_destroy
#pragma weak pthread_once
#pragma weak pthread_cond_init
#pragma weak pthread_cond_wait
#pragma weak pthread_cond_signal
#pragma weak pthread_cond_broadcast
#pragma weak pthread_cond_destroy
#pragma weak pthread_mutexattr_init
#pragma weak pthread_mutexattr_settype
#pragma weak pthread_mutexattr_destroy
#pragma weak pthread_self
#pragma weak pthread_cancel
static int const   fresh_once  =    (int const   )0;
extern  __attribute__((__nothrow__)) FILE *( __attribute__((__leaf__)) fdopen)(int __fd ,
                                                                               char const   *__modes ) ;
extern int fscanf(FILE * __restrict  __stream , char const   * __restrict  __format 
                  , ...) ;
extern int ungetc(int __c , FILE *__stream ) ;
static char const   * volatile  charset_aliases  ;
static char const   *get_charset_aliases(void) 
{ 
  char const   *cp ;
  char const   *dir ;
  char const   *base ;
  char *file_name___3 ;
  size_t dir_len___0 ;
  size_t tmp ;
  size_t base_len___0 ;
  size_t tmp___0 ;
  int add_slash ;
  int tmp___1 ;
  int fd ;
  FILE *fp ;
  char *res_ptr ;
  size_t res_size ;
  int c ;
  char buf1[51] ;
  char buf2[51] ;
  size_t l1 ;
  size_t l2 ;
  char *old_res_ptr ;
  int tmp___3 ;
  void *__cil_tmp26 ;
  void *__cil_tmp27 ;
  char *__cil_tmp28 ;
  char *__cil_tmp29 ;
  char *__cil_tmp30 ;
  char *__cil_tmp31 ;
  char *__cil_tmp32 ;
  char *__cil_tmp33 ;
  char *__cil_tmp34 ;
  char *__cil_tmp35 ;

  {
  cp = (char const   *)charset_aliases;
  if ((unsigned long )cp == (unsigned long )((void *)0)) {
    {
    base = "charset.alias";
    dir = (char const   *)getenv("CHARSETALIASDIR");
    }
    if ((unsigned long )dir == (unsigned long )((void *)0)) {
      dir = "/usr/local/lib";
    } else
    if ((int const   )*(dir + 0) == 0) {
      dir = "/usr/local/lib";
    }
    {
    tmp = strlen(dir);
    dir_len___0 = tmp;
    tmp___0 = strlen(base);
    base_len___0 = tmp___0;
    }
    if (dir_len___0 > 0UL) {
      if (! ((int const   )*(dir + (dir_len___0 - 1UL)) == 47)) {
        tmp___1 = 1;
      } else {
        tmp___1 = 0;
      }
    } else {
      tmp___1 = 0;
    }
    {
    add_slash = tmp___1;
    file_name___3 = (char *)malloc(((dir_len___0 + (size_t )add_slash) + base_len___0) + 1UL);
    }
    if ((unsigned long )file_name___3 != (unsigned long )((void *)0)) {
      {
      memcpy((void */* __restrict  */)file_name___3, (void const   */* __restrict  */)dir,
             dir_len___0);
      }
      if (add_slash) {
        *(file_name___3 + dir_len___0) = (char )'/';
      }
      {
      memcpy((void */* __restrict  */)((file_name___3 + dir_len___0) + add_slash),
             (void const   */* __restrict  */)base, base_len___0 + 1UL);
      }
    }
    if ((unsigned long )file_name___3 == (unsigned long )((void *)0)) {
      cp = "";
    } else {
      {
      fd = open((char const   *)file_name___3, 131072);
      }
      if (fd < 0) {
        cp = "";
      } else {
        {
        fp = fdopen(fd, "r");
        }
        if ((unsigned long )fp == (unsigned long )((void *)0)) {
          {
          close(fd);
          cp = "";
          }
        } else {
          res_ptr = (char *)((void *)0);
          res_size = (size_t )0;
          {
          while (1) {
            while_continue: /* CIL Label */ ;
            {
            c = getc_unlocked(fp);
            }
            if (c == -1) {
              goto while_break;
            }
            if (c == 10) {
              goto __Cont;
            } else
            if (c == 32) {
              goto __Cont;
            } else
            if (c == 9) {
              goto __Cont;
            }
            if (c == 35) {
              {
              while (1) {
                while_continue___0: /* CIL Label */ ;
                {
                c = getc_unlocked(fp);
                }
                if (c == -1) {
                  goto while_break___0;
                } else
                if (c == 10) {
                  goto while_break___0;
                }
              }
              while_break___0: /* CIL Label */ ;
              }
              if (c == -1) {
                goto while_break;
              }
              goto __Cont;
            }
            {
            ungetc(c, fp);
            tmp___3 = fscanf((FILE */* __restrict  */)fp, (char const   */* __restrict  */)"%50s %50s",
                             buf1, buf2);
            }
            if (tmp___3 < 2) {
              goto while_break;
            }
            {
            l1 = strlen((char const   *)(buf1));
            l2 = strlen((char const   *)(buf2));
            old_res_ptr = res_ptr;
            }
            if (res_size == 0UL) {
              {
              res_size = ((l1 + 1UL) + l2) + 1UL;
              res_ptr = (char *)malloc(res_size + 1UL);
              }
            } else {
              {
              res_size += ((l1 + 1UL) + l2) + 1UL;
              res_ptr = (char *)realloc((void *)res_ptr, res_size + 1UL);
              }
            }
            if ((unsigned long )res_ptr == (unsigned long )((void *)0)) {
              {
              res_size = (size_t )0;
              free((void *)old_res_ptr);
              }
              goto while_break;
            }
            {
            strcpy((char */* __restrict  */)(((res_ptr + res_size) - (l2 + 1UL)) - (l1 + 1UL)),
                   (char const   */* __restrict  */)(buf1));
            strcpy((char */* __restrict  */)((res_ptr + res_size) - (l2 + 1UL)), (char const   */* __restrict  */)(buf2));
            }
            __Cont: ;
          }
          while_break: /* CIL Label */ ;
          }
          {
          rpl_fclose(fp);
          }
          if (res_size == 0UL) {
            cp = "";
          } else {
            *(res_ptr + res_size) = (char )'\000';
            cp = (char const   *)res_ptr;
          }
        }
      }
      {
      free((void *)file_name___3);
      }
    }
    charset_aliases = (char const   */* volatile  */)cp;
  }
  return (cp);
}
}
char const   *locale_charset(void) 
{ 
  char const   *codeset ;
  char const   *aliases ;
  size_t tmp ;
  size_t tmp___0 ;
  size_t tmp___1 ;
  int tmp___2 ;
  char *__cil_tmp8 ;
  char *__cil_tmp9 ;

  {
  {
  codeset = (char const   *)nl_langinfo(14);
  }
  if ((unsigned long )codeset == (unsigned long )((void *)0)) {
    codeset = "";
  }
  {
  aliases = get_charset_aliases();
  }
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    if (! ((int const   )*aliases != 0)) {
      goto while_break;
    }
    {
    tmp___2 = strcmp(codeset, aliases);
    }
    if (tmp___2 == 0) {
      {
      tmp___1 = strlen(aliases);
      codeset = (aliases + tmp___1) + 1;
      }
      goto while_break;
    } else
    if ((int const   )*(aliases + 0) == 42) {
      if ((int const   )*(aliases + 1) == 0) {
        {
        tmp___1 = strlen(aliases);
        codeset = (aliases + tmp___1) + 1;
        }
        goto while_break;
      }
    }
    {
    tmp = strlen(aliases);
    aliases += tmp + 1UL;
    tmp___0 = strlen(aliases);
    aliases += tmp___0 + 1UL;
    }
  }
  while_break: /* CIL Label */ ;
  }
  if ((int const   )*(codeset + 0) == 0) {
    codeset = "ASCII";
  }
  return (codeset);
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2,4), __leaf__)) linkat)(int __fromfd ,
                                                                                               char const   *__from ,
                                                                                               int __tofd ,
                                                                                               char const   *__to ,
                                                                                               int __flags ) ;
static int have_follow_really  ;
void initbuffer(struct linebuffer *linebuffer ) ;
struct linebuffer *readlinebuffer_delim(struct linebuffer *linebuffer , FILE *stream ,
                                        char delimiter ) ;
void initbuffer(struct linebuffer *linebuffer ) 
{ 


  {
  {
  memset((void *)linebuffer, 0, sizeof(*linebuffer));
  }
  return;
}
}
struct linebuffer *readlinebuffer_delim(struct linebuffer *linebuffer , FILE *stream ,
                                        char delimiter ) 
{ 
  int c ;
  char *buffer ;
  char *p ;
  char *end ;
  int tmp ;
  int tmp___0 ;
  size_t oldsize ;
  char *tmp___1 ;

  {
  {
  buffer = linebuffer->buffer;
  p = linebuffer->buffer;
  end = buffer + linebuffer->size;
  tmp = feof_unlocked(stream);
  }
  if (tmp) {
    return ((struct linebuffer *)((void *)0));
  }
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    {
    c = getc_unlocked(stream);
    }
    if (c == -1) {
      if ((unsigned long )p == (unsigned long )buffer) {
        return ((struct linebuffer *)((void *)0));
      } else {
        {
        tmp___0 = ferror_unlocked(stream);
        }
        if (tmp___0) {
          return ((struct linebuffer *)((void *)0));
        }
      }
      if ((int )*(p + -1) == (int )delimiter) {
        goto while_break;
      }
      c = (int )delimiter;
    }
    if ((unsigned long )p == (unsigned long )end) {
      {
      oldsize = linebuffer->size;
      buffer = (char *)x2realloc((void *)buffer, & linebuffer->size);
      p = buffer + oldsize;
      linebuffer->buffer = buffer;
      end = buffer + linebuffer->size;
      }
    }
    tmp___1 = p;
    p ++;
    *tmp___1 = (char )c;
    if (! (c != (int )delimiter)) {
      goto while_break;
    }
  }
  while_break: /* CIL Label */ ;
  }
  linebuffer->length = (size_t )(p - buffer);
  return (linebuffer);
}
}
extern  __attribute__((__nothrow__)) long double ( __attribute__((__nonnull__(1),
__leaf__)) strtold)(char const   * __restrict  __nptr , char ** __restrict  __endptr ) ;
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
extern struct passwd *getpwuid(__uid_t __uid ) ;
static struct userid *user_alist  ;
static struct userid *nouser_alist  ;
static struct userid *group_alist  ;
static struct userid *nogroup_alist  ;
extern  __attribute__((__nothrow__)) struct lconv *( __attribute__((__leaf__)) localeconv)(void) ;
static char const   power_letter[9]  = 
  {      (char const   )0,      (char const   )'K',      (char const   )'M',      (char const   )'G', 
        (char const   )'T',      (char const   )'P',      (char const   )'E',      (char const   )'Z', 
        (char const   )'Y'};
static char const   * const  block_size_args[3]  = {      (char const   */* const  */)"human-readable",      (char const   */* const  */)"si",      (char const   */* const  */)0};
static int const   block_size_opts[2]  = {      (int const   )176,      (int const   )144};
static struct hash_tuning  const  default_tuning  =    {0.0f, 1.0f, 0.8f, 1.414f, (_Bool)0};
_Bool hard_locale(int category ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) setlocale)(int __category ,
                                                                                  char const   *__locale ) ;
_Bool hard_locale(int category ) 
{ 
  _Bool hard ;
  char const   *p ;
  char const   *tmp ;
  int tmp___0 ;
  int tmp___1 ;
  char *locale ;
  char *tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;

  {
  {
  hard = (_Bool)1;
  tmp = (char const   *)setlocale(category, (char const   *)((void *)0));
  p = tmp;
  }
  if (p) {
    if (1) {
      {
      tmp___0 = strcmp(p, "C");
      }
      if (tmp___0 == 0) {
        hard = (_Bool)0;
      } else {
        {
        tmp___1 = strcmp(p, "POSIX");
        }
        if (tmp___1 == 0) {
          hard = (_Bool)0;
        }
      }
    } else {
      {
      tmp___2 = strdup(p);
      locale = tmp___2;
      }
      if (locale) {
        {
        p = (char const   *)setlocale(category, "C");
        }
        if (p) {
          {
          tmp___3 = strcmp(p, (char const   *)locale);
          }
          if (tmp___3 == 0) {
            hard = (_Bool)0;
          } else {
            goto _L;
          }
        } else {
          _L: 
          {
          p = (char const   *)setlocale(category, "POSIX");
          }
          if (p) {
            {
            tmp___4 = strcmp(p, (char const   *)locale);
            }
            if (tmp___4 == 0) {
              hard = (_Bool)0;
            }
          }
        }
        {
        setlocale(category, (char const   *)locale);
        free((void *)locale);
        }
      }
    }
  }
  return (hard);
}
}
extern void setgrent(void) ;
extern struct group *getgrent(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) clock_gettime)(clockid_t __clock_id ,
                                                                                    struct timespec *__tp ) ;
extern int fflush_unlocked(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __fsetlocking)(FILE *__fp ,
                                                                                    int __type ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) tcgetattr)(int __fd ,
                                                                                struct termios *__termios_p ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) tcsetattr)(int __fd ,
                                                                                int __optional_actions ,
                                                                                struct termios  const  *__termios_p ) ;
static char *buf  ;
static size_t bufsize  ;
extern void ( __attribute__((__nonnull__(1,4))) qsort)(void *__base , size_t __nmemb ,
                                                       size_t __size , int (*__compar)(void const   * ,
                                                                                       void const   * ) ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2), __leaf__)) fstatfs)(int __fildes ,
                                                                                              struct statfs *__buf ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__nonnull__(1), __leaf__)) strtof)(char const   * __restrict  __nptr ,
                                                                                               char ** __restrict  __endptr ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) statfs)(char const   *__file ,
                                                                                               struct statfs *__buf ) ;
extern int fseeko(FILE *__stream , __off_t __off , int __whence ) ;
extern  __attribute__((__nothrow__)) __off_t ( __attribute__((__leaf__)) lseek)(int __fd ,
                                                                                __off_t __offset ,
                                                                                int __whence ) ;
int ( __attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp , off_t offset , int whence ) 
{ 
  off_t pos ;
  int tmp ;
  off_t tmp___0 ;
  int tmp___1 ;

  {
  if ((unsigned long )fp->_IO_read_end == (unsigned long )fp->_IO_read_ptr) {
    if ((unsigned long )fp->_IO_write_ptr == (unsigned long )fp->_IO_write_base) {
      if ((unsigned long )fp->_IO_save_base == (unsigned long )((void *)0)) {
        {
        tmp = fileno(fp);
        tmp___0 = lseek(tmp, offset, whence);
        pos = tmp___0;
        }
        if (pos == -1L) {
          return (-1);
        }
        fp->_flags &= -17;
        fp->_offset = pos;
        return (0);
      }
    }
  }
  {
  tmp___1 = fseeko(fp, offset, whence);
  }
  return (tmp___1);
}
}
extern FILE *freopen(char const   * __restrict  __filename , char const   * __restrict  __modes ,
                     FILE * __restrict  __stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) dup2)(int __fd ,
                                                                           int __fd2 ) ;
static _Bool protect_fd(int fd ) 
{ 
  int value ;
  int tmp ;
  int *tmp___0 ;

  {
  {
  tmp = open("/dev/null", 0);
  value = tmp;
  }
  if (value != fd) {
    if (0 <= value) {
      {
      close(value);
      tmp___0 = __errno_location();
      *tmp___0 = 9;
      }
    }
    return ((_Bool)0);
  }
  return ((_Bool)1);
}
}
FILE *freopen_safer(char const   *name , char const   *mode , FILE *f ) 
{ 
  _Bool protect_in ;
  _Bool protect_out ;
  _Bool protect_err ;
  int saved_errno ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  _Bool tmp___3 ;
  _Bool tmp___4 ;
  _Bool tmp___5 ;
  int *tmp___6 ;
  int *tmp___7 ;

  {
  {
  protect_in = (_Bool)0;
  protect_out = (_Bool)0;
  protect_err = (_Bool)0;
  tmp = fileno(f);
  }
  {
  if (tmp == 2) {
    goto case_2;
  }
  if (tmp == 1) {
    goto case_1;
  }
  if (tmp == 0) {
    goto case_0;
  }
  goto switch_default;
  switch_default: /* CIL Label */ 
  {
  tmp___0 = dup2(2, 2);
  }
  if (tmp___0 != 2) {
    protect_err = (_Bool)1;
  }
  case_2: /* CIL Label */ 
  {
  tmp___1 = dup2(1, 1);
  }
  if (tmp___1 != 1) {
    protect_out = (_Bool)1;
  }
  case_1: /* CIL Label */ 
  {
  tmp___2 = dup2(0, 0);
  }
  if (tmp___2 != 0) {
    protect_in = (_Bool)1;
  }
  case_0: /* CIL Label */ 
  goto switch_break;
  switch_break: /* CIL Label */ ;
  }
  if (protect_in) {
    {
    tmp___5 = protect_fd(0);
    }
    if (tmp___5) {
      goto _L___0;
    } else {
      f = (FILE *)((void *)0);
    }
  } else
  _L___0: 
  if (protect_out) {
    {
    tmp___4 = protect_fd(1);
    }
    if (tmp___4) {
      goto _L;
    } else {
      f = (FILE *)((void *)0);
    }
  } else
  _L: 
  if (protect_err) {
    {
    tmp___3 = protect_fd(2);
    }
    if (tmp___3) {
      {
      f = freopen((char const   */* __restrict  */)name, (char const   */* __restrict  */)mode,
                  (FILE */* __restrict  */)f);
      }
    } else {
      f = (FILE *)((void *)0);
    }
  } else {
    {
    f = freopen((char const   */* __restrict  */)name, (char const   */* __restrict  */)mode,
                (FILE */* __restrict  */)f);
    }
  }
  {
  tmp___6 = __errno_location();
  saved_errno = *tmp___6;
  }
  if (protect_err) {
    {
    close(2);
    }
  }
  if (protect_out) {
    {
    close(1);
    }
  }
  if (protect_in) {
    {
    close(0);
    }
  }
  if (! f) {
    {
    tmp___7 = __errno_location();
    *tmp___7 = saved_errno;
    }
  }
  return (f);
}
}
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) __fpurge)(FILE *__fp ) ;
extern int fputc(int __c , FILE *__stream ) ;
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
extern int fflush(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __freading)(FILE *__fp ) ;
__inline static void clear_ungetc_buffer_preserving_position(FILE *fp ) 
{ 


  {
  if (fp->_flags & 256) {
    {
    rpl_fseeko(fp, (off_t )0, 1);
    }
  }
  return;
}
}
int rpl_fflush(FILE *stream ) 
{ 
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
  if ((unsigned long )stream == (unsigned long )((void *)0)) {
    {
    tmp = fflush(stream);
    }
    return (tmp);
  } else {
    {
    tmp___0 = __freading(stream);
    }
    if (! (tmp___0 != 0)) {
      {
      tmp = fflush(stream);
      }
      return (tmp);
    }
  }
  {
  clear_ungetc_buffer_preserving_position(stream);
  tmp___1 = fflush(stream);
  }
  return (tmp___1);
}
}
extern int fcntl(int __fd , int __cmd  , ...) ;
static int have_dupfd_cloexec  =    0;
extern int fclose(FILE *__stream ) ;
int ( __attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp ) 
{ 
  int saved_errno ;
  int fd ;
  int result ;
  int tmp ;
  int *tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  __off_t tmp___3 ;
  int tmp___4 ;
  int *tmp___5 ;

  {
  {
  saved_errno = 0;
  result = 0;
  fd = fileno(fp);
  }
  if (fd < 0) {
    {
    tmp = fclose(fp);
    }
    return (tmp);
  }
  {
  tmp___1 = __freading(fp);
  }
  if (tmp___1 != 0) {
    {
    tmp___2 = fileno(fp);
    tmp___3 = lseek(tmp___2, (__off_t )0, 1);
    }
    if (tmp___3 != -1L) {
      _L: 
      {
      tmp___4 = rpl_fflush(fp);
      }
      if (tmp___4) {
        {
        tmp___0 = __errno_location();
        saved_errno = *tmp___0;
        }
      }
    }
  } else {
    goto _L;
  }
  {
  result = fclose(fp);
  }
  if (saved_errno != 0) {
    {
    tmp___5 = __errno_location();
    *tmp___5 = saved_errno;
    result = -1;
    }
  }
  return (result);
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) sigemptyset)(sigset_t *__set ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) sigaddset)(sigset_t *__set ,
                                                                                                int __signo ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) sigaction)(int __sig ,
                                                                                struct sigaction  const  * __restrict  __act ,
                                                                                struct sigaction * __restrict  __oact ) ;
static int fatal_signals[7]  = {      2,      15,      1,      13, 
        24,      25,      0};
static _Bool fatal_signals_initialized  =    (_Bool)0;
static actions_entry_t static_actions[32]  ;
static actions_entry_t * volatile  actions  =    (actions_entry_t */* volatile  */)(static_actions);
static int volatile   actions_count  =    (int volatile   )0;
static size_t actions_allocated  =    sizeof(static_actions) / sizeof(static_actions[0]);
static struct sigaction saved_sigactions[64]  ;
static _Bool cleanup_initialized  =    (_Bool)0;
static sigset_t fatal_signal_set  ;
static _Bool fatal_signal_set_initialized  =    (_Bool)0;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) posix_fadvise)(int __fd ,
                                                                                    off_t __offset ,
                                                                                    off_t __len ,
                                                                                    int __advise ) ;
void fdadvise(int fd , off_t offset , off_t len , fadvice_t advice ) ;
void fadvise(FILE *fp , fadvice_t advice ) ;
void fdadvise(int fd , off_t offset , off_t len , fadvice_t advice ) 
{ 
  int __x ;
  int tmp ;

  {
  {
  tmp = posix_fadvise(fd, offset, len, (int )advice);
  __x = tmp;
  }
  return;
}
}
void fadvise(FILE *fp , fadvice_t advice ) 
{ 
  int tmp ;

  {
  if (fp) {
    {
    tmp = fileno(fp);
    fdadvise(tmp, (off_t )0, (off_t )0, advice);
    }
  }
  return;
}
}
int volatile   exit_failure  =    (int volatile   )1;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1,2), __leaf__)) strcspn)(char const   *__s ,
                                                                                                   char const   *__reject )  __attribute__((__pure__)) ;
extern int fnmatch(char const   *__pattern , char const   *__name , int __flags ) ;
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
#pragma GCC diagnostic ignored "-Wsuggest-attribute=pure"
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma weak pthread_mutex_init
#pragma weak pthread_mutex_lock
#pragma weak pthread_mutex_unlock
#pragma weak pthread_mutex_destroy
#pragma weak pthread_rwlock_init
#pragma weak pthread_rwlock_rdlock
#pragma weak pthread_rwlock_wrlock
#pragma weak pthread_rwlock_unlock
#pragma weak pthread_rwlock_destroy
#pragma weak pthread_once
#pragma weak pthread_cond_init
#pragma weak pthread_cond_wait
#pragma weak pthread_cond_signal
#pragma weak pthread_cond_broadcast
#pragma weak pthread_cond_destroy
#pragma weak pthread_mutexattr_init
#pragma weak pthread_mutexattr_settype
#pragma weak pthread_mutexattr_destroy
#pragma weak pthread_self
#pragma weak pthread_cancel
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
char const   *Version  =    "8.16";
extern char *optarg ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) textdomain)(char const   *__domainname ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) bindtextdomain)(char const   *__domainname ,
                                                                                       char const   *__dirname ) ;
extern int putchar_unlocked(int __c ) ;
extern size_t fwrite_unlocked(void const   * __restrict  __ptr , size_t __size , size_t __n ,
                              FILE * __restrict  __stream ) ;
__inline static void emit_ancillary_info(void) 
{ 
  char *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  char const   *lc_messages ;
  char const   *tmp___3 ;
  char *tmp___4 ;
  char *tmp___5 ;
  int tmp___6 ;
  char *tmp___7 ;
  char *tmp___8 ;
  char *__cil_tmp13 ;
  char *__cil_tmp14 ;
  char *__cil_tmp15 ;
  char *__cil_tmp16 ;
  char *__cil_tmp17 ;

  {
  {
  tmp = last_component(program_name);
  tmp___0 = gettext("\nReport %s bugs to %s\n");
  printf((char const   */* __restrict  */)tmp___0, tmp, "bug-coreutils@gnu.org");
  tmp___1 = gettext("%s home page: <%s>\n");
  printf((char const   */* __restrict  */)tmp___1, "GNU coreutils", "http://www.gnu.org/software/coreutils/");
  tmp___2 = gettext("General help using GNU software: <http://www.gnu.org/gethelp/>\n");
  fputs_unlocked((char const   */* __restrict  */)tmp___2, (FILE */* __restrict  */)stdout);
  tmp___3 = (char const   *)setlocale(5, (char const   *)((void *)0));
  lc_messages = tmp___3;
  }
  if (lc_messages) {
    {
    tmp___6 = strncmp(lc_messages, "en_", sizeof("en_") - 1UL);
    }
    if (tmp___6) {
      {
      tmp___4 = last_component(program_name);
      tmp___5 = gettext("Report %s translation bugs to <http://translationproject.org/team/>\n");
      printf((char const   */* __restrict  */)tmp___5, tmp___4);
      }
    }
  }
  {
  tmp___7 = last_component(program_name);
  tmp___8 = gettext("For complete documentation, run: info coreutils \'%s invocation\'\n");
  printf((char const   */* __restrict  */)tmp___8, tmp___7);
  }
  return;
}
}
__inline static void emit_try_help(void) 
{ 
  char *tmp ;
  char *__cil_tmp2 ;

  {
  {
  tmp = gettext("Try \'%s --help\' for more information.\n");
  fprintf((FILE */* __restrict  */)stderr, (char const   */* __restrict  */)tmp, program_name);
  }
  return;
}
}
static _Bool hard_LC_COLLATE  ;
static size_t skip_fields  ;
static size_t skip_chars  ;
static size_t check_chars  ;
static enum countmode countmode  ;
static _Bool output_unique  ;
static _Bool output_first_repeated  ;
static _Bool output_later_repeated  ;
static _Bool ignore_case  ;
static char const   * const  delimit_method_string[4]  = {      (char const   */* const  */)"none",      (char const   */* const  */)"prepend",      (char const   */* const  */)"separate",      (char const   */* const  */)((void *)0)};
static enum delimit_method  const  delimit_method_map[3]  = {      (enum delimit_method  const  )0,      (enum delimit_method  const  )1,      (enum delimit_method  const  )2};
static enum delimit_method delimit_groups  ;
static struct option  const  longopts[12]  = 
  {      {"count", 0, (int *)((void *)0), 'c'}, 
        {"repeated", 0, (int *)((void *)0), 'd'}, 
        {"all-repeated", 2, (int *)((void *)0), 'D'}, 
        {"ignore-case", 0, (int *)((void *)0), 'i'}, 
        {"unique", 0, (int *)((void *)0), 'u'}, 
        {"skip-fields", 1, (int *)((void *)0), 'f'}, 
        {"skip-chars", 1, (int *)((void *)0), 's'}, 
        {"check-chars", 1, (int *)((void *)0), 'w'}, 
        {"zero-terminated", 0, (int *)((void *)0), 'z'}, 
        {"help", 0, (int *)((void *)0), -130}, 
        {"version", 0, (int *)((void *)0), -131}, 
        {(char const   *)((void *)0), 0, (int *)((void *)0), 0}};
 __attribute__((__noreturn__)) void usage(int status ) ;
void usage(int status ) 
{ 
  char *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  char *tmp___3 ;
  char *tmp___4 ;
  char *tmp___5 ;
  char *tmp___6 ;
  char *tmp___7 ;
  char *tmp___8 ;
  char *__cil_tmp12 ;
  char *__cil_tmp13 ;
  char *__cil_tmp14 ;
  char *__cil_tmp15 ;
  char *__cil_tmp16 ;
  char *__cil_tmp17 ;
  char *__cil_tmp18 ;
  char *__cil_tmp19 ;
  char *__cil_tmp20 ;
  char *__cil_tmp21 ;

  {
  if (status != 0) {
    {
    emit_try_help();
    }
  } else {
    {
    tmp = gettext("Usage: %s [OPTION]... [INPUT [OUTPUT]]\n");
    printf((char const   */* __restrict  */)tmp, program_name);
    tmp___0 = gettext("Filter adjacent matching lines from INPUT (or standard input),\nwriting to OUTPUT (or standard output).\n\nWith no options, matching lines are merged to the first occurrence.\n\n");
    fputs_unlocked((char const   */* __restrict  */)tmp___0, (FILE */* __restrict  */)stdout);
    tmp___1 = gettext("Mandatory arguments to long options are mandatory for short options too.\n");
    fputs_unlocked((char const   */* __restrict  */)tmp___1, (FILE */* __restrict  */)stdout);
    tmp___2 = gettext("  -c, --count           prefix lines by the number of occurrences\n  -d, --repeated        only print duplicate lines\n");
    fputs_unlocked((char const   */* __restrict  */)tmp___2, (FILE */* __restrict  */)stdout);
    tmp___3 = gettext("  -D, --all-repeated[=delimit-method]  print all duplicate lines\n                        delimit-method={none(default),prepend,separate}\n                        Delimiting is done with blank lines\n  -f, --skip-fields=N   avoid comparing the first N fields\n  -i, --ignore-case     ignore differences in case when comparing\n  -s, --skip-chars=N    avoid comparing the first N characters\n  -u, --unique          only print unique lines\n  -z, --zero-terminated  end lines with 0 byte, not newline\n");
    fputs_unlocked((char const   */* __restrict  */)tmp___3, (FILE */* __restrict  */)stdout);
    tmp___4 = gettext("  -w, --check-chars=N   compare no more than N characters in lines\n");
    fputs_unlocked((char const   */* __restrict  */)tmp___4, (FILE */* __restrict  */)stdout);
    tmp___5 = gettext("      --help     display this help and exit\n");
    fputs_unlocked((char const   */* __restrict  */)tmp___5, (FILE */* __restrict  */)stdout);
    tmp___6 = gettext("      --version  output version information and exit\n");
    fputs_unlocked((char const   */* __restrict  */)tmp___6, (FILE */* __restrict  */)stdout);
    tmp___7 = gettext("\nA field is a run of blanks (usually spaces and/or TABs), then non-blank\ncharacters.  Fields are skipped before chars.\n");
    fputs_unlocked((char const   */* __restrict  */)tmp___7, (FILE */* __restrict  */)stdout);
    tmp___8 = gettext("\nNote: \'uniq\' does not detect repeated lines unless they are adjacent.\nYou may want to sort the input first, or use \'sort -u\' without \'uniq\'.\nAlso, comparisons honor the rules specified by \'LC_COLLATE\'.\n");
    fputs_unlocked((char const   */* __restrict  */)tmp___8, (FILE */* __restrict  */)stdout);
    emit_ancillary_info();
    }
  }
  {
  exit(status);
  }
}
}
static size_t size_opt(char const   *opt , char const   *msgid ) 
{ 
  unsigned long size ;
  strtol_error tmp ;
  char *tmp___0 ;
  unsigned long tmp___1 ;
  char *__cil_tmp7 ;

  {
  {
  tmp = xstrtoul(opt, (char **)((void *)0), 10, & size, "");
  }
  {
  if ((unsigned int )tmp == 0U) {
    goto case_0;
  }
  if ((unsigned int )tmp == 1U) {
    goto case_0;
  }
  goto switch_default;
  case_0: /* CIL Label */ 
  case_1: /* CIL Label */ 
  goto switch_break;
  switch_default: /* CIL Label */ 
  {
  tmp___0 = gettext(msgid);
  error(1, 0, "%s: %s", opt, tmp___0);
  }
  switch_break: /* CIL Label */ ;
  }
  if (size < 0xffffffffffffffffUL) {
    tmp___1 = size;
  } else {
    tmp___1 = 0xffffffffffffffffUL;
  }
  return (tmp___1);
}
}
static char * __attribute__((__pure__)) find_field(struct linebuffer  const  *line ) 
{ 
  size_t count ;
  char const   *lp ;
  size_t size ;
  size_t i ;
  unsigned short const   **tmp ;
  unsigned char tmp___0 ;
  unsigned short const   **tmp___1 ;
  unsigned char tmp___2 ;
  size_t tmp___3 ;

  {
  lp = (char const   *)line->buffer;
  size = (size_t )(line->length - 1UL);
  i = (size_t )0;
  count = (size_t )0;
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    if (count < skip_fields) {
      if (! (i < size)) {
        goto while_break;
      }
    } else {
      goto while_break;
    }
    {
    while (1) {
      while_continue___0: /* CIL Label */ ;
      if (i < size) {
        {
        tmp = __ctype_b_loc();
        tmp___0 = to_uchar((char )*(lp + i));
        }
        if (! ((int const   )*(*tmp + (int )tmp___0) & 1)) {
          goto while_break___0;
        }
      } else {
        goto while_break___0;
      }
      i ++;
    }
    while_break___0: /* CIL Label */ ;
    }
    {
    while (1) {
      while_continue___1: /* CIL Label */ ;
      if (i < size) {
        {
        tmp___1 = __ctype_b_loc();
        tmp___2 = to_uchar((char )*(lp + i));
        }
        if ((int const   )*(*tmp___1 + (int )tmp___2) & 1) {
          goto while_break___1;
        }
      } else {
        goto while_break___1;
      }
      i ++;
    }
    while_break___1: /* CIL Label */ ;
    }
    count ++;
  }
  while_break: /* CIL Label */ ;
  }
  if (skip_chars < size - i) {
    tmp___3 = skip_chars;
  } else {
    tmp___3 = size - i;
  }
  i += tmp___3;
  return ((char */* __attribute__((__pure__)) */)(line->buffer + i));
}
}
static _Bool different(char *old , char *new , size_t oldlen , size_t newlen ) 
{ 
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;

  {
  if (check_chars < oldlen) {
    oldlen = check_chars;
  }
  if (check_chars < newlen) {
    newlen = check_chars;
  }
  if (ignore_case) {
    if (oldlen != newlen) {
      tmp___0 = 1;
    } else {
      {
      tmp = memcasecmp((void const   *)old, (void const   *)new, oldlen);
      }
      if (tmp) {
        tmp___0 = 1;
      } else {
        tmp___0 = 0;
      }
    }
    return ((_Bool )tmp___0);
  } else
  if (hard_LC_COLLATE) {
    {
    tmp___1 = xmemcoll(old, oldlen, new, newlen);
    }
    return ((_Bool )(tmp___1 != 0));
  } else {
    if (oldlen != newlen) {
      tmp___3 = 1;
    } else {
      {
      tmp___2 = memcmp((void const   *)old, (void const   *)new, oldlen);
      }
      if (tmp___2) {
        tmp___3 = 1;
      } else {
        tmp___3 = 0;
      }
    }
    return ((_Bool )tmp___3);
  }
}
}
static void writeline(struct linebuffer  const  *line , _Bool match , uintmax_t linecount ) 
{ 
  int tmp ;
  int tmp___0 ;

  {
  if (linecount == 0UL) {
    tmp___0 = (int )output_unique;
  } else {
    if (! match) {
      tmp = (int )output_first_repeated;
    } else {
      tmp = (int )output_later_repeated;
    }
    tmp___0 = tmp;
  }
  if (! tmp___0) {
    return;
  }
  if ((unsigned int )countmode == 0U) {
    {
    printf((char const   */* __restrict  */)"%7lu ", linecount + 1UL);
    }
  }
  {
  fwrite_unlocked((void const   */* __restrict  */)line->buffer, sizeof(char ), (size_t )line->length,
                  (FILE */* __restrict  */)stdout);
  }
  return;
}
}
static void check_file(char const   *infile , char const   *outfile , char delimiter ) 
{ 
  struct linebuffer lb1 ;
  struct linebuffer lb2 ;
  struct linebuffer *thisline ;
  struct linebuffer *prevline ;
  int *tmp ;
  int tmp___0 ;
  FILE *tmp___1 ;
  int *tmp___2 ;
  int tmp___3 ;
  FILE *tmp___4 ;
  char *prevfield ;
  size_t prevlen ;
  char *thisfield ;
  size_t thislen ;
  struct linebuffer *tmp___5 ;
  struct linebuffer *_tmp ;
  _Bool tmp___6 ;
  int tmp___7 ;
  char *prevfield___0 ;
  size_t prevlen___0 ;
  uintmax_t match_count ;
  _Bool first_delimiter ;
  struct linebuffer *tmp___8 ;
  _Bool match ;
  char *thisfield___0 ;
  size_t thislen___0 ;
  int tmp___9 ;
  struct linebuffer *tmp___10 ;
  _Bool tmp___11 ;
  int tmp___12 ;
  struct linebuffer *_tmp___0 ;
  int tmp___14 ;
  char *tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  char *__cil_tmp42 ;
  char *__cil_tmp43 ;
  char *__cil_tmp44 ;
  char *__cil_tmp45 ;

  {
  {
  tmp___0 = strcmp(infile, "-");
  }
  if (! (tmp___0 == 0)) {
    {
    tmp___1 = freopen_safer(infile, "r", stdin);
    }
    if (! tmp___1) {
      {
      tmp = __errno_location();
      error(1, *tmp, "%s", infile);
      }
    }
  }
  {
  tmp___3 = strcmp(outfile, "-");
  }
  if (! (tmp___3 == 0)) {
    {
    tmp___4 = freopen_safer(outfile, "w", stdout);
    }
    if (! tmp___4) {
      {
      tmp___2 = __errno_location();
      error(1, *tmp___2, "%s", outfile);
      }
    }
  }
  {
  fadvise(stdin, (fadvice_t )2);
  thisline = & lb1;
  prevline = & lb2;
  initbuffer(thisline);
  initbuffer(prevline);
  }
  if (output_unique) {
    if (output_first_repeated) {
      if ((unsigned int )countmode == 1U) {
        {
        while (1) {
          while_continue: /* CIL Label */ ;
          {
          tmp___7 = feof_unlocked(stdin);
          }
          if (tmp___7) {
            goto while_break;
          }
          {
          tmp___5 = readlinebuffer_delim(thisline, stdin, delimiter);
          }
          if ((unsigned long )tmp___5 == (unsigned long )((struct linebuffer *)0)) {
            goto while_break;
          }
          {
          thisfield = (char *)find_field((struct linebuffer  const  *)thisline);
          thislen = (thisline->length - 1UL) - (size_t )(thisfield - thisline->buffer);
          }
          if (prevline->length == 0UL) {
            goto _L;
          } else {
            {
            tmp___6 = different(thisfield, prevfield, thislen, prevlen);
            }
            if (tmp___6) {
              _L: 
              {
              fwrite_unlocked((void const   */* __restrict  */)thisline->buffer, sizeof(char ),
                              thisline->length, (FILE */* __restrict  */)stdout);
              }
              {
              while (1) {
                while_continue___0: /* CIL Label */ ;
                _tmp = prevline;
                prevline = thisline;
                thisline = _tmp;
                goto while_break___0;
              }
              while_break___0: /* CIL Label */ ;
              }
              prevfield = thisfield;
              prevlen = thislen;
            }
          }
        }
        while_break: /* CIL Label */ ;
        }
      } else {
        goto _L___2;
      }
    } else {
      goto _L___2;
    }
  } else {
    _L___2: 
    {
    match_count = (uintmax_t )0;
    first_delimiter = (_Bool)1;
    tmp___8 = readlinebuffer_delim(prevline, stdin, delimiter);
    }
    if ((unsigned long )tmp___8 == (unsigned long )((struct linebuffer *)0)) {
      goto closefiles;
    }
    {
    prevfield___0 = (char *)find_field((struct linebuffer  const  *)prevline);
    prevlen___0 = (prevline->length - 1UL) - (size_t )(prevfield___0 - prevline->buffer);
    }
    {
    while (1) {
      while_continue___1: /* CIL Label */ ;
      {
      tmp___14 = feof_unlocked(stdin);
      }
      if (tmp___14) {
        goto while_break___1;
      }
      {
      tmp___10 = readlinebuffer_delim(thisline, stdin, delimiter);
      }
      if ((unsigned long )tmp___10 == (unsigned long )((struct linebuffer *)0)) {
        {
        tmp___9 = ferror_unlocked(stdin);
        }
        if (tmp___9) {
          goto closefiles;
        }
        goto while_break___1;
      }
      {
      thisfield___0 = (char *)find_field((struct linebuffer  const  *)thisline);
      thislen___0 = (thisline->length - 1UL) - (size_t )(thisfield___0 - thisline->buffer);
      tmp___11 = different(thisfield___0, prevfield___0, thislen___0, prevlen___0);
      }
      if (tmp___11) {
        tmp___12 = 0;
      } else {
        tmp___12 = 1;
      }
      match = (_Bool )tmp___12;
      match_count += (uintmax_t )match;
      if (match_count == 0xffffffffffffffffUL) {
        match_count --;
      }
      if ((unsigned int )delimit_groups != 0U) {
        if (! match) {
          if (match_count) {
            first_delimiter = (_Bool)0;
          }
        } else
        if (match_count == 1UL) {
          if ((unsigned int )delimit_groups == 1U) {
            {
            putchar_unlocked((int )delimiter);
            }
          } else
          if ((unsigned int )delimit_groups == 2U) {
            if (! first_delimiter) {
              {
              putchar_unlocked((int )delimiter);
              }
            }
          }
        }
      }
      if (! match) {
        goto _L___0;
      } else
      if (output_later_repeated) {
        _L___0: 
        {
        writeline((struct linebuffer  const  *)prevline, match, match_count);
        }
        {
        while (1) {
          while_continue___2: /* CIL Label */ ;
          _tmp___0 = prevline;
          prevline = thisline;
          thisline = _tmp___0;
          goto while_break___2;
        }
        while_break___2: /* CIL Label */ ;
        }
        prevfield___0 = thisfield___0;
        prevlen___0 = thislen___0;
        if (! match) {
          match_count = (uintmax_t )0;
        }
      }
    }
    while_break___1: /* CIL Label */ ;
    }
    {
    writeline((struct linebuffer  const  *)prevline, (_Bool)0, match_count);
    }
  }
  closefiles: 
  {
  tmp___16 = ferror_unlocked(stdin);
  }
  if (tmp___16) {
    {
    tmp___15 = gettext("error reading %s");
    error(1, 0, (char const   *)tmp___15, infile);
    }
  } else {
    {
    tmp___17 = rpl_fclose(stdin);
    }
    if (tmp___17 != 0) {
      {
      tmp___15 = gettext("error reading %s");
      error(1, 0, (char const   *)tmp___15, infile);
      }
    }
  }
  {
  free((void *)lb1.buffer);
  free((void *)lb2.buffer);
  }
  return;
}
}
int main(int argc , char **argv ) 
{ 
  int optc ;
  _Bool posixly_correct ;
  char *tmp ;
  enum Skip_field_option_type skip_field_option_type ;
  int nfiles ;
  char const   *file[2] ;
  char delimiter ;
  char const   *tmp___0 ;
  char *tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  unsigned long size ;
  char const   *tmp___4 ;
  char *tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  strtol_error tmp___8 ;
  ptrdiff_t tmp___9 ;
  char *tmp___10 ;
  void *__cil_tmp22 ;
  char *__cil_tmp23 ;
  char *__cil_tmp24 ;
  char *__cil_tmp25 ;
  char *__cil_tmp26 ;
  char *__cil_tmp27 ;
  char *__cil_tmp28 ;
  char *__cil_tmp29 ;
  char *__cil_tmp30 ;
  char *__cil_tmp31 ;
  char *__cil_tmp32 ;
  char *__cil_tmp33 ;
  char *__cil_tmp34 ;
  char *__cil_tmp35 ;
  char *__cil_tmp36 ;

  {
  {
  optc = 0;
  tmp = getenv("POSIXLY_CORRECT");
  posixly_correct = (_Bool )((unsigned long )tmp != (unsigned long )((void *)0));
  skip_field_option_type = (enum Skip_field_option_type )0;
  nfiles = 0;
  delimiter = (char )'\n';
  file[1] = "-";
  file[0] = file[1];
  set_program_name((char const   *)*(argv + 0));
  setlocale(6, "");
  bindtextdomain("coreutils", "/usr/local/share/locale");
  textdomain("coreutils");
  hard_LC_COLLATE = hard_locale(3);
  atexit(& close_stdout);
  skip_chars = (size_t )0;
  skip_fields = (size_t )0;
  check_chars = 0xffffffffffffffffUL;
  output_first_repeated = (_Bool)1;
  output_unique = output_first_repeated;
  output_later_repeated = (_Bool)0;
  countmode = (enum countmode )1;
  delimit_groups = (enum delimit_method )0;
  }
  {
  while (1) {
    while_continue: /* CIL Label */ ;
    if (optc == -1) {
      goto _L___2;
    } else
    if (posixly_correct) {
      if (nfiles != 0) {
        goto _L___2;
      } else {
        goto _L___3;
      }
    } else {
      _L___3: 
      {
      optc = getopt_long(argc, (char * const  *)argv, "-0123456789Dcdf:is:uw:z", longopts,
                         (int *)((void *)0));
      }
      if (optc == -1) {
        _L___2: 
        if (argc <= optind) {
          goto while_break;
        }
        if (nfiles == 2) {
          {
          tmp___0 = quote((char const   *)*(argv + optind));
          tmp___1 = gettext("extra operand %s");
          error(0, 0, (char const   *)tmp___1, tmp___0);
          usage(1);
          }
        }
        tmp___2 = nfiles;
        nfiles ++;
        tmp___3 = optind;
        optind ++;
        file[tmp___2] = (char const   *)*(argv + tmp___3);
      } else {
        {
        if (optc == 1) {
          goto case_1;
        }
        if (optc == 48) {
          goto case_48;
        }
        if (optc == 49) {
          goto case_48;
        }
        if (optc == 50) {
          goto case_48;
        }
        if (optc == 51) {
          goto case_48;
        }
        if (optc == 52) {
          goto case_48;
        }
        if (optc == 53) {
          goto case_48;
        }
        if (optc == 54) {
          goto case_48;
        }
        if (optc == 55) {
          goto case_48;
        }
        if (optc == 56) {
          goto case_48;
        }
        if (optc == 57) {
          goto case_48;
        }
        if (optc == 99) {
          goto case_99;
        }
        if (optc == 100) {
          goto case_100;
        }
        if (optc == 68) {
          goto case_68;
        }
        if (optc == 102) {
          goto case_102;
        }
        if (optc == 105) {
          goto case_105;
        }
        if (optc == 115) {
          goto case_115;
        }
        if (optc == 117) {
          goto case_117;
        }
        if (optc == 119) {
          goto case_119;
        }
        if (optc == 122) {
          goto case_122;
        }
        if (optc == -130) {
          goto case_neg_130;
        }
        if (optc == -131) {
          goto case_neg_131;
        }
        goto switch_default;
        case_1: /* CIL Label */ 
        if ((int )*(optarg + 0) == 43) {
          {
          tmp___7 = posix2_version();
          }
          if (tmp___7 < 200112) {
            {
            tmp___8 = xstrtoul((char const   *)optarg, (char **)((void *)0), 10, & size,
                               "");
            }
            if ((unsigned int )tmp___8 == 0U) {
              if (size <= 0xffffffffffffffffUL) {
                skip_chars = size;
              } else {
                goto _L___1;
              }
            } else {
              goto _L___1;
            }
          } else {
            goto _L___1;
          }
        } else
        _L___1: 
        if (nfiles == 2) {
          {
          tmp___4 = quote((char const   *)optarg);
          tmp___5 = gettext("extra operand %s");
          error(0, 0, (char const   *)tmp___5, tmp___4);
          usage(1);
          }
        } else {
          tmp___6 = nfiles;
          nfiles ++;
          file[tmp___6] = (char const   *)optarg;
        }
        goto switch_break;
        case_48: /* CIL Label */ 
        case_49: /* CIL Label */ 
        case_50: /* CIL Label */ 
        case_51: /* CIL Label */ 
        case_52: /* CIL Label */ 
        case_53: /* CIL Label */ 
        case_54: /* CIL Label */ 
        case_55: /* CIL Label */ 
        case_56: /* CIL Label */ 
        case_57: /* CIL Label */ 
        if ((unsigned int )skip_field_option_type == 2U) {
          skip_fields = (size_t )0;
        }
        skip_field_option_type = (enum Skip_field_option_type )1;
        goto switch_break;
        case_99: /* CIL Label */ 
        countmode = (enum countmode )0;
        goto switch_break;
        case_100: /* CIL Label */ 
        output_unique = (_Bool)0;
        goto switch_break;
        case_68: /* CIL Label */ 
        output_unique = (_Bool)0;
        output_later_repeated = (_Bool)1;
        if ((unsigned long )optarg == (unsigned long )((void *)0)) {
          delimit_groups = (enum delimit_method )0;
        } else {
          {
          tmp___9 = __xargmatch_internal("--all-repeated", (char const   *)optarg,
                                         delimit_method_string, (char const   *)(delimit_method_map),
                                         sizeof(delimit_method_map[0]), argmatch_die);
          delimit_groups = (enum delimit_method )delimit_method_map[tmp___9];
          }
        }
        goto switch_break;
        case_102: /* CIL Label */ 
        {
        skip_field_option_type = (enum Skip_field_option_type )2;
        skip_fields = size_opt((char const   *)optarg, "invalid number of fields to skip");
        }
        goto switch_break;
        case_105: /* CIL Label */ 
        ignore_case = (_Bool)1;
        goto switch_break;
        case_115: /* CIL Label */ 
        {
        skip_chars = size_opt((char const   *)optarg, "invalid number of bytes to skip");
        }
        goto switch_break;
        case_117: /* CIL Label */ 
        output_first_repeated = (_Bool)0;
        goto switch_break;
        case_119: /* CIL Label */ 
        {
        check_chars = size_opt((char const   *)optarg, "invalid number of bytes to compare");
        }
        goto switch_break;
        case_122: /* CIL Label */ 
        delimiter = (char )'\000';
        goto switch_break;
        case_neg_130: /* CIL Label */ 
        {
        usage(0);
        }
        goto switch_break;
        case_neg_131: /* CIL Label */ 
        {
        version_etc(stdout, "uniq", "GNU coreutils", Version, "Richard M. Stallman",
                    "David MacKenzie", (char *)((void *)0));
        exit(0);
        }
        goto switch_break;
        switch_default: /* CIL Label */ 
        {
        usage(1);
        }
        switch_break: /* CIL Label */ ;
        }
      }
    }
  }
  while_break: /* CIL Label */ ;
  }
  if ((unsigned int )countmode == 0U) {
    if (output_later_repeated) {
      {
      tmp___10 = gettext("printing all duplicated lines and repeat counts is meaningless");
      error(0, 0, (char const   *)tmp___10);
      usage(1);
      }
    }
  }
  {
  check_file(file[0], file[1], delimiter);
  exit(0);
  }
}
}
