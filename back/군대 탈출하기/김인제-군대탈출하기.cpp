#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int board[101][101];
int dist[101][101][2];
int row, col;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

enum DIRECT {
	UP, DOWN, LEFT, RIGHT
};

const int MAX = 2000000000;

void minPath() {
	// maxValue, x, y, canJump
	queue<tuple<int, int, int, int> > pq;
	pq.push(make_tuple(-board[0][0], 1, 0, 0));
	dist[0][0][0] = dist[0][0][1] = board[0][0];

	while (pq.empty() == false) {

		int maxVal, x, y, canJump;
		tie(maxVal, canJump, x, y) = pq.front();
		maxVal = -maxVal;
		pq.pop();


		// go 1 step
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= row || ny >= col)
				continue;

			int nextDist = dist[nx][ny][canJump];
			int curDist = max(maxVal, board[nx][ny]);

			if ( curDist < nextDist) {
				dist[nx][ny][canJump] = curDist;
				pq.push(make_tuple(-curDist, canJump, nx, ny));
			}
		}

		// go 2 step by JUMP!
		if (canJump) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i] * 2;
				int ny = y + dy[i] * 2;

				if (nx < 0 || ny < 0 || nx >= row || ny >= col)
					continue;

				int nextDist = dist[nx][ny][0];
				int curDist = max(maxVal, board[nx][ny]);

				if (curDist < nextDist) {
					dist[nx][ny][0] = curDist;
					pq.push(make_tuple(-curDist, 0, nx, ny));
				}
			}
		}
	}

	cout << min(dist[row - 1][col - 1][0], dist[row - 1][col - 1][1]) << endl;
	return;
}

int main()
{
	cin >> row >> col;

	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int cur;	cin >> cur;
			board[i][j] = cur;
			dist[i][j][0] = dist[i][j][1] = MAX;
		}
	}

	minPath();


	return 0;
}