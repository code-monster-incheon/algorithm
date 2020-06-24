// https://www.acmicpc.net/problem/14948
// 이분탐색 + bfs

#include<bits/stdc++.h>
using namespace std;

typedef struct {
	int x, y, jump;
}Info;

const int MAX = 101;
const int INF = 987654321;
int N, M, ans = INF;
int MAP[MAX][MAX];
bool visited[MAX][MAX][2];
vector<int> v;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

// 벽을 부수는 개념이 아니라, 벽을 뛰어 넘어서 같은 방향의 다다음 칸으로 이동하는 개념
bool bfs(int value) {
	queue<Info> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = true;
	
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int jump = q.front().jump;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny][jump]) continue;
			if (MAP[nx][ny] <= value) {
				visited[nx][ny][jump] = true;
				q.push({ nx,ny,jump });
			}
			else if (jump == 0) {
				int nnx = nx + dx[i];
				int nny = ny + dy[i];
				if (nnx < 0 || nnx >= N || nny < 0 || nny >= M || visited[nnx][nny][jump]) continue;
				if (MAP[nnx][nny] <= value) {	// 하..
					visited[nnx][nny][jump+1] = true;
					q.push({ nnx,nny,jump+1});
				}
			}
		}
	}
	return false;
}

bool check(int value) {
	memset(visited, false, sizeof(visited));
	if (MAP[0][0] > value) return false;
	bool res = bfs(value);
	return res;
}

void solve() {

	int start = 0, end = v.size() - 1, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (check(v[mid])) end = mid - 1;
		else start = mid + 1;
	}
	cout << v[start] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			v.push_back(MAP[i][j]);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	solve();
	return 0;
}
