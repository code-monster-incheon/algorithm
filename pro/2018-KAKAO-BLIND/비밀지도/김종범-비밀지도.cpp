// https://programmers.co.kr/learn/courses/30/lessons/17681

#include<bits/stdc++.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> ans;

	for (int i = 0; i < n; i++) {
		int temp = arr1[i] | arr2[i];
		string res = "";

		for (int j = 0; j < n; j++) {
			if (temp % 2 == 0) res += '0';
			else res += '1';
			temp /= 2;
		}
		reverse(res.begin(), res.end());

		string store = "";
		for (int i = 0; i < res.length(); i++) {
			if (res[i] == '1') store += '#';
			else store += ' ';
		}
		ans.push_back(store);
	}

	return ans;
}

