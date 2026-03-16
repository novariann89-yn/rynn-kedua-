#include <stdio.h>
#include <string.h>

// membuat program pemesanan barang

int main(){

  char barang[20];
  float harga;
  int jumlah;

  printf("~~~ Welcome To Our Shop!! ~~~\n");

  printf("\nmasukkan nama barang: ");
  fgets(barang, sizeof(barang), stdin);

  printf("masukkan harga per barang nya: ");
  scanf("%g", &harga);

  printf("masukkan jumlah barang: ");
  scanf("%d", &jumlah);
  printf("\n");

  (void)getchar();
  printf("barang nya %s", barang);
  printf("harga per satu barang nya %g\n", harga);
  printf("jumlah barang nya %d\n", jumlah);

  float total = harga*jumlah;
  printf("\njadi totalnya %.3f rupiah\n", total);

  return 0;
}
