/*
ID: beniof1
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
	int bal; // net balance
	int init; // give away
	int recv; // how many receive
	char name[15];
};

struct person* who(struct person *people[], int len, char *name){
	int i = 0;
	for(; i < len; i++)
		if (strcmp(people[i]->name, name) == 0)
			return people[i];
	return NULL;
}

int main(void){
	FILE *fin = fopen("gift1.in","r");
	FILE *fout = fopen("gift1.out","w");

	int n;
	fscanf(fin, "%d", &n); 		

	struct person *people[n];
	
	int i;
	for (i = 0; i < n; i++){ // get all people
		people[i] = calloc(1, sizeof(struct person));
		fscanf(fin, "%s", people[i]->name);
	}
	
	for (i = 0; i < n; i++){
		char name[15];
		fscanf(fin, "%s", name); // current person

		struct person* cur = who(people, n, name);
		fscanf(fin, "%d %d", &cur->init, &cur->recv); // current person's money
		cur->bal += cur->init;
	
		if (cur->recv == 0) continue; // can't give away to 0 people
		
		int each = cur->init / cur->recv, j; // how much each person gets
		for (j = 0; j < cur->recv; j++){
			fscanf(fin, "%s", name);
			who(people, n, name)->bal += each; // give
			cur->bal -= each; // take from balance
		}
	}
	
	for (i = 0; i < n; i++){ // write results to file
		fprintf(fout, "%s %d\n", people[i]->name, people[i]->bal - people[i]->init);
		free(people[i]);
	}

	fclose(fin);
	fclose(fout);	
	return 0;
}
