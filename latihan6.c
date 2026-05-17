#include <stdio.h>
#include <math.h>

int main(){

  int num1;
  int num2;
  int hsil;
  char op;

  printf("   ↓↓↓ PROGRAM KALKULATOR SIMPEL ↓↓↓\n");
  printf("\n");
  printf("masukkan angka pertama = ");
  scanf("%d", &num1);

  printf("masukkan jenis operasi (+ or * or /) = ");
  scanf(" %c", &op);

  printf("masukkan angka kedua = ");
  scanf("%d", &num2);

  if (op=='+'){
    hsil=num1+num2;
  } else if (op=='*'){
    hsil=num1*num2;
  } else if (op=='/'){
    hsil=num1/num2;
  } else {
    printf("error!! masukkan input yang benar!\n");
  }

  printf("\n");
  printf("perhitungan kamu %d %c %d hasilnya %d\n", num1, op, num2, hsil);


  return 0;
}
