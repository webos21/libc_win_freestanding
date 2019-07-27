gcc -std=c99 -Wall -Wextra -nostdlib -ffreestanding -mconsole -Os -fno-stack-check -fno-stack-protector -mno-stack-arg-probe -o r64.exe freestanding.c -lkernel32
