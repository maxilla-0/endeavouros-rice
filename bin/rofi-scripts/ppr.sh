#!/bin/bash

UPINFO=$(upower -i /org/freedesktop/UPower/devices/battery_BAT1)
BAT=$(echo "$UPINFO" | awk '/percentage/ {gsub("%", ""); print $2}')
STATE=$(echo "$UPINFO" | awk '/state/ {print $2}')

echo -en "\0message\x1f$(cat /home/mandible/.local/bin/rofi-scripts/ppr.txt) $BAT% $STATE\n"

if [ x"$@" = x" Performance" ]
then
	coproc ( powerprofilesctl set performance  > /dev/null 2>&1 )
	echo '' > /home/mandible/.local/bin/rofi-scripts/ppr.txt
	coproc ( pkill -10 slstatus  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" Balanced" ]
then
	coproc ( powerprofilesctl set balanced  > /dev/null 2>&1 )
	echo '' > /home/mandible/.local/bin/rofi-scripts/ppr.txt
	coproc ( pkill -10 slstatus  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"󰌪 Power-saver" ]
then
	coproc ( powerprofilesctl set power-saver  > /dev/null 2>&1 )
	echo '󰌪' > /home/mandible/.local/bin/rofi-scripts/ppr.txt
	coproc ( pkill -10 slstatus  > /dev/null 2>&1 )
	exit 0
fi

echo " Performance"
echo " Balanced"
echo "󰌪 Power-saver"
