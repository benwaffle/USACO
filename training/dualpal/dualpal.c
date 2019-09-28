/*
ID: beniof1
LANG: C
TASK: dualpal
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

int is_pal(char *str){
	char *end = str;
	while (*end++);
	end -= 2; // extra ++ and \0
	
	while (str < end)
		if (*str++ != *end--)
			return 0;
	return 1;
}

int pal_in_2_bases(int i){
	int count = 0, base;
	for (base = 2; base <= 10; base++)
		count += is_pal(itoa(i, base));
	return count >= 2;
}

int main(void){
	FILE *fin = fopen("dualpal.in", "r");
	FILE *fout = fopen("dualpal.out", "w");

	int n, s; fscanf(fin, "%d %d", &n, &s);

	while (n) {
		if (pal_in_2_bases(++s)) {
			n--;
			fprintf(fout, "%d\n", s);
		}
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
