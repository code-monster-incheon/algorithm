// https://programmers.co.kr/learn/courses/30/lessons/17677

#include<bits/stdc++.h>
using namespace std;

int solution(string str1, string str2) {
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	map<string, int> m;
	int cnt = 0, total = 0;

	for (int i = 0; i < str1.length() - 1; i++) {
		if (!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;

		string str = "";
		str += str1[i];
		str += str1[i + 1];
		total++;
		m[str]++;
	}

	for (int i = 0; i < str2.length() - 1; i++) {
		if (!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;

		string str = "";
		str += str2[i];
		str += str2[i + 1];

		if (m.count(str)) {
			if (m[str] > 0) {
				m[str]--;
				cnt++;
			}
			else total++;
		}
		else total++;
	}
	
	//cout << cnt << ' ' <<  total << '\n';
	if (total == 0) return 65536;
	else {
		double res = double(cnt) / double(total) * 65536;
		int ans = res;
		cout << ans << '\n';
		return ans;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution("aa1+aa2", "AAAA12");
	return 0;
}