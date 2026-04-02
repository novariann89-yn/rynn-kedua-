#include <stdio.h>

int main(){

  int angka;

// ini else if biasa

  printf("pilih angka antara 1 - 3 : ");
  scanf("%d", &angka);

  if (angka == 1){
    printf("lu pilih satu, dh gt aj hehe\n");
  }
  else if (angka == 2){
    printf("lu pilih angka 2, dh gt aja hehe\n");
  }
  else if (angka == 3){
    printf("lu pilih angka 3, dh gt aja hehe\n");
  }
  else {
    printf("masukin angka yg bener dongok lu\n");
  }

  // nah kalo yang ini nested if

  char huruf;
  printf("pilih hurus a, b, atau c : ");
  scanf("%c", &huruf);

  if (huruf == 'a'){
    printf("lu pilih huruf a disini\n");
    if (huruf == 'b'){
      printf("nah lu pilih b, jadi ngelewatin a\n");
      if (huruf == 'c'){
        printf("nah terakhir lu pilih c, berarti ngelewatin a sama b\n");
      } else {
        printf("lu ga pilih c\n");
      }
    } else {
      printf("lu ga pilih b\n");
    } 
  } else {
    printf("lu ga pilih a\n");
  }

  return 0;
}
