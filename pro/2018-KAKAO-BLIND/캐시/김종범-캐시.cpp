// https://programmers.co.kr/learn/courses/30/lessons/17680

#include<bits/stdc++.h>
using namespace std;

const int MAX = 0;

int solution(int cacheSize, vector<string> cities) {
	if (cacheSize == 0) return cities.size() * 5;

	int answer = 0;
	int recent = 0;
	int count = 0;
	bool flag = false;
	vector<string> cash(cacheSize);
	vector<int> cash_recent(cacheSize);	// ĳ�ÿ� �����ϴ� �͵��� �󸶳� �ֱٰ� �������

	for (int i = 0; i < cities.size(); i++) {
		for (int j = 0; j < cities[i].length(); j++) {
			cities[i][j] = toupper(cities[i][j]);	// �빮�ڷ� ��ȯ
		}

		recent = 0;
		flag = false;
		auto it = find(cash.begin(), cash.end(), cities[i]);

		if (it != cash.end()) {	// hit�϶�
			for (int j = 0; j < cash.size(); j++) {
				if (cash[j] == cities[i]) {
					cash_recent[j] = count++;		// ĳ�ÿ� �����ϴ� ��Ҹ� ���� �ֱ����� ������
				}
			}
			answer++;
		}
		else {	// miss �϶�
			for (int j = 0; j < cash.size(); j++) {
				if (cash[j] == "") {		// ����ִٸ�
					answer += 5;
					cash[j] = cities[i];
					cash_recent[j] = count++;
					flag = true;
					break;
				}
				else {		// ĳ�ÿ��� ���� ������ ��� ã��
					if (cash_recent[recent] >= cash_recent[j]) {
						recent = j;
					}
				}
			}
			if (flag == false) {
				cash[recent] = cities[i];
				cash_recent[recent] = count++;
				answer += 5;
			}
		}
	}
	return answer;
}