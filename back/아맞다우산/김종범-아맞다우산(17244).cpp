// https://www.acmicpc.net/problem/17244
// 실수좀 제발 그만

#include<bits/stdc++.h>
using namespace std;

typedef struct {
	int x, y, cnt;
}Info;

const int MAX = 50;
const int INF = 987654321;
int N, M, ans = INF;
char MAP[MAX][MAX];
bool visited[MAX][MAX];
bool bfscheck[MAX][MAX];
vector<pair<int, int>> v, picked;
bool check[5];
int sx, sy, ex, ey;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

Info bfs(int x, int y, int destX, int destY) {
	queue<Info> q;
	q.push({ x,y,0 });
	bfscheck[x][y] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		if (x == destX && y == destY) {
			Info I = { destX, destY,cnt };
			return I;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (MAP[nx][ny] != '#' && bfscheck[nx][ny] == false) {
				bfscheck[nx][ny] = true;
				q.push({ nx,ny,cnt + 1 });
			}
		}
	}
}

// 조합으로 뽑은 좌표 순서대로 최단거리 갱신
int solution() {
	Info res = { sx,sy,0 };
	int sum = 0;
	for (int i = 0; i < picked.size(); i++) {
		res = bfs(res.x, res.y, picked[i].first, picked[i].second);
		sum += res.cnt;
		memset(bfscheck, false, sizeof(bfscheck));
	}
	res = bfs(res.x, res.y, ex, ey);
	sum += res.cnt;
	memset(bfscheck, false, sizeof(bfscheck));
	return sum;
}

// 단순 조합
void dfs() {
	if (picked.size() == v.size()) {
		ans = min(ans, solution());
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		picked.push_back(v[i]);
		dfs();
		check[i] = false;
		picked.pop_back();
	}
}

void solve() {
	dfs();
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'X') {
				v.push_back({ i,j });
			}
			else if (MAP[i][j] == 'S') {
				sx = i;
				sy = j;
				MAP[i][j] = '.';
			}
			else if (MAP[i][j] == 'E') {
				ex = i;
				ey = j;
				MAP[i][j] = '.';
			}
		}
	}
	solve();
	return 0;
}