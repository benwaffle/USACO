/*
ID: beniof1
LANG: C
TASK: palsquare
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char DIGITS[] = "0123456789ACBDEFGHIJKLMNOPQRSTUVWXYZ";

char* itoa(int i, int base) {
	char *str = calloc(33, 1);
	
	int pos = 32;
	while(pos >= 0) {
		str[pos] = DIGITS[i % base];
		i /= base;
		pos--;
	}
	
	int cut = strspn(str, "0");
	
	char *num = malloc(33-cut+1);
	strcpy(num, str+cut);
	
	return num;
}

int isPal(char *str){
	char *end = str;
	while (*end++);
	end -= 2; // extra ++ and \0
	
	while (str < end)
		if (*str++ != *end--)
			return 0;
	return 1;
}

int main(int argc, char *argv[]){	
	FILE *fin = fopen("palsquare.in", "r");
	FILE *fout = fopen("palsquare.out", "w");

	int b, i; fscanf(fin, "%d", &b);
	for (i = 1; i <= 300; i++){
		char *inbase = itoa(i*i, b);
		if (isPal(inbase))
			fprintf(fout, "%s %s\n", itoa(i, b), inbase);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
