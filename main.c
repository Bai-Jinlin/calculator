#include <stdio.h>
#include <stdlib.h>
#define cal(arg) ASMD(ana_str(arg))
struct Calentry *ana_str(const char *);
int ASMD(struct Calentry *);

int main()
{
	printf("%d", cal("1+2"));
	getchar();
}