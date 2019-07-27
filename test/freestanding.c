#include <windows.h>

int WINAPI
mainCRTStartup(void)
{
	void *ptr = NULL;
    char msg[] = "Hello, world!\n";
    DWORD rb;

    ptr = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 512);

    HANDLE stdout = GetStdHandle(STD_OUTPUT_HANDLE);
    WriteFile(stdout, msg, sizeof(msg), (DWORD[]){0}, NULL);

    HANDLE stdin = GetStdHandle(STD_INPUT_HANDLE);
    ReadFile(stdin, ptr, 1, &rb, NULL);

    WriteFile(stdout, ptr, 1, (DWORD[]){0}, NULL);
    HeapFree(GetProcessHeap(), 0, ptr);

    return 0;
}
