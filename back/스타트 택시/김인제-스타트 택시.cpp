/*
https://www.acmicpc.net/problem/19238

BFS 기반 간단한 구현 문제
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

int N, M, fuel;
int board[20][20];

int taxix, taxiy;
// dist, startx, starty, endx, endy
vector<tuple< int, int, int, int>> customers;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int startx, int starty, int endx, int endy) {
	queue<pair<int, int>> q;
	q.push({ startx, starty });

	bool visited[20][20];
	memset(visited, false, sizeof(visited));
	visited[startx][starty] = true;

	int step = 0;
	while (q.empty() == false) {
		int size = q.size();

		for (int k = 0; k < size; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			// 목적지 도착
			if (x == endx && y == endy)
				return step;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				// out of range || visited || can't go to wall
				if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] || board[nx][ny] == 1)
					continue;

				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}

		step++;
	}

	// 목적지 도달 불가능
	return -1;
}

void solve() {
	vector<bool> visited(401, false);

	for (int k = 0; k < M; k++) {

		int min_dist = INF;
		int min_idx = -1;

		for (int i = 0; i < customers.size(); i++) {
			int startx, starty, endx, endy;
			tie(startx, starty, endx, endy) = customers[i];

			int dist = bfs(taxix, taxiy, startx, starty);

			if (dist == -1) {
				std::cout << -1 << endl;
				return;
			}

			if (min_dist > dist && !visited[i]) {
				min_dist = dist;
				min_idx = i;
			}
		}

		visited[min_idx] = true;



		int startx, starty, endx, endy;
		tie(startx, starty, endx, endy) = customers[min_idx];

		int dist2Customer = bfs(taxix, taxiy, startx, starty);
		int dist2Destination = bfs(startx, starty, endx, endy);

		// can't go to destination
		if (dist2Customer == -1 || dist2Destination == -1) {
			cout << -1 << endl;
			return;
		}

		int fuel2Customer = fuel - dist2Customer;
		int fuel2Destination = fuel2Customer - dist2Destination;

		// 연료가 바닥남
		if (fuel2Customer < 0 || fuel2Destination < 0) {
			cout << -1 << endl;
			return;
		}

		fuel = fuel - dist2Customer + dist2Destination;
		taxix = endx;
		taxiy = endy;
		
	}

	cout << fuel << endl;
}

int main() {
	cin >> N >> M >> fuel;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	cin >> taxix >> taxiy;
	taxix--, taxiy--;

	for (int i = 0; i < M; i++) {
		int startx, starty, endx, endy;
		cin >> startx >> starty >> endx >> endy;

		customers.push_back({ startx-1, starty-1, endx-1, endy-1 });
	}

	sort(customers.begin(), customers.end());

	solve();


	return 0;
}