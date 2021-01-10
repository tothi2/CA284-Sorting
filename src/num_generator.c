#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// random number generator //

int main(int argu, char *argv[])
{
	int arg;
	int i;
	arg = atoi(argv[1]);
	srand(time(NULL));
	int array = (int*)malloc(arg * sizeof(arg));
	for(i = 0; i < arg; i++)
	{
		array = rand();
		printf("%d\n", array);
	}
	return 0;

}
