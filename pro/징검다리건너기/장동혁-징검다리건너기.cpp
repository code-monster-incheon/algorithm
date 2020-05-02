// https://programmers.co.kr/learn/courses/30/lessons/64062
#include <string>
#include <vector>
#include <map>
#define INF 987654321

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    // 디딤돌의 밟을 수 있는 횟수로 값을 정렬하고 싶으므로 key를 밟을 수 있는 횟수로, index값으로 key를 찾아야 할 경우가 있으므로 value로 index를 넣어준다.
    // (밟을 수 있는 횟수, index)
    multimap<int, int> m;
    multimap<int, int>::iterator iter;
    
    
    // k간격만큼 stones[i]를 포함시켜 k길이의 간격들을 만들어둔다.
    // value값으로 자동 정렬될 때, value가 같은 값을 가질 수 있다.
    // 이 경우 index가 작은 값을 먼저 탐색하기 위해서 index에 음수를 취해준다.
    for(int i = 0; i < k; i++) {
        m.insert({stones[i], -i});
    }
    
    // 맨처음 시작에서도 min값이 나올 수 있다.
    int min = INF;
    iter = m.end();
    int max = (*--iter).first;    
    if(min > max) min = max;
    
    // k간견을 갖는 multimap에 원소 하나를 추가하고, 가장 마지막 원소 하나를 빼준다.
    // multimap 안에서 가장 최대값이 min보다 작으면 min을 그 최대값으로 덮어써준다.
    for(int i = k; i < stones.size(); i++) {
        iter = m.find(stones[i - k]);
        m.erase(iter);
        m.insert({stones[i], -i});
        
        iter = m.end();
        int max = (*--iter).first;
       
        if(min > max) min = max;
    }
    
    answer = min;
    
    
    return answer;
}