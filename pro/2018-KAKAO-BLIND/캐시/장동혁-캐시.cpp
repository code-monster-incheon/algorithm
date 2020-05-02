// https://programmers.co.kr/learn/courses/30/lessons/17680
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    for(int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        bool flag = false;
        int index = -1;
        for(int i = 0; i < cache.size(); i++) {
            if(cache[i] == city) {
                flag = true;
                index = i;
                break;
            }   
        }
        if(cache.size() < cacheSize) {
            if(flag) {
                cache.push_back(city);
                cache.erase(cache.begin() + index);
                answer++;
            } else {
                cache.push_back(city);
                answer += 5;
            }
        } else {
            if(flag) {
                cache.push_back(city);
                cache.erase(cache.begin() + index);
                answer++;
            } else {
                cache.push_back(city);
                cache.erase(cache.begin());
                answer += 5;
            }
        }
        
    }
    
    
    return answer;
}



