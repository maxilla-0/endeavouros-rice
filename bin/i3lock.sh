#!/bin/sh

BLANK='#28282866'
CLEAR='#92837466'
DEFAULT='#ebdbb266'
TEXT='#fbf1c7'
WRONG='#fb4934'
VERIFYING='#fabd2f'
FONT='JetbrainsMono Nerd Font Propo'
#WALL=$(grep '^file=' ~/.config/nitrogen/bg-saved.cfg | cut -d'=' -f2)
#--image=$WALL -F		\
i3lock				\
--ignore-empty-password		\
--nofork			\
--color=1d202166		\
--pointer=default		\
--insidever-color=$CLEAR	\
--ringver-color=$VERIFYING	\
\
--insidewrong-color=$CLEAR	\
--ringwrong-color=$WRONG	\
\
--inside-color=$BLANK		\
--ring-color=$DEFAULT		\
--line-color=$BLANK		\
--separator-color=$DEFAULT	\
\
--verif-color=$TEXT		\
--wrong-color=$TEXT		\
--time-color=$TEXT		\
--date-color=$TEXT		\
--layout-color=$TEXT		\
--keyhl-color=$WRONG		\
--bshl-color=$WRONG		\
--greeter-color=$TEXT		\
\
--radius 400:20			\
--ring-width 12			\
--screen 1			\
--clock				\
--time-str="%I:%M %p"		\
--date-str="%A, %B %d, %Y"	\
--verif-text="Verifying..."	\
--wrong-text="WRONG!"		\
--noinput-text="No input"	\
--lock-text="Locking..."	\
--lockfailed-text="Lock failed :(" \
--greeter-text="Type password to unlock ..." \
\
--pass-media-keys		\
--pass-screen-keys		\
--pass-power-keys		\
--pass-volume-keys		\
\
--time-font=$FONT		\
--time-size=100			\
--date-font=$FONT		\
--date-size=45			\
--verif-font=$FONT		\
--verif-size=50			\
--wrong-font=$FONT		\
--wrong-size=50			\
--greeter-font=$FONT		\
--greeter-size=15		\
\
--ind-pos="w/2:h/2"		\
--time-pos="w/2:h/2 - 25"	\
--date-pos="w/2:h/2 + 45"	\
--greeter-pos="w-150:45"	\
--bar-indicator			\
--bar-pos="w/2 - 500:h/2 + 85"	\
--bar-color=$BLANK		\
--bar-total-width 1000		\
#--timeoutline-width=1		\
#--timeoutline-color=282828	\
#--dateoutline-width=1		\
#--dateoutline-color=282828	\
#--greeter-pos="w-150:45"	\
#--ind-pos="w-90:h-90"		\
#--time-pos="230:h-100"		\
#--date-pos="230:h-60"		\
#--greeteroutline-color=282828	\
#--greeteroutline-width=1	\
