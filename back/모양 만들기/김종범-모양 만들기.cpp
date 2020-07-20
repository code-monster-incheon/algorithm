// https://www.acmicpc.net/problem/16932

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1001;
int N, M, ans;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int CNT[MAX*MAX];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	MAP[x][y] = cnt;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || MAP[nx][ny] == 0 || visited[nx][ny]) continue;
			MAP[nx][ny] = cnt;
			q.push({ nx,ny });
			visited[nx][ny] = true;
		}
	}
}

void solve() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 1 && visited[i][j] == false) {
				bfs(i, j, ++cnt);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j]) {
				CNT[MAP[i][j]]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!MAP[i][j]) {
				vector<int>tmp;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (MAP[nx][ny]) {
						tmp.push_back(MAP[nx][ny]);
					}
				}
				if (!tmp.empty()) {
					sort(tmp.begin(), tmp.end());
					tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

					int sum = 0;
					for (int k = 0; k < tmp.size(); k++) {
						sum += CNT[tmp[k]];
					}
					sum += 1;
					ans = max(ans, sum);
				}
			}
		}
	}

	cout << ans << '\n';
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