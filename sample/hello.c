#include "libc.h"

int __main(int argc, char *argv[]) {
	char msg[] = "Hello World!\n";
	print_msg(msg, 13);
	return 0;
}

#if ECLIPSE_BUILD
int WinMain(void *hInstance, void *hPrevInstance, char *pCmdLine, int nCmdShow) {
	/* Nothing to do */
	(void)(hInstance);
	(void)(hPrevInstance);
	(void)(pCmdLine);
	(void)(nCmdShow);
}
#endif
