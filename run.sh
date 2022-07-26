qemu-system-arm  \
-drive file=booterImage,format=raw \
-nographic \
-serial mon:stdio \
-M virt \
-boot a \
