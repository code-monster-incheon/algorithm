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
	vector<int> cash_recent(cacheSize);	// 캐시에 존재하는 것들이 얼마나 최근과 가까운지

	for (int i = 0; i < cities.size(); i++) {
		for (int j = 0; j < cities[i].length(); j++) {
			cities[i][j] = toupper(cities[i][j]);	// 대문자로 변환
		}

		recent = 0;
		flag = false;
		auto it = find(cash.begin(), cash.end(), cities[i]);

		if (it != cash.end()) {	// hit일때
			for (int j = 0; j < cash.size(); j++) {
				if (cash[j] == cities[i]) {
					cash_recent[j] = count++;		// 캐시에 존재하는 요소를 가장 최근으로 지정함
				}
			}
			answer++;
		}
		else {	// miss 일때
			for (int j = 0; j < cash.size(); j++) {
				if (cash[j] == "") {		// 비어있다면
					answer += 5;
					cash[j] = cities[i];
					cash_recent[j] = count++;
					flag = true;
					break;
				}
				else {		// 캐시에서 가장 오래된 요소 찾기
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