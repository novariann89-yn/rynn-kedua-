 #include <stdio.h>
 #include <stdio.h>

 int main(){

   char input[30];

   printf("how's your day, homieee?? (good/bad/neutral):..  ");
   scanf("%s", input);
   printf("\n");

   if (strcmp(input, "good")==0){
     printf("GLAD TO HEAR THAT BROOOO!! LET'S FUKING GOOOOO!\n");
   } else if (strcmp(input, "bad")==0){
     printf("YO BRO IT'S COMPLETELY ALRIGHT! JUST KEEP POSITIVE.\n");
   } else if (strcmp(input, "neutral")==0){
     printf("K\n");
   } else {
     printf("choose from that three dawg!!\n");
   }

   return 0;
 }
