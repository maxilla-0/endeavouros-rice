#!/bin/sh

if [ x"$@" = x"󰙀 Tiled Layout" ]
then
	coproc ( dwmc setlayoutex 0  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" Floating Layout" ]
then
	coproc ( dwmc setlayoutex 1  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" Monocle Layout" ]
then
	coproc ( dwmc setlayoutex 2  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" Bottomstack Layout" ]
then
	coproc ( dwmc setlayoutex 3  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" Spiral Layout" ]
then
	coproc ( dwmc setlayoutex 4  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" Dwindle Layout" ]
then
	coproc ( dwmc setlayoutex 5  > /dev/null 2>&1 )
	exit 0
fi

echo "󰙀 Tiled Layout"
echo " Monocle Layout"
echo " Bottomstack Layout"
echo " Spiral Layout"
echo " Dwindle Layout"
echo " Floating Layout"
