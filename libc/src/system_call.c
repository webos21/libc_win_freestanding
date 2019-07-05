#include <windows.h>

#include "libc.h"

int print_msg(char *msg, int mlen) {
	HANDLE stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WriteFile(stdout, msg, mlen, (DWORD[]){0}, NULL);
	return 0;
}
