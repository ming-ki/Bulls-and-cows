#include <stdio.h>
#include <stdlib.h> /*rand 함수*/
#include <time.h>

int main(void)
{
	srand(time(NULL)); /*1초마다 다른 랜덤값 생성*/
	int answer = 0;
	int count = 0;
	int strike;
	int ball;
	int ans_arr[4] = { 0,0,0,0 };
	int input[4] = { 0,0,0,0 };

	for (int i = 0; i < 4; i++)
	{
		ans_arr[i] = rand() % 9 + 1; /*1~9까지 난수 생성*/

		for (int j = 0; j < i; j++) /*중복 검사*/
		{
			if (ans_arr[i] == ans_arr[j])
				i--;
		}

	}
	//printf("Answer:");
	///*for (int i = 0; i < 4; i++) /*정답 출력*/
	//{
	//	printf(" %d\n", ans_arr[i]);
	//} */

	for (int k = 0; k < 5; k++) /*정답 입력*/
	{
		strike = 0; /*스트라이크, 볼 0으로 초기화*/
		ball = 0;
		count++;
		int same=0;
		printf("숫자를 입력하세요: "); /*수 입력 받기*/
		scanf("%d%d%d%d", &input[0], &input[1], &input[2], &input[3]);

			for (int t = 0; t < 4; t++) /*입력 받은 답 중복 확인*/
			{
				for (int c = 0; c < 4; c++)
				{
					if (input[t] == input[c])
					{
						same++;
					}
				}
			}
			if (same != 4) /*중복 경고문*/
			{
				count--;
				k--; /*중복된 것은 횟수 증가 X*/
				printf("\n중복된 수를 입력하지마세요.\n");
			}
			else
			{
				if (ans_arr[0] == input[0]) strike++; /*숫자 비교*/
				else if (ans_arr[0] == input[1] || ans_arr[0] == input[2] || ans_arr[0] == input[3]) ball++;
				if (ans_arr[1] == input[1]) strike++;
				else if (ans_arr[1] == input[0] || ans_arr[1] == input[2] || ans_arr[1] == input[3]) ball++;
				if (ans_arr[2] == input[2]) strike++;
				else if (ans_arr[2] == input[0] || ans_arr[2] == input[1] || ans_arr[2] == input[3]) ball++;
				if (ans_arr[3] == input[3]) strike++;
				else if (ans_arr[3] == input[0] || ans_arr[3] == input[1] || ans_arr[3] == input[2]) ball++;

				printf("\n[%d회]  Strike: %d    Ball: %d\n\n", count, strike, ball);
			}

		if (strike == 4) /*게임 성공 여부*/
		{
			printf("<<GAME SUCCESS>>\n\n");
			break;
		}
		else if (k == 4)
		{
			printf("<<GAME OVER>>\n\n");
			printf("Answer:");
			for (int i = 0; i < 4; i++) /*정답 출력*/
			{
				printf(" %d", ans_arr[i]);
			}
			printf("\n");
			break;
		}
	}
}