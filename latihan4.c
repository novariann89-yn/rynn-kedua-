#include <stdio.h>
#include <math.h>

int main(){

  float pangkat=pow(8.0, 2.0);

  float a=3;
  float b=8;
  float c=12;
  float d =30;

  printf("8 pangkat 3 = %.2f\n", pow(b, a));
  printf("30 pangkat 8 = %.2f\n", pow(d, b));
  printf("30 pangkat 3 = %.2f\n", pow(d, a));
  printf("12 pangkat 3 = %.2f\n", pow(c, a));
  printf("12 pangkat 8 = %.2f\n", pow(c, b));
  printf("^^^ pow atau perpangkatan ^^^\n \n");

  printf("8 kuadrat = %.2f\n", sqrt(b));
  printf("12 kuadrat = %.2f\n", sqrt(c));
  printf("3 kuadrat = %.2f\n", sqrt(a));
  printf("30 kuadrat = %.2f\n", sqrt(d));
  printf("^^^ sqrt atau kuadrat ^^^\n \n");
  return 0;
}
