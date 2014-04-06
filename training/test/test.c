/*
ID: beniof1 
LANG: C
TASK: test
*/

#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]){
	FILE *fin = fopen("test.in", "r");
	FILE *fout = fopen("test.out", "w");

	if (fin == NULL || fout == NULL){
		perror("open()");
		return 1;
	}

	int a, b;
	fscanf(fin, "%d %d", &a, &b);
	fprintf(fout, "%d\n", a+b);
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}
