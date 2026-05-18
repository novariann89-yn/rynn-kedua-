#include <stdio.h>
#include <string.h>

void Words(char nama[], int umur){
printf("saya suka belaiar\n");
printf("saya hobi belajar\n");
printf("belajar membuat saya merasa baik\n");
printf("nama saya %s\n", nama);
printf("dan umur saya %d tahun\n \n", umur);
}

int main(){

  char nama[30];
  int umur;

  printf("siapa nama anda? ");
  fgets(nama, sizeof(nama), stdin);
  nama[strcspn(nama, "\n")]=0;

  printf("berapa umur anda? ");
  scanf("%d", &umur);

  Words(nama, umur);
  Words(nama, umur);
  Words(nama, umur);
  Words(nama, umur);
  Words(nama, umur);



  return 0;
}
