# libc_win_freestanding

This is the test project for bionic-libc on Windows.

* Use the MinGW-w64 for building
1. Create the DLL without linking with the CRT of MinGW-w64
2. Create the freestanding libc (c.dll)
3. Build the HelloWorld binary with the freestanding libc<br/>
   (It also has no dependency on the CRT of MinGW-w64)

* Need to clear below errors:

```dos
../amk/mingw32/emul/lib/alibcrt.a(crtdll.o): In function `pre_c_init':
C:/WorkDir/libc_win_freestanding/crt/src/crtdll.c:66: undefined reference to `malloc'
../amk/mingw32/emul/lib/alibcrt.a(crtdll.o): In function `CRT_INIT@12':
C:/WorkDir/libc_win_freestanding/crt/src/crtdll.c:134: undefined reference to `_amsg_exit'
C:/WorkDir/libc_win_freestanding/crt/src/crtdll.c:145: undefined reference to `free'
C:/WorkDir/libc_win_freestanding/crt/src/crtdll.c:108: undefined reference to `_initterm'
C:/WorkDir/libc_win_freestanding/crt/src/crtdll.c:102: undefined reference to `_amsg_exit'
C:/WorkDir/libc_win_freestanding/crt/src/crtdll.c:112: undefined reference to `_initterm'
../amk/mingw32/emul/lib/alibcrt.a(crtdll.o): In function `CRT_INIT':
C:/WorkDir/libc_win_freestanding/crt/src/crtdll.c:134: undefined reference to `_amsg_exit'
C:/WorkDir/libc_win_freestanding/crt/src/crtdll.c:145: undefined reference to `free'
../amk/mingw32/emul/lib/alibcrt.a(atonexit.o): In function `mingw_onexit':
C:/WorkDir/libc_win_freestanding/crt/src/atonexit.c:43: undefined reference to `_lock'
C:/WorkDir/libc_win_freestanding/crt/src/atonexit.c:47: undefined reference to `__dllonexit'
C:/WorkDir/libc_win_freestanding/crt/src/atonexit.c:51: undefined reference to `_unlock'
C:/WorkDir/libc_win_freestanding/crt/src/atonexit.c:42: undefined reference to `_imp___onexit'
C:/WorkDir/libc_win_freestanding/crt/src/atonexit.c:43: undefined reference to `_lock'
C:/WorkDir/libc_win_freestanding/crt/src/atonexit.c:47: undefined reference to `__dllonexit'
C:/WorkDir/libc_win_freestanding/crt/src/atonexit.c:51: undefined reference to `_unlock'
C:/WorkDir/libc_win_freestanding/crt/src/atonexit.c:42: undefined reference to `_imp___onexit'
../amk/mingw32/emul/lib/alibcrt.a(pseudo-reloc.o): In function `_report_error':
C:/WorkDir/libc_win_freestanding/crt/src/pseudo-reloc.c:149: undefined reference to `_imp___iob'
C:/WorkDir/libc_win_freestanding/crt/src/pseudo-reloc.c:149: undefined reference to `fprintf'
C:/WorkDir/libc_win_freestanding/crt/src/pseudo-reloc.c:150: undefined reference to `_imp___iob'
C:/WorkDir/libc_win_freestanding/crt/src/pseudo-reloc.c:150: undefined reference to `vfprintf'
C:/WorkDir/libc_win_freestanding/crt/src/pseudo-reloc.c:156: undefined reference to `abort'
../amk/mingw32/emul/lib/alibcrt.a(gs_support.o): In function `_report_gsfailure':
C:/WorkDir/libc_win_freestanding/crt/src/gs_support.c:152: undefined reference to `abort'
../amk/mingw32/emul/lib/alibcrt.a(tlsthrd.o): In function `__w64_mingwthr_add_key_dtor':
C:/WorkDir/libc_win_freestanding/crt/src/tlsthrd.c:48: undefined reference to `calloc'
../amk/mingw32/emul/lib/alibcrt.a(tlsthrd.o): In function `__w64_mingwthr_remove_key_dtor':
C:/WorkDir/libc_win_freestanding/crt/src/tlsthrd.c:87: undefined reference to `free'
../amk/mingw32/emul/lib/alibcrt.a(tlsthrd.o): In function `_mingw_TLScallback':
C:/WorkDir/libc_win_freestanding/crt/src/tlsthrd.c:141: undefined reference to `free'
../amk/mingw32/emul/lib/alibcrt.a(CRT_fp8.o): In function `fpreset':
C:/WorkDir/libc_win_freestanding/crt/src/CRT_fp8.c:14: undefined reference to `_imp___fpreset'
collect2.exe: error: ld returned 1 exit status
buildx.mk:146: recipe for target 'c.dll' failed
mingw32-make[2]: *** [c.dll] Error 1
mingw32-make[2]: Leaving directory 'C:/WorkDir/libc_win_freestanding/libc'
buildx.mk:97: recipe for target 'do_build' failed
mingw32-make[1]: *** [do_build] Error 2
mingw32-make[1]: Leaving directory 'C:/WorkDir/libc_win_freestanding'
Makefile:34: recipe for target 'mingw32' failed
mingw32-make: *** [mingw32] Error 2

```

