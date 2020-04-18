#include<bits/stdc++.h>
using namespace std;

int b_size, ans;
bool visited[9];
vector<string> user, ban;
set<string> res;

bool check(string a, string b) {
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '*') continue;
		if (a[i] != b[i]) return false;
	}
	return true;
}

void dfs(int idx, string str) {
	if (idx == b_size) {
		if (str.size() == b_size) {
			sort(str.begin(), str.end());	// �ߺ� �����ϱ� ���� ����
			res.insert(str);
		}
		return;
	}

	for (int i = 0; i < user.size(); i++) {
		if (user[i].size() != ban[idx].size()) continue;
		if (check(user[i], ban[idx])) {	// ����ϴٰ� �Ǹ��
			if (visited[i]) continue;
			visited[i] = true;
			str.push_back(i +'0');
			dfs(idx + 1, str);
			str.pop_back();
			visited[i] = false;
		}	
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	user = user_id;
	ban = banned_id;
	b_size = banned_id.size();
	dfs(0, "");
	
	int result = res.size();
	return result;
}