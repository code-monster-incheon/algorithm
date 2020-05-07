// https://programmers.co.kr/learn/courses/30/lessons/17682

#include<bits/stdc++.h>
using namespace std;

int solution(string str) {
	int res[4] = { 0,0,0,0 };
	int idx = 1, num = 0;

	int i = 0;
	while (i < str.size()) {
		if (str[i] >= '0' && str[i] <= '9') {
			num = str[i] - '0';
			if (str[i + 1] >= '0' && str[i + 1] <= '9') {		// 2��Ÿ ���ڰ� ������ 10�ΰ���
				num = 10;
				i += 2;
				continue;
			}
			i++;
			continue;
		}
		else if (isalpha(str[i])) {
			if (str[i] == 'S') {
				res[idx] = pow(num, 1);
			}
			else if (str[i] == 'D') {
				res[idx] = pow(num, 2);
			}
			else {
				res[idx] = pow(num, 3);
			}

			if (i < str.size() - 1) {		// ���� ������ �ɼ��� ������
				if (str[i + 1] == '*') {
					res[idx - 1] *= 2;
					res[idx] *= 2;
					i += 2;
					idx++;
					num = 0;
					continue;
				}
				else if(str[i+1] == '#'){
					res[idx] *= (-1);
					i += 2;
					idx++;
					num = 0;
					continue;
				}
			}
			idx++;
			i++;
			num = 0;
			continue;
		}
	}

	int ans = 0;
	for (int i = 1; i <= 3; i++) {
		//cout << res[i] << ' ';
		ans += res[i];
	}
	//cout << '\n' << ans << '\n';
	return ans;
}

int main() {

	return 0;
}