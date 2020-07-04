/*
https://www.acmicpc.net/problem/18808

행렬 회전을 연습하기 좋은 문제
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

int board[41][41];

int row, col, num;


// 행렬 회전 함수
vector< vector<vector<int>> > getRotates(vector<vector<int>> cur) {
	vector< vector<vector<int>> > rotates;
	rotates.push_back(cur);

	for (int k = 0; k < 3; k++) {
		int r = rotates.back()[0].size();
		int c = rotates.back().size();

		vector<vector<int>> rotate = vector<vector<int>>(r, vector<int>(c));

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				rotate[i][j] = rotates.back()[c-j-1][i];

		rotates.push_back(rotate);

		//cout << endl;
		//for (int i = 0; i < r; i++) {
		//	for (int j = 0; j < c; j++) {
		//		cout << rotate[i][j] << " ";
		//	}cout << endl;
		//}cout << endl << endl;
	}
	return rotates;
}

void solve() {
	
}

bool canSet(int x, int y, vector<vector<int>> rotate) {
	int r = rotate.size();
	int c = rotate[0].size();

	if (r + x > row || c + y > col)
		return false;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (board[i+x][j+y] == 1 && rotate[i][j] == 1)
				return false;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (rotate[i][j] == 1)
				board[i + x][j + y] = 1;

	return true;
}

void pprint() {
	cout << endl;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			cout << board[i][j] << " ";
		}cout << endl;
	}cout << endl << endl;
}

void set(vector< vector<vector<int>> > rotates) {

	for (auto& rotate : rotates)
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			
				if (canSet(i, j, rotate)) {
					//pprint();
					return;
				}
			
}

int main() {
	cin >> row >> col >> ::num;

	for (int k = 0; k < num; k++) {
		int r, c;	cin >> r >> c;
		vector<vector<int>> arr = vector<vector<int>>(r, vector<int>(c) );

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> arr[i][j];

		vector< vector<vector<int>> > rotates = getRotates(arr);

		set(rotates);
				
	}

	int ret = 0;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (board[i][j] == 1)
				ret++;

	cout << ret << endl;

	//solve();


	return 0;
}