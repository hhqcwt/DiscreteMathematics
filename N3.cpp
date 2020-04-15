#include<stdio.h>
#include<Windows.h>
#include <time.h>

int main() {
	clock_t start, end;
	double result;

	int i, j, k;
	int arr_1[4][4] = { {1,2,3,4},{4,3,2,1},{2,5,7,9},{6,3,2,1} };
	int arr_2[4][4] = { {1,5,6,7},{8,3,1,7},{6,2,8,3},{9,2,1,2} };
	int res[4][4] = { {0} };
	//print Arr_1 
	printf("배열_1 : \n");
	for (i = 0; i < 4; i++) {
		printf("          ");
		for (j = 0; j < 4; j++) {
			printf("%4d", arr_1[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	//print Arr_2 
	printf("배열_2 : \n");
	for (i = 0; i < 4; i++) {
		printf("          ");
		for (j = 0; j < 4; j++) {
			printf("%4d", arr_2[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	//init res 
	start = clock();
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			res[i][j] = 0;
		}
	}
	//multi Arr_1 Arr_2 with ( i , j , k )               //1
	printf("배열_1 * 배열_2 (i,j,k 순서로) : \n");

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				res[i][j] += arr_1[i][k] * arr_2[k][j];
			}
		}
	}
	end = clock();
	result = (double)(end - start);

	//print res 
	for (i = 0; i < 4; i++) {
		printf("                            ");
		for (j = 0; j < 4; j++) {
			printf("%4d", res[i][j]);
		}
		printf("\n");
	}
	printf("걸린시간: %lf", result);
	printf("\n\n");

	//init res 
	start = clock();
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			res[i][j] = 0;
		}
	}
	//multi Arr_1 Arr_2 with ( i , k , j )           //2

	printf("배열_1 * 배열_2 (i,k,j순서로) : \n");
	for (i = 0; i < 4; i++) {
		for (k = 0; k < 4; k++) {
			for (j = 0; j < 4; j++) {
				res[i][j] += arr_1[i][k] * arr_2[k][j];
			}
		}
	}
	end = clock();
	result = (double)(end - start);

	//print res 
	for (i = 0; i < 4; i++) {
		printf("                            ");
		for (j = 0; j < 4; j++) {
			printf("%4d", res[i][j]);
		}
		printf("\n");
	}
	printf("걸린시간: %lf", result);
	printf("\n\n");

	//init res 
	start = clock();
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			res[i][j] = 0;
		}
	}
	//multi Arr_1 Arr_2 with ( j, i, k )            //3

	printf("배열_1 * 배열_2 (j,i,k 순서로) : \n");
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {
			for (k = 0; k < 4; k++) {
				res[i][j] += arr_1[i][k] * arr_2[k][j];
			}
		}
	}
	end = clock();
	result = (double)(end - start);

	//print res 
	for (i = 0; i < 4; i++) {
		printf("                            ");
		for (j = 0; j < 4; j++) {
			printf("%4d", res[i][j]);
		}
		printf("\n");
	}
	printf("걸린시간: %lf", result);
	printf("\n\n");

	//init res 
	start = clock();
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			res[i][j] = 0;
		}
	}
	//multi Arr_1 Arr_2 with ( j , k , i )             //4

	printf("배열_1 * 배열_2 (j,k,i 순서로) : \n");
	for (j = 0; j < 4; j++) {
		for (k = 0; k < 4; k++) {
			for (i = 0; i < 4; i++) {
				res[i][j] += arr_1[i][k] * arr_2[k][j];
			}
		}
	}
	end = clock();
	result = (double)(end - start);

	//print res 
	for (i = 0; i < 4; i++) {
		printf("                            ");
		for (j = 0; j < 4; j++) {
			printf("%4d", res[i][j]);
		}
		printf("\n");
	}
	printf("걸린시간: %lf", result);
	printf("\n\n");

	//init res 
	start = clock();
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			res[i][j] = 0;
		}
	}
	//multi Arr_1 Arr_2 with ( k, i, j )            //5

	printf("배열_1 * 배열_2 (k,i,j 순서로) : \n");
	for (k = 0; k < 4; k++) {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				res[i][j] += arr_1[i][k] * arr_2[k][j];
			}
		}
	}
	end = clock();
	result = (double)(end - start);

	//print res 
	for (i = 0; i < 4; i++) {
		printf("                            ");
		for (j = 0; j < 4; j++) {
			printf("%4d", res[i][j]);
		}
		printf("\n");
	}
	printf("걸린시간: %lf", result);
	printf("\n\n");

	//init res 
	start = clock();
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			res[i][j] = 0;
		}
	}
	//multi Arr_1 Arr_2 with ( k, j, i )            //6

	printf("배열_1 * 배열_2 (k,j,i 순서로) : \n");
	for (k = 0; k < 4; k++) {
		for (j = 0; j < 4; j++) {
			for (i = 0; i < 4; i++) {
				res[i][j] += arr_1[i][k] * arr_2[k][j];
			}
		}
	}
	end = clock();
	result = (double)(end - start);

	//print res 
	for (i = 0; i < 4; i++) {
		printf("                            ");
		for (j = 0; j < 4; j++) {
			printf("%4d", res[i][j]);
		}
		printf("\n");
	}
	printf("걸린시간: %lf", result);
	printf("\n\n");

	printf("결론: 각각 실행시간이 다르다.\n");
	return 0;
}