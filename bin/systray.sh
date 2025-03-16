#!/bin/bash

if [ -z $(pidof stalonetray) ]; then
	stalonetray &
else 
	pkill stalonetray
fi
