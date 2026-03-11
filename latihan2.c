#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){

//gtw, ini lagi nyiapin variable nya
  char item1[10];
  char item2[20];
  int angka;

  printf("masukkan satu kosakata tanpa spasi..\n");
  scanf("%s", item1);
  printf("\n");

  if (strchr(item1, ' ') != NULL){
  printf("dongok dibilang tanpa spasi kok\n");
  printf("%s", item1); 
  } else {
    printf("sip\n");
    printf("%s", item1);
  }

  return 0;


}
