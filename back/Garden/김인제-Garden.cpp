/*
https://www.acmicpc.net/problem/18809

조합 + BFS 로 접근
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

int board[51][51];
int arr[51][51];
bool visited[51][51];
vector<pair<int, int>> cands;

int row, col, green, red;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<char> ret;

int maxVal = 0;

int sign(int x) {
	if (x == 0)return 0;
	return x < 0 ? -1 : 1;
}

void bfs() {
	int result = 0;

	memset(arr, 0, sizeof(arr));
	memset(visited, false, sizeof(visited));

	queue<pair<int, int>> q;

	for (int i = 0; i < ret.size(); i++) {
		int x = cands[i].first;
		int y = cands[i].second;

		if (ret[i] == 'g') {
			arr[x][y] = 1;
			q.push({ x, y });
		}
	}

	for (int i = 0; i < ret.size(); i++) {
		int x = cands[i].first;
		int y = cands[i].second;

		if (ret[i] == 'r') {
			arr[x][y] = -1;
			q.push({ x, y });
		}
	}

	while (q.empty() == false) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

        // 이미 꽃이 피어있다면, 배양액은 거기서 멈춘다
		if (visited[x][y])
			continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= row || ny >= col || board[nx][ny] == 0)
				continue;

			if (arr[nx][ny] == 0) {
				arr[nx][ny] = (arr[x][y] > 0 ? arr[x][y] + 1 : arr[x][y] - 1);
				q.push({ nx, ny });
			}
			else if (
				(sign(arr[nx][ny]) != sign(arr[x][y])) &&
				(abs(arr[nx][ny]) == (abs(arr[x][y]) + 1))&&
				visited[nx][ny] == false
				) {
				
				result++;

                // 한번 꽃이 핀 칸은, 다시 꽃이 필 수 없다
				visited[nx][ny] = true;

			}
		}
	}

	maxVal = max(maxVal, result);
}

void dfs(int idx,int green, int red) {
	if (green < 0 || red < 0)
		return;

	if (cands.size() - idx < green + red)
		return;

	if (green == 0 && red == 0) {
		bfs();
		return;
	}

	ret.push_back('g');
	dfs(idx + 1, green - 1, red);
	ret.pop_back();

	ret.push_back('r');
	dfs(idx + 1, green, red-1);
	ret.pop_back();

	ret.push_back(' ');
	dfs(idx + 1, green, red);
	ret.pop_back();


}

void solve() {
	dfs(0, green, red);

	cout << maxVal << endl;
}

int main() {
	cin >> row >> col >> green >> red;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> board[i][j];

			if (board[i][j] == 2)
				cands.push_back({ i, j });
		}


	solve();


	return 0;
}