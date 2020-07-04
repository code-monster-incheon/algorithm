/*
https://www.acmicpc.net/problem/2589

모든 정점에 대해 BFS 로 해결
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

const int INF = 987654321;

int row, col;

char board[51][51];


int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ret = 0;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	bool visited[51][51];
	memset(visited, false, sizeof(visited));

	q.push({ x, y });
	visited[x][y] = true;

	int dist = -1;

	while (q.empty() == false) {
		dist++;
		int size = q.size();
		for (int k = 0; k < size; k++) {
			int curx = q.front().first;
			int cury = q.front().second;
			q.pop();


			for (int i = 0; i < 4; i++) {
				int nx = curx + dx[i];
				int ny = cury + dy[i];

				if (nx < 0 || ny < 0 || nx >= row || ny >= col)
					continue;


				if (visited[nx][ny] || board[nx][ny] == 'W')
					continue;

				visited[nx][ny] = true;
				q.push({ nx, ny });

			}
		}
	}

	ret = max(ret, dist);

}

void solve() {
	
}

int main() {
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		string s; cin >> s;
		for (int j = 0; j < col; j++) {
			board[i][j] = s[j];
		}
	}
;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}

	solve();

	cout << ret << endl;

	return 0;
}