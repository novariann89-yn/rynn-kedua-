#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){

  // membuat membuqt program pengkonversi berat
  char pilih=' ';

  printf("A. Program Pengkonversi Beban\n"
         "B. Program Pengkonversi Suhu\n \n"
         "masukkan A untuk beban dan B untuk suhu = ");
  scanf("%c", &pilih);

  if (strcmp(&pilih, "A")==0){

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
           "*tolong pilih antara i1 atau 2!\n");
  }


} else if (strcmp(&pilih, "B")==0){

    float cel=0.0;
    float far=0.0;
    int choose=0;
    
    printf("   ↓↓↓ PROGRAM PENGKONVERSI SUHU ↓↓↓\n \n"
           "1. Celcius Ke Fahrenheit\n"
           "2. Farenheit Ke Celcius\n"
           "masukkan angka 1 atau 2 untuk memilih.. ");
    scanf("%d", &choose);
    printf("\n");

    if (choose==1){
      printf("masukkan suhu dalam satuan celcius = ");
      scanf("%f", &cel);
      far=(cel*9/5)+32;
      printf("%f celcius sama dengan %f fahrenheit\n", cel, far);
    } else if (choose==2){
      printf("masukkan suhu dalam fahrenheit = ");
      scanf("%f", &far);
      cel=(far-32)*5/9;
      printf("%f fahrenheit sama dengan %f celcius\n", far, cel);
    } else {
      printf("UNKNOWN INPUT !!\n"
             "tolong pilih 1 atau 2\n");
    }


  } else {
    printf("UNKNOWN INPUT !!!\n"
           "tolong pilih antara A atau B\n");
    return 1;
  }


  return 0;
}
