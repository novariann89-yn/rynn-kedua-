#include <stdio.h>

int main() {
    int pilihan = 0;
    
    while (pilihan != 3) {          // Selama tidak pilih "Keluar"
        printf("\n=== MENU ===\n");
        printf("1. Lihat saldo\n");
        printf("2. Transfer\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        
        if (pilihan == 1) {
            printf("Saldo: Rp 1.000.000\n");
        } else if (pilihan == 2) {
            printf("Transfer berhasil!\n");
        } else if (pilihan != 3) {
            printf("Pilihan tidak valid!\n");
        }
    }
    
    printf("Sampai jumpa!\n");
    return 0;
}

