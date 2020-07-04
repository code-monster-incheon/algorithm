/*
https://programmers.co.kr/learn/courses/30/lessons/42899

전형적인 DP 문제
현재의 상태는 몇번째 구간인지 와 현재까지 소요된 시간 으로 표현할 수 있다

같은 도시에 도착했을 때, 소요 시간이 같다면 동일한 상태 이며 소요시간이 다르다면 이에따라
모금액의 총 합 또한 달라지므로 소요 시간에 따라서 상태를 구분해준다
*/
#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <limits.h>
using namespace std;

vector<vector<int>> travels;
int K;
int num;
const int INF = INT_MAX-1;

// cache[idx][time]
int cache[111][100001];

int dp(int idx, int time){
    if (time > K)
        return -INF;
    
    if (idx == ::num)
        return 0;
    
    int& ret = cache[idx][time];
    
    if(ret != -1)
        return ret;
    
    int walkTIme = travels[idx][0];
    int walkCost = travels[idx][1];
    int bikeTime = travels[idx][2];
    int bikeCost = travels[idx][3];
    
    ret = 0;
    ret = max(ret, walkCost+dp(idx+1, time+walkTIme));
    ret = max(ret, bikeCost+dp(idx+1, time+bikeTime));
    
    return ret;
    
}

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    ::travels = travel;
    ::K = K;
    ::num = travel.size();
    
    int sum = 0;
    for(auto& t : travel){
        sum += min(t[0], t[2]);
    }
    if (sum > K)
        return 0;
    
    memset(cache, -1, sizeof(cache));
    answer = dp(0, 0);
    
    
    
    return answer;
}