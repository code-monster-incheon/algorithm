
/*
https://programmers.co.kr/learn/courses/30/lessons/42895

동적계획법의 전형적인 문제

현재 선택할수 있는 선택지는
- N 을 한자리 늘리거나
- N 을 이전의 식에다가 사칙연산하거나
+ (N / N) == + 1
- (N / N) == - 1

*/

#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

int cache[10][300000];
int N, number;
const int INF = 987654321;

int dp(int count, int sum, string calc){
    if (count > 8)
        return INF;
    
    if (sum > N*number || sum < 0)
        return INF;
    
    if (sum == number)
        return count;
    
    
    int &ret = cache[count][sum];
    
    if (ret != -1)
        return ret;
    
    ret = INF;
    

    
    for(int n = N, i = 1; n <= N * number; n = n*10 + N, i++){
        ret = min(ret, dp(count + i, sum + n, calc + " +N "));
        ret = min(ret, dp(count + i, sum * n, calc + " *N "));
        ret = min(ret, dp(count + i, int(sum / n), calc + " /N "));
        ret = min(ret, dp(count + i, sum - n, calc + " -N "));
    }
    
    ret = min(ret, dp(count + 2, sum + 1, calc + " +(N / N) "));
    ret = min(ret, dp(count + 2, sum - 1, calc + " -(N / N) "));
      
    return ret;
}

int solution(int N, int number) {
    int answer = 0;
    ::N = N;
    ::number = number;
    
    memset(cache, -1, sizeof(cache));
    answer = dp(0, 0, "");
    return answer == INF ? -1 : answer;
}