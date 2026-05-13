#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){

  bool isCal;
  int pilih;

  printf("ketik 1 untuk calculator dan 2 untuk yang lain.. ");
  scanf("%d", &pilih);

  isCal=(pilih == 1);

  if (isCal){

  //simplest interest rate calculator

  char a[50]="↓↓↓ Interest Rate Calculator ↓↓↓\n";
  double principal=0.0;
  double rate=0.0;
  int years=0;
  int TimesCompounded=0;
  double total=0.0;

  printf("%50s", a);

  printf("masukkan berapa yang anda investasikan dalam rupiah.. ");
  scanf("%lf", &principal);

  printf("masukkan suku bunga nya.. ");
  scanf("%lf", &rate);
  rate = rate/100;

  printf("masukkan berapa tahun anda akan berinvestasi.. ");
  scanf("%d", &years);

  printf("masukkan berapa kali dilipatgandakan.. ");
  scanf("%d", &TimesCompounded);

  total=principal*pow(1+rate/TimesCompounded,TimesCompounded*years);

  printf("\n");
  printf("jika yang anda investasikan berjumlah %.3lf\n", principal);
  printf("dengan bunga %g persen\n", rate);
  printf("maka hasilnya adalah %.3lf rupiah\n", total);
  } else {
    printf("trus mau apa mek, disini cuma bisa calcularor\n");
  }


  printf("\n");
  char b[50]="↓↓↓ ANOTHER IF ELSE ↓↓↓\n";
  printf("%30s", b);
  



  return 0;
}
