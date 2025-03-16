#!/bin/sh

if [ x"$@" = x" Increase" ]
then
	coproc ( pamixer -i 5 ; pkill -10 slstatus  > /dev/null  2>&1 )
elif [ x"$@" = x" Decrease" ]
then
	coproc ( pamixer -d 5 ; pkill -10 slstatus  > /dev/null  2>&1 )
elif [ x"$@" = x" Mute" ]
then
	coproc ( pamixer -t ; pkill -10 slstatus  > /dev/null  2>&1 )
elif [ x"$@" = x" Volume mixer" ]
then
	coproc ( pavucontrol  > /dev/null  2>&1 )
	exit 0
fi

echo " Increase"
echo " Decrease"
echo " Mute"
echo " Volume mixer"
