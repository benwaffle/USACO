/*
ID: beniof1
LANG: C
TASK: milk
*/

#include <stdio.h>
#include <stdlib.h>

#define MIN(x,y) ((x) < (y) ? (x) : (y))

struct farmer {
	int price, amt;
};

int compare(const void *a, const void *b) {
	return ((struct farmer *)a)->price - ((struct farmer *)b)->price;
}

int main(void){
	FILE *fin = fopen("milk.in", "r");
	FILE *fout = fopen("milk.out", "w");

	int need, n;
	fscanf(fin, "%d %d", &need, &n);

	struct farmer farmers[n];

	int i;	
	for (i = 0; i < n; i++)
		fscanf(fin, "%d %d", &farmers[i].price, &farmers[i].amt);

	qsort(farmers, n, sizeof(struct farmer), compare);

	int cost = 0, f = 0;
	while (need > 0) {
		struct farmer *cur = &farmers[f++];
		int use = MIN(need, cur->amt);
		need -= use;
		cost += use * cur->price;
	}

	fprintf(fout, "%d\n", cost);

	fclose(fin);
	fclose(fout);
	return 0;
}
