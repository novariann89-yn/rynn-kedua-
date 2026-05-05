#include <stdio.h>
#include <stdbool.h>

int main(){



// yg dibawah ini gw mau bikin else if bisa
	int suhu;

	printf("masukkan suhu saat ini\n");
	printf("\n");
	scanf("%d", &suhu);

	if (suhu >= 100){
	  printf("panas maksimal broo bahayaa!!\n");
	  printf("suhu saat ini: %d\n", suhu);
	  printf("\n");
	}
	else if (suhu >= 80){
	  printf("blum maksimal tpi udah cukup bahaya!\n");
	  printf("suhu saat ini: %d\n", suhu);
	  printf("\n");
	}
	else if (suhu >= 60){
	  printf("panas bner broo!!\n");
	  printf("suhu saat ini: %d\n", suhu);
	  printf("\n");
	}
	else if (suhu >= 40){
	  printf("wadaw udah mayan kerasa ini mah\n");
	  printf("suhu saat ini: %d\n", suhu);
	  printf("\n");
	}
	else if (suhu >= 30){
	  printf("hmmm normal si bro aman aja\n");
	  printf("suhu saat ini: %d\n", suhu);
	  printf("\n");
	}
	else {
	  printf("dingin inimah bejieerr brrrr\n");
	  printf("suhu saat ini: %d\n", suhu);
	  printf("\n");
	}


/**nah kalo yg dibawah ini gw niatan bikin nested if ya
guys, dimana ini sulit banet buat dipahami buat aku pribadi,
butuh 3 harian bejir buat mahamin nested if doang, tapi
kayaknya bukan karna aku nya aja yg sulit mahamin tapi cara
aku belajarnya, buktinya aku pahamnya itu karna ganti cara
belajar nya, dmn aku pake gpt dan pake prompt khusus.
gas dh bikin, pnajang bner cug ngetik comment hhh
**/

	int suhububu;

	printf("nah lagi bro, masukkin suhu..\n");
	printf("\n");
	scanf("%d", &suhububu);

	if (suhububu >= 40){
	  printf("panas bro inimah\n");
		if (suhububu >= 60){
		  printf("PANAS BAHAYA BROOO KALO INI!!\n");
	}

	else {
	  printf("cukup normal bro panas nya\n");
	}
}

	return 0;
}



