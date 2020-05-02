#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define BUSSTART 540

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> time(timetable.size());
    for(int i = 0; i < timetable.size(); i++) {
        string str = timetable[i];
        time[i] = stoi(str.substr(0,2)) * 60 + stoi(str.substr(3,2));
    }
    
    sort(time.begin(), time.end());
    
    int tIdx = 0;
    int ansTime = 0;
    int pNum = timetable.size(); // 승객 수
    bool lastBus = false;
    
    for(int bus = 0; bus < n; bus++) {
        int arvTime = BUSSTART +  bus * t;
        int busMax = m;
        while(true) {
            if(arvTime >= time[tIdx]) {
                if(bus == n - 1 && busMax == 1) {
                    ansTime = time[tIdx] - 1;
                    lastBus = true;
                    break;
                }
                
                tIdx++;
                busMax--;
            }
            else {
                break;
            }
            
            if(busMax == 0) break;
            
            if(tIdx == pNum) break;
        }
        
        if(lastBus) break;
        
        
        
    }
    
    if(!lastBus) {
        ansTime = BUSSTART + (n - 1) * t;
    }

    int hour = ansTime / 60;
    int minute = ansTime % 60;
    
    if(!(hour / 10)) {
        answer += '0';  
    }
     answer += to_string(hour) + ':';
    if(!(minute / 10)) {
        answer += '0';
    }
    answer += to_string(minute);
    return answer;
}