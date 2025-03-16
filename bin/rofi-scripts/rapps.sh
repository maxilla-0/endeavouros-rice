#!/bin/sh

if [ x"$@" = x" Terminal" ]
then
	coproc ( alacritty  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" File Manager" ]
then
	coproc ( pcmanfm  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" Web Browser" ]
then
	coproc ( firefox  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" Process Viewer" ]
then
	coproc ( alacritty -T Btop -e btop  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" Color Picker" ]
then
	coproc ( xcolor -s  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" Camera" ]
then
	coproc ( mpv  --profile=low-latency --untimed /dev/video0  > /dev/null 2>&1 )
	exit 0
fi

echo " Terminal"
echo " File Manager"
echo " Web Browser"
echo " Process Viewer"
echo " Color Picker"
echo " Camera"
