//https://programmers.co.kr/learn/courses/30/lessons/62049

#include <string>
#include <vector>

using namespace std;


vector<int> solution(int n) {
    vector<int> answer;
    vector<int> temp;
    // 최초에 한번 접었을 때
    temp.push_back(0);
    answer = temp;
    
    for(int i = 2; i <= n; i++) {
        int len = temp.size();
        // 가운데 찍기
        temp.push_back(0);
        //오른쪽 모양 왼쪽 보면서 반대로 찍기
        for(int i = len - 1; i >= 0; i--) {
            if(temp[i] == 1) {
                temp.push_back(0);    
            } else {
                temp.push_back(1);
            }
        }
        answer = temp;
    }
    
    return answer;
}