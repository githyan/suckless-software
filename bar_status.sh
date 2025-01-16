#!/bin/dash

. $HOME/.cache/wal/colors.sh
grey=$color14

fsmon() {
  ROOTPART=$(df -h | awk '/\/$/ { print $3}')
  HOMEPART=$(df -h | awk '/\/home/ { print $3}')
  SWAPPART=$(cat /proc/swaps | awk '/\// { print $4 }')

  echo "   $ROOTPART    $HOMEPART    $SWAPPART"
}
volume_alsa() {

  mono=$(amixer -M sget Master | grep Mono: | awk '{ print $2 }')

  if [ -z "$mono" ]; then
    muted=$(amixer -M sget Master | awk 'FNR == 6 { print $7 }' | sed 's/[][]//g')
    vol=$(amixer -M sget Master | awk 'FNR == 6 { print $5 }' | sed 's/[][]//g; s/%//g')
  else
    muted=$(amixer -M sget Master | awk 'FNR == 5 { print $6 }' | sed 's/[][]//g')
    vol=$(amixer -M sget Master | awk 'FNR == 5 { print $4 }' | sed 's/[][]//g; s/%//g')
  fi

  if [ "$muted" = "off" ]; then
    echo " muted"
  else
    if [ "$vol" -ge 65 ]; then
      echo " $vol%"
    elif [ "$vol" -ge 40 ]; then
      echo " $vol%"
    elif [ "$vol" -ge 0 ]; then
      echo " $vol%"
    fi
  fi
}
network() {
  conntype=$(ip route | awk '/default/ { print substr($5,1,1) }')

  if [ -z "$conntype" ]; then
    echo " down"
  elif [ "$conntype" = "e" ]; then
    echo " up"
  elif [ "$conntype" = "w" ]; then
    echo "^c$grey^   $up"
  fi
}
pkg_updates() {
  updates=$({ timeout 20 doas xbps-install -un 2>/dev/null || true; } | wc -l) # void
  # updates=$({ timeout 20 checkupdates 2>/dev/null || true; } | wc -l) # arch
  # updates=$({ timeout 20 aptitude search '~U' 2>/dev/null || true; } | wc -l)  # apt (ubuntu, debian etc)

  if [ -z "$updates" ]; then
    printf "^c$color5^  Fully updates"
  else
    printf "^c$color5^  $updates"" updates "
  fi
}
brightness() {
  printf "^c$background^^b$color5^  "
  printf "^c$color0^^b$foreground^ $(cat /sys/class/backlight/*/brightness) "
}
battery() {
  get_capacity="$(cat /sys/class/power_supply/BAT0/capacity)"
  printf "^c$grey^^b$color3^  "
  printf "^c$color0^^b$grey^ $get_capacity "
}
mem() {
  printf "^c$color0^^b$color5^  "
  printf "^c$color0^^b$foreground^ $(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g) "
}
cpu() {
  cpu_val=$(grep -o "^[^ ]*" /proc/loadavg)
  printf "^b$color5^^c$background^  "
  printf "^b$foreground^ $cpu_val "
}
clocks() {
  printf "^c$grey^^b$color15^ 󱑆 "
  printf "^c$color0^^b$grey^ $(date '+%T') "
}

while true; do
  sleep 1 && xsetroot -name "$(fsmon)^f5^$(volume_alsa)^f5^$(network)^f5^$(battery)^f5^$(cpu)$(brightness)$(mem)^f5^$(clocks)^d^^d^"
done
