#include <malloc.h>

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

typedef _W64 int            INT_PTR, *PINT_PTR;
typedef _W64 unsigned int   UINT_PTR, *PUINT_PTR;

typedef _W64 long           LONG_PTR, *PLONG_PTR;
typedef _W64 unsigned long  ULONG_PTR, *PULONG_PTR;

#define __int3264           __int32

#endif // _WIN64


typedef void               *LPVOID;
typedef void               *HANDLE;
typedef int                 BOOL;
typedef unsigned long      DWORD;
typedef ULONG_PTR           SIZE_T, *PSIZE_T;

extern LPVOID HeapAlloc(
  HANDLE hHeap,
  DWORD  dwFlags,
  SIZE_T dwBytes
);

extern BOOL HeapFree(
  HANDLE hHeap,
  DWORD  dwFlags,
  LPVOID lpMem
);

extern HANDLE GetProcessHeap();


void* malloc(size_t byte_count) {
	return HeapAlloc(GetProcessHeap(), 0, byte_count);
}

void free(void* p) {
	HeapFree(GetProcessHeap(), 0, p);
}
