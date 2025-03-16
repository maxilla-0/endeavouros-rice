#!/bin/bash

DEFAULT_SINK=$(pactl info | awk -F': ' '/Default Sink/ {print $2}')

read VOLUME MUTE IS_BLUETOOTH < <(pactl list sinks | awk -v default_sink="$DEFAULT_SINK" '
  BEGIN { volume = -1; mute = ""; bluetooth = 0; found = 0 }
  $1 == "Name:" && $2 == default_sink { found = 1 }
  found && /Volume:/ && volume == -1 { 
    sub(/%/, "", $5); 
    volume = $5; 
  } 
  found && /Mute:/ && mute == "" { 
    mute = $2; 
  }
  found && /bluez/ { 
    bluetooth = 1; 
  }
  found && volume != -1 && mute != "" { exit }
  END { 
    print volume, mute, bluetooth 
  }
')

if [[ $MUTE == "yes" ]]; then
    if [[ $IS_BLUETOOTH -eq 1 ]]; then
        echo " $VOLUME% "
    else
        echo " $VOLUME%"
    fi
elif [[ $MUTE == "no" && $VOLUME -le 24 ]]; then
    if [[ $IS_BLUETOOTH -eq 1 ]]; then
        echo " $VOLUME% "
    else
        echo " $VOLUME%"
    fi
elif [[ $MUTE == "no" && $VOLUME -le 59 ]]; then
    if [[ $IS_BLUETOOTH -eq 1 ]]; then
        echo " $VOLUME% "
    else
        echo " $VOLUME%"
    fi
elif [[ $MUTE == "no" && $VOLUME -le 100 ]]; then
    if [[ $IS_BLUETOOTH -eq 1 ]]; then
        echo " $VOLUME% "
    else
        echo " $VOLUME%"
    fi
elif [[ $MUTE == "no" && $VOLUME -gt 100 ]]; then
    if [[ $IS_BLUETOOTH -eq 1 ]]; then
        echo "󰓃 $VOLUME% "
    else
        echo "󰓃 $VOLUME%"
    fi
fi
