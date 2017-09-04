# mount

## swork
busybox mount -t nfs -o nolock 172.16.20.21:/work/aidrifter.chang

## 6404
mkdir -p /Customer/nfs
busybox mount -t nfs -o nolock 172.16.20.97:/home/aidrifter /Customer/nfs

## 6403
busybox mount -t nfs -o nolock 172.16.20.38:/home/aidrifter .
mount -o rw,remount /system
busybox mount -o rw,remount /system
busybox mount -o rw,remount /vendor


## mount
./target/Makefile 會去寫mount 順序

可以到mboot console, 打mmc part
看appcache是幾號

mount -t ext4 -o loop /dev/mmcblk11 /appcache

## remount lib
cp -R /mslib /OAD

vi /Customer/profile
mount /OAD/mslib/ /mslib/

# mount usb to mnt
mount /dev/sda1  /mnt/sda1

