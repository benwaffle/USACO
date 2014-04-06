#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	srand(time(NULL));
	
	int n = atoi(argv[1]);
	printf("%d\n", n);
	
	for (int i = 0; i < n; i++){
		printf("%d %c\n", rand() % 1000000000, rand() % 2 == 0 ? 'G' : 'H');
	}		
	
	return 0;
}
