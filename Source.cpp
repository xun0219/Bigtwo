#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstdlib>

#define LEN 13

int str_poker[LEN];
int int_poker[5][13] = {0};

void classification(int len, int str_array[], int int_array[][13]);
void check(int len, int poker[][13]);

int main()
{
	//��J�d�P
	int i,j;
	for (i = 0; i < LEN; i++)
		scanf("%d", &str_poker[i]); 
	//�P�_���Ʀr
	classification(LEN, str_poker, int_poker);

	//�X�k
	printf("���G:\n");
	check(LEN, int_poker);

	//�L�X�}�C
	for (i = 0; i < 5; i++) {
		if (i == 0) { printf("\n����\t"); }
		if (i == 1) { printf("���\t"); }
		if (i == 2) { printf("����\t"); }
		if (i == 3) { printf("�®�\t"); }
		if (i == 4) { printf("�i��\t"); }
	for (j = 0; j < 13; j++) { printf("%d\t", int_poker[i][j]); }
	printf("\n");
	}
	
	system("pause");
	return 0;
}

void classification(int len, int str_array[], int int_array[][13])
{
	int a, b;
	for (int i = 0; i < LEN; i++)
	{
		a = str_array[i] / 13;	//���A���� ��� ���� �®�
		b = str_array[i] % 13;	//�j�p
		int_array[a][b] = 1;	
		int_array[4][b]++ ;		//�����P�Ʀr�j�p���X�i
	}
}

void check(int len, int int_array[][13])
{ 
	int i, j, pair=0, triple=0, quad=0, quad_num=0, straight=0, fullhouse=0, straightflush=0, sum=0;

	printf("��i %d ��\n", len);

	printf("�@�� ");
	for (i = 0; i < LEN; i++){
		if (int_array[4][i] == 2) { pair+=1; }	//C2��2
		if (int_array[4][i] == 3) { pair+=3; }	//C3��2
		if (int_array[4][i] == 4) { pair+=6; }	//C4��2
	}
	printf("%d ��\n", pair);

	printf("�T�� ");
	for (i = 0; i < LEN; i++) {
		if (int_array[4][i] == 3) { triple+=1; }	//C3��3
		if (int_array[4][i] == 4) { triple+=4; }	//C4��3
	}
	printf("%d ��\n", triple);

	printf("�K�� ");
	for (i = 0; i < LEN; i++) {
		if (int_array[4][i] == 4) { quad_num+=1; }
	}
	quad = quad_num*9;
	printf("%d ��\n", quad);
	printf("�K�� %d ��\n", quad_num);

	printf("��Ī ");
	int temp2 = 1;
	for (i = 0; i < LEN; i++) {
		temp2 = 1;
		if (int_array[4][i] >= 3) {
			if (int_array[4][i] == 4) { temp2 *= 4; }
			for (j = 0; j < LEN; j++) {
				if (int_array[4][j] >= 2 && j != i) {
					if (int_array[4][j] == 2) { fullhouse += temp2; }
					if (int_array[4][j] == 3) {
						temp2 *= 3;
						fullhouse += temp2;
						temp2 /= 3;
					}
					else if (int_array[4][j] == 4) {
						temp2 *= 6;
						fullhouse += temp2;
						temp2 /= 6;
					}
				}
			}
		}
	}
	printf("%d ��\n", fullhouse);

	printf("���l ");
	int counter1 = 0, temp = 1;
	if (int_array[4][0] != 0) {
		counter1 += 1;
		temp *= int_array[4][0];
	}
	for (i = 12; i >= 0; i--) {
		if (int_array[4][i] != 0) {
			counter1 += 1;
			temp *= int_array[4][i];
			if (counter1 == 5) { straight += temp; }
			if (counter1 >= 6) {
				temp /= int_array[4][(i + 5) % 13];
				straight += temp;
			}
		}
		else {
			counter1 = 0;
			temp = 1;
		}
	}
	printf("%d ��\n", straight);

	printf("�P�ᶶ ");
	int counter2 = 0;
	for (i = 0; i <= 3; i++) {
		counter2 = 0;
		if (int_array[i][0] != 0) { counter2 += 1; }
		for (j = 12; j >= 0; j--) {
			if (int_array[i][j] != 0) {
				counter2 += 1;
				if (counter2 >= 5) { straightflush += 1; }
			}
			else { counter2 = 0; }
		}
	}
	printf("%d ��\n", straightflush);

	sum = len + pair + triple + quad + fullhouse + straight + straightflush;
	printf("�@ %d ��\n", sum);
}