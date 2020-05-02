/* 
https://www.acmicpc.net/problem/2194

유닛의 전체 좌표를 이동시키는 것 이 아닌 맨 왼쪽의 위 기준점 을 통해 4방향으로 움직 일 때 각 이동방향 마다
막힌 칸이 있는지 검사 후 유닛을 BFS 로 이동시킴
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

class Point {
public:
	int x;
	int y;
	int dist;

	Point(int x, int y, int dist = 0)
		:x(x), y(y), dist(dist) {}
	
	Point() :dist(0) {}
};

int map[501][501];
bool visited[501][501];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

enum DIRECTION {
	UP, DOWN, LEFT, RIGHT
};

Point start, finish;
int h, w, k;
int N, M;

void solution() {
	queue<Point> q;
	q.push(start);
	visited[start.x][start.y] = true;

	while (q.empty() == false) {
		Point cur = q.front();
		q.pop();

		if (cur.x == finish.x && cur.y == finish.y) {
			cout << cur.dist << endl;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx < 0 || ny < 0 || nx + h - 1 >= N || ny + w - 1 >= M || visited[nx][ny])
				continue;

			bool flag = true;

			if (i == UP) {
				for (int j = 0; j < w; j++)
					if (map[nx][cur.y + j] == 1) {
						flag = false;
						break;
					}
			}
			else if (i == DOWN) {
				for (int j = 0; j < w; j++)
					if (map[nx + h - 1][cur.y + j] == 1) {
						flag = false;
						break;
					}
			}
			else if (i == LEFT) {
				for (int j = 0; j < h; j++)
					if (map[cur.x + j][ny] == 1) {
						flag = false;
						break;
					}
			}
			else if (i == RIGHT) {
				for (int j = 0; j < h; j++)
					if (map[cur.x + j][ny + w - 1] == 1) {
						flag = false;
						break;
					}
			}

			if (flag) {
				q.push(Point(nx, ny, cur.dist + 1));
				visited[nx][ny] = true;
			}
		}
	}

	cout << -1 << endl;
	return;
}

int main()
{
	cin >> N >> M >> h >> w >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1;
	}

	int startX, startY, endX, endY;
	cin >> startX >> startY >> endX >> endY;
	start = Point(startX - 1, startY - 1);
	start.dist = 0;
	finish = Point(endX - 1, endY - 1);

	solution();

	return 0;
}