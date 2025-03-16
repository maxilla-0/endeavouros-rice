#!/bin/sh

if [ -z $(pidof bluetoothd) ]
then
	bd='󰂲'
	stat='Off'
else
	bd='󰂯'
	stat='On'
	echo -en "\0message\x1fConnected device: $(bluetoothctl devices Connected | awk '{ print $3 }')\n"
fi

if [ x"$@" = x"󰂲 Bluetooth Adapter: Off" ]
then
	coproc ( systemctl start bluetooth.service  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"󰂯 Bluetooth Adapter: On" ]
then
	coproc ( systemctl kill bluetooth.service  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"󰂳 Bluetooth Manager" ]
then
	coproc ( blueman-manager  > /dev/null 2>&1 )
	exit 0
fi

echo "$bd Bluetooth Adapter: $stat"
echo "󰂳 Bluetooth Manager"
