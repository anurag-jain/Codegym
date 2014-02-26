#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <vector>
#include <iterator>



using namespace std;

void insertSort();



int main()
{
	//Generate random data
	//
	char *a = "12sjdfjs";
	char *b = "jfkfs109";
	char *c = "1234";
	char *d = "-123";
	char *e = "-123asd";
	char *f = "3782849328498249829849283498239482984983294832984283498324983294829";
	char *t;

	printf("%ld\n", strtol(a,&t,0));
	printf("%d %d\n", a, t);
	printf("%ld\n", strtol(b,&t,0));
	printf("%d %d\n", b, t);
	printf("%ld\n", strtol(c,&t,0));
	printf("%d %d\n", c, t);
	printf("%ld\n", strtol(d,&t,0));
	printf("%d %d\n", d, t);
	printf("%ld\n", strtol(e,&t,0));
	printf("%d %d\n", e, t);
	printf("%ld\n", strtol(f,&t,0));
	printf("%d %d\n", f, t);

	return 0;
}