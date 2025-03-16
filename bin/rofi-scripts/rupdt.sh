#!/bin/sh

if [ x"$@" = x"󰮯 Pacman" ]
then
	coproc ( alacritty -T Update -e sudo pacman -Syu  > /dev/null 2>&1 )
	exit 0
elif [ x"$@" = x" AUR" ]
then
	coproc ( alacritty -T Update -e yay -Syu  > /dev/null 2>&1 )
	exit 0
fi

echo "󰮯 Pacman"
echo " AUR"
