/*
https://www.acmicpc.net/problem/19237

전형적인 구현 문제
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
int N, M, K;

class Shark {
public:
	int x = 0;
	int y = 0;
	int prevDirection = 0;
	vector <vector<int> > direct = vector <vector<int> >(4, vector<int>(4, 0));

	Shark() {}
	Shark(int x, int y)
		:x(x), y(y) {}
};

// 1 ~ M 번 상어의 정보 저장
vector< Shark > sharks;

int board[21][21];

// 현재 상어의 이동 상태 저장
// pair <shark num, smell> [x][y]
pair<int, int> shark_board[21][21];

// up, down, left, right
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 현재 상어의 위치에 냄새를 뿌림
void add_smell() {
	for (int k = 1; k <= M; k++) {
		int x = sharks[k].x;
		int y = sharks[k].y;

		if (x == -1)
			continue;

		shark_board[x][y].first = k;
		shark_board[x][y].second = K;
	}
}

// 전체 보드에서 냄새를 1 감소시킴
void remove_smell() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (shark_board[i][j].second > 0)
				shark_board[i][j].second--;

			if (shark_board[i][j].second == 0)
				shark_board[i][j].first = 0;
		}
}

void move_shark() {

	// 상어들이 겹치는 경우 이를 제거해야 하므로, 상어의 이동을 각각 즉시 이동하는게 아닌
	// 큐에 저장한 후 한번에 처리함
	// shark num, nx, ny, nextD
	vector< tuple<int, int, int, int> > q;

	// 맨 뒷번호의 상어부터
	// 이렇게 구현하면, 번호가 앞선 상어가 뒤의 상어를 삭제하는걸 자연스럽게 구현 가능
	for (int k = M; k >= 1; k--) {
		int x = sharks[k].x;
		int y = sharks[k].y;

		// 현재 상어가 죽은 경우
		if (x == -1)
			continue;

		int prevD = sharks[k].prevDirection;

		bool cango = false;

		// 4방향으로 빈칸이 있는 경우 탐색
		for (int i = 0; i < 4; i++) {
			int nextD = sharks[k].direct[prevD][i];
			int nx = x + dx[nextD];
			int ny = y + dy[nextD];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;

			// 비어있어야 함
			if (shark_board[nx][ny].second != 0)
				continue;

			cango = true;
			q.push_back(make_tuple(k, nx, ny, nextD));
			break;
		}

		// 4방향으로 자신의 냄새 탐색
		if (cango == false) {
			for (int i = 0; i < 4; i++) {
				int nextD = sharks[k].direct[prevD][i];
				int nx = x + dx[nextD];
				int ny = y + dy[nextD];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;

				// 자신의 냄새여야 함
				if (shark_board[nx][ny].first != k)
					continue;

				q.push_back(make_tuple(k, nx, ny, nextD));
				break;
			}
		}
	}

	// 살아있는 상어들의 이동을 처리하고 겹치는 경우 삭제함
	for (int i = 0; i < q.size(); i++) {
		int num, nx, ny, nextD;
		tie(num, nx, ny, nextD) = q[i];


		// 다른 상어가 이미 존재하는 경우
		if (shark_board[nx][ny].first != 0 && 
			shark_board[nx][ny].first != num) {

			// 다른 상어 삭제
			int other = shark_board[nx][ny].first;
			sharks[other].x = -1;
			sharks[other].y = -1;
		}

		// 현재 상어를 다음 위치로 이동시킴
		shark_board[nx][ny].first = num;
		sharks[num].x = nx;
		sharks[num].y = ny;
		sharks[num].prevDirection = nextD;
	}
}

// 첫 번쨰 상어만 생존해 있는지 확인
bool check_first_shark_alive_only() {

	for (int i = 2; i <= M; i++)
		if (sharks[i].x != -1)
			return false;

	return sharks[1].x != -1;
}

void pprint() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << shark_board[i][j].first << " ";
		}cout << endl;
	}cout << endl << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << shark_board[i][j].second << " ";
		}cout << endl;
	}cout << endl << endl;
}

void solve() {

	for (int i = 0; i < 1000; i++) {
		// add smell
		add_smell();
		// pprint();
		
		// move shark
		move_shark();
		// pprint();

		// remove smell
		remove_smell();
		// pprint();

		if (check_first_shark_alive_only()){
			cout << i + 1 << endl;
			return;
		}
		
	}

	cout << -1 << endl;
}

int main() {
	cin >> N >> M >> K;

	sharks = vector<Shark>(401);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];

			if (board[i][j] != 0)
				sharks[board[i][j]] = Shark(i, j);

			shark_board[i][j] = { 0, 0 };
		}

	for (int i = 1; i <= M; i++) {
		int d; cin >> d;

		sharks[i].prevDirection = d-1;
	}

	for (int k = 1; k <= M; k++) {

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				int d;	cin >> d;

				sharks[k].direct[i][j] = d-1;
			}

	}


	solve();

	return 0;
}