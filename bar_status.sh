#!/bin/dash

. $HOME/.cache/wal/colors.sh
grey=$color14

wlan() {
  case "$(cat /sys/class/net/wl*/operstate 2>/dev/null)" in
  up) printf "^c$color0^ 󰤨 %s" "^c$color0^Connected" ;;
  down) printf "^c$color^^b$grey^ 󰤭 %s" "^c$color0^Disconnected" ;;
  esac
}
pkg_updates() {
  #updates=$({ timeout 20 doas xbps-install -un 2>/dev/null || true; } | wc -l) # void
  updates=$({ timeout 20 checkupdates 2>/dev/null || true; } | wc -l) # arch
  # updates=$({ timeout 20 aptitude search '~U' 2>/dev/null || true; } | wc -l)  # apt (ubuntu, debian etc)

  if [ -z "$updates" ]; then
    printf "^c$color5^^b$grey^  Fully Up"
  else
    printf "^c$color5^^b$grey^  $updates""Up "
  fi
}
brightness() {
  printf "^c$background^^b$color5^  "
  printf "^c$color0^^b$foreground^ $(cat /sys/class/backlight/*/brightness) "
}
ssd() {
  sval="$(df -lh | awk '{if ($6 == "/") { print $5 }}' | head -1 | cut -d'%' -f1) "
  printf "^b$color3^^c$grey^  "
  printf "^b$grey^^c$color0^ $sval"
}
battery() {
  get_capacity="$(cat /sys/class/power_supply/BAT0/capacity)"
  printf "^c$grey^^b$color3^  "
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

  # [ $interval = 0 ] || [ $(($interval % 3600)) = 0 ] && updates=$(pkg_updates)
  # interval=$((interval + 1))

  # sleep 1 && xsetroot -name "$updates $(battery) $(brightness) $(cpu) $(mem) $(wlan) $(clock)"
  sleep 1 && xsetroot -name "$(wlan)^f5^$(ssd)$(battery)^f5^$(cpu)$(brightness)$(mem)^f5^$(clocks)^d^^d^"
done
