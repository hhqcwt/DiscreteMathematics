#include<Windows.h> 
#include <stdio.h>
#define MAXITEM 10

void main() {
	int m[MAXITEM + 1][MAXITEM + 1];
	int i, j, x, y, max;
	printf("�Է����� ���� ���� ����� ���� ũ���?\n");
	scanf("%d", &max);
	printf("\n");
	printf("1�� 0���� �����͸� �Է��ϼ���.?\n");
	for (i = 1; i <= max; i++) {
		for (j = 1; j <= max; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	printf("\n");
	for (i = 1; i <= max; i++) {
		for (j = 1; j <= max; j++) {
			if (m[i][j] == 1) {
				for (x = 1; x <= max; x++) {
					if (m[j][x] == 1) {
						for (y = 1; y <= max; y++) {
							if (m[x][y] == 1) {
								printf("(%2d%2d%2d%2d) => (%d..%d)\n", i, j, x, y, i, y);
							}
						}
					}
				}
			}
		}
	}
	system("PAUSE");
}
