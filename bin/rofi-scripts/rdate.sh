#!/bin/sh

echo -en "\0message\x1f$(date '+%A, %B %d, %Y, %H:%M')\n"

if [ x"$@" = x" Calendar" ]
then
	coproc ( gsimplecal  > /dev/null  2>&1 )
	exit 0
elif [ x"$@" = x" Clock" ]
then
	coproc ( alacritty -T Clock -e peaclock --config-dir ~/.config/peaclock  > /dev/null  2>&1 )
	exit 0
fi

echo " Calendar"
echo " Clock"
