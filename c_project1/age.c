#include "hello.h"

#include <stdio.h>

int age()
{
	int age=0;
	printf("quel est ton age?\n");
	scanf("%i",&age);
	printf("\ndans 10 ans tu aura %i ans\n",age+10);
	printf("wahou... jsuis fort!");
	return age;
}
