#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

  int spasi=40;
  char a[50]="jenis jenis format specifier\n \n";
  printf("%*s",spasi, a);

  printf("   dengan penjelasan simpel saja\n"
         "1. 'persen'd adalah untuk integer data type atau angka bulat\n"
         "2. 'persen'f adalah untuk float atau angka desimal atau pecahan\n"
         "3. 'persen'lf adalah double untuk desimal juga but dengan memori lebih besar\n"
         "4. 'persen'c adalah untuk charachter yaitu berisi satu karakter\n"
         "5. 'persen's adalah untuk string or charachter dengan ukuran\n \n");

  char arit[40]="Arithmetic Operations\n";
  printf("%40s\n", arit);
  printf("dimana ini menggunakan header file <math.h>\n"
         "aku tidak perlu menghafalnya karena belum menemukan\n"
         "real use case untuk itu, aku akan belajar jika menemukan\n \n \n");

  char userin [50]="User input\n \n";
  printf("%30s", userin);

  char nem[10];
  char fullnem[30];
  printf("masukkan nama panggilan kamu!.. ");
  scanf("%s", nem);

  printf("masukkan nama panjang kamu!.. ");
  (void)getchar();
  fgets(fullnem, sizeof(fullnem), stdin);
  fullnem[strcspn(fullnem, "\n")]=0;
  printf("\n");

  printf("halooo perkenalkan nama aku %s\n", nem );
  printf("perkenalkan, saya %s\n", fullnem);


return 0;
}
