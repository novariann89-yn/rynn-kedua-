#include <stdio.h>

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
  printf("hasil >>> total tagihan anda = %.3f\n", hasil);



  return 0;
}
