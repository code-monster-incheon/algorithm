// https://programmers.co.kr/learn/courses/30/lessons/17679

#include<bits/stdc++.h>
using namespace std;

const int MAX = 30;
int N, M, ans;
char MAP[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void down(int x, int y) {
	char temp = MAP[x][y];
	MAP[x][y] = '.';

	int nx = x + dx[2];	// 아래로 내리기
	while (true) {
		if (nx >= N || MAP[nx][y] != '.') {
			nx -= dx[2];
			break;
		}
		nx += dx[2];
	}
	MAP[nx][y] = temp;
}

int solution(int m, int n, vector<string> board) {

	swap(m, n);
	N = n, M = m;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].length(); j++) {
			MAP[i][j] = board[i][j];
		}
	}

	while (true) {
		bool flag = false;
		memset(visited, false, sizeof(visited));

		// 같은놈들 찾기
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 1; j++) {
				if (MAP[i][j] != '.' && MAP[i][j] == MAP[i + 1][j] && MAP[i][j] == MAP[i][j + 1] && MAP[i][j + 1] == MAP[i + 1][j + 1]) {
					visited[i][j] = true;
					visited[i + 1][j] = true;
					visited[i][j + 1] = true;
					visited[i + 1][j + 1] = true;
				}
			}
		}

		// 공백으로 바꾸기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j]) {
					MAP[i][j] = '.';
					flag = true;
					ans++;
				}
			}
		}

		if (!flag) return ans;	// 더이상 터질께 없다면

		// 공백 내리기
		for (int j = 0; j < M; j++) {
			for (int i = N - 1; i >= 0; i--) {
				if (MAP[i][j] != '.')
					down(i, j);
			}
		}	
	}
}
