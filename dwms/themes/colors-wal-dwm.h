static const char *fonts[] = { "FiraCode Nerd Font:style=Medium:size=10" };

static const char normfgcolor[] = "#e9decc";
static const char normbgcolor[] = "#191c24";
static const char normbordercolor[] = "#a39b8e";

static const char selfgcolor[] = "#e9decc";
static const char selbgcolor[] = "#798C8F";
static const char selbordercolor[] = "#e9decc";

static const char urg_fg[] = "#e9decc";
static const char urg_bg[] = "#6F7587";
static const char urg_border[] = "#6F7587";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { normfgcolor,     normbgcolor,   normbordercolor }, // unfocused wins
    [SchemeTagsNorm]  = { selfgcolor,      selbgcolor,    selbordercolor },  // the focused win
    [SchemeSel] =  { urg_fg,      urg_bg,    urg_border },
};
