#!/bin/bash

# --- Biến ---
HOST=$(hostname)
KERNEL=$(uname -r)
NOW=$(date '+%F %T')

# --- Hàm ---
section() {
    local title="$1"
    printf '\n===== %s =====\n' "$title"
}

# --- Điều kiện ---
if [ "$(id -u)" -eq 0 ]; then
    role="[ROOT]"
else
    role="[USER]"
fi

section "THÔNG TIN HỆ THỐNG"
echo "Máy: $HOST"
echo "Kernel: $KERNEL"
echo "Thời điểm: $NOW  $role"

section "PHÂN VÙNG ĐĨA (cảnh báo > 80%)"
# --- Vòng lặp ---
df -h --output=source,pcent,target | tail -n +2 | while read -r src pct tgt; do
    used=${pct%\%}
    if [ "$used" -ge 80 ]; then
        echo "CẢNH BÁO: $tgt ($src) đã dùng $pct"
    else
        echo "OK: $tgt dùng $pct"
    fi
done
