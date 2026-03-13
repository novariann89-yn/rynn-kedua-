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

  (void)getchar();
  printf("masukkan nama anda: ");
  fgets(namapembeli, sizeof(namapembeli), stdin);
  strspn[namapembeli(namapembeli, "\n")]=0;

  (void)getchar();
  printf("masukkan nama barang: ");
  fgets(namapembeli, sizeof(namapembeli), stdin);
  strspn[namapembeli(namapembeli, "\n")]=0;

  printf("masukkan harga barang (spesifik): ");
  scanf("%f", &harga);

  printf("masukkan simbol mata uang-nya: \n \n");
  scanf(" %c", matauang);


  printf("nomor urut anda = %d\n", nomor);
  printf("nama anda = %s\n", nama);
  printf("nama barang anda = %s\n", namabarang);
  printf("harga barang anda = %f\n", harga);
  printf("simbol mata uang anda = %c\n \n", );

  printf("dah gt aj.");

  return 0;
  
}
