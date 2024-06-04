#!/bin/bash

# Get the default sink name
DEFAULT_SINK=$(pactl info | awk -F': ' '/Default Sink/ {print $2}')

# Get the volume and mute status of the default sink
read VOLUME MUTE < <(pactl list sinks | awk -v default_sink="$DEFAULT_SINK" '
  $1 == "Name:" && $2 == default_sink { found = 1 }
  found && /Volume:/ && !volume_found { 
    sub(/%/, "", $5); 
    volume = $5; 
    volume_found = 1;
  } 
  found && /Mute:/ && !mute_found { 
    mute = $2; 
    mute_found = 1;
  }
  found && volume_found && mute_found { exit }
  END { 
    print volume, mute 
  }
')

if [[ $MUTE == "yes" ]]; then
    echo "󰝟 $VOLUME%"
elif [[ $MUTE == "no" && $VOLUME -eq 0 ]]; then
    echo "󰖁"
elif [[ $MUTE == "no" && $VOLUME -lt 30 ]]; then
    echo "󰕿 $VOLUME%"
elif [[ $MUTE == "no" && $VOLUME -lt 50 ]]; then
    echo "󰖀 $VOLUME%"
elif [[ $MUTE == "no" && $VOLUME -le 100 ]]; then
    echo "󰕾 $VOLUME%"
elif [[ $MUTE == "no" && $VOLUME -gt 100 ]]; then
    echo "󰝝 $VOLUME%"
fi

