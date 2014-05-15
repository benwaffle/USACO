/*
ID: beniof1 
LANG: C
TASK: friday
*/

#include <stdio.h>

int leap(int year){
	return year % (4 * (year % 100 == 0 ? 100 : 1)) == 0;
}

int days(int year, int month){
	switch(month){
		case 3: case 5: case 8: case 10: return 30;
		case 1: return leap(year) ? 29 : 28;
		default: return 31;
	}
}

int main(int argc, char *argv[]){
	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");

	int count[7] = {0};
	int years;
	fscanf(fin, "%d", &years);
	fclose(fin);

	int dow = 1, y, m, i;

	for (y = 1900; y <= 1900 + years - 1; ++y)
		for (m = 0; m < 12; ++m){
			count[(dow + 5) % 7]++; 
			dow = (dow + days(y, m)) % 7;
		}

	fprintf(fout, "%d", count[6]); // start with sat
	for (i = 0; i < 6; i++) // sun to fri
		fprintf(fout, " %d", count[i]);
	fprintf(fout, "\n");
	
	fclose(fout);
	return 0;
}
