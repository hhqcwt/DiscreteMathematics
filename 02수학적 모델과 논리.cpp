#include<stdio.h>
#include<windows.h>

//�������� ������ ������ ����ó�� �� �� ������ �ǹ��ϴ� Node�Դϴ�.
struct Node {
	int Value;
	//�ռ����� �Ǵ� �ǿ������� �������� ��� �����Դϴ�.
	int HeadArrive;
	//Stack�� head�� ����ִ��� ������� �������� �����ϴ� �����Դϴ�.
	char Modify[200];
	//�ռ����� �� �Ǵ� �ǿ�����, �����ڵ��� ����ִ� ���ڿ� �����Դϵ�.
	struct Node* Next;
	//���� ��带 ����Ű�� ����ü �������Դϴ�. 
};

typedef struct Node Node; Node* Push(Node* head, int value, char* modify) {
	int i; Node* NewNode, * Temp = head;
	if (head->HeadArrive == 0) {
		head->Value = value;//����ִ� ��忡 ���� �����մϴ�.
		head->Next = NULL;//�ֻ�� ����̱⶧���� Next�� Null�Դϴ�.
		head->HeadArrive = 1;
		i = 0;

		while (modify[i] != '\0')//�ռ������� �����մϴ�.
		{
			head->Modify[i] = modify[i]; i++;
		}
		head->Modify[i] = '\0';
		return head;//��尪�� �����մϴ�.
	}
	else {
		while (Temp->Next != NULL)//������ �ֻ�ܱ��� ã�ư��ϴ�.
		{
			Temp = Temp->Next;
		} NewNode = (Node*)malloc(sizeof(Node));//���ο� ��带 �Ҵ��մϴ�.
		Temp->Next = NewNode;
		NewNode->Value = value;//���� �����մϴ�.
		NewNode->Next = NULL;
		i = 0;
		while (modify[i] != '\0')//�ռ������� �����մϴ�. 
		{
			NewNode->Modify[i] = modify[i];
			i++;
		}NewNode->Modify[i] = '\0';
		return NewNode;
	}
}
//-------------------------------------------------------------------------------------
//Top��带 �˽�Ű�� Top Node �� �ּҰ��� �����մϴ�. 
Node* Pop(Node* head, char* copyModify)
{
	int i = 0, j = 0;
	//Index�� ����� i,j�� �����մϴ�.
	Node* Temp = head, * Temp2;
	if (head->Next == NULL)
		//���� ��尡 �� ������ ��.
	{
		if (head->HeadArrive == 0)
			//���� head�� ������� ��. 
		{
			printf("�߸��� Pop����.\n");
			return 0;
		}

		while (copyModify[j] != '\0') {
			j++;
		}
		while (head->Modify[i] != '\0') {
			copyModify[j + i] = head->Modify[i];
			i++;
		}
		copyModify[j + i] = '\0';
		head->HeadArrive = 0;
		return head;
	}
	else {
		while (Temp->Next->Next != NULL) {
			Temp = Temp->Next;
		}
		Temp2 = Temp;

		Temp = Temp->Next;
		while (copyModify[j] != '\0') {
			j++;
		}
		while (Temp->Modify[i] != '\0') {
			copyModify[j + i] = Temp->Modify[i];
			i++;
		} copyModify[j + i] = '\0';
		Temp2->Next = NULL; free(Temp);

		return Temp2;

	}
}

int checkElementry(char* Input, char* EleAry) {
	int i = 0, j, k; int valueNum = 0;
	while (Input[i] != '\0')
	{
		switch (Input[i])
		{
		case '&': case '|': case '>': case '!': break;
		default:
			j = 0;
			k = 0;
			while (EleAry[j] != '\0') {
				if (Input[i] == EleAry[j]) {
					k = 1;
					break;
				}
				j++;
			}
			if (k == 0)
			{
				valueNum++; EleAry[j] = Input[i]; EleAry[j + 1] = '\0';
			}
		}
		i++;
	}
	return valueNum;

}

void cSwap(char* cAry) {
	int i = 0, length;
	char swap;
	while (cAry[i] != '\0')
	{
		i++;
	}
	length = i - 1;
	for (i = 0; i <= length / 2; i++)
	{
		swap = cAry[i];
		cAry[i] = cAry[length - i];
		cAry[length - i] = swap;
	}
}

int ParsingCheck(char Stack, char Input) {
	int ParsingTable[4][4] = { {1,1,1,0}, {1,1,1,0}, {1,1,1,0}, {1,1,1,0} };
	int i, j;
	switch (Stack) {
	case '&': i = 0; break;
	case '|': i = 1; break;
	case '>': i = 2; break;
	case '!': i = 3; break;
	}
	switch (Input)
	{
	case '&': j = 0; break;
	case '|': j = 1; break;
	case '>': j = 2; break;
	case '!': j = 3; break;
	}
	return ParsingTable[i][j];
}

int MainOperator(int value_1, char op, int value_2) {
	switch (op) {
	case '!': if (value_1 == 0) { return 1; }
			else { return 0; } break;
	case '|': if ((value_1 | value_2) != 0) {
		return 1;
	}
			else {
		return 0;
	} break;
	case '&':
		if ((value_1 & value_2) == 1) { return 1; }
		else { return 0; } break;
	case '>': if (value_1 == 1 && value_2 == 0)
	{
		return 0;
	}
			else { return 1; } break; default:
				printf("�߸��� ������.\n"); return -1;
	}
}
double LowPower(int under, int upper) {
	int i; double result = 1.0; if (upper < 0)
	{
		for (i = 0; i < (upper * -1); i++) { result *= (double)under; } return result;
	}
	else if (upper == 0)
	{
		return 1.0;
	}
	else
	{
		for (i = 0; i < upper; i++) { result *= (double)under; } return result;
	}
}
void valueTableCreate(int** Ary, int valueNum) {
	int i, j; for (i = 0; i < valueNum; i++) {
		for (j = 0; j < LowPower(2, valueNum); j++) {
			if ((j & (int)LowPower(2, (valueNum - 1) - i)) != 0)
			{
				Ary[i][j] = 1;
			}
			else { Ary[i][j] = 0; }
		}
	}
}
int BackValue(int** Ary, char* EleAry, char Check, int InputNum)
{
	int i = 0;
	while (EleAry[i] != '\0') {
		if (EleAry[i] == Check)
		{
			break;
		} i++;
	} return Ary[i][InputNum];

}
int HowManyLength(char* Input) {
	int i = 0;
	while (Input[i] != '\0') {
		i++;
	}
	return i;
}

int main() {
	FILE* fp; char InModify[200];
	char TempModify[200] = { '\0' };
	char EleAry[10] = { '\0' };
	char TempOp;
	int valueNum = 0;

	int EleValue = 0;
	int TempValue_1, TempValue_2, ResultValue;
	int i, j, k, p;
	int modifyPrint = 0;
	int modifyLength = 0;
	int HoleLineLength = 0;
	int** valueAry;

	Node Operator, Operand, * tail_1 = &Operator, * tail_2 = &Operand;
	Operator.HeadArrive = 0;
	Operand.HeadArrive = 0;
	Operator.Modify[0] = '\0';
	Operand.Modify[0] = '\0';
	system("mode con:cols=150 lines=30"); fp = fopen("Truth Table.txt", "w");
	printf("�ռ����� �Է�: ");
	scanf("%s", InModify);

	valueNum = checkElementry(InModify, EleAry);

	valueAry = (int**)malloc(sizeof(int*) * valueNum);
	for (i = 0; i < valueNum; i++) {
		valueAry[i] = (int*)malloc(sizeof(int) * ((int)LowPower(2, valueNum)));
	}
	valueTableCreate(valueAry, valueNum);
	printf("\n\n- Truth Table -\n\n");
	fprintf(fp, "- Truth Table -\n\n");

	for (j = 0; j < (int)LowPower(2, valueNum); j++) {
		printf("| "); fprintf(fp, "| ");
		HoleLineLength += 2;
		for (k = 0; k < valueNum; k++) {
			if (j == 0 && modifyPrint == 0) {
				printf("%c ", EleAry[k]);
				fprintf(fp, "%c ", EleAry[k]);
				HoleLineLength += 2;
			}
			else {
				printf("%c ", valueAry[k][j] ? 'T' : 'F');
				fprintf(fp, "%c ", valueAry[k][j] ? 'T' : 'F');
			}
		} printf("|"); fprintf(fp, "|");
		HoleLineLength += 1;
		i = 0;
		while (InModify[i] != '\0') {
			switch (InModify[i]) {
			case '!':case '&':case '|':case '>':
				while (Operator.HeadArrive == 1 && ParsingCheck(tail_1->Modify[0], InModify[i])) {
					TempModify[0] = '\0'; if (tail_1->Modify[0] == '!') {

						TempValue_1 = tail_2->Value;
						tail_2 = Pop(&Operand, TempModify);
						TempOp = tail_1->Modify[0];
						tail_1 = Pop(&Operator, TempModify);
						ResultValue = MainOperator(TempValue_1, TempOp, TempValue_1);
						tail_2 = Push(&Operand, ResultValue, TempModify); cSwap(TempModify);
					}
					else {
						TempValue_2 = tail_2->Value;
						tail_2 = Pop(&Operand, TempModify);
						TempOp = tail_1->Modify[0];
						tail_1 = Pop(&Operator, TempModify);
						TempValue_1 = tail_2->Value; tail_2 = Pop(&Operand, TempModify);
						ResultValue = MainOperator(TempValue_1, TempOp, TempValue_2);
						tail_2 = Push(&Operand, ResultValue, TempModify); cSwap(TempModify);
					}
					if (j == 0 && modifyPrint == 0) {
						printf("   %s   |", TempModify);
						fprintf(fp, "   %s   |", TempModify);
						HoleLineLength += HowManyLength(TempModify) + 7;
					}
					else {
						modifyLength = HowManyLength(TempModify) + 6; for (p = 0; p < modifyLength / 2; p++)
						{
							printf(" ");
							fprintf(fp, " ");
						}
						printf("%c", tail_2->Value ? 'T' : 'F');
						fprintf(fp, "%c", tail_2->Value ? 'T' : 'F');
						for (p = 0; p < (modifyLength - 1) / 2; p++) {
							printf(" ");
							fprintf(fp, " ");
						}
						printf("|");
						fprintf(fp, "|");
					}
				} TempModify[0] = InModify[i];
				TempModify[1] = '\0'; tail_1 = Push(&Operator, 0, TempModify);
				break;
			default:
				TempModify[0] = InModify[i];
				TempModify[1] = '\0';
				EleValue = BackValue(valueAry, EleAry, InModify[i], j);
				tail_2 = Push(&Operand, EleValue, TempModify);
			} i++;
		}
		while (Operator.HeadArrive == 1) {
			TempModify[0] = '\0'; if (tail_1->Modify[0] == '!') {
				TempValue_1 = tail_2->Value;
				tail_2 = Pop(&Operand, TempModify);
				TempOp = tail_1->Modify[0];
				tail_1 = Pop(&Operator, TempModify);
				ResultValue = MainOperator(TempValue_1, TempOp, TempValue_1);
				tail_2 = Push(&Operand, ResultValue, TempModify);
				cSwap(TempModify);
			}
			else {
				TempValue_2 = tail_2->Value;
				tail_2 = Pop(&Operand, TempModify);
				TempOp = tail_1->Modify[0];
				tail_1 = Pop(&Operator, TempModify);
				TempValue_1 = tail_2->Value;
				tail_2 = Pop(&Operand, TempModify);

				ResultValue = MainOperator(TempValue_1, TempOp, TempValue_2);
				tail_2 = Push(&Operand, ResultValue, TempModify);
				cSwap(TempModify);
			}

			if (j == 0 && modifyPrint == 0) {
				printf("   %s   |", TempModify);
				fprintf(fp, "   %s   |", TempModify);
				HoleLineLength += HowManyLength(TempModify) + 7;
			}
			else
			{

				modifyLength = HowManyLength(TempModify) + 6;
				for (p = 0; p < modifyLength / 2; p++) {
					printf(" "); fprintf(fp, " ");
				}
				printf("%c", tail_2->Value ? 'T' : 'F');
				fprintf(fp, "%c", tail_2->Value ? 'T' : 'F');
				for (p = 0; p < (modifyLength - 1) / 2; p++) {
					printf(" ");
					fprintf(fp, " ");
				}
				printf("|");
				fprintf(fp, "|");
			}
		}
		Operand.HeadArrive = 0;
		printf("\n");
		fprintf(fp, "\n");
		if (j == 0 && modifyPrint == 0) {
			j = -1; modifyPrint = 1;
			for (p = 0; p < HoleLineLength; p++) {
				printf("=");
				fprintf(fp, "=");
			}
			printf("\n");
			fprintf(fp, "\n");
		}
	} printf("\n");
	fclose(fp);
	system("PAUSE");
	return 0;
}