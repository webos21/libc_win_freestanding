#include <windows.h>

int print_msg(char *msg, int mlen) {
	DWORD wb;
	HANDLE stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WriteFile(stdout, msg, mlen, &wb, NULL);
	return 0;
}

BOOL __stdcall DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason,
		LPVOID lpvReserved) {
	(void) (hinstDLL);
	(void) (fdwReason);
	(void) (lpvReserved);
	return TRUE;
}

