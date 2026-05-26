#include <stdio.h>
#include <unistd.h> 

int main(){
  int i=1;
  for (i=1; i<=10; i++){
    if (i == 5){
      continue;
    } if (i == 8){
      break;
    }
    usleep(500000);
    printf("%d\n", i);
  }
  return 0;
}
