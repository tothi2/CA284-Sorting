#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// random number generator//


int main(int argu, char *argv[]){
	int arg;
	int i;
	int num;
	arg = atoi(argv[1]);
	srand(time(NULL));
	for(i = 0; i < arg; i++){
		num = rand();
		printf("%d\n", num);
	}
	return 0;

}
