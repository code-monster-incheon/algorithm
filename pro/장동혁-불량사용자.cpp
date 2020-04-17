#include <string>
#include <vector>
#include <iostream>
#include <set>
#define MAX 8

using namespace std;

bool visit[MAX + 1] = {false,};
set<string> s;

int getCnt(const vector<string>& user_id, const vector<string>& banned_id, int bIndex) {
    if(bIndex == banned_id.size()) {
        string str = "";
        for(int i = 0; i < MAX + 1; i++) {
            if(visit[i]) str += i;
        }
        if(s.insert(str).second) {
            return 1;
        }
        return 0;
    }
    
    int ret = 0;
    
    for(int i = 0; i < user_id.size(); i++) {
        if(visit[i] || user_id[i].size() != banned_id[bIndex].size()) continue;
        bool DiffFlag = false;
        for(int j = 0; j < banned_id[bIndex].size(); j++) {
            if(banned_id[bIndex][j] == '*') continue;
            if(banned_id[bIndex][j] != user_id[i][j]) {
                DiffFlag = true;
                break;
            }
        }
        if(!DiffFlag) {
            visit[i] = true;
            ret += getCnt(user_id, banned_id, bIndex + 1);
            visit[i] = false;
        }
        
    }
    return ret;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    answer = getCnt(user_id, banned_id, 0);
    
    return answer;
}
