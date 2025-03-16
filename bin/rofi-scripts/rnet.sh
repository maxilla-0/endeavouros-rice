#!/bin/sh

if [[ $(nmcli radio wifi) == "enabled" ]]
then
	wf=󰤨
	stat=On
	echo -en "\0message\x1fConnected network: $(iwgetid -r)\n"
else
	wf=󰤭
	stat=Off
fi

if [ x"$@" = x"󰤨 Wifi: On" ]
then
	coproc ( nmcli radio wifi off  > /dev/null  2>&1 )
	echo -en "\0message\x1fWifi is off, click again to refresh\n"
elif [ x"$@" = x"󰤭 Wifi: Off" ]
then
	coproc ( nmcli radio wifi on  > /dev/null  2>&1 )
	echo -en "\0message\x1fWifi is on, click again to refresh\n"
elif [ x"$@" = x"󰤨 Available wifi connections" ]
then
	coproc ( /home/mandible/.local/bin/rofi-scripts/rofi-wifi-menu  > /dev/null  2>&1 )
	exit 0
elif [ x"$@" = x"󰢩 Network Manager (TUI)" ]
then
	coproc ( alacritty -T Wi-Fi -e nmtui  > /dev/null  2>&1 )
	exit 0
elif [ x"$@" = x"󱤚 Edit connections" ]
then
	coproc ( nm-connection-editor  > /dev/null  2>&1 )
	exit 0
elif [ x"$@" = x" Firewall" ]
then
	coproc ( firewall-config  > /dev/null  2>&1 )
	exit 0
fi

echo "$wf Wifi: $stat"
echo "󰤨 Available wifi connections"
echo "󰢩 Network Manager (TUI)"
echo "󱤚 Edit connections"
echo " Firewall"
