/*
https://www.acmicpc.net/problem/5549

2차원 누적합 문제.
주의할 점은 입출력이 10만개 로 많으므로, cin, cout 으로 처리하면 알고리즘은 맞았어도 입출력에서 시간초과.
이때에는 printf, scanf 를 사용해야 함.
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int sum[1002][1002][3];
char board[1002][1002];
int N, M;;
int num;

char type[3] = { 'J', 'O', 'I' };

int startX, startY, endX, endY;

void accumulateSum() {
	for (int k = 0; k < 3; k++) {
		int ret = sum[endX][endY][k] - sum[startX - 1][endY][k] - sum[endX][startY - 1][k] + sum[startX - 1][startY - 1][k];

		printf("%d ", ret);
	}printf("\n");

}

int main() {
	cin >> M >> N;
	cin >> num;

	for (int i = 1; i <= M; i++) {
		string s;	cin >> s;
		for (int j = 1; j <= N; j++) {
			board[i][j] = s[j - 1];
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {

			for (int k = 0; k < 3; k++) {
				sum[i][j][k] = sum[i][j - 1][k] + sum[i - 1][j][k] - sum[i - 1][j - 1][k];

				if (board[i][j] == type[k])
					sum[i][j][k]++;
			}

		}
	}

	for (int i = 0; i < num; i++) {
		scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
		// cin >> startX >> startY >> endX >> endY;
        // 10만개 이상의 입출력시, cin 은 시간초과가 남! printf, scanf 사용할 것!

		accumulateSum();
	}
	return 0;
}

