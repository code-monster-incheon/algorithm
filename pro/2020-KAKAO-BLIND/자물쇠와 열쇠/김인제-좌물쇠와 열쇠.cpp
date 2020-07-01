/*
https://programmers.co.kr/learn/courses/30/lessons/60059#

비트마스크 + 양방향 BFS + 행렬회전 등의 구현이 결합된 문제

BFS 로 2차원 행렬의 상태를 표현해가며 해결할 수 있는 문제.
이때 20 x 20 행렬을 표현하기 위해, 20 x 20 배열이 아닌 한 행을 bitmask 로 표현하여 공간복잡도를 줄여야 함
또한 상태공간이 많아질 수 있어, 양방향 BFS 를 적용해야 시간초과가 안남

- 2차원 행렬을 bitmask 로 표현한 후 회전하는 연산은 getRotates() 참고.
- 시간초과를 막기위해 휴리스틱 함수 사용 (사용 안하면 아슬아슬하게 시간초과 남)
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

vector<int> start;
vector<int> end;
int sumLock;
int N, M;

vector<vector<int>> getRotates (vector<int> cur){
    vector<vector<int>> ret;
    ret.push_back(cur);
    
    for(int i = 0; i < 3; i++){
        vector<int> rotate = cur;
        
        for(int i = 0; i < N; i++){
            int temp = 0;
            
            for(int j = N-1; j >= 0; j--){
                int bit = (cur[j] & (1 << (N-1-i))) ? 1 : 0;
                
                temp |= (bit << j);
            }
            rotate[i] = temp;
        }
        cur = rotate;
        ret.push_back(rotate);
    }
    
    return ret;
}

map< vector<int>, int > visited;

vector< vector<int> > getShiftedKey(vector<int> cur){
    vector<vector<int>> ret;
    
    vector<int> up = cur;
    vector<int> down = cur;
    vector<int> left = cur;
    vector<int> right = cur;
    
    for(int i = 0; i < N-1; i++)
        up[i] = up[i+1];
    up[N-1] = 0;
    
    for(int i = N-1; i > 0; i--)
        down[i] = down[i-1];
    down[0] = 0;
    
    for(int i = 0; i < N; i++)
        right[i] >>= 1;
    
    for(int i = 0; i < N; i++){
        left[i] <<= 1;
        left[i] &= ( (1 << N) - 1);
    }
    ret.push_back(up);
    ret.push_back(down);
    ret.push_back(left);
    ret.push_back(right);
    
    return ret;
}

vector< vector<int> > getShiftedLock(vector<int> cur){
    vector<vector<int>> ret;
    vector<int> up = cur;
    vector<int> down = cur;
    vector<int> left = cur;
    vector<int> right = cur;
    
    if (cur[0] == 0){
        
        
        for(int i = 0; i < N-1; i++)
            up[i] = up[i+1];
        up[N-1] = 0;
        
        ret.push_back(up);
    }
    
    if (cur[N-1] == 0){
        
        
        for(int i = N-1; i > 0; i--)
            down[i] = down[i-1];
        down[0] = 0;
        
        ret.push_back(down);
    }
    
    bool left_flag = true;
    for(int i = 0; i < N; i++)
        if (cur[i] & (1 << (N-1))){
            left_flag = false;
            break;
        }
    
    if (left_flag){
        
        
        for(int i = 0; i < N; i++){
            left[i] <<= 1;
        }
        
        ret.push_back(left);
    }
    
    bool right_flag = true;
    for(int i = 0; i < N; i++)
        if (cur[i] & 1){
            right_flag = false;
            break;
        }
    
    if (right_flag){
        
        
        for(int i = 0; i < N; i++)
            right[i] >>= 1;

        ret.push_back(right);
    }
       
    return ret;
}

int sign(int x){
    if (!x) return 0;
    return x > 0 ? 1 : -1;
}
int incr(int x){
    return x < 0 ? x-1 : x+1;
}

void pprint(vector<int> cur){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (cur[i] & (1 << (N-1-j) ))
                cout << "1 ";
            else
                cout << "0 ";
        }cout << endl;
    }cout << endl << endl;
}

bool hueristic(vector<int> cur){
    int sum = 0;
    for(int i = 0; i < N-1; i++)
        sum += __builtin_popcount(cur[i]);
    
    return (sum < sumLock);
}

int getCount(vector<int> cur){
    int sum = 0;
    for(int i = 0; i < N-1; i++)
        sum += __builtin_popcount(cur[i]);
    
    return sum;
}

bool bfs(){
    queue< vector<int> > q;
    
    vector< vector<int> > starts = getRotates(::start);
    vector< vector<int> > ends = getRotates(::end);
    
    
    
    for(int i = 0; i < starts.size(); i++){
        //pprint(starts[i]);
        q.push(starts[i]);
        visited[starts[i]] = 1;
    }
    
    for(int i = 0; i < ends.size(); i++){
        //pprint(ends[i]);
        
        if (visited[ends[i]] == 1)
			return true;
        
        q.push(ends[i]);
        visited[ends[i]] = -1;
    }
    
    while(q.empty() == false){
        vector<int> cur = q.front();    
        q.pop();
        

        
        if (visited[cur] > 0){
            
            if (hueristic(cur))
                continue;
            
            vector< vector<int> > shifts = getShiftedKey(cur);
            
            if(shifts.size() == 0)
                continue;
            
            for (auto& next : shifts){
                int &there = visited[next];
                
                if (there == 0){
                    there = 1;
                    q.push(next);
                }
                else if (there == -1)
                    return true;
            }
        }
        else if (visited[cur] <0){
            
            vector< vector<int> > shifts = getShiftedLock(cur);
            if(shifts.size() == 0)
                continue;
            
            for (auto& next : shifts){
                int &there = visited[next];
                
                if (there == 0){
                    there = -1;
                    q.push(next);
                }
                else if (there == 1)
                    return true;
            }
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    ::N = lock.size();
    ::M = key.size();
    ::start = vector<int>(N, 0);
    ::end = vector<int>(N, 0);

    
    for(int i = 0; i < M; i++){
        for(int  j = 0; j < M; j++){
            if (key[i][j] == 1)
                ::start[i] |= (1 << (M-1-j));
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int  j = 0; j < N; j++){
            if (lock[i][j] == 0)
                ::end[i] |= (1 << (N-1-j));
        }
    }
    
    for(int i = 0; i < N; i++)
        sumLock += __builtin_popcount(::end[i]);

    answer = bfs();
    
    
    return answer;
}