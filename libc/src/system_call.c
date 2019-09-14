#include <windows.h>

#include "libc.h"

static void print_last_error() {
	LPVOID lpMsgBuf;
	DWORD dwLastError = GetLastError();

	FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM
					| FORMAT_MESSAGE_IGNORE_INSERTS, NULL, dwLastError,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR) &lpMsgBuf, 0,
			NULL);
	OutputDebugStringA(lpMsgBuf);
}

void debug_msg(char *dmsg) {
	OutputDebugStringA(dmsg);
}

int print_msg(char *msg, int mlen) {
	DWORD wb = 0;
	HANDLE so;

	so = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE == so) {
		OutputDebugStringA("No OUTPUT Handle!!!");
	} else {
		OutputDebugStringA("HAS OUTPUT Handle!!!");
	}
	if (!WriteFile(so, msg, mlen, &wb, NULL)) {
		print_last_error();
	}

	return 0;
}

BOOL __stdcall DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason,
		LPVOID lpvReserved) {
	OutputDebugStringA("DllMainCRTStartup!!!");

	(void) (hinstDLL);
	(void) (fdwReason);
	(void) (lpvReserved);

	return TRUE;
}
