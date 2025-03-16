#!/bin/bash
xset r rate 450 30
xset dpms 600 0 0
xautolock -time 20 -locker "systemctl suspend" &
xss-lock -- /home/mandible/.local/bin/i3lock.sh &
#rofi -show drun -show-icons -icon-theme Zafiro-Nord-Black-Blue &
#mpv --no-video --volume=500 /home/mandible/.local/share/sounds/Windows\ Startup\ Sound.m4a &
#conky &
#/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
rofi-polkit-agent &
picom &
exec awesome
