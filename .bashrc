alias r1='clang hello.c -o hello && ./hello'
alias e1='nvim hello.c'
# ── SYSTEM INFO ──────────────────────────
echo ""
echo "  ┌─────────────────────────────────┐"
echo "  │        TERMUX DASHBOARD         │"
echo "  └─────────────────────────────────┘"
echo ""

# Tanggal & waktu
echo "  📅 $(date '+%A, %d %B %Y  %H:%M:%S')"
echo ""

# RAM
RAM_TOTAL=$(free -m | awk '/Mem:/ {print $2}')
RAM_USED=$(free -m | awk '/Mem:/ {print $3}')
echo "  🧠 RAM    : ${RAM_USED}MB / ${RAM_TOTAL}MB"

# Storage
STORAGE=$(df -h ~/storage/shared 2>/dev/null | awk 'NR==2 {print $3" used / "$2" total"}')
echo "  💾 Storage: $STORAGE"

# IP lokal
IP=$(ip route get 1 2>/dev/null | awk '{print $7; exit}')
echo "  🌐 IP     : ${IP:-tidak terdeteksi}"

# Uptime
echo "  ⏱️  Uptime : $(uptime -p)"

echo ""
echo "  ─────────────────────────────────"
echo ""
