#include <stdio.h>
#include <string.h>

int main(){

  int nomor;
  char namapembeli[20];
  char namabarang[20];
  float harga;
  char matauang[20];
  char ok[20];

  // user input excercise lagi

  printf("~~~ MOHON ISI APAPUN DIBAWAH INI DENGAN BENAR ~~~\n");
  printf("kamu mengerti? (yes/no) ");
  scanf("%s", ok);
  printf("jawaban kamu: %s. bagus!\n \n", ok);

  printf("masukkan nomor urut anda: ");
  scanf("%d", &nomor);

  (void)getchar();
  printf("masukkan nama lengkap anda: ");
  fgets(namapembeli, sizeof(namapembeli), stdin);
  namapembeli[strlen(namapembeli)-1]='\0';

  printf("masukkan nama barang: ");
  fgets(namabarang, sizeof(namabarang), stdin);
  namabarang[strlen(namabarang)-1]='\0';

  printf("masukkan harga barang (spesifik): ");
  scanf("%f", &harga);

  (void)getchar();
  printf("masukkan simbol mata uang-nya: ");
  fgets(matauang, sizeof(matauang), stdin);
  matauang[strlen(matauang)-1]='\0';
  printf("\n");

  printf("\nnomor urut anda = %d\n", nomor);
  printf("nama anda = %s\n", namapembeli);
  printf("nama barang anda = %s\n", namabarang);
  printf("harga barang anda = %.3f\n", harga);
  printf("simbol mata uang anda = %s\n \n", matauang);

  printf("nomor urut anda %d, lalu nama anda itu %s\n,"
         "setelah itu nama barang anda %s, yang harganya %.3f %s\n"
          , nomor, namapembeli,
         namabarang, harga, matauang);

  printf("\ndah gt aj.");

  return 0;
  
}
