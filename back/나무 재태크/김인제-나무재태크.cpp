/*
https://www.acmicpc.net/problem/16235

삼성 SW 역량 테스트 기출, 구현 위주의 문제
한 칸에 나무가 여러개 존재할 수 있으므로, 이에 유의하여 적절한 자료구조를 선택해야 함
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int INF = 987654321;
int N, M, K;
vector<int> trees[11][11];
int dead[11][11];
int soil[11][11];

int add[11][11];

int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, -1, 0, 1, -1 };

int treeAlive = 0;

void solve() {
	// spring
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (trees[i][j].size() == 0)
				continue;

			sort(trees[i][j].begin(), trees[i][j].end());

			for (int k = 0; k < trees[i][j].size(); k++) {
				int& tree = trees[i][j][k];

				// grow
				if (tree <= soil[i][j]) {
					soil[i][j] -= tree;	
					tree++;
				}
				
				// dead
				else {
					// 나무가 죽는 경우, 나이의 절반을 soil 에 더해줌
					for (int t = k; t < trees[i][j].size(); t++)
						dead[i][j] += (int(trees[i][j][t] / 2));

					// 죽는 나무들은 삭제 해 줌
                    // vector.erase() 로 죽는 나무를 한번에 삭제 해 줌
					treeAlive -= (trees[i][j].size() - k);
					trees[i][j].erase(trees[i][j].begin() + k, trees[i][j].end());
						
					break;
				}
			}
		}
	}

	// summer
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			soil[i][j] += dead[i][j];
			dead[i][j] = 0;
		}
	}

	// fall
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			
			for (auto& tree : trees[i][j]) {
				// 나무의 나이가 5 이상의 5의 배수인 경우 에만
				if (tree % 5 != 0)
					continue;

				// 8 - directions
				for (int k = 0; k < 8; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					// out of range
                    // 범위 유의!! 문제의 좌표축에서 (1, 1) 이 좌측 상단 좌표임
					if (nx < 1 || ny < 1 || nx > N || ny > N)
						continue;
					
					treeAlive++;
					trees[nx][ny].push_back(1);
				}
			}

		}
	}

	// winter
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			soil[i][j] += add[i][j];	
}

int main() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> add[i][j];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			soil[i][j] = 5;

	for (int i = 0; i < M; i++) {
		int x, y, age;	cin >> x >> y >> age;

		trees[x][y].push_back(age);
	}


	treeAlive = M;

	for (int a = 0; a < K; a++) {
		solve();

		if (treeAlive == 0)
			break;
	}


	cout << treeAlive << endl;

	return 0;
}