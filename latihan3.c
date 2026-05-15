#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){

  char tittle [50]="--- Simple Shopping Chart Program ---";
  char note [50]="↓↓↓ SILAHKAN ISI FORM DIBAWAH INI ↓↓↓";
  printf("%40s\n",  tittle);
  printf("%30s\n \n", note);

  char nama [10]="";
  char namabarang [30]="";
  int jumlah=0;
  float harga=0.0;

  printf("1. masukkan nama panggilan anda: ");
  scanf("%s", nama);
  
  printf("2. masukkan nama barang yang anda pesan: ");
  (void)getchar();
  fgets(namabarang, sizeof(namabarang), stdin);
  namabarang[strcspn(namabarang, "\n")]=0;

  printf("3. masukkan jumlah barang yang anda pesan: ");
  scanf("%d", &jumlah);

  printf("4. masukkan harga barang yang anda pesan: ");
  scanf("%f", &harga);

  printf("\nnama anda adalah %s\n", nama);
  printf("nama barang yang anda pesan adalah %s\n", namabarang);
  printf("jumlah anda memesan barang tersebut adalah %d\n", jumlah);
  printf("harga per biji barang yang anda pesan adalah %.3f\n \n", harga);

  float hasil=0.0;
  hasil=jumlah*harga;
  printf("hasil >>> total tagihan anda = %.3f\n \n", hasil);


  //SIMPLEST CIRCLE CALCULATOR PROGRAM
  char a[50]="PROGRAM SIMPLE KALKULATOR LINGKARAN ATAU BOLA\n";
  printf("%40s\n", a);
  printf("\n");
  double area=0.0;
  double radius=0.0;
  double volume=0.0;
  double AreaPermukaan=0.0;
  double PI=3.14159;

  
  
  printf("masukkan angka radius nya.. ");
  scanf("%lf", &radius);

  printf("  ↓↓↓ HASILNYA ↓↓↓\n \n");

  area=PI*pow(radius, 2);
  printf("1. area = %.3lf\n", area);

  double patga=4/3;
  volume=patga*PI*pow(radius, 3);
  printf("2. volume = %3lf\n", volume);

  AreaPermukaan=4*PI*pow(radius, 2);
  printf("3. Area Permukaan = %3lf\n \n \n", AreaPermukaan);



  // mempelajari ulang switch statement
  int num=0;

  printf("   ↓↓↓ Switches Statement ↓↓↓\n"
         "pilih 1, 2, atau 3 = ");
  scanf("%d", &num);

  switch(num){
    case 1:
    printf("ok lu pilih 1 y\n");
    break;

    case 2:
    printf("ok lu pilih 2 y\n");
    break;

    case 3:
    printf("ok lu pilih 3 y\n");
    break;

      default:
    printf("masukin input yang bener dongok\n"
           "pilih noooh\n");
  }


  return 0;
}
