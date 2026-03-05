#include <stdio.h>

int main() {
    int jam, menit, totalMenit;
    int batasWaktu = 7 * 60 + 0; // 07.00 dikonversi ke menit (420 menit)

    printf("Masukkan waktu (HH.MM): ");
    // Mengambil input jam dan menit secara terpisah
    scanf("%d.%d", &jam, &menit);

    // Konversi input ke total menit
    totalMenit = (jam * 60) + menit;

    // Menampilkan output dengan format dua digit (%02d)
    printf("Waktu yang dimasukkan: %02d.%02d\n", jam, menit);

    // Logika perbandingan
    if (totalMenit >= batasWaktu) {
        printf("Status: Anda Terlambat!\n");
    } else {
        printf("Status: Tepat Waktu.\n");
    }

    return 0;
}
