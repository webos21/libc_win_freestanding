#ifndef LIBC_H
#define LIBC_H

#define FREESTANDING_MAIN                                 \
	int mainCRTStartup(int argc, char *argv[]) {          \
		return main(argc, argv);                          \
	}                                                     \
	void __main(void) {                                   \
	}

void debug_msg(char *dmsg);
int print_msg(char *msg, int mlen);

#endif /* LIBC_H */
