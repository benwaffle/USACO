void printArr(char *arr){
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) printf("[%c]", arr[i*len+j]);
		printf("\n");
	}
}
