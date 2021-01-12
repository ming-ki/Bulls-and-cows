#include <stdio.h>
#include <stdlib.h> /*rand �Լ�*/
#include <time.h>

int main(void)
{
	srand(time(NULL)); /*1�ʸ��� �ٸ� ������ ����*/
	int answer = 0;
	int count = 0;
	int strike;
	int ball;
	int ans_arr[4] = { 0,0,0,0 };
	int input[4] = { 0,0,0,0 };

	for (int i = 0; i < 4; i++)
	{
		ans_arr[i] = rand() % 9 + 1; /*1~9���� ���� ����*/

		for (int j = 0; j < i; j++) /*�ߺ� �˻�*/
		{
			if (ans_arr[i] == ans_arr[j])
				i--;
		}

	}
	//printf("Answer:");
	///*for (int i = 0; i < 4; i++) /*���� ���*/
	//{
	//	printf(" %d\n", ans_arr[i]);
	//} */

	for (int k = 0; k < 5; k++) /*���� �Է�*/
	{
		strike = 0; /*��Ʈ����ũ, �� 0���� �ʱ�ȭ*/
		ball = 0;
		count++;
		int same=0;
		printf("���ڸ� �Է��ϼ���: "); /*�� �Է� �ޱ�*/
		scanf("%d%d%d%d", &input[0], &input[1], &input[2], &input[3]);

			for (int t = 0; t < 4; t++) /*�Է� ���� �� �ߺ� Ȯ��*/
			{
				for (int c = 0; c < 4; c++)
				{
					if (input[t] == input[c])
					{
						same++;
					}
				}
			}
			if (same != 4) /*�ߺ� ���*/
			{
				count--;
				k--; /*�ߺ��� ���� Ƚ�� ���� X*/
				printf("\n�ߺ��� ���� �Է�����������.\n");
			}
			else
			{
				if (ans_arr[0] == input[0]) strike++; /*���� ��*/
				else if (ans_arr[0] == input[1] || ans_arr[0] == input[2] || ans_arr[0] == input[3]) ball++;
				if (ans_arr[1] == input[1]) strike++;
				else if (ans_arr[1] == input[0] || ans_arr[1] == input[2] || ans_arr[1] == input[3]) ball++;
				if (ans_arr[2] == input[2]) strike++;
				else if (ans_arr[2] == input[0] || ans_arr[2] == input[1] || ans_arr[2] == input[3]) ball++;
				if (ans_arr[3] == input[3]) strike++;
				else if (ans_arr[3] == input[0] || ans_arr[3] == input[1] || ans_arr[3] == input[2]) ball++;

				printf("\n[%dȸ]  Strike: %d    Ball: %d\n\n", count, strike, ball);
			}

		if (strike == 4) /*���� ���� ����*/
		{
			printf("<<GAME SUCCESS>>\n\n");
			break;
		}
		else if (k == 4)
		{
			printf("<<GAME OVER>>\n\n");
			printf("Answer:");
			for (int i = 0; i < 4; i++) /*���� ���*/
			{
				printf(" %d", ans_arr[i]);
			}
			printf("\n");
			break;
		}
	}
}