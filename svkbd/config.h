static const Bool wmborder = True;
static int fontsize = 20;
/* overlay delay in seconds */
static double overlay_delay = 0.50;
/* repeat delay in seconds, will not work on keys with overlays */
static double repeat_delay = 0.75;
/* scan rate in microseconds, affects key repetition rate */
static int scan_rate = 50;
/* one row of keys takes up 1/x of the screen height */
static int heightfactor = 14;
static int xspacing = 5;
static int yspacing = 5;
static const char *defaultfonts[] = {
	"JetbrainsMono Nerd Font Mono:size=20"
};
static const char *defaultcolors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { "#fbf1c7", "#282828" },
	[SchemeNormShift] = { "#83a598", "#282828" },
	[SchemeNormABC] = { "#ebdbb2", "#282828" },
	[SchemeNormABCShift] = { "#83a598", "#282828" },
	[SchemePress] = { "#282828", "#98971a" },
	[SchemePressShift] = { "#282828", "#98971a" },
	[SchemeHighlight] = { "#282828", "#fe8019" },
	[SchemeHighlightShift] = { "#282828", "#fe8019" },
	[SchemeOverlay] = { "#d5c4a1", "#1d2021" },
	[SchemeOverlayShift] = { "#bdae93", "#1d2021" },
	[SchemeWindow] = { "#d65d0e", "#282828" },
};

