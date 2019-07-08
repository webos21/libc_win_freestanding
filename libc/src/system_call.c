#if 0
#include <windows.h>
#endif

#include "libc.h"

int print_msg(char *msg, int mlen) {
#if 0
	HANDLE stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WriteFile(stdout, msg, mlen, (DWORD[]){0}, NULL);
#else
	(void)(msg);
	(void)(mlen);
#endif
	return 0;
}
