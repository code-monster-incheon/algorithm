/*
https://www.acmicpc.net/problem/11066

동적계획법 문제이지만 점화식을 생각하는 과정이 매우 어려웠던 문제
인접한 파일만 합칠수 있다는 아이디어에서 중복되는 부분과 메모이제이션을 생각하는 과정이 어려웠음
코드 구현은 매우 쉬운 편이며 전형적인 메모이제이션으로 해결
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
int N;
int cache[501][501];
int cost[501];
int preSum[501];

int dp(int a, int b) {
	if (a == b)
		return cost[a];


	int& ret = cache[a][b];
	if (ret != -1)	return ret;

	ret = INF;

	int sum = preSum[b+1] - preSum[a];
	for (int i = a; i < b; i++) {
		ret = min(ret, dp(a, i) + dp(i + 1, b) + sum);
	}

	return ret;
}

void solve(int num) {
	int ret = INF;

	for (int i = 0; i < num - 1; i++) {
		ret = min(ret, dp(0, i) + dp(i + 1, num - 1));
	}

	cout << ret << endl;
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		memset(cache, -1, sizeof(cache));
		int num;	cin >> num;

		for (int j = 0; j < num; j++)
			cin >> cost[j];
		
	
		for (int j = 1; j <= num; j++)
			preSum[j] = preSum[j - 1] + cost[j-1];

		solve(num);
	}


	return 0;
}