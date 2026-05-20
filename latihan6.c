#include <stdio.h>

int Angka(int ang){
  int hasil=ang*5;

  return hasil;
}

int Pabrik(int a, int b){
  int jadinya=a*b;
  return jadinya;
}

void Pembagian(float pembilang, float penyebut){
  if (penyebut==0){
    printf("ERROR! ANGKA 0 DAN MINUS TIDAK BISA DIBAGI!\n");
    return;
  } 
  float hasilp=pembilang/penyebut;
  printf("hasilnya %f\n", hasilp);
}

int main(){
  // pemanggilan fungsi pertama

  int x=Angka(5);
  int y=Angka(8);
  int z=Angka(13);

  printf("%d\n", x);
  printf("%d\n", y);
  printf("%d\n", z);

  //pemanggilan fungsi kedua
  int a, b;

  printf("\n \n↓↓↓ perkalian ↓↓↓\n");
  printf("masukkan angka pertama = ");
  scanf("%d", &a);
  printf("masukkan angka kedua = ");
  scanf("%d", &b);

  int hasill=Pabrik(a, b);

  printf("hasilnya %d\n", hasill);

  // pemanggilan fungsi ketiga 
  
  float pembilang, penyebut;

  printf("\n \n↓↓↓ pembagian ↓↓↓\n");
  printf("masukkan angka pembilang = ");
  scanf("%f", &pembilang);
  printf("masukkan angka penyebut = ");
  scanf("%f", &penyebut);

  Pembagian(pembilang, penyebut);

  return 0;
}



