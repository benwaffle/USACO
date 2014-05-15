/*
ID: beniof1
LANG: C
TASK: milk2
*/

#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define IN(low, key, high) ((low) <= (key) && (key) < (high))

typedef struct {
	int from, to;
} range;

int main(void){
	FILE *fin = fopen("milk2.in", "r");
	FILE *fout = fopen("milk2.out", "w");

	int count, i, first = 1000001, last = -1, r, t,
		longest_milk = 0, current_milk = 0, longest_nomilk = 0;
	fscanf(fin, "%d", &count);

	range times[count];

	for (i = 0; i < count; i++){
		fscanf(fin, "%d %d", &times[i].from, &times[i].to);
		first = MIN(first, times[i].from);
		last = MAX(last, times[i].to);
	}
	
	for (t = first; t <= last; ){
		int nextclosest = 1000001, found = 0;
		
		for (r = 0; r < count; r++){
			if (IN(times[r].from, t, times[r].to)){ // if t in r
				current_milk += times[r].to - t; // add t to current range
				t = times[r].to; // update time
				goto next;
			}
			if (IN(t, times[r].from, nextclosest))
				nextclosest = times[r].from;
		}
		
		longest_milk = MAX(current_milk, longest_milk);
		
		if (nextclosest != 1000001)
			longest_nomilk = MAX(longest_nomilk, nextclosest - t);

		t = nextclosest;
		current_milk = 0;
		next:;
	}
	
	fprintf(fout, "%d %d\n", longest_milk, longest_nomilk);
	fclose(fin);
	fclose(fout);
	return 0;
}
