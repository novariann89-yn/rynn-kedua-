#include <stdio.h>
#include <math.h>

int main(){

  float a;
  float hasil;
  float c;

  printf("masukkan angka yang mau di kuadrat: ");
  scanf("%f", &a);

  printf("mau di kuadrat berapa?: ");
  scanf("%f", &c);

  hasil=pow(a, c);
  printf("hasil kuadrat dari %f pangkat %f adalah %f\n",
         a, c, hasil);

  return 0;
}
