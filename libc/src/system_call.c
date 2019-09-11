#include <windows.h>

/*
 * ERROR_NOACCESS (998) : Console
 * ERROR_INVALID_USER_BUFFER (1784) : File
 */

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

static void setup_console() {
	/* Need to implement "_initterm" on MSVCRT */
	/* Need to implement "_initterm" on MSVCRT */
	/* Need to implement "_initterm" on MSVCRT */

	if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
		if (GetLastError() != ERROR_ACCESS_DENIED) { //already has a console
			if (!AttachConsole(GetCurrentProcessId())) {
				DWORD dwLastError = GetLastError();
				if (dwLastError != ERROR_ACCESS_DENIED) { //already has a console
					OutputDebugStringA("Console Attach Failed!!!");
					return;
				} else {
					OutputDebugStringA("Already HAS Console(in)!!!");
				}
			} else {
				OutputDebugStringA("ATTACH_CURRENT_PROCESS");
			}
		} else {
			OutputDebugStringA("Already HAS Console(out)!!!");

		}
	} else {
		OutputDebugStringA("ATTACH_PARENT_PROCESS");
	}
}

int print_msg(char *msg, int mlen) {
	DWORD wb = 0;

#if 0
	HANDLE hFile;

	hFile = CreateFileA("test.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL,
			OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hFile) {
		print_last_error();
		return -1;
	}
	Sleep(100);
	if (!WriteFile(hFile, msg, mlen, &wb, NULL)) {
		print_last_error();
	}
	if (hFile != NULL) {
		CloseHandle(hFile);
	}
#else
	HANDLE stdout;

	setup_console();

	stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (stdout == NULL) {
		OutputDebugStringA("No Handle!!!");
	} else {
		OutputDebugStringA("HAS Handle!!!");
	}
	if (!WriteFile(stdout, msg, mlen, &wb, NULL)) {
		print_last_error();
	}
#endif

	return 0;
}

BOOL __stdcall DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason,
		LPVOID lpvReserved) {
	(void) (hinstDLL);
	(void) (fdwReason);
	(void) (lpvReserved);

	setup_console();

	OutputDebugStringA("DllMainCRTStartup!!!");

	return TRUE;
}

