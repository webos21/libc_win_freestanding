#include <windows.h>

void *dlopen(const char* filename, int flag) {
	return LoadLibraryExA(filename, (void *) (0), flag);
}

const char *dlerror(void) {
	return "";
}

void *dlsym(void* handle, const char *symbol) {
	return GetProcAddress(handle, symbol);
}

int dlclose(void* handle) {
	return FreeLibrary((HMODULE) handle);
}
