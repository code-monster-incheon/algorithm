// https://www.acmicpc.net/problem/15809
// 쉬운 union-find
// 유의해야 할점 : 두 국가가 동맹을 했으면 하나의 국가로 바뀐다!

#include<bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int N, M;
int parents[MAX], army[MAX];

// 부모 찾기
int getParent(int x) {
	if (parents[x] == x) return x;
	return parents[x] = getParent(parents[x]);
}

// 동맹
void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) {
		parents[b] = a;
		army[a] += army[b];
		army[b] = 0;
	}
	else {
		parents[a] = b;
		army[b] += army[a];
		army[a] = 0;
	}
}

void solve() {
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		if (army[i] > 0) v.push_back(army[i]);
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';

	for (int i = 1; i <= N; i++) {
		cout << parents[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parents[i] = i;
		cin >> army[i];
	}
	for (int i = 0; i < M; i++) {
		int O, P, Q;
		cin >> O >> P >> Q;

		if (O == 1) {		// 동맹
			Union(P, Q);
		}
		else {				// 전쟁
			int p = getParent(P);
			int q = getParent(Q);
			if (army[p] == army[q]) {		// 전쟁해야할 두 나라의 총 병력이 같을때
				parents[p] = parents[q] = 0;
				army[p] = army[q] = 0;
			}
			else if (army[p] > army[q]) {	// P나라의 병력이 더 많을때, Q는 P의 속국이 된다.
				army[p] -= army[q];
				army[q] = 0;
				parents[q] = p;
			}
			else if (army[p] < army[q]) {	// Q나라의 병력이 더 많을때, P는 Q의 속국이 된다.
				army[q] -= army[p];
				army[p] = 0;
				parents[p] = q;
			}
		}
	}

	solve();
	return 0;
}