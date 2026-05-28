#include <stdio.h>
#include <unistd.h>

int main(){
for (int i = 0; i < 2; i++) {        // 🔄 Outer Loop (Baris)
    for (int j = 0; j < 3; j++) {// 🔄 Inner Loop (Kolom)
        printf("(%d,%d) ", i, j);// 🖨️ Cetak Koordinat
    }
    printf("\n");                    // ↩️ Turun ke baris baru
}
}
// BEEN FILLING MY BRAIN's GAP,IT'S IN UNDERSTANDING MENTAL MODEL OF NESTED STATEMENT.
