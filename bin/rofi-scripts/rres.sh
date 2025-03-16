#!/bin/sh

if [ x"$@" = x"Screen Settings" ]
then
	coproc ( arandr  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1920x1080" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1680x1050" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1400x1050" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1600x900" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1280x1024" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1400x900" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1280x960" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1440x810" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1368x768" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1280x800" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1280x720" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1024x768" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"960x720" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"928x696" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"896x672" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"1024x576" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"960x600" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"960x540" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"800x600" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"840x525" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"864x486" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"700x525" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"800x450" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"640x512" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"700x450" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"640x480" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"720x405" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"684x384" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"640x400" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"640x360" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"512x384" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"512x288" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"480x270" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"400x300" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"432x243" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"320x240" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"360x202" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x"320x180" ]
then
	coproc ( xrandr -s $@  > /dev/null 2>&1 )
	coproc ( nitrogen --restore  > /dev/null 2>&1 )
	exit 0
fi

echo "Screen Settings"
echo "1920x1080"
echo "1680x1050"
echo "1400x1050"
echo "1600x900"
echo "1280x1024"
echo "1400x900"
echo "1280x960"
echo "1440x810"
echo "1368x768"
echo "1280x800"
echo "1280x720"
echo "1024x768"
echo "960x720"
echo "928x696"
echo "896x672"
echo "1024x576"
echo "960x600"
echo "960x540"
echo "800x600"
echo "840x525"
echo "864x486"
echo "700x525"
echo "800x450"
echo "640x512"
echo "700x450"
echo "640x480"
echo "720x405"
echo "684x384"
echo "640x400"
echo "640x360"
echo "512x384"
echo "512x288"
echo "480x270"
echo "400x300"
echo "432x243"
echo "320x240"
echo "360x202"
echo "320x180"
