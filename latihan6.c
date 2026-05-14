#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){

  bool isSeru;
  char yesno[10];

  printf("ketik yes jika itu seru dan no jika tidak.. ");
  scanf("%s", yesno);

  if (strcmp(yesno, "yes")==0){
    isSeru=true;
  } else if (strcmp(yesno, "no")==0){
    isSeru=false;
  } else {
    printf("tolong pilih yes atau no!\n");
    return 1;
  }


  if (isSeru){
      printf("YOI BGG SERU TADI TU!!\n");
    } else {
      printf("kgk seru si bang menurut ku\n");
    }

  

  return 0;
}
