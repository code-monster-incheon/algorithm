// https://programmers.co.kr/learn/courses/30/lessons/17684

#include<bits/stdc++.h>
using namespace std;

vector<int> solution(string msg) {
	vector<int> ans;

	map<string, int> m;
	int cnt = 1;
	for (char i = 'A'; i <= 'Z'; i++) {
		string str = "";
		str += i;
		m[str] = cnt++;
	}

	bool flag = true;
	int idx = 27;
	int num;
	for (int i = 0; i < msg.length(); i++, flag = true) {
		string str = "";
		while (flag) {
			str += msg[i];
			if (m.count(str) != 0) {
				num = m[str];
				i++;					// ÀÎµ¦½º Á¶Á¤ÀÌ ÇÙ½É¿äÀÎ
			}
			else {
				flag = false;
				ans.push_back(num);
				m[str] = idx++;
				i--;
			}
		}
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	solution("KAKAO");
	return 0;
}