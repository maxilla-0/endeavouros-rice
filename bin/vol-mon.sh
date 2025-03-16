#!/bin/bash

pactl subscribe | while read -r event; do
	if echo "$event" | grep -E "Event '(new|change)' on card"; then
		pkill -RTMIN+1 slstatus
	fi
done
