#include <stdio.h>
#include <string.h>

void belajar(char name[], int age){
  printf("saya ingat saya pernah menulis sesuatu\n");
  printf("waktu saya menggunakan code editor sebelumnya\n");
  printf("disana saya menjelaskan bahwa..\n");
  printf("belajar adalah keputusan pengubah hidup terbaik\n");
  printf("nama saya %s dan saya berusia %d tahun\n \n", name, age);
}

int main(){
  char name[20];
  int age;

  printf("masukkan nama anda = ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")]=0;

  printf("masukkan usia anda = ");
  scanf("%d", &age);

  belajar(name, age);
  belajar(name, age);
  belajar(name, age);
  belajar(name, age);
  belajar(name, age);
  belajar(name, age);
  belajar(name, age);

  return 0;
}
