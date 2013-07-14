/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

#define MODKEY Mod1Mask
#define MONKEY Mod4Mask
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \

/* appearance */
static const char font[]            = "Droid Sans 8";
static const char normbordercolor[] = "#8C8C8C";
static const char normbgcolor[]     = "#232323";
static const char normfgcolor[]     = "#8C8C8C";
static const char selbordercolor[]  = "#4A90D9";
static const char selbgcolor[]      = "#232323";
static const char selfgcolor[]      = "#4A90D9";
static const char urgbgcolor[]      = "#232323";
static const char urgfgcolor[]      = "#DC322F";

/* settings */
static const unsigned int borderpx       = 1;      /* Border pixel of windows */
static const unsigned int snap           = 2;      /* Snap pixel */
static const unsigned int minwsz         = 20;     /* Minimal heigt of a client for smfact */
static const float mfact                 = 0.63;   /* factor of master area size [0.05..0.95] */
static const float smfact                = 0.00;   /* factor of tiled clients [0.05..1.00] */
static const char chatclient[]           = "chat - Skype™"; /* Name of chat client for chatlayout */
static const int nmaster                 = 1;      /* number of clients in master area */
static const Bool showbar                = True;   /* False means no bar */
static const Bool topbar                 = True;   /* False means bottom bar */
static const Bool resizehints            = False;  /* True means respect size hints in tiled resizals */

/* layouts */
static const Layout layouts[] = {
  /* symbol arrange */
	{ "T",  tile },
	{ "C",  chat },
	{ "B",  bstack },
	{ "M",  monocle },
	{ "F",  NULL },
};

/* tagging */
static const Tag tags[] = {
	/* name	     layout       mfact	nmaster */
	{ "1 web",   &layouts[0], -1,	-1 },
	{ "2 term", &layouts[0], -1, -1 },
	{ "3 term",  &layouts[0], -1,	-1 },
	{ "4 misc",  &layouts[0], -1 	-1 },
  { "9 dl",    &layouts[0], -1, -1}
};

/* rules */
static const Rule rules[] = {
    /*WM_CLASS              WM_CLASS    WM_NAME
      class                 instance    title               tags mask   isfloating  monitor */
    { "Firefox",            NULL,       NULL,               1,          False,      -1 },
    { "Skype",              NULL,       NULL,               1 << 1,     False,      -1 },
    { "MPlayer",            NULL,       NULL,               1 << 3,     True,       -1 },
    { "Gimp",               NULL,       NULL,               1 << 3,     False,      -1 },
    { "Transmission-gtk",   NULL,       NULL,               1 << 3,     False,      -1 },
    { "VirtualBox",         NULL,       NULL,               1 << 3,     False,      -1 },
    { "Evince",             NULL,       NULL,               1 << 3,     False,      -1 },
};

/* commands */
static const char *dmenu[]   = { "dmenu_run", "-f", "-p", "Run:", NULL };
static const char *find[]    = { "dmenu_finder", NULL };
static const char *dmfm[]    = { "dmenu_fm", NULL };
static const char *term[]    = { "terminal", NULL };
static const char *scrot[]   = { "scrot", NULL };
static const char *kill[]    = { "xkill", NULL };
static const char *lock[]    = { "slock", NULL };
static const char *halt[]    = { "dmenu_shutdown", NULL };
static const char *volup[]   = { "amixer", "-q", "sset", "Master", "5%+", "unmute", NULL };
static const char *voldown[] = { "amixer", "-q", "sset", "Master", "5%-", "unmute", NULL };
static const char *volmute[] = { "amixer", "-q", "sset", "Master", "toggle", NULL };
static const char *play[]    = { "audtool", "playback-playpause", NULL };
static const char *next[]    = { "audtool", "playlist-advance", NULL };
static const char *prev[]    = { "audtool", "playlist-reverse", NULL };
static const char *stop[]    = { "audtool", "playback-stop", NULL };

/* shortcuts */
static Key keys[] = {
	/* modifier                 key        function        argument */
	{ MODKEY,                   XK_p,                       spawn,          {.v = dmenu } },
	{ MODKEY,                   XK_x,                       spawn,          {.v = kill } },
	{ MODKEY,                   XK_l,                       spawn,          {.v = lock } },
	{ MODKEY,                   XK_Escape,                  spawn,          {.v = halt } },
	{ MODKEY,                   XK_z,                       spawn,          {.v = find } },
	{ MODKEY,                   XK_o,                       spawn,          {.v = dmfm } },
	{ 0,                        XK_Print,                   spawn,          {.v = scrot } },
	{ 0,                        XF86XK_AudioRaiseVolume,    spawn,          {.v = volup } },
	{ 0,                        XF86XK_AudioLowerVolume,    spawn,          {.v = voldown } },
	{ 0,                        XF86XK_AudioMute,           spawn,          {.v = volmute } },
	{ 0,                        XF86XK_AudioPlay,           spawn,          {.v = play } },
	{ 0,                        XF86XK_AudioNext,           spawn,          {.v = next } },
	{ 0,                        XF86XK_AudioPrev,           spawn,          {.v = prev } },
	{ 0,                        XF86XK_AudioStop,           spawn,          {.v = stop } },
	{ MODKEY|ControlMask,       XK_b,                       togglebar,      {0} },
	{ MODKEY|ControlMask,       XK_q,                       quit,           {0} },
	{ MODKEY|ControlMask,       XK_Return,                  spawn,          {.v = term } },
  	{ MODKEY,                   XK_Return,                  zoom,           {0} },
	{ MODKEY,                   XK_Tab,                     view,           {0} },
	{ MODKEY|ShiftMask,         XK_c, 				        killclient,     {0} },
	{ MODKEY,                   XK_space,                   setlayout,      {0} },
  	{ MODKEY,                   XK_j,                       focusstack,     {.i = +1 } },
  	{ MODKEY,                   XK_k,                       focusstack,     {.i = -1 } },
  	{ MODKEY,                   XK_i,                       incnmaster,     {.i = +1 } },
  	{ MODKEY,                   XK_d,                       incnmaster,     {.i = -1 } },
  	{ MODKEY,                   XK_h,                       setmfact,       {.f = -0.05} },
  	{ MODKEY,                   XK_l,                       setmfact,       {.f = +0.05} },
	{ MODKEY,                   XK_Up,                      pushup,         {0} },
	{ MODKEY,                   XK_Down,                    pushdown,       {0} },
	{ MODKEY|ShiftMask,         XK_Left,                    tagcycle,       {.i = -1 } },
	{ MODKEY|ShiftMask,         XK_Right,                   tagcycle,       {.i = +1 } },
	{ MODKEY|ShiftMask,         XK_f,                       togglefloating, {0} },
	{ MODKEY,                   XK_t,                       setlayout,      {.v = &layouts[0] } },
	{ MODKEY,                   XK_c,                       setlayout,      {.v = &layouts[1] } },
	{ MODKEY,                   XK_b,                       setlayout,      {.v = &layouts[2] } },
	{ MODKEY,                   XK_m,                       setlayout,      {.v = &layouts[3] } },
	{ MODKEY,                   XK_f,                       setlayout,      {.v = &layouts[4] } },
	TAGKEYS(                    XK_1,                      0)
	TAGKEYS(                    XK_1,                      0)
	TAGKEYS(                    XK_2,                      1)
	TAGKEYS(                    XK_3,                      2)
	TAGKEYS(                    XK_4,                      3)
  	TAGKEYS(                    XK_9,                      9)
	{ MODKEY,                   XK_a,                       view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,         XK_a,                       tag,            {.ui = ~0 } },
	{ MONKEY,                   XK_Left,                    focusmon,       {.i = -1 } },
	{ MONKEY,                   XK_Right,                   focusmon,       {.i = +1 } },
	{ MONKEY|ShiftMask,         XK_Left,                    tagmon,         {.i = -1 } },
	{ MONKEY|ShiftMask,         XK_Right,                   tagmon,         {.i = +1 } },
};

/* mouse button */
/* click can be ClkLtSymbol, ClkStatusText, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = term } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        tag,            {0} },
};

