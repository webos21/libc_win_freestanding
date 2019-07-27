#if 0
#include <windows.h>
#endif

#if 1
#include <stddef.h>

//////////////
// _W64
//////////////
#if !defined(_W64)
#if !defined(__midl) && (defined(_X86_) || defined(_M_IX86)) && _MSC_VER >= 1300
#define _W64 __w64
#else  // __midi/X86...
#define _W64
#endif // !__midi/X86...
#endif // !_W64

//////////////
// PTR : INT_PTR,PINT_PTR,UINT_PTR,PUINT_PTR
//////////////
#ifdef _WIN64
typedef long long           INT_PTR, *PINT_PTR;
typedef unsigned long long  UINT_PTR, *PUINT_PTR;

typedef long long           LONG_PTR, *PLONG_PTR;
typedef unsigned long long  ULONG_PTR, *PULONG_PTR;

#define __int3264           __int64

#else // !_WIN64

typedef _W64 int INT_PTR, *PINT_PTR;
typedef _W64 unsigned int UINT_PTR, *PUINT_PTR;

typedef _W64 long LONG_PTR, *PLONG_PTR;
typedef _W64 unsigned long ULONG_PTR, *PULONG_PTR;

#define __int3264           __int32

#endif // _WIN64

typedef void *PVOID;
typedef void *LPVOID;
typedef void *LPCVOID;
typedef void *HANDLE;
typedef void *HINSTANCE;
typedef int BOOL;
typedef unsigned long DWORD;
typedef DWORD *LPDWORD;
typedef ULONG_PTR SIZE_T, *PSIZE_T;

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#endif

#if 1
const int STD_OUTPUT_HANDLE = -11;

typedef struct _OVERLAPPED {
  ULONG_PTR Internal;
  ULONG_PTR InternalHigh;
  union {
    struct {
      DWORD Offset;
      DWORD OffsetHigh;
    } DUMMYSTRUCTNAME;
    PVOID Pointer;
  } DUMMYUNIONNAME;
  HANDLE    hEvent;
} OVERLAPPED, *LPOVERLAPPED;


extern HANDLE GetStdHandle(DWORD nStdHandle);
extern BOOL WriteFile(
		  HANDLE       hFile,
		  LPCVOID      lpBuffer,
		  DWORD        nNumberOfBytesToWrite,
		  LPDWORD      lpNumberOfBytesWritten,
		  LPOVERLAPPED lpOverlapped
		);

#endif /* 0 */

int print_msg(char *msg, int mlen) {
#if 1
	HANDLE stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WriteFile(stdout, msg, mlen, (DWORD[]){0}, NULL);
#else
	(void) (msg);
	(void) (mlen);
#endif
	return 0;
}

BOOL __stdcall DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason,
		LPVOID lpvReserved) {
	return TRUE;
}

