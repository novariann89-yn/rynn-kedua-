#include <stdio.h>
#include <stdbool.h>

int main(){
	// like yesterday,it is the most common
	printf("ok id train my subconcious\n");
	printf("\n");

	/**ok i will not write this too long
	what i mean is the comment
	**/

	char text[] = "coding";
	char name[] = "Riyan";
	printf("Halo nama saya %s\n",name);
	printf("i want to make something through %s\n",text);

	int age = 19;
	printf("this year my age is %d\n",age);

	char lng1 = 'C';
	char lng2[] = "Python";
	printf("my current favorite language is %c, not %s anymore\n",lng1,lng2);

	float number1 = 45.50;
	double number2 = 68373.82736281878287;
	printf("id like to write random numbers = %g and %.lf\n",number1,number2);


	// here bro i face the boolean{
	bool isTall = true;

	if (isTall){
	printf("Yea bro he's tall\n");
	printf("\n");
	} else {
	printf("no bro he's short\n");
	printf("\n");
	}


	int umurr;

	printf("masukin umur lu brooo!..\n");
	scanf("%d", &umurr);

	if (umurr > 18){
	printf("oke umur lu %d bg, udah gede lu!\n", umurr);
	} else {
	printf("hmm umur lu masi %d bro, dibawah umur!\n", umurr);
	}

	return 0;
}

