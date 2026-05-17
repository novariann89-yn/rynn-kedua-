#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){

  // penggunaan if else dengan boolean

  bool isNgantuk;
  char yesno[10];

  printf("bang apakah lu ngantuk?\n"
         "jawab dengan yes atau no = ");
  scanf(" %c", yesno);

  if (strcmp(yesno, "yes")==0){
    isNgantuk=true;
  } else if (strcmp(yesno, "no")==0){
    isNgantuk=false;
  } else {
    printf("masukin input yang bener bg\n");
    return 1;
  }

  if (isNgantuk){
    printf("hhh iya bg gw juga ngantuk bener ini\n");
  } else {
    printf("buset masa ga ngantuk si lu bang\n");
  }


  return 0;
}
