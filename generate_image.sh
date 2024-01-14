mkdir -p image/iso
mkdir -p image/iso/boot/grub

cp -r ./cacaoKernel/bin ./image/iso/

grub-mkrescue -o out/cacaoOS.img image/iso
