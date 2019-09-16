#include <windows.h>

void *memcpy(void *dest, const void *src, size_t n) {
	volatile size_t i;
	char *d;
	char *s;

	d = (char *)dest;
	s = (char *)src;

	for (i = 0; i < n; i++) {
		d[i] = s[i];
	}

	return dest;
}
