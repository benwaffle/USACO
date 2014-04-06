/*
ID: beniof1
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <ctype.h>

int main(void){
	FILE *fin = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");

	char comet[7], group[7];
	fscanf(fin, "%s%s", comet, group);

	int cval, gval, i;
	for (cval = gval = 1, i = 0; i < 6; i++){
		if (isalpha(comet[i])) cval *= comet[i]-'A'+1;
		if (isalpha(group[i])) gval *= group[i]-'A'+1;
	}
	
	fprintf(fout, (cval % 47 == gval % 47 ? "GO\n" : "STAY\n"));
		
	fclose(fin);
	fclose(fout);
	return 0;
}
