#include <stdio.h>
#include <math.h>

int main(){

  // berlatih menggunakan math oleration

  //akar kuadrat biasa
  double kuadrat = sqrt(65.0);

  //basis atau pangkat^basis
  double basis = pow(6.0, 8.0);

  // nilai mutlak  (untuk angka desimal))
  double angkadesimal = fabs(-6.0);

  // pembulatan KE ATAS
  double keatas = ceil(5.5);

  // pembulatan kebawah 
  double kebawah = floor(8.8);

  // pembulatan ke terdekat
  double terdekat = round(56.6);

  // 
  char a[50] = "THIS IS MATH OPERATION\n";
  printf("%10s\n", a);

  printf("\nuntuk kuadrat dari 65.0 = %.3lf\n", kuadrat);
  printf("untuk angka basis dari 6.0 dan 8.0 = %.3lf\n", basis);
  printf("untuk angka desimal dari -6.0 = %.3lf\n", angkadesimal);
  printf("untuk pembulatan keatas untuk 5.5 = %.3lf\n", keatas);
  printf("untuk pembulatan kebawiah untuk 8.8 = %.3lf\n", kebawah);
  printf("untuk pembulatan terdekat untuk 56.6 = %.3lf\n", terdekat);


  
  return 0;


}
