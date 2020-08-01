// https://www.acmicpc.net/problem/15812
// 오랜만에 bfs 레벨링 문제

#include<bits/stdc++.h>
using namespace std;

typedef struct {
	int x, y;
}Info;

const int MAX = 21;
const int INF = 987654321;
int N, M, ans = INF;
int MAP[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<pair<int, int>> v, picked, town;

bool check() {
	for (int i = 0; i < town.size(); i++) {
		if (visited[town[i].first][town[i].second] == false) return false;
	}
	return true;
}

void bfs() {
	memset(visited, false, sizeof(visited));
	queue<Info> q;
	q.push({ picked[0].first, picked[0].second });
	q.push({ picked[1].first, picked[1].second });
	visited[picked[0].first][picked[0].second] = true;
	visited[picked[1].first][picked[1].second] = true;

	int bfs_level = 0;
	while (!q.empty()) {
		int size = q.size();
		bfs_level++;
		for (int i = 0; i < size; i++) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny]) continue;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
		if (check()) {
			ans = min(ans, bfs_level);
			return;
		}
	}
}

void dfs(int idx) {
	if (picked.size() == 2) {
		bfs();
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		picked.push_back(v[i]);
		dfs(i + 1);
		picked.pop_back();
	}
}

void solve() {
	dfs(0);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			MAP[i][j] = str[j] - '0';
			if (MAP[i][j] == 1) town.push_back({ i,j });
			else v.push_back({ i,j });
		}
	}
	solve();
	return 0;
}