#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){

  bool isSuhu;
  char yesno[10];

  printf("panas nggak sih suhunya? yes or no.. ");
  scanf("%s", yesno);

  if (strcmp(yesno, "yes")==0){
    isSuhu=true;
  } else if (strcmp(yesno, "no")==0){
    isSuhu=false;
  } else {
    printf("masukin input yg bener!\n");
    return 1;
  }

  if (!isSuhu){
    printf("nggak panas berarti dingin\n");
  } else {
    printf("berarti panas yak?\n");
  }


  return 0;
}

