#! /bin/bash

echo $(cat /tmp/tmpclip.txt | dmenu -l 10 -p 'Clipboard:') | tr -d '\n' | xclip -sel c
