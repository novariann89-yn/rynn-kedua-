#include <stdio.h>

int main(){
  // latihan membuat program menggunakan nested if

  int num;

  printf("pilih nomor antara 1-100 : ");
  scanf("%d", &num);

  if (num >= 1){
    printf("kamu berada di level 1! dimana ini diantara 1-20\n");
    if (num >= 21){
      printf("kamu berada di level 2! dimana ini diantara 21-40\n");
      if (num >= 41){
        printf("kamu berada di level 3! dimana ini diantara 41-60\n");
        if (num >= 61){
          printf("kamu berada di level 4! dimana ini diantara 61-80\n");
          if (num >= 81 && num < 100){
            printf("kamu berada di level 5! dimana ini diantara 81-100\n");
            if (num > 100){
          } else {
            printf("else nya 81>, berarti input kamu 61-80\n");
          }
        } else {
          printf("else nya 61>, berarti input kamu 41-60\n");
        }
      } else {
        printf("else nya 41>, berarti input kamu 21-40\n");
      }
    } else {
      printf("else nya 21>, berarti input kamu 1-20\n");
    }
  } else {
    printf("else nya 1>, berarti input kamu 0\n");
  }
  return 0;

  }
}
