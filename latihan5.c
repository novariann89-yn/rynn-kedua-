#include <stdio.h>

int main(){

  char huruf;
  printf("pilih antara a, b, atau c : ");
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

  // anyinggg salah pengertian ternyata, padahal angka tu gabisa pake > or <
  // malah ku pakein nested if ah ah
}
