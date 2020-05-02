// https://programmers.co.kr/learn/courses/30/lessons/17687
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string toChar(int n) {
    if(n <= 9) return to_string(n);
    switch(n) {
        case 10:
            return "A";
            break;
        case 11:
            return "B";
            break;
        case 12:
            return "C";
            break;
        case 13:
            return "D";
            break;
        case 14:
            return "E";
            break;
        case 15:
            return "F";
            break;
    }
    return "";
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int maxLen = t * m;
    
    string str = "";
    
    int cnt = 0;
    while(true) {
        string temp = "";
        int num = cnt++;
        while(true) {
            temp += toChar(num % n);
            num /= n;
            if(num == 0) break;
        }
        reverse(temp.begin(), temp.end());
        str += temp;
        if(str.size() > maxLen) break;
    }
    
    
    int len = t;
    for(int i = 0; i < t; i++) {
        answer += str[p - 1 + i * m];
    }
    
    
    return answer;
}