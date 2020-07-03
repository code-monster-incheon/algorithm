/*
https://programmers.co.kr/learn/courses/30/lessons/67260

문제를 이해하는 것이 힘들지만, 결국 그래프에서 싸이클이 발생하는지를 찾는 문제
예를들어, 0 -> 1 -> 2 -> 3 -> 4 와 같은 유향 그래프 에서
주어진 방문 순서가 4 -> 2 라면, 이는 불가능함!

그 이유는, 0 에서 4를 방문하는 과정에서 2를 필연적으로 방문하게 되는데,
주어진 방문 순서는 4를 방문하고 그 이후에 2를 방문해야 하므로
이때 2를 방문하지 않고, 4를 방문하고 그 이후에 2를 방문할 수 있는 경우는 존재하지 않음

따라서, 문제의 양방향 그래프를 0번 노드부터 BFS 로 단방향 트리로 바꿔준 후에
싸이클이 존재하는지 DFS 로 탐색해주면 됨
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;


vector<int> adj[200001];
vector<int> direct_adj[200001];
vector<int> discovered;
vector<int> finished;
int counter = 0;

bool flag = true;

void dfs(int here){
    if (::flag == false)
        return;

    discovered[here] = counter++;
    
    for (auto& there : direct_adj[here]){
        
        // 아직 방문하지 않은 노드
        if (discovered[there] == -1)
            dfs(there);
        // 순방향 간선
        else if (discovered[here] < discovered[there])
            continue;
        // 싸이클이 발생한 경우
        else if (finished[there] == -1){
            ::flag = false;
            return;
        }

    }
    finished[here] = 1;
    
    return;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    
    // 양방향 그래프 생성
    for (auto& p : path){
        int start = p[0];
        int end = p[1];
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    
    // root 를 0번 노드로 설정한 후 BFS 로 단방향 그래프 생성
    while(q.empty() == false){
        int cur = q.front();    q.pop();
        
        for(auto& next: adj[cur]){
            if (visited[next])
                continue;
            
            visited[next] = true;
            q.push(next);
            direct_adj[cur].push_back(next);
        }
    }
    
    for (auto& o : order){
        int here = o[0];
        int there = o[1];
        
        direct_adj[here].push_back(there);
    }
    
    discovered = vector<int>(n+1, -1);
    finished = vector<int>(n+1, -1);
    
    // 깊이 우선 탐색으로 싸이클 탐색
    dfs(0);
    
    return ::flag;
}