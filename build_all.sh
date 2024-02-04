#!/bin/bash

project_root=$(pwd)

#Build our bootloader
echo "Building Bootloader"
cd bootloader
. build.sh

#This should be static at 512 bytes maybe we should make an error state ?
bootloader_size=$(stat -c %s "bin/boot.bin")

#Build the drivers
cd $project_root
echo "Building the drivers"
cd drivers

. build.sh



#Build our kernel
cd $project_root
echo "Building Kernel"
cd cacaoKernel
. build.sh

kernel_size=$(stat -c %s "bin/kernel.bin")

cd $project_root
os_size=$((bootloader_size + kernel_size))

echo "The complete image size is $os_size"

floppy_size=1409949
fill_size=$((floppy_size- os_size))

echo "Creating Image from boot.bin and kernel.bin"
cat bootloader/bin/boot.bin cacaoKernel/bin/kernel.bin > CacaoOs_floppy.img

# Enable when we get Bochs to work ?
echo "The image will be filled with $fill_size bytes of zero data"
# dd without any security checks is probably a bad idea as well...
dd if=/dev/zero bs="$fill_size" count=1 >> CacaoOs_floppy.img