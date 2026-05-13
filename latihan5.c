#include <stdio.h>
#include <stdbool.h>
#include <string.h>   // Butuh ini untuk fungsi strcmp()

int main() {
    bool isSeger;      // Boolean: true atau false
    char yesno[10];    // String untuk menampung input "yes" atau "no"

    printf("ketik yes kalau seger dan no kalau tidak.. ");
    scanf("%s", yesno);

    // Periksa string yang dimasukkan user, ubah jadi boolean
    if (strcmp(yesno, "yes") == 0) {
        isSeger = true;   // User ketik "yes" → minuman seger
    } else {
        isSeger = false;  // Selain "yes" → tidak seger
    }

    // Sekarang gunakan boolean di if-else
    if (isSeger == true) {
        printf("iya seger bro minumannya\n");
    } else {
        printf("kagak seger minumannya\n");
    }

    return 0;
}

