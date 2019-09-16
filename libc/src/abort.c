#include <windows.h>

void abort(void) {
	ExitProcess(-1);
}
