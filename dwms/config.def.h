/* See LICENSE file for copyright and license details. */

/* autostart*/
static const char autostartblocksh[] = "autostart_blocking.sh";
static const char autostartsh[] = "autostart.sh";
static const char dwmdir[] = "dwm";
static const char localshare[] = ".local/share";

/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */

static const unsigned int gappih = 5; /* horiz inner gap between windows */
static const unsigned int gappiv = 5; /* vert inner gap between windows */
static const unsigned int gappoh =
    5; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov =
    15; /* vert outer gap between windows and screen edge */
static int smartgaps =
    0; /* 1 means no outer gap when there is only one window */

static const unsigned int systraypinning =
    0; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor
          X */
static const unsigned int systrayonleft =
    0; /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int systraypinningfailfirst =
    1; /* 1: if pinning fails, display systray on the first monitor, False:
          display systray on the last monitor*/
static const int showsystray = 1; /* 0 means no systray */
static const int vertpad = 5;     /* vertical padding of bar */
static const int sidepad = 60;    /* horizontal padding of bar */
static const int showbar = 1;     /* 0 means no bar */
static const int topbar = 1;      /* 0 means bottom bar */
static const int horizpadbar = 2; /* horizontal padding for statusbar */
static const int vertpadbar = 2;  /* vertical padding for statusbar */
static const char *fonts[] = {
    "Iosevka:style:medium:size=12",
    "JetBrainsMono Nerd Font Mono:style:medium:size=19"};
static const char dmenufont[] = "monospace:size=10";

static char normbgcolor[] = "#222222";
static char normbordercolor[] = "#444444";
static char normfgcolor[] = "#bbbbbb";
static char selfgcolor[] = "#eeeeee";
static char selbordercolor[] = "#005577";

/*status2d xrdb colors*/
static char selbgcolor[] = "#005577";
static char termcol0[] = "#000000";  /* black   */
static char termcol1[] = "#ff0000";  /* red     */
static char termcol2[] = "#33ff00";  /* green   */
static char termcol3[] = "#ff0099";  /* yellow  */
static char termcol4[] = "#0066ff";  /* blue    */
static char termcol5[] = "#cc00ff";  /* magenta */
static char termcol6[] = "#00ffff";  /* cyan    */
static char termcol7[] = "#d0d0d0";  /* white   */
static char termcol8[] = "#808080";  /* black   */
static char termcol9[] = "#ff0000";  /* red     */
static char termcol10[] = "#33ff00"; /* green   */
static char termcol11[] = "#ff0099"; /* yellow  */
static char termcol12[] = "#0066ff"; /* blue    */
static char termcol13[] = "#cc00ff"; /* magenta */
static char termcol14[] = "#00ffff"; /* cyan    */
static char termcol15[] = "#ffffff"; /* white   */
static char *termcolor[] = {
    termcol0,  termcol1,  termcol2,  termcol3,  termcol4,  termcol5,
    termcol6,  termcol7,  termcol8,  termcol9,  termcol10, termcol11,
    termcol12, termcol13, termcol14, termcol15,
};

static char *colors[][3] = {
    /*               fg           bg           border   */
    [SchemeNorm] = {normfgcolor, normbgcolor, normbordercolor},
    [SchemeSel] = {selfgcolor, selbgcolor, selbordercolor},
};
/* tagging */
static const char *tags[] = {"", "", "", "", "",
                             "", "", "", ""};
static const char *tagsalt[] = {"", "", "", "", "",
                                "", "", "", ""};

static const int momentaryalttags =
    1; /* 1 means alttags will show only when key is held down*/

static const unsigned int ulinepad =
    2; /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke =
    3; /* thickness / height of the underline */
static const unsigned int ulinevoffset =
    0; /* how far above the bottom of the bar the line should appear */
static const int ulineall =
    0; /* 1 to show underline on all tags, 0 for just the active ones */
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 1, False, -1},
    {"discord", NULL, NULL, 1 << 8, False, -1},
    {"zen-beta", "Navigator", NULL, 1 << 1, False, -1},
    {"dwm", NULL, NULL, 0, False, -1},
    {"steam", "steamwebhelper", "Steam", 1 << 8, 1, -1},
    {"kitty", "kitty", NULL, 0, 0, -1},
    {"Spotify", NULL, NULL, 1 << 2, False, -1},
};

static const char *incvol[] = {"/usr/bin/amixer", "set", "Master", "5%+", NULL};
static const char *decvol[] = {"/usr/bin/amixer", "set", "Master", "5%-", NULL};
static const char *mutevol[] = {"/usr/bin/amixer", "set", "Master", "toggle",
                                NULL};
static const char *scrot[] = {
    "scrot", "/home/archaen/Pictures/screenshot/%Y-%m-%d-%T.png", NULL};
static const char *scrot_select[] = {
    "scrot", "-s", "/home/archaen/Pictures/screenshot/%Y-%m-%d-%T.png", NULL};
/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */
#define FORCE_VSPLIT                                                           \
  1 /* nrowgrid layout: force two clients to always split vertically */
#include "movestack.c"
#include "vanitygaps.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"[M]", monocle},
    {"[@]", spiral},
    {"[\\]", dwindle},
    {"H[]", deck},
    {"TTT", bstack},
    {"===", bstackhoriz},
    {"HHH", grid},
    {"###", nrowgrid},
    {"---", horizgrid},
    {":::", gaplessgrid},
    {"|M|", centeredmaster},
    {">M>", centeredfloatingmaster},
    {"><>", NULL}, /* no layout function means floating behavior */
    {NULL, NULL},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
    "dmenu_run", "-c",           "-l",        "20",       "-fn",
    dmenufont,   "-nb",          normbgcolor, "-nf",      normfgcolor,
    "-sb",       selbordercolor, "-sf",       selfgcolor, NULL};
static const char *termcmd[] = {"st", NULL};

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_grave, togglealttag, {0}},
    {MODKEY, XK_p, spawn, {.v = dmenucmd}},
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY | ShiftMask, XK_j, movestack, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, movestack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_j, movestack, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, movestack, {.i = -1}},
    {MODKEY | ShiftMask, XK_h, setcfact, {.f = +0.25}},
    {MODKEY | ShiftMask, XK_l, setcfact, {.f = -0.25}},
    {MODKEY | ShiftMask, XK_o, setcfact, {.f = 0.00}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY | Mod1Mask, XK_u, incrgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_u, incrgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_i, incrigaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_i, incrigaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_o, incrogaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_o, incrogaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_6, incrihgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_6, incrihgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_7, incrivgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_7, incrivgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_8, incrohgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_8, incrohgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_9, incrovgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_9, incrovgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_0, togglegaps, {0}},
    {MODKEY | Mod1Mask | ShiftMask, XK_0, defaultgaps, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, XK_c, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY | ShiftMask, XK_t, setlayout, {.v = &layouts[1]}},
    {MODKEY | ShiftMask | ControlMask, XK_t, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[3]}},
    {MODKEY | ShiftMask, XK_m, setlayout, {.v = &layouts[4]}},
    {MODKEY | ShiftMask | ControlMask, XK_m, setlayout, {.v = &layouts[5]}},
    {MODKEY, XK_n, setlayout, {.v = &layouts[6]}},
    {MODKEY | ShiftMask, XK_n, setlayout, {.v = &layouts[7]}},
    {MODKEY | ShiftMask | ControlMask, XK_n, setlayout, {.v = &layouts[8]}},

    {MODKEY, XK_f, togglefullscr, {0}},
    {MODKEY | ShiftMask, XK_f, setlayout, {.v = &layouts[9]}},
    {MODKEY | Mod1Mask | ShiftMask, XK_f, setlayout, {.v = &layouts[10]}},
    {MODKEY | ShiftMask | ControlMask, XK_f, setlayout, {.v = &layouts[11]}},

    {MODKEY, XK_g, setlayout, {.v = &layouts[12]}},
    {MODKEY | ShiftMask, XK_g, setlayout, {.v = &layouts[13]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    {MODKEY, XK_F5, xrdb, {.v = NULL}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, quit, {0}},
    {MODKEY | ControlMask | ShiftMask, XK_q, quit, {1}},
    {0, XF86XK_AudioLowerVolume, spawn, {.v = decvol}},
    {0, XF86XK_AudioRaiseVolume, spawn, {.v = incvol}},
    {0, XF86XK_AudioMute, spawn, {.v = mutevol}},
    {0, XK_Print, spawn, {.v = scrot}},
    {ShiftMask, XK_Print, spawn, {.v = scrot_select}},
    {MODKEY, XK_minus, scratchpad_show, {0}},
    {MODKEY | ShiftMask, XK_minus, scratchpad_hide, {0}},
    {MODKEY, XK_equal, scratchpad_remove, {0}},

};
/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
