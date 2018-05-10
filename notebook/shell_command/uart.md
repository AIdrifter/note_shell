# uart
dmesg | egrep --color 'serial|ttyS'

setserial -g /dev/ttyS2

chmod 777 /dev/ttyS2

SCREEN /dev/ttyS2 19200

