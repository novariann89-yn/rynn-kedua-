#include <stdio.h>

int main(){

  int choice=0;
  float kgs=0.0f;
  float lbs=0.0f;

  printf("weight converter program\n");
  printf("1. kg to lbs\n");
  printf("2. lbs to kgs\n");
  printf("choose between both (1 or 2): ");
  scanf("%d", choice);

  if (choice == 1){
    printf("input weight in kgs\n");
    scanf("%f", &kgs);
    lbs=kgs*2.20462;
    printf("%.2f kgs is equal to %.2f lbs\n", kgs, lbs);
  }
  else if (choice == 2){
    printf("input weight in kgs\n");
    scanf("%f", &lbs);
    kgs=lbs/2.20462;
    printf("%.2f lbs is equal to %.2f kgs\n", lbs, kgs);
  }
  else {
    printf("invalid input! please choose either 1 or 2!!\n");
  }

}
