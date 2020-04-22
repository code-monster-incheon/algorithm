// https://www.acmicpc.net/problem/1079

#include<bits/stdc++.h>
using namespace std;

const int MAX = 17;
int N, ans;
int MAP[MAX];		// ��������
int R[MAX][MAX];	// �������� ��������
bool alive[MAX];	// ��������
int mafia;

void MAP_change(int i) {
	for (int j = 0; j < N; j++) {
		if (!alive[j]) continue;
		MAP[j] += R[i][j];
	}
}

void MAP_reverse(int i) {
	for (int j = 0; j < N; j++) {
		if (!alive[j]) continue;
		MAP[j] -= R[i][j];
	}
}

void brute(int citizen, char day, int cnt) {
	if (!alive[mafia]) {		// ���Ǿư� �׾��ٴ°� ���� �׾��ٴ� ��
		ans = max(ans, cnt);
		return;
	}
	if (citizen == 0) {			// �ù��� 0�̶�°� ���Ǿư� �������� ��Ҵٴ� ��
		ans = max(ans, cnt);
		return;
	}

	if (day == 'n') {		// ���ΰ��
		for (int i = 0; i < N; i++) {
			if (i == mafia || !alive[i]) continue;		// ���Ǿưų� �ù��� �̹� ���� ���
			alive[i] = false;
			MAP_change(i);
			brute(citizen - 1, 'a', cnt + 1);
			MAP_reverse(i);
			alive[i] = true;
		}
	}
	else if (day == 'a') {	// ���ΰ��
		int person = 0, maxMAP = 0;
		for (int i = N - 1; i >= 0; i--) {	// �������� �����鼭 ���� �Ʒ���ȣ �� ��� ���ϱ�
			if (!alive[i]) continue;
			if (MAP[i] >= maxMAP) {
				maxMAP = MAP[i];
				person = i;
			}
		}
		alive[person] = false;
		if (person == mafia)
			brute(citizen, 'n', cnt);
		else
			brute(citizen - 1, 'n', cnt);
		alive[person] = true;
	}
}

void solve() {
	memset(alive, true, sizeof(alive));

	if (N % 2 == 0)	// ��
		brute(N - 1, 'n', 0);
	else			// ��;
		brute(N - 1, 'a', 0);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> MAP[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> R[i][j];
	cin >> mafia;
	solve();
	return 0;
}