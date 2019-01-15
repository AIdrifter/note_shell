gtf 2560 1080 50
xrandr --newmode "TEST" 188.60  2560 2704 2976 3392  1080 1081 1084 1112  -HSync +Vsync
xrandr --addmode HDMI-1 "TEST"
xrandr --output HDMI-1 --mode "TEST"
