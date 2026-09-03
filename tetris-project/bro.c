#include <stdio.h>

int main(){

	int nilai;

	printf("masukkan nilai kamu(1-100)\n");
	printf("\n");
	scanf("%d", &nilai);

	if (nilai >= 60){
		printf("kamu lulus!\n");

		if (nilai >= 90){
			printf("nilai sempurnaa!!\n");	
		} else {
			printf("lumayan bro nilai lu\n");
		}
	} else {
		printf("tidak lulus masbro..\n");
	}


// bikin nested lagi nih, tapi yang lebib dalem ya

	int suhu;

	printf("lagi ya bang, masukkan suhu saat ini..\n");
	printf("\n");
	scanf("%d", &suhu);

	if (suhu >= 35){
		printf("lumayan bro suhunya\n");
		printf("suhu saat ini: %d\n", suhu);

		if (suhu >= 45){
			printf("wah udah lebih dari lumayan bro woaaahh!!\n");

			if (suhu >= 60){
				printf("bro is cooked, TERPANGGANGG!!!!\n");
			} else {
				printf("dibawahnya cooked, tapi ya udh panas bner njim!!\n");
			}
		} else {
			printf("dibawah 45 bro tapi lumayan panas menn\n ");
		}		
		
	} else {
		printf("biasa aja sih bro normal suhunya\n");
	}


// ok this time ill try to make else if statement inside mested if
// how that will be bro

	float jam;

	printf("input jam berapa sekarang (dengan format ** . **)\n");
	printf("/n");
	scanf("%f",&jam);

	if (jam >= 08.00){
		printf("jam masuk kerja");
		printf("jam saat ini: %g")
	}
	
	return 0;
}
