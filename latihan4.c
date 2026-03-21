#include <stdio.h>
#include <math.h>

int main(){

  float pangkat=pow(8.0, 2.0);

  float a=3.5;
  float b=8.3;
  float c=12.6;
  float d =30;
  float e=-35;
  float f=-2.5;
  float g=6.7;

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

  printf("jika 6.7 dibulatkan maka jadi %.2f\n", fabs(g));
  printf("jika -2.5 dibulatkan maka jadi %.2f\n", fabs(f));
  printf("jika -35 dibulatkan maka jadi %.2f\n", fabs(e));
  printf("^^^ fabs atau nilai mutlak untuk desimal ^^^\n \n"); 

  printf("pembulatan keatas dari 3.5 = %.2f\n", ceil(a));
  printf("pembulatan keatas dari 8.3 = %.2f\n", ceil(b));
  printf("pembulatan keatas dari 12.6 = %.2f\n", ceil(c));
  printf("^^^ ceil atau pembulatan keatas ^^^\n \n");

  printf("pembulatan kebawah dari 3.5 = %.2f\n", ceil(a));
  printf("pembulatan kebawah dari 8.3 = %.2f\n", ceil(b));
  printf("pembulatan kebawah dari 12.6 = %.2f\n", ceil(c));
  printf("^^^ floor atau pembulatan kebawah ^^^\n \n");

  printf("pembulatan ke yang terdekat dari 3.5 = %.2f\n", floor(a));
  printf("pembulatan ke yang terdekat dari 8.3 = %.2f\n", floor(a));
  printf("pembulatan ke yang terdekat dari 12.6 = %.2f\n", floor(a));
  printf("^^^ round atau pembulatan ke yang terdekat ^^^\n \n");

  printf("logaritma natural dari %.2f = %.2f\n", a, log(a));
  printf("logaritma natural dari %.2f = %.2f\n", b, log(b));
  printf("logaritma natural dari %.2f = %.2f\n", c, log(c));
  printf("^^^ log atau logaritma natural ^^^\n \n");

  printf("log10 dari %.2f = %.2f\n", a, log10(a));
  printf("log10 dari %.2f = %.2f\n", b, log10(b));
  printf("log10 dari %.2f = %.2f\n", c, log10(c));
  printf("^^^ log10 atau logaritma basis 10\n \n");
  


  float yo=70;
  printf("%.2f jika di kuadrat akan menjadi %.2f\n", yo, sqrt(yo));
  

  return 0;
}
