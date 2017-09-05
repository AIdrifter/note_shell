# usb
echo "cd /lib/modules/usb/"
cd /lib/modules/usb/

echo "first mount"
insmod usb-common.ko
echo "insmod usbcore.ko"
insmod usbcore.ko
echo "insmod ehci-hcd.ko"
insmod ehci-hcd.ko
echo "insmod usb-storage.ko"
insmod usb-storage.ko
echo "sleep 2s"
sleep 2s
echo "mount /dev/sda1 /mnt/sdp1"
mount /dev/sda1 /mnt/sdp1
cd /applications/apm

