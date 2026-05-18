#include <stdio.h>

float pembagian(float a, float b){
  return a / b;
}

int main(){

  float a;
  float b;

  printf("masukkan angka pertama = ");
  scanf("%f", &a);
  printf("masukkan angka kedua = ");
  scanf("%f", &b);

  float hasil = pembagian(a, b);
  printf("hasilnya %f\n", hasil);

  return 0;
}
