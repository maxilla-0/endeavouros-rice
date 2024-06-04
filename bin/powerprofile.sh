#!/bin/sh

PP=$(powerprofilesctl get)

if [[ $PP == performance ]]
then
	echo "" 

elif [[ $PP == balanced ]]
then
	echo " "

elif [[ $PP == power-saver ]]
then
	echo "󰌪"
fi
