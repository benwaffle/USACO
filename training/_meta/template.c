/*
ID: beniof1
LANG: C
TASK: _task_
*/

#include <stdio.h>

int main(void){
	FILE *fin = fopen("_task_.in", "r");
	FILE *fout = fopen("_task_.out", "w");

	fclose(fin);
	fclose(fout);
	return 0;
}
