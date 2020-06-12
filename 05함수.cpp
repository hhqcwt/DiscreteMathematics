#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define domain 10
void readfile(char fn[13], char adjancy[domain + 1][domain + 1], int nocheck, int n2);
void main() {
	char adjancymx[domain + 1][domain + 1];
	char check_1, check_2;
	char fn[13] = "pp3-1.dat";
	char fn2[13] = "pp3-2.dat";
	int nocol, nocheck = 1, i, j, n1 = 10, n2 = 10;
	for (i = 1; i <= 10; i++) {
		for (j = 1; j <= 10; j++) {
			adjancymx[i][j] = 0;
		}
	}
	readfile(fn, adjancymx, nocheck, n1);
	printf("}\n\n");
	check_1 = 1;
	for (i = 1; i <= 10; i++) {
		check_2 = 0;
		nocol = 0;
		for (j = 1; j <= 10; j++) {
			if (adjancymx[i][j] == 1) { check_2 = 1; nocol++; }
		}
		if (check_2 == 0) {
			check_1 = 0;
			printf("%4cf%d는 함수가 아니다.", ' ', nocheck);
			printf(" f(%d) 가 정의되지 않음.\n", i);
		}
		if (nocol > 1) {
			check_1 = 0;
			printf("%4cf%d는 함수가 아니다.", ' ', nocheck);
			printf(" f(%d) 가.\n", i);
		}
	}
	if (check_1 == 1) { printf("%4cf%d는 함수이다.\n\n", ' ', nocheck); }
	nocheck++;
	printf("\n");
	for (i = 1; i <= 10; i++) {
		for (j = 1; j <= 10; j++) {
			adjancymx[i][j] = 0;
		}
	}
	readfile(fn2, adjancymx, nocheck, n2); printf("}\n\n");
	check_1 = 1;
	for (i = 1; i <= 10; i++) {
		check_2 = 0;
		nocol = 0;
		for (j = 1; j <= 10; j++) {
			if (adjancymx[i][j] == 1) {
				check_2 = 1;
				nocol++;
			}
		}
		if (check_2 == 0) {
			check_1 = 0; printf("%4cf%d는 함수가 아니다", ' ', nocheck);
			printf(" f(%d)가 정의되지않음.\n", i);
		}
		if (nocol > 1) {
			check_1 = 0;
			printf("%4cf%d 는 함수가 아니다.", ' ', nocheck);
			printf(" f(%d) 대응되는 이미지가 같다.\n", i);
		}
	}
	if (check_1 == 1) { printf("%4cf%d는 함수이다.\n", ' ', nocheck); }
	system("pause");
}
void readfile(char fn[13], char adjancy[domain + 1][domain + 1], int nocheck, int n2) {
	FILE* fp; int i, x, y;
	fp = fopen(fn, "r"); 
	printf("%4cf%d={", ' ', nocheck);
	for (i = 1; i <= n2; i++) {
		fscanf(fp, "%d %d", &x, &y);
		adjancy[x][y] = 1;
		printf("%c(%d,%d)", ' ', x, y);
	}
	fclose(fp);
}