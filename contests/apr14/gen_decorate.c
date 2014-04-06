#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	srand(time(NULL));
	
	int n = atoi(argv[1]);
	printf("%d %d\n", n, n);
	
	for (int i = 0; i < n; i++){
		printf("%d %d\n", (rand() % n)+1, (rand() % n)+1);
	}		
	
	return 0;
}
