#include<stdio.h>
#include<Windows.h>
void main()
{
	int i;
	int input;
	printf("�Է�(Input)�� ���� �Ҽ� �Ǻ��� �ص帳�ϴ�.\n");
	printf("�Ҽ� �Ǻ��ϱ� ���� N���� �Է��� �ּ��� : "); scanf("%d", &input);
	for (i = 2; i < input; i++)
	{
		if (input % i == 0 && input != i)
		{
			printf("\ninput number -->%5d Not Prime number!!\n", input);
			system("PAUSE");
			return;
		}
	}
	if (input > 1)
	{
		printf("\ninput number -->%5d Prime number!!\n", input);
	}
	else
	{
		printf("\ninput number -->%5d Not Prime number!!\n", input);
	}
	system("PAUSE");
}