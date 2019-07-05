# libc_win_freestanding

This is the test project for bionic-libc on Windows.

* Use the MinGW-w64 for building
1. Create the DLL without linking with the CRT of MinGW-w64
2. Create the freestanding libc (c.dll)
3. Build the HelloWorld binary with the freestanding libc<br/>
   (It also has no dependency on the CRT of MinGW-w64)

