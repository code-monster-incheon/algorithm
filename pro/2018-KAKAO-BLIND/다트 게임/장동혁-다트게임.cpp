// https://programmers.co.kr/learn/courses/30/lessons/17682
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> ret;
    
    for(int i = 0; i < dartResult.size(); i++) {
        // 문자일 때만 점수 매긴다.
        if(isalpha(dartResult[i])) {
            int num;
            if(i != 1 && dartResult[i - 2] == '1') { // 10일 때
                string str = "" + dartResult[i - 2] + dartResult[i - 1];
                num = 10;
            } else { // 0 ~ 9 일 때
                num = dartResult[i - 1] - '0';
            }
            
            // 점수를 문자에 따라서 제곱승 해줌
            switch(dartResult[i]) {
                case 'S':
                    break;
                case 'D':
                    num = num * num;
                    break;
                case 'T':
                    num = num * num * num;
                    break;
            }
            
            // '*'랑 '#' 처리
            if(i != dartResult.size() - 1) {
                if(dartResult[i + 1] == '*') {
                    if(!ret.empty()) {
                        ret[ret.size() - 1] = 2 * ret[ret.size() - 1];
                    }
                    ret.push_back(2 * num);
                } else if(dartResult[i + 1] == '#') {
                    ret.push_back(-1 * num);
                } else {
                    ret.push_back(num);
                }
            } else {
                ret.push_back(num);
            }
            
        }
    }
    
    for(const auto& el : ret) {
        answer += el;
    }
    
    
    
    return answer;
}