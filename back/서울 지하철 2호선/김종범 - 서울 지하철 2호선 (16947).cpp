// https://www.acmicpc.net/problem/16947

#include<bits/stdc++.h>
using namespace std;

const int MAX = 3002;
int N;
bool flag;
bool visited[MAX];
int ans[MAX];
vector<int> graph[MAX];

void dfs(int first, int num, int cnt) {
	if (flag) return;
	
	for (int i = 0; i < graph[num].size(); i++) {
		int next = graph[num][i];
		if (visited[next]) {
			if (next == first && cnt > 2) {		// cnt가 2보다 큰 상태로 처음으로 돌아왔다 -> 순환이다.
				flag = true;
				return;
			}
		}
		else {
			visited[next] = true;
			dfs(first, next, cnt + 1);
			visited[next] = false;
		}
	}
}

// 순환선에 포함되지 않는 역들을 순환선까지의 노드 거리 찾기
void find_distance(int now) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ now, 0 });
	visited[now] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (ans[cur] == 0) {
			ans[now] = cnt;
			return;
		}

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (visited[next]) continue;
			visited[next] = true;
			q.push({ next, cnt + 1 });
		}
	}
}

void solve() {
	memset(ans, -1, sizeof(ans));

	for (int i = 1; i <= N; i++) {
		// memset(visited, false, sizeof(visited)); 
		flag = false;
		visited[i] = true;
		dfs(i,i,1);
		visited[i] = false;

		if (flag)
			ans[i] = 0;
	}
	
	for (int i = 1; i <= N; i++) {
		if (ans[i] == -1) {
			find_distance(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	solve();
	return 0;
}