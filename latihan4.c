#include <stdio.h>
#include <math.h>

int main(){
  //simplest interest rate calculator

  char a[50]="↓↓↓ Interest Rate Calculator ↓↓↓\n";
  double principal=0.0;
  double interest=0.0;
  double rate=0.0;
  int years=0;
  int TimesCompounded=0;
  double total=0.0;

  printf("%50s", a);

  printf("masukkan berapa yang anda investasikan dalam rupiah.. ");
  scanf("%lf", &principal);

  printf("masukkan berapa interest nya dalam persen.. ");
  scanf("%lf", &interest);

  printf("masukkan rate nya dalam persen.. ");
  scanf("%lf", &rate);
  rate = rate/100;

  printf("masukkan berapa tahun anda akan berinvestasi.. ");
  scanf("%d", &years);

  printf("masukkan berapa kali dilipatgandakan.. ");
  scanf("%d", &TimesCompounded);

  total=principal*pow(1+rate/TimesCompounded,TimesCompounded*interest);

  printf("\n");
  printf("jika yang anda investasikan berjumlah %lf\n", principal);
  printf("maka hasilnya adalah %lf\n", total);




  return 0;
}
