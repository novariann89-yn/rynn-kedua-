#include <stdio.h>
#include <string.h>

int main(){
  
  int num1;
  int num2;
  char op[5];

  printf("masukkan angka pertama: ");
  scanf("%d", &num1);

  printf("masukkan angka kedua: ");
  scanf("%d", &num2);

  printf("masukkan jenis operasi (+, -, *, /): ");
  scanf("%c", &op);

  

  return 0;
}
