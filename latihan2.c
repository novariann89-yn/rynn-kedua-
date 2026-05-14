#include <stdio.h>
#include <math.h>

int main(){

  // membuat membuqt program pengkonversi berat

  float kgs=0.0;
  float lbs=0.0;
  int mana=0;

  char a[50]="↓↓↓ PROGRAM PENGKONVERSI BEBAN ↓↓↓\n";
  printf("%60s", a);

  printf("1. kgs ke lbs\n"
         "2. lbs ke kgs\n \n"
         "masukkan 1 atau 2 untuk memilih operasi yang mana!.. ");
  scanf("%d", &mana);

  if (mana ==1){
    printf("masukkan berat dalam satuan kg.. ");
    scanf("%f", &kgs);
    printf("\n");
    lbs=kgs*2.205;
    printf("%3f kilogram sama dengan %3f pounds\n", kgs, lbs);
  } else if (mana ==2){
    printf("masukkan berat dalam satuan lbs.. ");
    scanf("%f", &lbs);
    printf("\n");
    kgs=lbs/2.205;
    printf("%3f pounds sama dengan %3f kilogram\n", lbs, kgs);
  } else {
    printf("UNKNOWN INPUT!!!\n"
           "*tolong pilih antara 1 atau 2!\n");
  }

  return 0;
}
