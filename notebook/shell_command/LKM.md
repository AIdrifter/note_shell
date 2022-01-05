# LKM
Disable LMK directly

chmod 777 /sys/module/lowmemorykiller/parameters/minfree
echo 0 > /sys/module/lowmemorykiller/parameters/minfree
