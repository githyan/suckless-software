/* See LICENSE file fThunderbird'or copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static const unsigned int alpha = 0xb0/* 0xa0 */ /* 0xff */;
static int centered = 1;                    /* -c option; centers dmenu on screen */
static int min_width = 500;                    /* minimum width when centered */
static const float menu_height_ratio = 4.0f;  /* This is the ratio used in the original calculation */
/* -fn option overrides fonts[0]; default X11 font or font set */
#include "themes/gruvbox.h"
#include "/home/archaen/.cache/wal/colors-wal-dmenu.h"
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *symbol_1 = "<";
static const char *symbol_2 = ">";
static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm] = { OPAQUE, alpha },
	[SchemeSel] = { OPAQUE, alpha },
	[SchemeOut] = { OPAQUE, alpha },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;
/* -h option; minimum height of a menu line */
static unsigned int lineheight = 0;
static unsigned int min_lineheight = 8;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 3;
