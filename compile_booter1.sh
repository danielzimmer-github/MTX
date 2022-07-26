

as86 -o bs.o bs.s
bcc -o bc.o boot.c

ld86 -d -o booter bs.o bc.o /usr/lib/bcc/lib.a

dd -if=booter -of=booterImage bs=512 count=1 conv=notrunk