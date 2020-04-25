/*
* https://programmers.co.kr/learn/courses/30/lessons/17680
* LRU 캐쉬 구현 문제
* map + minHeap으로 구현하였음 O(NlogN)
* 더 빠른 시간복잡도를 원한다면 map + Double Linked List 로 구현, O(N)
*/
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    priority_queue< pair<int, string>, vector<pair<int, string>> > pq;
    map< string, int > m;
    
    int curCacheSize = 0;
    
    if (cacheSize == 0)
        return cities.size() * 5;
    
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        cities[i] = city;
        
        
        m.insert({city, 0});
    }
    

    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        
        
        
        auto iter = m.find(city);
        int& prior = iter->second;
        
        if (curCacheSize < cacheSize) {
            if (prior > 0)  {
                prior = i + 1;
                pq.push({-prior, city});
                answer += 1;
            }
            else {
                prior = i + 1;
                pq.push({-prior, city});
                curCacheSize++;
                answer += 5;
            }
            cout << pq.top().first << " " << pq.top().second << endl;
        }
        else {
            if (prior > 0)  {
                prior = i + 1;
                pq.push({-prior, city});
                answer += 1;
            }
            else {
                while(!pq.empty()) {
                    string _city = pq.top().second;
                    int _prior = -pq.top().first;
                    pq.pop();
                    
                    auto _iter = m.find(_city);
                    int& origin_prior = _iter->second;
                    
                    
                    
                    if (_prior == origin_prior) {
                        origin_prior = 0;
                        
                        prior = i + 1;
                        pq.push({-prior, city});
                        answer += 5;
                        
                        break;
                    }
                    
                }
            }
        }
    }
    
    
    return answer;
}