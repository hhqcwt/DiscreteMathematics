#include<stdio.h>
#include<stdlib.h> 
#include<conio.h> 
#include<process.h>

int combi(int n, int r);
int fact(int n);
void output(int r, int c, int** data);
void copy(int r, int c, int** be_data, int** data);

void main() {
	int i, j, k, element, ** data, ** be_data, be_row, col, r, c;
	system("cls");
	printf("\n### How many elements? ");
	scanf("%d", &element);
	printf("\n### Set = {");
	for (i = 1; i < element; i++)
		printf("%d,", i);
	printf("%d}\n\n", i);
	printf("### ? 는 공집합 표시입니다.\n\n");
	printf("### 멱집합 = {");
	printf("%c%c,", 237, 44); // output:

//allocate element 
	i = element / 2;
	j = combi(element, i);
	data = (int**)malloc(sizeof(int) * j);
	for (i = 0; i < j; i++)
		*(data + i) = (int*)malloc(sizeof(int) * element);
	be_data = (int**)malloc(sizeof(int) * j);
	for (i = 0; i < j; i++)
		*(be_data + i) = (int*)malloc(sizeof(int) * element);

	c = 1;
	r = combi(element, c);

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			be_data[i][j] = i + 1;
	}
	output(r, c, be_data);

	for (col = 2; col < element; col++) {
		be_row = combi(element, col - 1);
		r = 0;
		for (i = 0; i < be_row; i++) {
			if (i < be_data[i][col - 2] < element) {
				for (j = be_data[i][col - 2] + 1; j <= element; j++) {
					for (k = 0; k < col - 1; k++)
						data[r][k] = be_data[i][k];
					data[r++][k] = j;
				}
			}
		}
		output(r, col, data);

		k = combi(element, element / 2);
		for (i = 0; i < k; i++) {
			for (j = 0; j < element; j++)
				be_data[i][j] = 0;
		}
		copy(r, col, be_data, data);
		for (i = 0; i < k; i++) {
			for (j = 0; j < element; j++)
				data[i][j] = 0;
		}
	}

	printf("{");
	for (i = 1; i < element; i++) { printf("%d,", i); }
	printf("%d", i);
	printf("} }\n");
	system("pause");

}
void copy(int r, int c, int** be_data, int** data) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			be_data[i][j] = data[i][j];
}
void output(int r, int c, int** data) {
	int i, j;
	for (i = 0; i < r; i++) {
		printf("{");
		for (j = 0; j < c - 1; j++)
			printf("%d,", data[i][j]);
		printf("%d},", data[i][j]);
	}
}

int combi(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }

int fact(int n) {
	if (n == 0) return(1);
	else return(fact(n - 1) * n);
}