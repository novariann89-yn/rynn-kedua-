#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
  bool isNyala;
  char yesno[10];

  printf("ketik yes jika lampunya nyala dan no jika tidak.. ");
  scanf("%s", yesno);

  if (strcmp(yesno, "yes")==0){
    isNyala=true;
  } else {
    isNyala=false;
  }

  if (isNyala){
    printf("ya bg lampunya nyala!\n");
  } else {
    printf("kgk bg lampunya mati\n");
  }

  return 0;
}
