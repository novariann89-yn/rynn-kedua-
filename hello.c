#include <stdio.h>
#include <string.h>

int main(){

	int umur;

	printf("masukin umur lu bang\n");
	printf("\n");
	scanf("%d", &umur);

	printf("yang lu masukin: %d\n", umur);

int suhu;
  printf("masukin suku saat ini\n");
  scanf("%d", &suhu);

  if (suhu >= 30){
    printf("diatas 30 bro suhunya, panas\n");
    printf("suhu saat ini: %d\n", suhu);
    
    if (suhu >= 60){
      printf("DAN SEKARANG LEBIH DARI 60 BRO!!, TERBAKAR\n");
      
    } else {
      printf("dibawah 60, diatas 30 suhunya\n");
    }
  } else {
    printf("dibawah 30 suhunya, dingin\n");
  }

 char text[100];
  printf("tulis apapun\n");
  scanf("%s", text);

  if (strcmp(text, "NEOVIM") == 0){
    printf("bang.. NEOVIM KEREN BAT COOOOOOOOO!!\n");
    printf("tapi butuh waktu buat terbiasa, banyak command yg cukup rumit hahah\n");

  } else {
    printf("error\n");
  }


	return 0;
}
