#!/bin/bash

# Define the options
options=" Performance\n Balanced\n󰌪 Power-saver"

# Display the options in a Rofi menu
chosen=$(echo -e "$options" | rofi -dmenu -i -p "Power Profile [current: $(powerprofilesctl get)]:" -theme-str 'window {width: 25%;}')

# Act based on the chosen option
case "$chosen" in
    ' Performance')
        powerprofilesctl set performance
        ;;
    ' Balanced')
        powerprofilesctl set balanced
        ;;
    '󰌪 Power-saver')
        powerprofilesctl set power-saver
        ;;

    *)
        exit 1
        ;;
esac
