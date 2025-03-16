#!/bin/bash
xset r rate 450 30
xset dpms 600 0 0
xautolock -detectsleep -time 20 -locker "systemctl suspend" &
xss-lock -- /home/mandible/.local/bin/i3lock.sh &
#mpv --no-video --volume=500 /home/mandible/.local/share/sounds/Windows\ Startup\ Sound.m4a &
picom -b
nitrogen --restore
dunst &
rofi-polkit-agent -theme-str 'inputbar {children: [prompt,entry];} entry {placeholder: "Type password...";}' &
batsignal -b -e -p -w 20 -c 10 -d 5 -W '󰂃 Battery is low' -C '󰂃 Battery is critically low!' -D 'systemctl hibernate' -P '󰚥 Plugged in' -U '󰚦 Unplugged' -m 1
sleep 0.5
slstatus &
sleep 0.5
while true; do
	dwm 2> ~/.dwm.log
done
