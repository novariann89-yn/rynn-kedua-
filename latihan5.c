#include <stdio.h>
#include <string.h>

int main(){

  //Simple nested if program 
  //tentang mengecek nilai

  int num=0;

  printf("masukkan nilai anda.. ");
  scanf("%d", &num);

  if (num > 0){
    printf("sayang banget bro, dibawah kkm, lu gagal!\n");
  } else {
    printf("*tidak dibawah kkm (else nya =>0)");
  } if (num > 60){
    printf("nilai kamu %d, oke la udah masuk kkm\n", num);
  } else {
    printf("nilai lu dibawah kkm ya?\n");
  }



  return 0;
}
