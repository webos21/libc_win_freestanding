#include <stdlib.h>
#include <string.h>

#include "libc.h"

int main(int argc, char *argv[]) {
	char *tp;

	int mlen = 13;
	char msg[] = "Hello World!\n";

	debug_msg("main");
	print_msg(msg, mlen);

	tp = malloc(32);
	memset(tp, 0, 32);
	memcpy(tp, msg, 13);
	print_msg(tp, mlen);
	free(tp);

	return 0;
}

#if !ECLIPSE_BUILD
/* MUST CALL */
FREESTANDING_MAIN
#endif
