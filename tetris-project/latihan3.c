#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int min=20;
  int max=80;

  srand(time(NULL));
  int rnum1=(rand()%(max-min+1)+min);
  int rnum2=(rand()%(max-min+1)+min);
  int rnum3=(rand()%(max-min+1)+min);


  printf("%d%d%d\n", rnum1, rnum2, rnum3);

  return 0;
}
