#!/usr/bin/python
import os, subprocess, sys

def log(msg):
	print('\033[92m[*] ' + msg +  '\033[0m')

def execute(cmd, cwd):
	log(cmd)
	subprocess.Popen(cmd, shell=True, cwd = cwd).wait()

if __name__ == '__main__':
	current_path = os.getcwd()
	execute("mkdir xed_files", current_path)
	xed_files = os.path.join(current_path, "xed_files")
	execute("git clone https://github.com/intelxed/xed.git xed", xed_files)
	execute("git clone https://github.com/intelxed/mbuild.git mbuild", xed_files)
	xed = os.path.join(xed_files, "xed")
	execute("./mfile.py --shared install", xed)
	kits = os.path.join(xed, "kits")
	xed_built = os.path.join(kits, os.listdir(kits)[0])
	xed_lib = os.path.join(xed_built, "lib")
	xed_include = os.path.join(xed_built, "include/xed")
	execute("mkdir build", current_path)
	build = os.path.join(current_path, "build")
	execute("cmake -DPTUNIT=ON -DPTTC=ON -DPTDUMP=ON -DPTXED=ON -DXED_INCLUDE={} -DXED_LIBDIR={} -DSIDEBAND=ON -DPEVENT=ON -DFEATURE_ELF=ON ../".format(xed_include, xed_lib), build)
	execute("make", build)
	log("Decoder: {}/bin/ptxed".format(build))
