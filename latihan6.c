#include <stdio.h>
#include <math.h>

int main(){

  double radius;
  double area;
  double surface;
  double volume;
  double pi=3.141592;

  printf("--- penghitung area, surface, dan volume lingkaran ---\n \n");
  printf("masukkan radius: ");
  scanf("%lf", &radius);
  printf("\n");

  area=pi*pow(radius, 2);
  surface=4*pi*pow(radius, 2);
  volume=(4.0/3.0)*pi*pow(radius, 3);

  printf("hasil area nya adalah %.2f\n", area);
  printf("hasil surface nya adalaha %.2f\n", surface);
  printf("hasil volume nya adalah %.2f\n \n", volume);
  printf("thanks.\n");


  return 0;
}
