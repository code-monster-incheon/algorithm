#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string word[21];
vector<int> solution(int n) {

    vector<int> ret;
    word[1] ="0";
    word[2] ="001";
    
    for(int i = 3; i <= n; i++)
    {
        word[i] = word[i - 1] + "0";
        string beforeWord = word[i - 1];
        
        for(int j = 0; j < beforeWord.size(); j++)
        {
            beforeWord[j] = beforeWord[j] == '0' ? '1' : '0';
        }
       
        reverse(beforeWord.begin(), beforeWord.end());
        
        word[i] += beforeWord;
        
    }
    
    for(int i = 0; i < word[n].size(); i++)
    {
        ret.push_back(word[n][i] - '0');
    }
    
    return ret;
}