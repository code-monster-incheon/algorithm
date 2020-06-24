// https://www.acmicpc.net/problem/2037

#include<bits/stdc++.h>
using namespace std;

const int MAX = 0;
int p, w, ans;
string Input;
map<char, pair<int, int>> m;

void solve() {
	m['A'] = { 2,1 };
	m['B'] = { 2,2 };
	m['C'] = { 2,3 };
	m['D'] = { 3,1 };
	m['E'] = { 3,2 };
	m['F'] = { 3,3 };
	m['G'] = { 4,1 };
	m['H'] = { 4,2 };
	m['I'] = { 4,3 };
	m['J'] = { 5,1 };
	m['K'] = { 5,2 };
	m['L'] = { 5,3 };
	m['M'] = { 6,1 };
	m['N'] = { 6,2 };
	m['O'] = { 6,3 };
	m['P'] = { 7,1 };
	m['Q'] = { 7,2 };
	m['R'] = { 7,3 };
	m['S'] = { 7,4 };
	m['T'] = { 8,1 };
	m['U'] = { 8,2 };
	m['V'] = { 8,3 };
	m['W'] = { 9,1 };
	m['X'] = { 9,2 };
	m['Y'] = { 9,3 };
	m['Z'] = { 9,4 };

	ans += m[Input[0]].second * p;
	for (int i = 1; i < Input.length(); i++) {
		if (Input[i] == ' ') ans += p;
		else if (m[Input[i - 1]].first == m[Input[i]].first) {
			ans += w;
			ans += m[Input[i]].second * p;
		}
		else {
			ans += m[Input[i]].second * p;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> p >> w;
	cin.ignore();
	getline(cin, Input);
	solve();
	return 0;
}