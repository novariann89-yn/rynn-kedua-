#include <stdio.h>

int main(){
  int pilihan;
  while (pilihan != 3){
    printf("\n--- program cash app ---\n");
    printf("1. cek saldo\n");
    printf("2. transfer\n");
    printf("3. keluar\n");
    printf("silahkan masukkan pilihan anda = ");
    scanf("%d", &pilihan);

   if (pilihan == 1){
      printf("\nsaldo anda = 4.500.000 rp\n");
    } else if (pilihan == 2){
      printf("\nTRANSFER BERHASIL!\n");
    } else if (pilihan != 3){
      printf("pilihan invalid! pilih diantara ketiga nomor\n");
    }
  } printf("\nterimakasih telah menggunakan program ini!!\n");

  return 0;
}
