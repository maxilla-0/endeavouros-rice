#!/bin/sh

if [ x"$@" = x"Off" ]
then
	coproc ( redshift -x  > /dev/null 2>&1 )
elif [ x"$@" = x"6000K" ]
then
	coproc ( redshift -P -O $@  > /dev/null 2>&1 )
elif [ x"$@" = x"5500K" ]
then
	coproc ( redshift -P -O $@  > /dev/null 2>&1 )
elif [ x"$@" = x"5000K" ]
then
	coproc ( redshift -P -O $@  > /dev/null 2>&1 )
elif [ x"$@" = x"4500K" ]
then
	coproc ( redshift -P -O $@  > /dev/null 2>&1 )
elif [ x"$@" = x"4000K" ]
then
	coproc ( redshift -P -O $@  > /dev/null 2>&1 )
elif [ x"$@" = x"3500K" ]
then
	coproc ( redshift -P -O $@  > /dev/null 2>&1 )
elif [ x"$@" = x"3000K" ]
then
	coproc ( redshift -P -O $@  > /dev/null 2>&1 )
elif [ x"$@" = x"2500K" ]
then
	coproc ( redshift -P -O $@  > /dev/null 2>&1 )
elif [ x"$@" = x"2000K" ]
then
	coproc ( redshift -P -O $@  > /dev/null 2>&1 )
elif [ x"$@" = x"1500K" ]
then
	coproc ( redshift -P -O $@  > /dev/null 2>&1 )
elif [ x"$@" = x"1000K" ]
then
	coproc ( redshift -P -O $@  > /dev/null 2>&1 )
fi

echo "Off"
echo "6000K"
echo "5500K"
echo "5000K"
echo "4500K"
echo "4000K"
echo "3500K"
echo "3000K"
echo "2500K"
echo "2000K"
echo "1500K"
echo "1000K"
