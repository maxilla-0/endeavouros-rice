#!/bin/bash

BAT=$(cat /sys/class/power_supply/BAT1/capacity)
STATE=$(upower -i /org/freedesktop/UPower/devices/battery_BAT1 | awk '/state/ {print $2}')

case $STATE in
  "charging" | "fully-charged")
    ICON="󰂄"
    ;;
  "discharging")
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
    ;;
esac

# Output the result
echo "$ICON $BAT%"

