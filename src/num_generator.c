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
	for(i = 0; i < arg; i++) //This is where I edited the code to half sort the elements, I replacaed i < arg with i < arg / 2
	{
		array = rand();
		printf("%d\n", array);
	}
	return 0;

}
