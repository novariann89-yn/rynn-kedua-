#include <stdio.h>
#include <string.h>

int main(){

  // belajar tentang user input

  int umur;
  float tb;
  char peringkat;
  char nama[10];

  printf("masukkan umur kamu: ");
  scanf("%d", &umur);

  printf("masukkan tinggi badan: ");
  scanf("%f", &tb);

  printf("masukkan peringkat anda: ");
  scanf("%c", &peringkat);
  
  printf("masukkan nama anda: ");
  scanf("%s", nama);
  printf("\n");



  printf("nama kamu %d\n", umur);
  printf("tinggi badan kamu %.2f\n", tb);
  printf("peringkat kamu %c\n", peringkat);
  printf("nama kamu %s\n", nama);
  
  return 0;
}
