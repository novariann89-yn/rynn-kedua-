#include <stdio.h>
#include <stdbool.h>

int main(){

	int umur;

	printf("masukin umur lu!\n");
	scanf("%d", &umur);

	if (umur >=17){
	printf("remaja lu\n");
	printf("karna lu %d thun\n", umur);
	  if (umur >= 21){
	  printf("dewasa lu\n");
	  printf("karna lu %d\n", umur);
	  }
	  else if (umur >=18){
	  printf("remaja juga si tpi lebi berumur\n");
	  }
	  else {
	  printf("bocah\n");
	  }
	} else {
	    printf("bocahh\n");
	}


	return 0;
}
