#include <stdio.h>

int main(){

  // mencoba membuat tiny program pakai switch statement
  int nomor;

  printf("masukkan nomor antara 1-7 untuk hari : ");
  scanf("%d", &nomor);

  switch(nomor){
    case 1:
    printf("hari senin, malas banar\n");
    break;
    case 2:
    printf("hari selasa, masi cukup malas sih\n");
    break;
    case 3:
    printf("hari rabu, oh aja\n");
    break;
    case 4:
    printf("hari kamis, lumayan laa\n");
    break;
    case 5:
    printf("hari jumat, okeee let's go\n");
    break;
    case 6:
    printf("hari sabtu, uuuuyyeaaaaaahhh easy dayy\n");
    break;
    case 7:
    printf("hari minggu, enjoy.\n");
    break;
    default:
    printf("masukkan input dengan tepat!! pilih antara 1-7\n");
  }
  return 0;
}
