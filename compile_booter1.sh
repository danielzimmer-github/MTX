

as86 -o bs.o bs.s
bcc -c -o bc.o -ansi boot.c

ld86 -d -o booter bs.o bc.o /usr/lib64/bcc/libc.a

dd if=booter of=booterImage bs=512 count=1 conv=notrunc