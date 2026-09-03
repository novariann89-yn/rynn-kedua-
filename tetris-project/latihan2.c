#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void NamaUsia(char name[20], int age);
bool CekUmur(int umur);

int main(){
  // 1
  char namee[20];
  int agee;
  printf("masukkan nama anda = ");
  fgets(namee, sizeof(namee), stdin);
  namee[strcspn(namee, "\n")]=0;
  printf("masukkan usia anda = ");
  scanf("%d", &agee);
  NamaUsia(namee, agee);

  // 2
  int umurr;
  printf("\n \nmasukkan umur lagi = ");
  scanf("%d", &umurr);
  if (CekUmur(umurr)){
    printf("okela legal\n");
  } else {
    printf("belum legal\n");
  }
  return 0;
}

void NamaUsia(char name[20], int age){
  printf("nama anda %s\n", name);
  printf("usia anda %d tahun\n", age);
}

bool CekUmur(int umur){
  if (umur >= 17){
    return true;
  } else {
    return false;
  }
}
