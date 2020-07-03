/*
https://www.acmicpc.net/submit/1756/20694830

구간의 최소값을 활용하는 재미있는 문제
오븐의 형태를 잘 바꾸면 이분탐색으로 더 빠르게 해결 가능

이분탐색으로 해결하는 방법은 https://n-square.tistory.com/21 참조
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>
#pragma warning(disable:4996)
using namespace std;

const int INF = 987654321;
int Depth, Num;

vector<int> ovens;
vector<int> pizzas;

// 0 ~ idx 구간의 최소 값
int segMin[300001];
int back;

void solve() {
	
    // 구간의 최소값 계산
	segMin[0] = ovens[0];
	for (int i = 1; i < ovens.size(); i++) {
		if (segMin[i-1] > ovens[i]){
			segMin[i] = ovens[i];
		}
		else {
			segMin[i] = segMin[i - 1];
		}
	}

    // 피자가 들어갈 수 있는 오븐의 최 하단 위치
	int back = ovens.size() - 1;

	for (int i = 0; i < pizzas.size(); i++) {

		int pizza = pizzas[i];

        // [0, back] 구간에서 최 하단에 pizza 가 들어갈 수 있는 경우
        // back 을 하나 줄임
		if (segMin[back] >= pizza){
			back--;
		}
        // [0, back] 구간에서 pizza 가 구간 사이에 들어가야 하는 경우
		else {
            // [0, back] 구간의 최소값 보다 pizza 가 크면 현재 구간에 피자를 못넣음
			while (segMin[back] < pizza)
				back--; // back 감소

            // 현재 back 에 피자를 넣으므로, back을 1 더 감소
			back--;
		}

        // 더이상 못넣는 경우
		if (back < 0) {
			cout << 0 << endl;
			return;
		}
	}
    // back == 피자가 들어간 마지막 위치 - 1
	cout << back+2 << endl;

}

int main() {
	cin >> Depth >> Num;
	pizzas = vector<int>(Num);

	for (int i = 0; i < Depth; i++) {
		int oven; scanf("%d", &oven);
		ovens.push_back(oven);
		
	}


	for (int i = 0; i < Num; i++) {
		scanf("%d", &pizzas[i]);
		
	}


	solve();

	return 0;
}