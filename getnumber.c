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
	printf("Answer:");
	for (int i = 0; i < 4; i++) /*���� ���*/
	{
		printf(" %d", ans_arr[i]);
	}

	for (int k = 0; k < 5; k++) /*���� �Է�*/
	{
		strike = 0; /*��Ʈ����ũ, �� 0���� �ʱ�ȭ*/
		ball = 0;
		count++;
		printf("\n���ڸ� �Է��ϼ���: ");
		scanf("%d%d%d%d", &input[0], &input[1], &input[2], &input[3]);

	}
}