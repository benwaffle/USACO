/*
ID: beniof1
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#define KEYMAP(c) ((c - (c > 'Q') - 65) / 3 + 2)

int match(char *num, char *str) {
	if (strlen(num) != strlen(str)) return 0;
	for (; *num && *str; num++, str++)
		if (*num-48 != KEYMAP(*str))
			return 0;
	return 1;
}

int main(void){
	FILE *fin = fopen("namenum.in", "r");
	FILE *dict = fopen("dict.txt", "r");
	FILE *fout = fopen("namenum.out", "w");
	
	char num[14], str[14], gotany = 0;
	fscanf(fin, "%s", num);
	
	while (fgets(str, 14, dict)) { // string\n\0
		str[strlen(str)-1] = 0; // fgets stores \n
		if (match(num, str)){
			gotany = 1;
			fprintf(fout, "%s\n", str);
		}
	}

	if (!gotany) fprintf(fout, "NONE\n");

	fclose(fin);
	fclose(fout);
	return 0;
}
