/*
https://www.acmicpc.net/problem/17825

상당히 난이도 있는 구현 문제
윷놀이 판에 같은 숫자들이 여러개 존재하므로 이를 다르게 처리해 주는 것이 아이디어
문제를 잘 읽자!
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

int dice[10];
int ret = 0;

class Chess {
public:
	int idx = 0;
	int order_group = 0;

	Chess() {};
	Chess(int idx, int order) :idx(idx), order_group(order) {};
};

vector< vector<int> > order = {
	{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},

	// 1번째 코스와 같은 숫자들은 10 을 곱해서 다른 숫자로 표현 함
	{10, 13, 16, 19, 25, 30 * 10, 35, 40},
	{20, 22 * 10, 24 * 10, 25, 30 * 10, 35, 40},
	{30, 28 * 10, 27, 26 * 10, 25, 30 * 10, 35, 40}
};

// 주사위 숫자 만큼 이동한 다음 칸 반환
Chess getNext(int idx, int order_group, int offset) {
	if (order_group == 0) {

		if (order[0][idx] == 10)
			return getNext(0, 1, offset);
		else if (order[0][idx] == 20)
			return getNext(0, 2, offset);
		else if (order[0][idx] == 30)
			return getNext(0, 3, offset);

		else {
			if (idx + offset >= order[order_group].size())
				return Chess(-1, -1);
			else
				return Chess(idx + offset, order_group);
		}
	}
	else {
		if (idx + offset >= order[order_group].size())
			return Chess(-1, -1);
		else
			return Chess(idx + offset, order_group);
	}

}

// 현재 윷놀이 판의 상태
map <vector<int>, bool> visited;

void solve() {

	// 윷놀이 판 처음 상태
	vector <Chess> state;

	for (int i = 0; i < 4; i++)
		state.push_back(Chess(0, 0));

	queue< pair< vector<Chess>, int> > q;
	q.push({ state, 0 });

	int step = 0;

	while (q.empty() == false) {
		int size = q.size();

		for (int k = 0; k < size; k++) {
			vector<Chess> cur = q.front().first;
			int cost = q.front().second;
			q.pop();

			// get MAX value
			if (step == 10)
				ret = max(ret, cost);

			// BFS 상 에서 이미 방문한 상태는 방문 안함
			// cache 는 4개 말의 위치와 현재까지의 점수의 합 으로 구성됨
			vector<int> cache;
			for (int i = 0; i < 4; i++) {
				int curChessIdx = cur[i].idx;
				int curChessOrder = cur[i].order_group;

				if (curChessIdx == -1)
					cache.push_back(-1);
				else
					cache.push_back(order[cur[i].order_group][cur[i].idx]);
			}
			sort(cache.begin(), cache.end());
			cache.push_back(cost);
			
			if (visited[cache])
				continue;
			visited[cache] = true;


			// 4개의 말에 대해서 이동
			for (int i = 0; i < 4; i++) {
				int curChessIdx = cur[i].idx;
				int curChessOrder = cur[i].order_group;
				
				// already out of board
				if (curChessIdx == -1)
					continue;

				// 주사위 숫자만큼 현재 말을 이동한 좌표
				Chess nextChess = getNext(curChessIdx, curChessOrder, dice[step]);

				// out of board
				if (nextChess.idx == -1) {
					vector<Chess> next = cur;
					next[i] = nextChess;
					q.push({ next, cost });

					continue;
				}

				bool canGo = true;

				// 다른 말이 이미 존재하는 칸 으로 이동 불가능
				for (int j = 0; j < 4; j++) {
					if (i == j)	continue;

					int otherChessIdx = cur[j].idx;
					int otherChessOrder = cur[j].order_group;

					if (otherChessIdx == -1)
						continue;

					// here: 현재 말이 이동한 칸, there: 다른 말의 칸
					int here = order[nextChess.order_group][nextChess.idx];
					int there = order[otherChessOrder][otherChessIdx];

					// 현재말을 이동한 칸 이 다른 말의 위치와 동일할 때 이동 불가
					if (here == there)
						canGo = false;
				}

				// 말 이동 가능
				if (canGo) {
					vector<Chess> next = cur;
					next[i] = nextChess;
					int nextcost;

					// 앞서 다른 칸 이지만 같은 숫자인 칸 들에 대해서 한쪽 칸 들에 10을 곱해주었으므로, 10을 나눠서 더해줌
					if (order[nextChess.order_group][nextChess.idx] > 100)
						nextcost = cost + order[nextChess.order_group][nextChess.idx] / 10;
					else
						nextcost = cost + order[nextChess.order_group][nextChess.idx];

					
					q.push({ next, nextcost });
				}
			}

		}

		step++;
	}

	cout << ret << endl;
}

int main() {

	for (int i = 0; i < 10; i++)
		cin >> dice[i];

	solve();


	return 0;
}