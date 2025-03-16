#!/bin/sh

eval $(xdotool getmouselocation --shell)
x=`echo $X`
y=`echo $Y`

rofi -show drun run -modes drun,run -show-icons -location 1 -theme-str "mainbox {children: [listview,message,inputbar];} window {width: 35%; x-offset: $x; y-offset: $y; border: 0px;} listview {padding: 6px; lines: 10; columns: 1; scrollbar: true;} element-icon {size: 37px;} inputbar {padding: 0px 6px 6px 6px; children: [prompt,entry,mode-switcher];}" -hover-select -me-select-entry '' -me-accept-entry '!MousePrimary'
