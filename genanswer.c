#include <stdio.h>
#include <stdlib.h> /*rand �Լ�*/
#include <time.h>

int main(void)
{
	srand(time(NULL)); /*1�ʸ��� �ٸ� ������ ����*/
	int answer = 0;
	int ans_arr[4] = { 0,0,0,0 };

	for (int i = 0; i < 4; i++)
	{
		ans_arr[i] = rand() % 9 + 1; /*1~9���� ���� ����*/
		
		for (int j = 0; j < i; j++) /*�ߺ� �˻�*/
		{
			if (ans_arr[i] == ans_arr[j])
				i--;
		}
		
	}
	for (int i = 0; i < 4; i++) /*���� ���*/
	{
		printf("%d", ans_arr[i]);
	}
}
