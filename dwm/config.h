/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;	/* border pixel of windows */
static const unsigned int gappx     = 8;        /* gaps between windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 34;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]          = { "JetbrainsMono Nerd Font:size=10:antialias=true:autohint=true"/*, "Symbols Nerd Font:size=10:antialias=true:autohint=true"*/ };
static const char dmenufont[]       = "JetbrainsMono Nerd Font:size=10";
static char normfgcolor[]           = "#000000";
static char normbgcolor[]           = "#000000";
static char selfgcolor[]            = "#000000";
static char selbgcolor[]            = "#000000";
static char normbordercolor[]       = "#282828";
static char selbordercolor[]        = "#83a598";
static const char col_borderbar[]   = "#282828";
static char *colors[][4] = {
       /*               fg           bg           border*/
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor },
	[SchemeStatus]  = { "#83a598", "#282828",  "#000000"  },
//	[SchemeStatus]  = { "#1d2021", "#83a598",  "#000000"  },
	[SchemeTagsSel]  = { "#fb4934", "#282828",  "#000000"  },
//	[SchemeTagsSel]  = { "#1d2021", "#83a598",  "#000000"  },
	[SchemeTagsNorm]  = { "#fb4934", "#282828",  "#000000"  },
//	[SchemeTagsNorm]  = { "#1d2021", "#83a598",  "#000000"  },
	[SchemeInfoSel]  = { "#d3869b", "#282828",  "#000000"  },
//	[SchemeInfoSel]  = { "#1d2021", "#83a598",  "#000000"  },
	[SchemeInfoNorm]  = { "#282828", "#282828",  "#000000"  },
//	[SchemeInfoNorm]  = { "#83a598", "#83a598",  "#000000"  },
};

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = { "", "󰈹", "󰺵", "󰝚", "", "" };
//static const char *tags[] = { "󰎤", "󰎧", "󰎪", "󰎭", "󰎱", "󰎳", "󰎶", "󰎹", "󰎼" };
//static const char *tags[] = { "一", "二", "三", "四", "五", "六" };

static const unsigned int ulinepad	= 2;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance  title           tags mask  iscentered  isfloating  isterminal  noswallow  monitor */
	{ "firefox",            NULL,     NULL,           2,         1,          0,          0,          -1,        -1 },
	{ "Alacritty",          NULL,     NULL,           0,         1,          0,          1,           0,        -1 },
	{ "VirtualBox Manager", NULL,     NULL,           0,         1,          0,          1,           0,        -1 },
	{ "svkbd",              NULL,     NULL,           0,         0,          1,          0,           0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

/* mouse scroll resize */
static const int scrollsensetivity = 30; /* 1 means resize window by 1 pixel for each scroll event */


static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " ",       tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont};
static const char *termcmd[]  = { "alacritty", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "alacritty", "-T", scratchpadname, NULL };
static const char *upvol[] = {"pactl", "set-sink-volume", "@DEFAULT_SINK@", "+2%", NULL };
static const char *downvol[] = {"pactl", "set-sink-volume", "@DEFAULT_SINK@", "-2%", NULL };
static const char *mutevol[] = {"pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };
static const char *brupcmd[] = { "brightnessctl", "set", "1%+", NULL };
static const char *brdowncmd[] = { "brightnessctl", "set", "1%-", NULL };
static const char *rofi[]     = {"rofi", "-show", "drun", "-show-icons", "-icon-theme", "Gruvbox dark plus","-theme-str", "window {width: 70%;}", NULL };
static const char *rofiwifi[]    = {"/home/mandible/.local/bin/rofi-wifi-menu", NULL };
static const char *rofilinks[]    = {"/home/mandible/.local/bin/links", NULL };
static const char *rofisearch[] = {"rofi", "-show", "search", "-modi", "search:/home/mandible/.local/bin/rofi-web-search.py", NULL };
static const char *rofishowwindow[] = {"rofi", "-show", "window", "-show-icons", "-icon-theme", "'Gruvbox dark plus'", "-width", "35", NULL };
static const char *rofipowermenu[] = {"rofi", "-show", "power-menu", "-theme-str", "window {width: 10%;}", "-modi", "power-menu:/home/mandible/.local/bin/rofi-power-menu", NULL };
static const char *ppr[] = {"/home/mandible/.local/bin/ppr.sh", NULL};
static const char *ff[]    = {"firefox", NULL };
static const char *fileman[] = {"pcmanfm", NULL };
static const char *screenshot[] = {"flameshot", "gui", NULL};
static const char *lock[]    = {"slock", NULL };
static const char *clipboard[] = {"/home/mandible/.local/bin/dmenuclip.sh", NULL};
static const char *osk[]    = {"svkbd-mobile-intl", "-g", "1000x400+460+669", NULL };
static const char *mskb[] = { "alacritty", "-T", "Musikcube", "-e", "musikcube", NULL };
static const char *medplaypausecmd[] = { "playerctl", "play-pause", NULL };
static const char *mednextcmd[] = { "playerctl", "next", NULL };
static const char *medprevcmd[] = { "playerctl", "previous", NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier                     	key        			function        	argument */
	{ MODKEY,				XK_l,      			setmfact,       	{.f = +0.01} },
	{ MODKEY,				XK_k,      			focusstack,     	{.i = -1 } },
	{ MODKEY,				XK_j,      			focusstack,     	{.i = +1 } },
	{ MODKEY,				XK_h,      			setmfact,       	{.f = -0.01} },
	{ MODKEY|ShiftMask,			XK_h,      			togglebar,      	{0} },
	{ MODKEY|ShiftMask,			XK_t,      			toggletopbar,   	{0} },
	{ MODKEY,				XK_f,      			zoom,           	{0} },
	{ MODKEY,				XK_d,      			incnmaster,     	{.i = -1 } },
	{ MODKEY,				XK_s,      			incnmaster,     	{.i = +1 } },
	{ MODKEY,				XK_c,      			killclient,     	{0} },
	{ MODKEY,				XK_v,      			setlayout,      	{.v = &layouts[0]} },
	{ MODKEY,				XK_n,      			setlayout,      	{.v = &layouts[1]} },
	{ MODKEY,				XK_m,      			setlayout,      	{.v = &layouts[2]} },
	{ MODKEY,				XK_y,      			setlayout,      	{.v = &layouts[3]} },
	{ MODKEY,				XK_g,      			togglefloating, 	{0} },
	{ MODKEY|ControlMask|ShiftMask,		XK_g,      			center,         	{0} },
	{ MODKEY,				XK_t,      			setlayout,      	{0} },
	{ MODKEY,				XK_space,  			spawn,          	{.v = dmenucmd } },
	{ MODKEY,				XK_Return, 			spawn,          	{.v = termcmd } },
	{ MODKEY,				XK_grave,  			togglescratch,  	{.v = scratchpadcmd } },
	{ MODKEY,				XK_z,      			spawn,          	{.v = rofi } },
	{ MODKEY|ShiftMask,			XK_z,      			spawn,          	{.v = rofiwifi } },
	{ MODKEY,				XK_x,      			spawn,          	{.v = ppr } },
	{ MODKEY,				XK_b,      			spawn,          	{.v = rofilinks } },
	{ MODKEY|ShiftMask,			XK_s,      			spawn,          	{.v = rofisearch } },
	{ MODKEY,				XK_a,      			spawn,          	{.v = rofishowwindow } },
	{ MODKEY,				XK_Escape, 			spawn,          	{.v = rofipowermenu } },
	{ ControlMask|ShiftMask,		XK_f,      			spawn,          	{.v = ff } },
	{ ControlMask|ShiftMask,		XK_Escape, 			spawn,          	SHCMD("alacritty -T btop -e btop") },
	{ MODKEY|ShiftMask,			XK_f,      			spawn,          	{.v = fileman } },
	{ MODKEY|ShiftMask,			XK_l,      			spawn,          	{.v = lock } },
	{ MODKEY|ShiftMask,			XK_k,      			spawn,          	{.v = osk } },
	{ 0,					0xff61,    			spawn,          	{.v = screenshot } },
	{ MODKEY|ShiftMask,			XK_F1,				spawn,          	SHCMD("firefox dwm.suckless.org") },
	{ 0,					XF86XK_AudioRaiseVolume,	spawn,          	{.v = upvol } },
	{ 0,					XF86XK_AudioLowerVolume,	spawn,          	{.v = downvol } },
	{ 0,					XF86XK_AudioMute,		spawn,          	{.v = mutevol } },
	{ MODKEY|ShiftMask,			XK_m,      			spawn,          	{.v = mskb } },
	{ MODKEY|ControlMask|ShiftMask,		XK_m,      			spawn,          	SHCMD("myxer") },
	{ 0,					XF86XK_AudioPlay,	        spawn,          	{.v = medplaypausecmd } },
	{ 0,					XF86XK_AudioNext,       	spawn,          	{.v = mednextcmd } },
	{ 0,					XF86XK_AudioPrev,       	spawn,          	{.v = medprevcmd } },
	{ 0,					XF86XK_MonBrightnessUp, 	spawn,          	{.v = brupcmd} },
	{ 0,			        	XF86XK_MonBrightnessDown,	spawn,          	{.v = brdowncmd} },
	{ MODKEY|ShiftMask,			XK_v,      			spawn,			SHCMD("alacritty -T [Update] -e sudo pacman -Syu") },
	{ MODKEY|ShiftMask,			XK_space,  			spawn,          	{.v = clipboard } },
	{ MODKEY|ControlMask|ShiftMask,		XK_z,      			spawn,          	SHCMD("	/home/mandible/.local/bin/xzoom") },
	{ MODKEY,                       	XK_Tab,    			view,           	{0} },
	{ MODKEY,                       	XK_0,      			view,           	{.ui = ~0 } },
	{ MODKEY|ShiftMask,             	XK_0,      			tag,            	{.ui = ~0 } },
	{ MODKEY,                       	XK_comma,  			focusmon,       	{.i = -1 } },
	{ MODKEY,                       	XK_period, 			focusmon,       	{.i = +1 } },
	{ MODKEY|ShiftMask,             	XK_comma,  			tagmon,         	{.i = -1 } },
	{ MODKEY|ShiftMask,             	XK_period, 			tagmon,         	{.i = +1 } },
	{ MODKEY,                       	XK_minus,  			setgaps,        	{.i = -1 } },
	{ MODKEY,                       	XK_equal,  			setgaps,        	{.i = +1 } },
	{ MODKEY|ShiftMask,             	XK_equal,  			setgaps,        	{.i =  0 } },
	{ MODKEY,                       	XK_F5,     			xrdb,           	{.v = NULL } },
	TAGKEYS(                        	XK_1,                      0)
	TAGKEYS(                        	XK_2,                      1)
	TAGKEYS(                        	XK_3,                      2)
	TAGKEYS(                        	XK_4,                      3)
	TAGKEYS(                        	XK_5,                      4)
	TAGKEYS(                        	XK_6,                      5)
	TAGKEYS(                        	XK_7,                      6)
	TAGKEYS(                        	XK_8,                      7)
	TAGKEYS(                        	XK_9,                      8)
	{ MODKEY|ShiftMask,             	XK_c,      			quit,           	{0} },
	{ MODKEY|ControlMask|ShiftMask, 	XK_c,      			spawn,          	SHCMD("pkill -u mandible") },
};

/* resizemousescroll direction argument list */
static const int scrollargs[][2] = {
	/* width change         height change */
	{ +scrollsensetivity,	0 },
	{ -scrollsensetivity,	0 },
	{ 0,   +scrollsensetivity },
	{ 0,   -scrollsensetivity },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask     	button          function        	argument */
	{ ClkLtSymbol,          0,             	Button1,        setlayout,      	{0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      	{.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           	{0} },
	{ ClkStatusText,        0,              Button1,        spawn,          	SHCMD("gnome-control-center wifi") },
	{ ClkStatusText,        0,              Button3,        spawn,          	SHCMD("alacritty -T htop -e htop") },
	{ ClkStatusText,        0,              Button2,        spawn,          	SHCMD("alacritty -e nvim /home/mandible/.local/src/slstatus/config.h") },
	{ ClkStatusText,        MODKEY,         Button2,        spawn,          	SHCMD("alacritty -e nvim /home/mandible/.local/src/dwm/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      	{0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, 	{0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    	{0} },
	{ ClkClientWin,         MODKEY,         Button4,        resizemousescroll, 	{.v = &scrollargs[0]} },
	{ ClkClientWin,         MODKEY,         Button5,        resizemousescroll, 	{.v = &scrollargs[1]} },
	{ ClkClientWin,         MODKEY,         Button6,        resizemousescroll, 	{.v = &scrollargs[2]} },
	{ ClkClientWin,         MODKEY,         Button7,        resizemousescroll, 	{.v = &scrollargs[3]} },
	{ ClkTagBar,            0,              Button1,        view,           	{0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     	{0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            	{0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      	{0} },
	{ ClkRootWin,           0,              Button3,        spawn,          	SHCMD("jgmenu_run") },
};
