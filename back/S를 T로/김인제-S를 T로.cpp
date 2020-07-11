/*
https://www.acmicpc.net/problem/3806

완전탐색과 DP 는 조합의 경우의 수가 너무 많으므로, 그리디로 해결
S = {0, 1, ?}, T = {0, 1} 이므로 S X T = { {0, 0}, {0, 1}, {1, 0}, {1, 1}, {?, 0}, {?, 1}}

이떄, S X T 의 모든 조합에 대해서 {0, 0}, {1, 1} 는 변경할 필요 없음
{1, 0} 은 문제의 규칙에서 바꾸는 방법이 {*, 1} 과 교환하는 방법 밖에 없음
이때 {*, 1} = {?, 1} or {0, 1} 이며 {?, 1} 는 바꾸는데 2회, {0, 1} 은 1회 소모 됨
따라서, 바꾸는 횟수가 더 적은 {0, 1} 을 {1, 0} 과 최대한 매칭시킨 후 남은 {1, 0} 과 {?, 1} 을 매칭

{1, 0} 의 개수 > {0, 1} 의 개수 + {?, 1} 의 개수 인 경우 아무리 잘 바꿔도 {1, 0} 이 남으므로 불가능
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



void solve() {


}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int ret = 0;
		int one2zero = 0;   // {1, 0}
		int zero2one = 0;   // {0, 1}
		int something2one = 0;  // {?, 1}
		int something2zero = 0; // {?, 0}

		string s, t;
		cin >> s;
		cin >> t;

		for (int j = 0; j < s.length(); j++) {
			if (s[j] != t[j]){
				if (s[j] == '1' && t[j] == '0')
					one2zero++;
				else if (s[j] == '0' && t[j] == '1')
					zero2one++;
				else if (s[j] == '?' && t[j] == '1')
					something2one++;
				else if (s[j] == '?' && t[j] == '0')
					something2zero++;
			}
		}

		if (one2zero > zero2one + something2one) {
			cout <<"Case "<<i+1<<": " << -1 << endl;
			continue;
		}

		int zero_one_swap = min(one2zero, zero2one);
		ret += zero_one_swap;
		one2zero -= zero_one_swap;
		zero2one -= zero_one_swap;

		if (one2zero > 0) {

			int something_one_swap = min(one2zero, something2one);
			ret += something_one_swap * 2;
			something2one -= something_one_swap;

			ret += something2one;
			ret += something2zero;
		}
		else {
			ret += something2one;
			ret += something2zero;
			ret += zero2one;
		}

		cout << "Case " << i + 1 << ": " << ret << endl;
	}



	solve();

	return 0;
}