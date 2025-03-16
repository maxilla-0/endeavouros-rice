/* See LICENSE file for copyright and license details. */

/* 32 FUCKING PATCHES APPLIED, VERY BLOATED DWM
 * alwaysontop
 * activetagindicatorbar
 * adjacenttag
 * alternativetags
 * autoraise_windows
 * barpadding
 * bottomstack
 * center
 * clientmonoclesymbol
 * colorbar
 * cursorwarp
 * decorhints
 * dwmc
 * fibonacci
 * launchers
 * movecenter
 * movestack
 * preserveonrestart
 * preview-all-windows
 * refreshrate
 * resizecorners
 * scratchpad
 * smartborders
 * statusbutton
 * swallow
 * tagfun
 * tapresize
 * tiledmove
 * toggletopbar-barpadding
 * truecenteredtitle
 * underlinetags
 * vanitygaps */

/* appearance */
static const unsigned int borderpx  = 2;	/* border pixel of windows */
static const unsigned int gappih    = 6;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 6;       /* vert inner gap between windows */
static const unsigned int gappoh    = 6;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 6;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int vertpad            = 6;	/* vertical padding of bar */
static const int sidepad            = 6;	/* horizontal padding of bar */
static const unsigned int snap      = 6;	/* snap pixel */
static const int swallowfloating    = 0;	/* 1 means swallow floating windows by default */
static const int showbar            = 1;	/* 0 means no bar */
static const int topbar             = 1;	/* 0 means bottom bar */
static const char buttonbar[]       = "";
static const int user_bh            = 36;	/* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]          = { "Jetbrains Mono:size=10:antialias=true:autohint=true", "Symbols Nerd Font:size=10.5:antialias=true:autohint=true" };
static const char dmenufont[]       = "JetbrainsMono Nerd Font Propo:size=10";
static const char normfgcolor[]           = "#000000";
static const char normbgcolor[]           = "#000000";
static const char selfgcolor[]            = "#000000";
static const char selbgcolor[]            = "#000000";
static const char normbordercolor[]       = "#282828";
static const char selbordercolor[]        = "#bdae93";
static const char *colors[][3] = {
	/*              		fg           bg           border*/
	[SchemeNorm]		= { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]		= { selfgcolor,  selbgcolor,  selbordercolor  },
	[SchemeStatus]		= { "#83a598", "#282828",  "#000000" },
	[SchemeTagsSel]		= { "#fb4934", "#1d2021",  "#000000" },
	[SchemeTagsNorm]	= { "#fb4934", "#1d2021",  "#000000" },
	[SchemeInfoSel]		= { "#d3869b", "#1d2021",  "#000000" },//d3869b
	[SchemeInfoNorm]	= { "#1d2021", "#1d2021",  "#000000" },
	[SchemeLtSymbol]	= { "#b16286", "#3c3836",  "#000000" },
	[SchemeStatusButton]	= { "#fbf1c7", "#3c3836",  "#000000" },
	[SchemeLauncher]	= { "#b16286", "#282828",  "#000000" },
};

/* tagging */
static const char *tags[] = { "", "󰈹", "", "", "", "" };
static const char *tagsalt[] = { "1", "2", "3", "4", "5", "6" };
static const int momentaryalttags = 0; /* 1 means alttags will show only when key is held down*/

static const unsigned int ulinepad	= 6;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

/* launcher commands (They must be NULL terminated) */
static const char* Launch1[]      = { "/home/mandible/.local/bin/systray.sh", NULL };
//static const char* Launch2[]      = { "blueman-manager", NULL };
//static const char* Launch3[]      = { "alacritty", "-T", "Wi-Fi", "-e", "nmtui", NULL };
//static const char* Launch3[]      = { "/home/mandible/.local/bin/rofi-scripts/rofi-wifi-menu", NULL };
static const char* Launch4[]      = { "flameshot", "full", NULL };
//static const char* Launch5[]      = { "pcmanfm", NULL };
//static const char* Launch6[]      = { "svkbd-mobile-intl", "-g", "1000x400+460+669", NULL };
static const char* Launch7[]      = { "nitrogen", "--set-zoom-fill", "--random", "/home/mandible/Pictures/Wallpapers/gruvbox-wallpapers", "--save", NULL };
//static const char* Launch8[]      = { "boomer", NULL };
//static const char* Launch9[]      = { "rofi", "-show", "Power Menu", "-modes", "Power Menu:/home/mandible/.local/bin/rofi-scripts/rofi-power-menu ", "-theme-str", "window {width: 10%; x-offset: 498; y-offset: 48; border: 0px; border-radius: 0px;} inputbar {children: [prompt];}", "-hover-select", "-me-select-entry", "", "-me-accept-entry", "!MousePrimary", "-location", "1", NULL };
static const char* Launch10[]     = { "dwmc", "previewallwin", NULL };

static const Launcher launchers[] = {
       /* command	name to display */
	{ Launch1,	"󱊔" },
	//{ Launch8,	"" },
	//{ Launch6,	"󰌌" },
	//{ Launch2,	"" },
	//{ Launch3,	"" },
	{ Launch4,	"" },
	{ Launch7,	"󰸉" },
	//{ Launch9,	"" },
	{ Launch10,	"󱂬" },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance  title           tags mask       iscentered  isalwaysontop  isfloating  isterminal  noswallow  monitor */
	{ "firefox",            NULL,     NULL,           1 << 1,         1,          0,             0,          0,          -1,        -1 },
	{ "Alacritty",          NULL,     NULL,           0,              1,          0,             0,          1,           0,        -1 },
	{ "VirtualBox Manager", NULL,     NULL,           1 << 5,         1,          0,             0,          0,           1,        -1 },
	{ "TelegramDesktop",    NULL,     NULL,           1 << 4,         1,          0,             0,          0,           0,        -1 },
	{ "steam",              NULL,     NULL,           1 << 2,         1,          0,             0,          0,          -1,        -1 },
	{ "dotnet",             NULL,     NULL,           1 << 2,         1,          0,             0,          0,          -1,        -1 },
	{ "svkbd",              NULL,     NULL,           0,              0,          1,             1,          0,           0,        -1 },
	{ "pavucontrol",	NULL,     NULL,           0,              1,          0,             1,          0,           0,        -1 },
	{ "Blueman-manager",	NULL,     NULL,           0,              1,          0,             1,          0,           0,        -1 },
	{ "stalonetray",	NULL,     NULL,           0,              0,          1,             1,          0,           0,        -1 },
	{ "Pcmanfm",		NULL,     "Execute File", 0,              1,          0,             1,          0,           0,        -1 },
	{ "activate-linux",	NULL,     NULL,           0,              0,          1,             0,          0,           0,        -1 },
	{ "Eww",		NULL,     NULL,           0,              0,          1,             1,          0,           0,        -1 },
	{ "Oneko",              NULL,     NULL,           0,              0,          1,             1,          0,           0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 0;    /* 1 means respect decoration hints */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "vanitygaps.c"
#include "movestack.c"

/* mouse scroll resize */
static const int scrollsensetivity = 30; /* 1 means resize window by 1 pixel for each scroll event */


static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "󰙀",       tile },    /* first entry is default */
	{ "",       NULL },    /* no layout function means floating behavior */
	{ "󰎣",       monocle },
	{ "",       bstack },
	{ "",       spiral },
	{ "",       dwindle },
	{ NULL,      NULL },
};

/* custom symbols for nr. of clients in monocle layout */
/* when clients >= LENGTH(monocles), uses the last element */
static const char *monocles[] = { "󰎤", "󰼐", "󰼑", "󰼒", "󰼓", "󰼔", "󰼕", "󰼖", "󰼗", "󰼘" };

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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "alacritty", "-T", scratchpadname, NULL };
/*static const char *upvol[] = { "sh", "-c", "pamixer -i 2;pkill -RTMIN+1 slstatus", NULL };
static const char *upvolalt[] = { "sh", "-c", "pamixer -i 1;pkill -RTMIN+1 slstatus", NULL };
static const char *downvol[] = { "sh", "-c", "pamixer -d 2;pkill -RTMIN+1 slstatus", NULL };
static const char *downvolalt[] = { "sh", "-c", "pamixer -d 1;pkill -RTMIN+1 slstatus", NULL };
static const char *mutevol[] = { "sh", "-c", "pamixer -t;pkill -RTMIN+1 slstatus", NULL };*/
static const char *upvol[] = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ +2%;pkill -10 slstatus", NULL };
static const char *upvolalt[] = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ +1%;pkill -10 slstatus", NULL };
static const char *downvol[] = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ -2%;pkill -10 slstatus", NULL };
static const char *downvolalt[] = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ -1%;pkill -10 slstatus", NULL };
static const char *mutevol[] = { "sh", "-c", "pactl set-sink-mute @DEFAULT_SINK@ toggle;pkill -10 slstatus", NULL };
static const char *brupcmd[] = { "brightnessctl", "set", "1%+", NULL };
static const char *brdowncmd[] = { "brightnessctl", "set", "1%-", NULL };
static const char *rofi[]     = { "rofi", "-show", "drun", "-show-icons", "-theme-str", "window {width: 70%;}", NULL };
static const char *rofiwifi[]    = { "/home/mandible/.local/bin/rofi-scripts/rofi-wifi-menu", NULL };
static const char *rofilinks[]    = { "/home/mandible/.local/bin/rofi-scripts/links", NULL };
static const char *rofisearch[] = { "rofi", "-show", "Search", "-modi", "Search:/home/mandible/.local/bin/rofi-scripts/rofi-web-search.py", "-theme-str", "mainbox {children: [inputbar,message,listview];} inputbar {children: [prompt,entry];}", NULL };
static const char *rofishowwindow[] = { "rofi", "-show", "window", "-show-icons", "-theme-str", "mainbox {children: [inputbar,message,listview];} window {width: 50%;} inputbar {children: [prompt,entry];}", NULL };
static const char *rofipowermenu[] = { "rofi", "-show", "Power Menu", "-theme-str", "mainbox {children: [message,listview];} window {width: 10%; x-offset: -12; border: 0px; border-radius: 0px;} listview {padding: 6px;}", "-modi", "Power Menu:/home/mandible/.local/bin/rofi-scripts/rofi-power-menu", "-location", "4", NULL };
static const char *ppr[] = { "rofi", "-show", "powerprofile", "-modes", "powerprofile:/home/mandible/.local/bin/rofi-scripts/ppr.sh", "-location", "3", "-theme-str", "mainbox {children: [message,listview];} window {width: 12.5%; border: 0px; border-radius: 0px; x-offset: -12; y-offset: 12px;} inputbar {enabled: false;} message {margin: 6px;} listview {lines: 3; columns: 1; padding: 0px 6px 6px 6px;}", "-hover-select", "-me-select-entry", "", "-me-accept-entry", "!MousePrimary", NULL };
static const char *ff[]    = { "firefox", NULL };
static const char *fileman[] = { "pcmanfm", NULL };
static const char *screenshot[] = { "flameshot", "gui", NULL };
static const char *lock[]    = { "/home/mandible/.local/bin/i3lock.sh", NULL };
static const char *clipboard[] = { "/home/mandible/.local/bin/dmenuclip.sh", NULL };
static const char *osk[]    = { "svkbd-mobile-intl", "-g", "1000x400+460+669", NULL };
static const char *mskb[] = { "alacritty", "-T", "Musikcube", "-e", "musikcube", NULL };
static const char *medplaypausecmd[] = { "playerctl", "play-pause", NULL };
static const char *mednextcmd[] = { "playerctl", "next", NULL };
static const char *medprevcmd[] = { "playerctl", "previous", NULL };
static const char *layoutmenu[] = { "rofi", "-show", "layout-menu", "-modes", "layout-menu:/home/mandible/.local/bin/rofi-scripts/layoutmenu.sh", "-theme-str", "mainbox {children: [inputbar,message,listview];} window {width: 12.3%; border: 0px; border-radius: 0px; x-offset: 294; y-offset: 48;} inputbar {enabled: false; children: [prompt];} listview {padding: 6px;}", "-hover-select", "-me-select-entry", "", "-me-accept-entry", "!MousePrimary", "-location", "1", NULL };
static const char *menu[] = { "rofi", "-show", "drun", "run", "filebrowser", "-modes", "drun,run,filebrowser", "-show-icons", "-location", "1", "-theme-str", "mainbox {children: [inputbar,mode-switcher,message,listview];} window {width: 35%; x-offset: 6; y-offset: 48; border: 0px; border-radius: 0px;} listview {lines: 12; columns: 1; scrollbar: true;} element-icon {size: 37px;}", "-hover-select", "-me-select-entry", "", "-me-accept-entry", "!MousePrimary", NULL };
static const char *statusmenu[] = { "rofi", "-show", "", "󰛳", "", "", "", "󰹑", "", "", "", "-modes", ":/home/mandible/.local/bin/rofi-scripts/rdate.sh,󰛳:/home/mandible/.local/bin/rofi-scripts/rnet.sh,:/home/mandible/.local/bin/rofi-scripts/rbt.sh,:/home/mandible/.local/bin/rofi-scripts/rvol.sh,:/home/mandible/.local/bin/rofi-scripts/ppr.sh,󰹑:/home/mandible/.local/bin/rofi-scripts/rres.sh,:/home/mandible/.local/bin/rofi-scripts/rpiss.sh,:/home/mandible/.local/bin/rofi-scripts/rupdt.sh,:/home/mandible/.local/bin/rofi-scripts/rofi-power-menu", "-location", "3", "-theme-str", "mainbox {children: [mode-switcher,message,listview];} window {width: 35%; x-offset: -6; y-offset: 48; border: 0px;} listview {scrollbar: false;} inputbar {enabled: false;} listview {padding: 0px 6px 6px 6px; lines: 13;} element {padding: 10px;} mode-switcher {padding: 6px;} button {padding: 10px;} button selected {background-color: #fb4934;}", "-hover-select", "-me-select-entry", "", "-me-accept-entry", "!MousePrimary", NULL };

static struct {
	void (*func)(const Arg *arg);
	const Arg arg;
} tagfun_cmds[LENGTH(tags)] = {
	[0] = { spawn,	{ .v = termcmd } },
	[1] = { spawn,	{ .v = ff } },
	[2] = { spawn,	SHCMD("steam") },
	[3] = { spawn,	{ .v = mskb } },
	[4] = { spawn,	SHCMD("telegram-desktop")},
	[5] = { spawn,	SHCMD("virtualbox") },
};


#include <X11/XF86keysym.h>

static const Key keys[] = {
	/* modifier                     	key        			function        	argument */
	{ MODKEY,				XK_l,      			setmfact,       	{.f = +0.01 } },
	{ MODKEY,				XK_j,				focusstack,		{.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,		XK_j,				movestack,		{.i = +1 } },
	{ MODKEY,				XK_k,				focusstack,		{.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask,		XK_k,      			movestack,          	{.i = -1 } },
	{ MODKEY,				XK_h,      			setmfact,       	{.f = -0.01 } },
	{ MODKEY|ShiftMask,			XK_h,      			togglebar,      	{0} },
	{ MODKEY|ShiftMask,			XK_t,      			toggletopbar,      	{0} },
	{ MODKEY,				XK_f,      			zoom,           	{0} },
	{ MODKEY,				XK_d,      			incnmaster,     	{.i = -1 } },
	{ MODKEY,				XK_s,      			incnmaster,     	{.i = +1 } },
	{ MODKEY,				XK_c,      			killclient,     	{0} },
	{ MODKEY,				XK_v,      			setlayout,      	{.v = &layouts[0]} },
	{ MODKEY,				XK_n,      			setlayout,      	{.v = &layouts[1]} },
	{ MODKEY,				XK_m,      			setlayout,      	{.v = &layouts[2]} },
	{ MODKEY,				XK_b,      			setlayout,      	{.v = &layouts[3]} },
	{ Mod1Mask,				XK_b,      			setlayout,      	{.v = &layouts[4]} },
	{ Mod1Mask|ShiftMask,			XK_b,      			setlayout,      	{.v = &layouts[5]} },
	{ MODKEY,				XK_g,      			togglefloating, 	{0} },
	{ MODKEY|ShiftMask,			XK_g,      			togglealwaysontop,	{0} },
	{ MODKEY|ControlMask|ShiftMask,		XK_g,      			movecenter,         	{0} },
	{ MODKEY,				XK_t,      			setlayout,      	{0} },
	{ MODKEY,				XK_space, 			spawn,			{.v = dmenucmd } },
	{ MODKEY,				XK_Return, 			spawn,			{.v = termcmd } },
	{ MODKEY,				XK_grave,  			togglescratch,		{.v = scratchpadcmd } },
	{ MODKEY|ShiftMask,			XK_grave,  			spawn,			{.v = scratchpadcmd } },
	{ MODKEY,				XK_z,      			spawn,          	{.v = rofi } },
	{ Mod1Mask,				XK_z,      			spawn,          	{.v = statusmenu } },
	{ MODKEY|ShiftMask,			XK_z,      			spawn,          	{.v = rofiwifi } },
	{ MODKEY,				XK_x,      			spawn,          	{.v = ppr } },
	{ MODKEY|ShiftMask,			XK_b,      			spawn,          	{.v = rofilinks } },
	{ MODKEY|ShiftMask,			XK_s,      			spawn,          	{.v = rofisearch } },
	{ MODKEY,				XK_a,      			spawn,          	{.v = rofishowwindow } },
	{ MODKEY,				XK_Escape, 			spawn,          	{.v = rofipowermenu } },
	{ ControlMask|ShiftMask,		XK_f,      			spawn,          	{.v = ff } },
	{ ControlMask|ShiftMask,		XK_Escape, 			spawn,          	SHCMD("alacritty -T btop -e btop") },
	{ MODKEY|ShiftMask,			XK_f,      			spawn,          	{.v = fileman } },
	{ MODKEY|ShiftMask,			XK_l,      			spawn,          	{.v = lock } },
	{ MODKEY|ShiftMask,			XK_k,      			spawn,          	{.v = osk } },
	{ 0,					0xff61,    			spawn,          	{.v = screenshot } },
	{ ShiftMask,				0xff61,				spawn,			SHCMD("flameshot full") },
	{ MODKEY|ShiftMask,			XK_F1,				spawn,          	SHCMD("firefox dwm.suckless.org") },
	{ 0,					XF86XK_AudioRaiseVolume,	spawn,          	{.v = upvol } },
	{ 0,					XF86XK_AudioLowerVolume,	spawn,          	{.v = downvol } },
	{ 0,					XF86XK_AudioMute,		spawn,          	{.v = mutevol } },
	{ MODKEY|ShiftMask,			XK_m,      			spawn,          	{.v = mskb } },
	{ MODKEY|ControlMask|ShiftMask,		XK_m,      			spawn,          	SHCMD("myxer") },
	{ 0,					XF86XK_AudioPlay,	        spawn,          	{.v = medplaypausecmd } },
	{ 0,					XF86XK_AudioNext,       	spawn,          	{.v = mednextcmd } },
	{ 0,					XF86XK_AudioPrev,       	spawn,          	{.v = medprevcmd } },
	{ 0,					XF86XK_MonBrightnessUp, 	spawn,          	{.v = brupcmd } },
	{ 0,			        	XF86XK_MonBrightnessDown,	spawn,          	{.v = brdowncmd } },
	{ MODKEY|ShiftMask,			XK_v,      			spawn,			SHCMD("alacritty -T Update -e sudo pacman -Syu") },
	{ MODKEY|ShiftMask,			XK_space,  			spawn,          	{.v = clipboard } },
	{ MODKEY|ControlMask|ShiftMask,		XK_z,      			spawn,          	SHCMD("boomer") },
	{ MODKEY|ShiftMask,                    	XK_Tab,    			view,           	{0} },
	{ MODKEY,				XK_Tab,				previewallwin,		{0} },
	{ MODKEY,                       	XK_0,      			view,           	{.ui = ~0 } },
	{ MODKEY|ShiftMask,             	XK_0,      			tag,            	{.ui = ~0 } },
	{ MODKEY,                       	XK_comma,  			focusmon,       	{.i = -1 } },
	{ MODKEY,                       	XK_period, 			focusmon,       	{.i = +1 } },
	{ MODKEY|ShiftMask,             	XK_comma,  			tagmon,         	{.i = -1 } },
	{ MODKEY|ShiftMask,             	XK_period, 			tagmon,			{.i = +1 } },
	{ MODKEY,		             	XK_Right, 			viewnext,		{0} },
	{ MODKEY,		             	XK_Left, 			viewprev,		{0} },
	{ MODKEY|ShiftMask,	             	XK_Right, 			tagtonext,		{0} },
	{ MODKEY|ShiftMask,	             	XK_Left, 			tagtoprev,		{0} },
	{ MODKEY,				XK_minus,			incrgaps,		{.i = -1 } },
	{ Mod1Mask,				XK_minus,			incrogaps,		{.i = -1 } },
	{ Mod1Mask,				XK_o,				incrohgaps,		{.i = -1 } },
	{ Mod1Mask|ShiftMask,			XK_o,				incrovgaps,		{.i = -1 } },
	{ Mod1Mask|ShiftMask,			XK_minus,			incrigaps,		{.i = -1 } },
	{ Mod1Mask,				XK_i,				incrihgaps,		{.i = -1 } },
	{ Mod1Mask|ShiftMask,			XK_i,				incrivgaps,		{.i = -1 } },
	{ MODKEY,				XK_equal,			incrgaps,		{.i = +1 } },
	{ Mod1Mask,				XK_equal,			incrogaps,		{.i = +1 } },
	{ Mod1Mask|ControlMask,			XK_o,				incrohgaps,		{.i = +1 } },
	{ Mod1Mask|ControlMask|ShiftMask,	XK_o,				incrovgaps,		{.i = +1 } },
	{ Mod1Mask|ShiftMask,			XK_equal,			incrigaps,		{.i = +1 } },
	{ Mod1Mask|ControlMask,			XK_i,				incrihgaps,		{.i = +1 } },
	{ Mod1Mask|ControlMask|ShiftMask,	XK_i,				incrivgaps,		{.i = +1 } },
	{ MODKEY|ShiftMask,			XK_equal,			defaultgaps,		{0} },
	{ Mod1Mask|ControlMask|ShiftMask,	XK_equal,			togglegaps,		{0} },
	{ MODKEY,				XK_y,				togglealttag,		{0} },
	{ MODKEY,                       	XK_F5,     			spawn,			SHCMD("stalonetray") },
	{ MODKEY|ShiftMask,                  	XK_F5,     			spawn,			SHCMD("pkill stalonetray") },
	{ MODKEY|ShiftMask,             	XK_c,      			quit,           	{0} },
	{ MODKEY|ControlMask|ShiftMask, 	XK_c,      			spawn,	          	SHCMD("mpv --no-video '/home/mandible/.local/share/sounds/Tuco_GET_OUT_Sound_Effect.webm' ; loginctl terminate-session ${XDG_SESSION_ID-}") },
	TAGKEYS(                        	XK_1,                     	0)
	TAGKEYS(                        	XK_2,                     	1)
	TAGKEYS(                        	XK_3,                     	2)
	TAGKEYS(                        	XK_4,                     	3)
	TAGKEYS(                        	XK_5,                     	4)
	TAGKEYS(                        	XK_6,                     	5)
	TAGKEYS(                        	XK_7,                     	6)
	TAGKEYS(                        	XK_8,                     	7)
	TAGKEYS(                        	XK_9,                     	8)
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
static const Button buttons[] = {
	/* click                event mask     	button          function        	argument */
	{ ClkButton,		0,		Button3,	togglescratch,		{.v = scratchpadcmd } },
	{ ClkButton,		MODKEY,		Button3,	spawn,			{.v = scratchpadcmd } },
	{ ClkButton,		0,		Button2,	spawn,			SHCMD("/home/mandible/.local/bin/bar") },
	{ ClkButton,		0,		Button1,	spawn,			{.v = menu } },
	{ ClkLtSymbol,          0,             	Button1,        setlayout,      	{0} },
	{ ClkLtSymbol,          0,             	Button3,        spawn,		      	{.v = layoutmenu } },
	{ ClkWinTitle,          0,              Button2,        zoom,           	{0} },
	{ ClkWinTitle,          0,              Button1,        movemouse,           	{0} },
	{ ClkWinTitle,          0,              Button3,        spawn,           	SHCMD("/home/mandible/.local/bin/window") },
	{ ClkStatusText,        0,              Button1,        spawn,          	{.v = statusmenu } },
	{ ClkStatusText,        0,              Button5,        spawn,          	{.v = upvolalt } },
	{ ClkStatusText,        0,              Button4,        spawn,          	{.v = downvolalt } },
	{ ClkStatusText,        0,              Button3,        spawn,          	{.v = mutevol } },
	{ ClkStatusText,        0,              Button6,        spawn,          	{.v = brupcmd } },
	{ ClkStatusText,        0,              Button7,        spawn,          	{.v = brdowncmd } },
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
	{ ClkTagBar,            0,              Button2,        tagfun,                 {0} },
	{ ClkTagBar,            0,              Button6,        viewnext,               {0} },
	{ ClkTagBar,            0,              Button7,        viewprev,               {0} },
	{ ClkRootWin,           0,              Button3,        spawn,          	SHCMD("jgmenu") },
	//{ ClkRootWin,           0,              Button3,        spawn,          	SHCMD("/home/mandible/.local/bin/menu3") },
};

void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
	{ "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "toggletopbar",   toggletopbar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
	{ "movecenter",     movecenter },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
	{ "movemouse",      movemouse },
	{ "resizemouse",    resizemouse },
	{ "togglealwaysontop", togglealwaysontop },
	{ "previewallwin",  previewallwin },
};
