//Á½¸ön*n¾ØÕóÏà³Ë
//test:
//3
//1 0 0
//0 1 0
//0 0 1
//2 3 4
//5 6 7
//8 9 10
//result:
//2 3 4
//5 6 7
//8 9 10
#include<stdio.h>
#include<stdlib.h>
#define LIMIT 10
int main() {
	int** arr1 = (int**)calloc(LIMIT,sizeof(int*));
	int** arr2= (int**)calloc(LIMIT, sizeof(int*));
	int** arr3 = (int**)calloc(LIMIT, sizeof(int*));
	for (int i = 0; i < LIMIT; i++) {
		arr1[i] = (int*)calloc(LIMIT,sizeof(int));
		arr2[i] = (int*)calloc(LIMIT, sizeof(int));
		arr3[i] = (int*)calloc(LIMIT, sizeof(int));
	}

	int n;
	scanf_s("%d",&n);
	for (int i = 0; i < n*n; i++) {
		scanf_s("%d",&arr1[i/n][i%n]);
	}
	for (int i = 0; i < n * n; i++) {
		scanf_s("%d", &arr2[i / n][i % n]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr3[i][j] = 0;
			for (int k = 0; k < n; k++) {
				arr3[i][j]=arr3[i][j]+ arr1[i][k] * arr2[k][j];
			}
		}
	}

	for (int i = 0; i < n * n; i++) {
		if (i % n == 0&& i!=0) {
			printf("\n");
		}
		printf("%d ",arr3[i/n][i%n]);
	}


	for (int i = 0; i < LIMIT; i++) {
		free(arr1[i]);
		free(arr2[i]);
		free(arr3[i]);
	}


	free(arr1);
	free(arr2);
	free(arr3);


	return 0;

}