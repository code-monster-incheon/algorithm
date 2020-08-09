// https://www.acmicpc.net/problem/16929

#include<bits/stdc++.h>
using namespace std;

const int MAX = 50;
int N, M;
bool ans;
char MAP[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int fx, int fy, int x, int y, int cnt, char alpha) {
	if (ans) return;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || MAP[nx][ny] != alpha) continue;
		if (nx == fx && ny == fy) {
			if (visited[nx][ny] == true && cnt > 2) {
				ans = true;
				return;		
			}
		}
		else {
			if (visited[nx][ny] == false) {
				visited[nx][ny] = true;
				dfs(fx, fy, nx, ny, cnt + 1, alpha);
				visited[nx][ny] = false;
			}
		}
	}

}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ans == false) {
				visited[i][j] = true;
				dfs(i, j, i, j, 1, MAP[i][j]);
				visited[i][j] = false;
			}
		}
	}
	
	if (ans) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
	solve();
	return 0;
}