//https://programmers.co.kr/learn/courses/30/lessons/17686
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct File{
    string name;
    string head;
    int num;
    string tail;
    int index;
};

bool compare(const File& a, const File& b) {
    if(a.head == b.head) {
        if(a.num == b.num) {
            return a.index < b.index;
        } else {
            return a.num < b.num;
        }
    } else {
        return a.head < b.head;
    }
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> f(files.size());
    
    for(int i = 0; i < files.size(); i++) {
        string str = files[i];
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        
        int nIndex = 0;
        while(true) {
            if(isdigit(str[nIndex])) break;
            nIndex++;
        }
        
        int len = files[i].size();
        int tIndex = nIndex;
        while(true) {
            if(tIndex == len || !isdigit(str[tIndex])) break;
            tIndex++;
        }
        
        
        f[i].name = files[i];
        f[i].head = str.substr(0, nIndex);
        f[i].num = stoi(str.substr(nIndex, tIndex - nIndex));
        f[i].tail = str.substr(tIndex);
        f[i].index = i;
    }
    
    
    sort(f.begin(), f.end(), compare);
    
    
    answer.assign(f.size(), "0");
    for(int i = 0; i < f.size(); i++) {
        answer[i] = f[i].name;
    }
    
    return answer;
}