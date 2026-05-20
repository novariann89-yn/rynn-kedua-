#include <stdio.h>

void Angka(int a, int b){
  if (a > b){
    printf("%d lebih besar daripada %d\n", a, b);
  } else if (a < b){
    printf("%d lebih besar daripada %d\n", b, a);
  }
}

int main(){
  int a;
  int b;

  printf("masukkan angka pertama = ");
  scanf("%d", &a);

  printf("masukkan angka kedua = ");
  scanf("%d", &b);

  Angka(a, b);

  return 0;
}
