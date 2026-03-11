#include <stdio.h>
#include <stdbool.h>

int main(){

// latihan menggunakan format specifier
// yaitu: width, specufier, flag.

  int umur = 19;
  float tb = 168.5;
  char sym = 'N';
  char nama[10] = "iyan";
  double harga = 16.500;

 // width *yang dantara % dan symbol clode
  printf("%d\n", umur);
  printf("%3d\n", umur);
  printf("%4d\n", umur);
  printf("%5d\n", umur);
  printf("%6d\n", umur);
  printf("~~~ nah diatas itu width ya guys ~~~\n");
  printf("\n");

  // specifier
  printf("umur saya %d\n", umur);
  printf("tinggi badan saya %.1f\n", tb);
  printf("harga nya %.3lf\n", harga);
  printf("~~~ yg diatas ni specifier ya ~~~\n");
  printf("\n");

  // flag *ya ini width anjim!! hehe
  printf("|%10d|\n", umur);  // Rata kanan, lebar 10
  printf("|%-10d|\n", umur); // Rata kiri, lebar 10
  printf("|%+10d|\n", umur); // Rata kanan, lebar 10, paksa tanda
  printf("|%010d|\n", umur); // Rata kanan, lebar 10, isi nol
  printf("~~~ yg diatas ni flag guys, *width, mboh, ncen podo kyk e ~~~\n");
  printf("\n");

  // ini gabut pengen bikin boolean, jg biar ga lupa 
  bool isHard = false;

  printf("is it hard bro?\n");
  if (isHard){
    printf("yes it's hard\n");
    printf("\n");
  } else {
    printf("no, it's not\n");
    printf("\n");
  }


  //** below, ill train mysellf to write
  //some arithmetic operations
  // yaitu ada +, -, *, /, %, ++

  int x = 20;
  int y = 25;
  int z = 0;

  int a = 2;
  int b = 5;
  int c = 10;
  int d = 15;
  int e = -12;
  int f = - 11;

  z = x+y;
  printf("z = x(20) + y(25) = %d\n", z);

  z = x-y;
  printf("z = x(20) - y(25) = %d\n", z);

  z = y*x;
  printf("z = y(25) * x(20) = %d\n", z);

  // mulai kebawah udah agak agak nih
  z = y/x;
  printf("z = y(20) / x(25) = %d\n", z);
  z = c/a/b;
  printf("pokoknya ini 10/2/5 = %d\n", z);

  // coba yg lain yak
  float g = 2;
  float h = 5;
  float i = 8;
  float j = 0;

  j = g/h;
  printf("float, j = g(2) / h(5) = %.2f\n", j);
  g = i/h;
  printf("float, g(2) = i(8) / h(5) = %.2f\n", g);
  i = h/i/g;
  printf("float, i(8) = h(5) / i(8) / g(2) = %f\n", i);
  printf("\n");
  // kocak, disitu aku make variable yg nilai nya udh berubah
  // menganggap nilai nya masih seperti awal dibuat
  // mkanya aku bingung knp output sm hasil kalkulator beda hh

  // ok, sekarang yang 

  int aa = 2;
  int bb = 5;
  int cc = 8;
  int dd = 0;

  aa = bb%cc;
  printf("aa = 5 (persen) 8 = %d\n", aa);

  dd = cc%aa;
  printf("dd = 8 (persen) 2 = %d\n", dd);

  int k = 20 % 4;
  printf("k = 20 (persen) 4 = %d\n", k);
  printf("~~~ diatas adalah arithmetic operations ~~~\n");
  printf("\n");
  // ini gabisa ya guis, menggunakan % ke float (arithmetic)


  // nah ok guys, dibawan kita akan hajar materi lain 
  // yaitu, user input. gampang 

  char namaa[10];
  printf("masukkan nama panggilan kamu..\n");
  scanf("%s", namaa);
  printf("nama kamu: %s\n", namaa);

  return 0;

}
