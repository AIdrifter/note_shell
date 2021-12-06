# Amlogic

git clone https://gitlab-partner.tools.roku.com/aml-t962/port -b roxton
git clone https://gitlab-partner.tools.roku.com/aml-t962/porting_kit -b porting_kit_release_12_29
cd port/amlogic/t318
make image

The built image is in dist/image/acramfs-tcl-tcl.bin


defenv; save
usb start; fatload usb 0:1 0x7400000 acramfs-tcl-tcl.bin
rokuflash ddr 0x7400000 Firmware 0x6000000
reset

http://192.168.10.6/
account: rokudev
passwd:  aaaa

sudo screen /dev/ttyUSB0 921600

ref: https://confluence.portal.roku.com:8443/pages/viewpage.action?pageId=326810903
