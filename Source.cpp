#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 13

int str_poker[LEN];
int int_poker[5][13] = {0};

void classification(int len, int str_array[], int int_array[][13]);
void check(int len, int poker[][13]);

int main()
{
	//輸入卡牌
	int i,j;
	for (i = 0; i < LEN; i++)
		scanf("%d", &str_poker[i]); 
	//判斷花色數字
	classification(LEN, str_poker, int_poker);

	//出法
	printf("結果:\n");
	check(LEN, int_poker);

	//印出陣列
	for (i = 0; i < 5; i++) {
		if (i == 0) { printf("\n梅花\t"); }
		if (i == 1) { printf("方塊\t"); }
		if (i == 2) { printf("紅心\t"); }
		if (i == 3) { printf("黑桃\t"); }
		if (i == 4) { printf("張數\t"); }
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
		a = str_array[i] / 13;	//花色，梅花 方塊 紅心 黑桃
		b = str_array[i] % 13;	//大小
		int_array[a][b] = 1;	
		int_array[4][b]++ ;		//紀錄同數字大小有幾張
	}
}

void check(int len, int int_array[][13])
{ 
	int i, j, pair=0, triple=0, quad=0, straight=0, fullhouse=0, straightflush=0, sum=0;

	printf("單張 %d 種\n", len);

	printf("一對 ");
	for (i = 0; i < LEN; i++){
		if (int_array[4][i] == 2) { pair+=1; }	//C2取2
		if (int_array[4][i] == 3) { pair+=3; }	//C3取2
		if (int_array[4][i] == 4) { pair+=6; }	//C4取2
	}
	printf("%d 種\n", pair);

	printf("三條 ");
	for (i = 0; i < LEN; i++) {
		if (int_array[4][i] == 3) { triple+=1; }	//C3取3
		if (int_array[4][i] == 4) { triple+=4; }	//C4取3
	}
	printf("%d 種\n", triple);

	printf("鐵支 ");
	for (i = 0; i < LEN; i++) {
		if (int_array[4][i] == 4) {
			for (j = 0; j < LEN; j++) {
				if (int_array[4][j] == 1) { quad+=1; }
				if (int_array[4][j] == 2) { quad+=2; }
				if (int_array[4][j] == 3) { quad+=3; }
			}
		}
	}
	printf("%d 種\n", quad);

	printf("葫蘆 ");
	for (i = 0; i < LEN; i++) {
		if (int_array[4][i] == 3) {
			for (j = 0; j < LEN; j++) {
				if (int_array[4][j] == 2) { fullhouse += 1; }
			}
		}
	}
	printf("%d 種\n", fullhouse);

	printf("順子 ");
	
	printf("%d 種\n", straight);

	printf("同花順 ");
	
	printf("%d 種\n", straightflush);

	sum = len + pair + triple + quad + fullhouse + straight + straightflush;
	printf("共 %d 種\n", sum);
}