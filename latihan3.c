#include <stdio.h>

int main(){

  // VALIDASI ANGKA 
  int angka;
  printf("masukkan angka positif = ");
  scanf("%d", &angka);

  while (angka <= 0){
    printf("invalid! masukkan ulang = ");
    scanf("%d", &angka);
  } 
  printf("valid! oke\n");


  //CASH APP PROGRAM
  int num;
  printf("\n↓↓↓ Money App Program ↓↓↓ \n");
  printf("1. lihat saldo\n"
         "2. transfer\n"
         "3. keluar\n");
  printf("pilih = ");
  scanf("%d", &num);
  while (num !=3){
    if (num == 1){
      printf("saldo kamu 1.400.000 rupiah\n");
      scanf("%d", &num);
    } else if (num == 2){
      printf("TRANSFER BERHASIL!\n");
      scanf("%d", &num);
    } else {
      printf("invalid!\n");
    }
    printf("1. lihat saldo\n"
           "2. transfer\n"
           "3. keluar\n");
    printf("pilih = ");
    scanf("%d", &num);

  }
  printf("thank you\n");
  return 0;
}
