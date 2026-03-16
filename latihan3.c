#include <stdio.h>
#include <string.h>

int main(){

  char item1[50]="";
  char item2[50]="";
  char item3[50]="";
  char item4[50]="";
  char item5[50]="";

  printf("masukkan apapun (pertama): ");
  fgets(item1, sizeof(item1), stdin);
  item1[strcspn(item1, "\n")]=0; 

  printf("masukkan apapun (kedua): ");
  fgets(item2, sizeof(item2), stdin);
  item2[strcspn(item2, "\n")]=0; 

  printf("masukkan apapun (ketiga): ");
  fgets(item3, sizeof(item3), stdin);
  item3[strcspn(item3, "\n")]=0; 

  printf("masukkan apapun (keempat): "); 
  fgets(item4, sizeof(item4), stdin);
  item4[strcspn(item4, "\n")]=0; 

  printf("masukkan apapun (kelima): ");
  fgets(item5, sizeof(item5), stdin);
  item5[strcspn(item5, "\n")]=0; 
}
