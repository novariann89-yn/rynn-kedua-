#include <stdio.h>
#include <unistd.h>

void Jeda(int wak){
  usleep(wak*10000);
}

int main(){
  for(int i=1; i <= 10; i++){
    Jeda(50);
    printf("%d\n", i);
  }

  return 0;
}
