#include<stdio.h>
#include<conio.h>
#include<Windows.h>

const max = 3;
typedef int matrix[3][3];

matrix c, d, e;
void mat_compute(matrix, matrix);
void print_matrix(matrix);

int main() {
	int i, j;
	matrix a, b;

	putchar('\n');
	printf("부울 행렬 A(3*3)를 입력하세요.\n(0과 1만 사용하세요)\n");
	printf("ex) 0 1 0\n    0 0 0\n    1 0 1\n\n");
	for (i = 0; i < max; i++) {
		for (j = 0; j < max; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("\n 부울 행렬 B(3*3)을 입력하세요.\n");
	for (i = 0; i < max; i++) {
		for (j = 0; j < max; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	mat_compute(a, b);
	putchar('\n');
	printf("A MEET B\n");
	print_matrix(c);
	putchar('\n');
	printf("A JOIN B\n");
	print_matrix(d);
	putchar('\n');
	printf("A Boolean product B\n");
	print_matrix(e);
	system("PAUSE");
}

void mat_compute(matrix a, matrix b) {
	int i, j, k;
	for (i = 0; i < max; i++) {
		for (j = 0; j < max; j++) {
			for (k = 0; k < max; k++) {
				c[i][j] = a[i][j] & b[i][j]; d[i][j] = a[i][j] | b[i][j];
				if (k == 0) {
					e[i][j] = a[i][k] * b[k][j];
				}
				else {
					e[i][j] = e[i][j] | (a[i][k] & b[k][j]);
				}
			}
		}
	}
}
void print_matrix(matrix x) {
	int i, j;
	for (i = 0; i < max; i++) {
		putchar('\n');
		for (j = 0; j < max; j++) {
			printf("%2d", x[i][j]);
		}
	}
	putchar('\n');
}