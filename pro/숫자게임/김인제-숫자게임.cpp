/*
그리디 알고리즘을 베이스로 접근
A 선수에 B선수를 매칭시킬때 트리 구조를 사용하면 100,000 명의 선수가 존재하므로 시간초과
A 선수들의 순서는 독립집합으로 마음대로 바꿔도 상관없음, B 선수의 순서들을 마음대로 조절할 수 있기 떄문
따라서, A 와 B 선수 목록을 sort() 후 앞에서 부터 비교해줌
이때 A 선수를 이길 수 있는 가장 작은 점수의 B 선수를 매칭시키고, 그 외의 경우는 B가 패배하는 경우임.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    // multiset <int> ratings(B.begin(), B.end());
    sort(B.begin(), B.end());
    sort(A.begin(), A.end());
    
    if (A[0] >= B[B.size()-1])
        return 0;

    int idxA = 0, idxB = 0, size = A.size();
    
    while(idxA < size && idxB < size){
        if (A[idxA] < B[idxB]){
            idxA++, idxB++, answer++; 
        }
        else{
            idxB++;
        }
    }
    
    
    return answer;
}