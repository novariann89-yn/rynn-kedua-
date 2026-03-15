#include <stdio.h>
#include <string.h>

int main(){

  int nomor;
  char namapembeli[10];
  char namabarang[10];
  float harga;
  char matauang;
  char ok[3];

  // user input excercise lagi

  printf("~~~ MOHON ISI APAPUN DIBAWAH INI DENGAN BENAR ~~~\n");
  printf("kamu mengerti? (yes/no) ");
  scanf("%s", ok);
  printf("jawaban kamu: %s. bagus!\n \n", ok);

  printf("masukkan nomor urut anda: ");
  scanf("%d", &nomor);

  
  printf("masukkan nama lengkap anda: ");
  fgets(namapembeli, sizeof(namapembeli), stdin);
  namapembeli[strcspn(namapembeli, "\n")]=0;

  printf("masukkan nama barang: ");
  fgets(namabarang, sizeof(namabarang), stdin);
  namabarang[strcspn(namabarang, "\n")]=0;

  printf("masukkan harga barang (spesifik): ");
  scanf("%f", &harga);
  
  (void)getchar();
  printf("masukkan simbol mata uang-nya: ");
  scanf(" %c", &matauang);

  printf("\nnomor urut anda = %d\n", nomor);
  printf("nama anda = %s\n", namapembeli);
  printf("nama barang anda = %s\n", namabarang);
  printf("harga barang anda = %f\n", harga);
  printf("simbol mata uang anda = %c\n \n", matauang);

  printf("nomor urut anda %d, lalu nama anda itu %s\n,"
         "setelah itu nama barang anda %s, yang harganya %f\n"
         "dann simbol mata uangnya iti %c\n", nomor, namapembeli,
         namabarang, harga, matauang);

  printf("dah gt aj.");

  return 0;
  
}
