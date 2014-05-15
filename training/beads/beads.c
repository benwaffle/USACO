/*
ID: beniof1
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <stdlib.h>

int next(int i, int max){
	if (i+1 >= max) return 0;
	else return i+1;
}

int main(void){
	FILE *fin = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	char necklace[n+1];
	fscanf(fin, "%s", necklace);

	int maxlen = -1, i;
	for (i = 0; i < n; i++){
		int try_i = i, try_len = 0, side = 2;
		char try_char;

		while (necklace[try_i] == 'w'){ // get all 'w's
			try_i = next(try_i, n);
			try_len++;
			if (try_i == i) goto skiploop;
		}

		while (side > 0) { // side: 2 => 1 => 0
			try_char = necklace[try_i];
			while (necklace[try_i] == try_char || necklace[try_i] == 'w'){
				try_i = next(try_i, n);
				try_len++;
				if (try_i == i) goto skiploop;
			}
			side--;
		}

		skiploop:;

		if (try_len > maxlen)
			maxlen = try_len;
	}
    
	free(necklace);
	fprintf(fout, "%d\n", maxlen);

	fclose(fin);
	fclose(fout);
	return 0;
}
