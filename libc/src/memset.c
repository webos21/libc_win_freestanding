#include <windows.h>

void *memset(void *s, int c, size_t n) {
	volatile size_t i;
	char *p;

	p = s;
	for (i = 0; i < n; i++) {
		p[i] = (c & 0x000000FF);
	}

	return s;
}
