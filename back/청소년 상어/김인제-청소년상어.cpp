/*
https://www.acmicpc.net/problem/19236

삼성 SW 역량테스트 기출, 전형적인 구현 문제
행렬의 상태를 탐색하기 위해 BFS 로 접근하였음
각각의 행렬 상태를 문제의 조건에 알맞게 변경하는 것이 중요
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
int ret = 0;

class State {
public:
	int num = 0;
	int direction = 0;

	State() {};
	State(int num, int direction) :num(num), direction(direction) {};
};

vector<vector<State>> arr;


int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void pprint(vector<vector<State>>& arr) {
	cout << "num" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j].num << " ";
		}cout << endl;
	}cout << endl << endl;

	cout << "d" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j].direction << " ";
		}cout << endl;
	}cout << endl << endl;
}

void goFish(vector<vector<State>>& arr) {
	for (int k = 1; k <= 16; k++) {
		int fishX = -1, fishY = -1;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (arr[i][j].num == k) 
					fishX = i, fishY = j;

		// fish not exist
		if (fishX == -1)
			continue;

		State fish = arr[fishX][fishY];
		int fishNum = fish.num;
		int fishDirection = fish.direction;

		for (int i = fishDirection; i < fishDirection + 8; i++) {
			int direction = i % 8;
			int nx = fishX + dx[direction];
			int ny = fishY + dy[direction];

			// out of range or shark (num == -1)
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || arr[nx][ny].num == -1)
				continue;

			// swap
			State temp(fishNum, direction);
			arr[fishX][fishY] = arr[nx][ny];
			arr[nx][ny] = temp;


			//pprint(arr);

			break;
		}
	}
}

vector< pair<vector<vector<State>>, int> > goShark(vector<vector<State>> arr, int curSharkEat) {
	int sharkX, sharkY;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (arr[i][j].num == -1)
				sharkX = i, sharkY = j;

	State shark = arr[sharkX][sharkY];
	int sharkNum = shark.num;
	int sharkDirection = shark.direction;

	vector< pair<vector<vector<State>>, int> > sharkMoved;

	for(int offset = 1; ; offset++){
		
		int nx = sharkX + dx[sharkDirection] * offset;
		int ny = sharkY + dy[sharkDirection] * offset;

		// out of range
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
			break;

		// empty (num == 0)
		if (arr[nx][ny].num == 0)
			continue;

		vector<vector<State>> temp = arr;

		// shark move
		int sharkEat = curSharkEat+temp[nx][ny].num;

		temp[nx][ny].num = -1;
		temp[sharkX][sharkY].num = 0;

		sharkMoved.push_back({ temp, sharkEat });
	}

	return sharkMoved;

}

void solve() {
	queue< pair< vector<vector<State>>, int> > q;
	int sharkEat = arr[0][0].num;
	arr[0][0].num = -1;

	q.push({ arr, sharkEat});

	while (q.empty() == false) {
		vector<vector<State>> curState = q.front().first;
		int curSharkEat = q.front().second;
		ret = max(ret, curSharkEat);

		q.pop();

	
		//pprint(curState);
		goFish(curState);
		//pprint(curState);
		vector< pair<vector<vector<State>>, int> > sharkMoved = goShark(curState, curSharkEat);

		for (auto& newState : sharkMoved) {
			//pprint(newState.first);
			q.push(newState);
		}
	}

	cout << ret << endl;
}

int main() {
	arr = vector<vector<State>>(4, vector<State>(4));

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			int num, direction;
			cin >> num >> direction;

			arr[i][j] = State(num, direction-1);
		}
	}



	solve();


	return 0;
}