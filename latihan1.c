#include <stdio.h>

int main(){

  char choice;
  float kgs=0.0f;
  float lbs=0.0f;

  printf("--- weight conversion program ---\n");
  printf("1. ubah dari KGs ke LBs\n");
  printf("2. ubah dari LBs ke KGs\n");
  printf("pilih (1 or 2) = ");
  scanf("%c", &choice);

  if (choice == '1'){
    printf("masukkan beban dalam KGs = ");
    scanf("%f", &kgs);
    lbs=kgs*2.20462;
    printf("hasil nya = %.2f KGs sama dengan %.2f LBs\n", kgs, lbs);
  }
  else if (choice == '2'){
    printf("masukkan beban dalam LBs = ");
    scanf("%f", &lbs);
    kgs=lbs/2.20462;
    printf("hasil nya = %.2f LBs sama dengan %.2f KGs\n", lbs, kgs);
  }
  else {
    printf("masukkan input yang benar! pilih 1 atau 2\n");
  }

  return 0;
}
