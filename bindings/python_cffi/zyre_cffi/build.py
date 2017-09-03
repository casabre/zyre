################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################

from __future__ import print_function
import os
import re
import sys

import subprocess
def pkgconfig_installed ():
   try:
        subprocess.check_output (["pkg-config", "--version"])
        return True
   except subprocess.CalledProcessError:
        return False

def pkgconfig_kwargs (libs):
    """If pkg-config is available, then return kwargs for set_source based on pkg-config output

    It setup include_dirs, library_dirs, libraries and define_macros
    """

    # make API great again!
    if isinstance (libs, (str, bytes)):
        libs = (libs, )

    # drop starting -I -L -l from cflags
    def dropILl (string):
        def _dropILl (string):
            if string.startswith (b"-I") or string.startswith (b"-L") or string.startswith (b"-l"):
                return string [2:]
        return [_dropILl (x) for x in string.split ()]

    # convert -Dfoo=bar to list of tuples [("foo", "bar")] expected by cffi
    def macros (string):
        def _macros (string):
            return tuple (string [2:].split (b'=', 2))
        return [_macros (x) for x in string.split () if x.startswith (b"-D")]

    # pkg-config call
    def pc (libname, *args):
        a = ["pkg-config", "--print-errors"]
        a.extend (args)
        a.append (libname)
        return subprocess.check_output (a)

    # return kwargs for given libname
    def kwargs (libname):
        return {
                "include_dirs" : dropILl (pc (libname, "--cflags-only-I")),
                "library_dirs" : dropILl (pc (libname, "--libs-only-L")),
                "libraries" : dropILl (pc (libname, "--libs-only-l")),
                "define_macros" : macros (pc (libname, "--cflags")),
                }

    # merge all arguments together
    ret = {}
    for libname in libs:
        foo = kwargs (libname)
        for key, value in foo.items ():
            if not key in ret:
                ret [key] = value
            else:
                ret [key].extend (value)

    # Python3 and strict unicode
    for key, value in ret.items ():
        if isinstance (value, bytes):
            ret [key] = value.decode ("utf-8")
        elif isinstance (value, list):
            if len (value) == 0:
                continue
            if isinstance (value[0], tuple):
                ret [key] = [(v[0].decode ("utf-8"), v[1].decode ("utf-8")) for v in value]
            else:
                ret [key] = [v.decode ("utf-8") for v in value]

    return ret

if not pkgconfig_installed ():
    print ("ERROR: build without pkg-config not supported", file=sys.stderr)
    sys.exit (1)

kwargs = pkgconfig_kwargs ([
    "libzmq",
    "libczmq",
    "libzyre"
])
import cffi
# can't import does not work, read and exec manually
with open (os.path.join (
    os.path.dirname (__file__),
    "cdefs.py"), 'r') as fp:
    cdefs_py = fp.read()
gl = {}
exec (cdefs_py, gl)
zyre_cdefs = gl ["zyre_cdefs"]

ffibuilder = cffi.FFI ()
ffibuilder.set_source ("zyre_cffi.native", "#include <zyre.h>", **kwargs)

# Custom setup for zyre
for item in zyre_cdefs:
    ffibuilder.cdef(item)

if __name__ == "__main__":
    ffibuilder.compile (verbose=True)
