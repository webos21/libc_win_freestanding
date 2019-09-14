#include "libc.h"

int main(int argc, char *argv[]) {
	int mlen = 13;
	char msg[] = "Hello World!\n";

	debug_msg("main");
	print_msg(msg, mlen);

	return 0;
}

#if !ECLIPSE_BUILD
/* MUST CALL */
FREESTANDING_MAIN
#endif
