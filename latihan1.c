#include <stdio.h>

int main(){

  int nom;

  printf("pilih nonor antara 1-3: ");
  scanf("%d", &nom);

  switch(nom){
    case 1:
    printf("lu pilih angka 1, dh gt aja\n");
    break;
    case 2:
    printf("lu pilih angka 2, dh gt aja\n");
    break;
    case 3:
    printf("lu pilih angka 3, dh gt aja\n");
    break;
    default:
    printf("masukkan input yang bener!\n");
  }

  return 0;
}
