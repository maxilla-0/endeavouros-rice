#!/bin/bash
slstatus &
xinput --set-prop 9 'libinput Accel Speed' .45
xinput --set-prop 10 'libinput Accel Speed' .45
xinput --set-prop 11 'libinput Accel Speed' .45
xset r rate 450 30
xset dpms 600
xautolock -time 20 -locker "systemctl suspend" &
xss-lock -- slock &
#rofi -show drun -show-icons -icon-theme Zafiro-Nord-Black-Blue &
#mpv --no-video --volume=500 /home/mandible/.local/share/sounds/Windows\ Startup\ Sound.m4a &
picom --experimental-backends -b
nitrogen --restore
#conky &
/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
batsignal -b -e -p -w 20 -c 10 -d 5 -W '󰂃 Battery is low' -C '󰂃 Battery is critically low!' -D 'systemctl hibernate' -P '󰚥 Plugged in' -U '󰚦 Unplugged' -I '/usr/share/icons/gruvbox-dark-icons-gtk/64x64@2x/devices/battery.svg' -m 1
exec /home/mandible/.local/bin/dwmloop.sh
