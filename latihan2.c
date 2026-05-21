#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void Data(char nama[20],int umur);
bool Check(int age);

int main(){

  // pemanggilan function pertama
  char nama[20];
  int umur;
  printf("masukkan nama kamu = ");
  fgets(nama, sizeof(nama), stdin);
  nama[strcspn(nama,"\n")]=0;

  printf("masukkan usia anda = ");
  scanf("%d", &umur);
  Data(nama, umur);

  //pemanggilan function kedua
  int age;
  printf("\n \nmasukkan umur lagi = ");
  scanf("%d", &age);

  if (Check(age)){
    printf("bisa kerja disini\n");
  } else {
    printf("tidak boleh kerja disini\n");
  }


  return 0;

}

void Data(char nama[20], int umur){
  printf("nama kamu %s\n", nama);
  printf("dan usia kamu %d\n", umur);
}

bool Check(int age){
  if (age>=16){
    return true;
  } else {
    return false;
  }
}
