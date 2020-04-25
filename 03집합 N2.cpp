#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include<math.h>
#define MAX 100

void setout(char A[MAX + 1]);
void Union(char A[MAX + 1], char B[MAX + 1]);
void Inter(char A[MAX + 1], char B[MAX + 1]);
void Minus(char A[MAX + 1], char B[MAX + 1]);

void main() {
	int i, j;
	int a_element, b_element, c_element;
	char seta[MAX + 1], setb[MAX + 1];
	int temp;
	srand(time(NULL));
	for (i = 1; i <= MAX; i++)
	{
		seta[i] = setb[i] = 0;
	}
	printf("\n*********************************************\n");
	printf("******* This is set operation program *******\n");

	printf("함수 A의 원소 개수입력: ");
	scanf("%d", &a_element);
	printf("함수 A의 원소 입력:");

	for (i = 0; i < a_element; i++) {
		scanf("%d", &temp);
		if (seta[temp] == 1) {
			printf("중복\n"); i--;
		}
		else {
			seta[temp] = 1;
		}
	}

	printf("함수 B의 원소 개수입력:");
	scanf("%d", &b_element);
	printf("함수 B의 원소 입력: ");
	for (i = 0; i < b_element; i++) {
		scanf("%d", &temp);
		if (setb[temp] == 1) {
			printf("중복\n");
			i--;
		}
		else { setb[temp] = 1; }
	}
	printf(" A = \n");
	setout(seta);
	printf(" B = \n");
	setout(setb);
	printf("\n");
	printf("A ∪ B = \n");
	Union(seta, setb);
	printf("A ∩ B = \n");
	Inter(seta, setb);
	printf(" A - B = \n");
	Minus(seta, setb);
	system("PAUSE");
}

void setout(char A[MAX + 1]) {
	int i, count = 0;
	printf("{");
	for (i = 1; i <= MAX; i++) {
		if (A[i] == 1) {
			if (count != 0) {
				printf(",");
			}
			printf("%4d", i);
			count = 1;
		}
	}
	printf("}\n\n");
}

void Union(char A[MAX + 1], char B[MAX + 1]) {
	int i; char temp[MAX + 1];
	for (i = 1; i <= MAX; i++) {
		if (A[i] == 1 || B[i] == 1) { temp[i] = 1; }
		else { temp[i] = 0; }
	}
	setout(temp);
}
void Inter(char A[MAX + 1], char B[MAX + 1]) {
	int i; char temp[MAX + 1];
	for (i = 1; i <= MAX; i++) {
		if (A[i] == 1 && B[i] == 1) { temp[i] = 1; }
		else { temp[i] = 0; }
	}
	setout(temp);
}
void Minus(char A[MAX + 1], char B[MAX + 1]) {
	int i; char temp[MAX + 1];
	for (i = 1; i <= MAX; i++) {
		if (A[i] == 1 && B[i] == 0) { temp[i] = 1; }
		else { temp[i] = 0; }
	}
	setout(temp);
}