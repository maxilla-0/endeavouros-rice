#!/bin/bash

# Fetch battery capacity and state in a single call to upower
UPINFO=$(upower -i /org/freedesktop/UPower/devices/battery_BAT1)
BAT=$(echo "$UPINFO" | awk '/percentage/ {gsub("%", ""); print $2}')
STATE=$(echo "$UPINFO" | awk '/state/ {print $2}')

# Determine battery icon
if [[ $STATE == "charging" || $STATE == "fully-charged" ]]; then
  ICON="󰂄"
else
  if (( BAT < 5 )); then
    ICON="󰂎"
  elif (( BAT < 25 )); then
    ICON="󰁺"
  elif (( BAT < 50 )); then
    ICON="󰁽"
  elif (( BAT < 75 )); then
    ICON="󰁿"
  elif (( BAT < 100 )); then
    ICON="󰂂"
  elif (( BAT == 100 )); then
    ICON="󰁹"
  fi
fi

# Fetch power profile
PP=$(powerprofilesctl get)

# Determine power profile icon
case $PP in
  performance)
    PP_ICON=""
    ;;
  balanced)
    PP_ICON=""
    ;;
  power-saver)
    PP_ICON="󰌪"
    ;;
esac

# Output the result
echo "$ICON $BAT%|$PP_ICON"

