// https://programmers.co.kr/learn/courses/30/lessons/17677
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    map<string, int> m1;
    map<string, int> m2;
    map<string, int>::iterator iter1;
    map<string, int>::iterator iter2;
    
    for(int i = 0; i < str1.size() - 1; i++) {
        if(!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;
        string twoChar = "";
        twoChar += str1[i]; 
        twoChar += str1[i + 1];
        if(m1.find(twoChar) == m1.end()) {
            m1[twoChar] = 1;
        } else {
            m1[twoChar]++;
        }
    }
    
    
    for(int i = 0; i < str2.size() - 1; i++) {
        if(!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;
        string twoChar = "";
        twoChar += str2[i];
        twoChar += str2[i + 1];
        if(m2.find(twoChar) == m2.end()) {
            m2[twoChar] = 1;
        } else {
            m2[twoChar]++;
        }
    }
    
    
//     map<string, int>::iterator iter;
//     for(iter = m1.begin(); iter != m1.end(); iter++) {
//         cout << iter->first << ' ' << iter->second << '\n';
//     }
//     cout << "==========\n";
    
    
//     for(iter = m2.begin(); iter != m2.end(); iter++) {
//         cout << iter->first << ' ' << iter->second << '\n';
//     }
//     cout << "==========\n";
    
    
    // 병합 정렬 합칠 때는 아이디어, 시간 복잡도가 무려 O(1)이다.
    iter1 = m1.begin(), iter2 = m2.begin();
    int sum1 = 0;
    int sum2 = 0;
    while(iter1 != m1.end() && iter2 != m2.end()) {
        if(iter1->first > iter2->first) {
            //합집합으로 가버렷!
            sum2 += iter2->second;
            iter2++;
        } else if(iter1->first < iter2->first) {
            //합집합으로 가버렷!
            sum2 += iter1->second;
            iter1++;
        } else {
            //교집합
            sum1 += min(iter1->second, iter2->second);
            sum2 += max(iter1->second, iter2->second);
            iter1++;
            iter2++;
        }
    }
    
    while(iter1 != m1.end()) {
        //m1에 남은 값들이 m2의 마지막 값보다 더 크다.
        sum2 += iter1->second;
        iter1++;
    }
    
    while(iter2 != m2.end()) {
        sum2 += iter2->second;
        iter2++;
    }
    
    if(sum1 == 0 && sum2 == 0) answer = 65536;
    else {
        answer = ((double)sum1 / (double)sum2) * 65536;
    }
    
    
    return answer;
}