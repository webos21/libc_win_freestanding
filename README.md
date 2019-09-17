# libc_win_freestanding

This is the test project for bionic-libc on Windows.

* Use the MinGW-w64 for building [OK]
1. Create the DLL without linking with the CRT of MinGW-w64
2. Create the freestanding libc (c.dll)  => [solved] with "-lmingw32"
3. Build the HelloWorld binary with the freestanding libc => [solved] "mainCRTStartup" MACRO

* dlmalloc(the malloc apis of Doug Lee) is applyed!

* Basic function must be implemented!!
1. memcpy (by assembly)
2. memset (by assembly)
3. vsprintf
4. open
5. read
6. write
7. close
8. socket
9. ...


