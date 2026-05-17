#include <stdio.h>
#include <string.h>

int main (){

  int nilai;

  // PROGRAM PENGECEK NILAI
  // mengetes apakah aku benwr benar paham nested if atau belum
  
  printf("   ↓↓↓ PROGRAM PENGECEK NILAI\n");
  printf("masukkan nilai anda = ");
  scanf("%d", &nilai);
  
  if (nilai>=0&&nilai<70){
    printf("nilai kamu %d! Dibawah KKM, jadi nggak dapet apa apa\n", nilai);
  } else {
    printf("else 0 70\n");
  }   if (nilai>=70&&nilai<80){
      printf("nilai kamu %d! Diatas KKM, kamu dapet hadiah level 1!\n", nilai);
  }   else {
      printf("else 70 80\n");
  }     if (nilai>=80&&nilai<90){
        printf("nilai kamu %d! Diatas KKM, kamu dapat hadiah level 2!!\n", nilai);
  }     else {
        printf("else 80 90\n");
  }       if (nilai>=90&&nilai<=100){
          printf("nilai kamu %d! diatas KKM, kamu dapat hadiah level 3!!!\n", nilai);
  }       else {
          printf("else 90 100\n");
  }         if (nilai>100&&nilai<0){
    printf("invalid! masukin nilai yang bener bro (diatas 0 dan dibawah 100)\n");
  }





  return 0;
}
