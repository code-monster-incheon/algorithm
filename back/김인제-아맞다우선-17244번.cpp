/*
* https://www.acmicpc.net/problem/17244
* 
* bfs 로 각 정점 사이 거리를 구한 후 정점을 그래프로 치환하고 간선에 정점간 거리를 넣어줌
* dfs 로 start 에서 모든 정점을 방문하고 end 에 도착하는 경로의 최단 거리를 완전 탐색, 정점이 7개 밖에 없으므로 완전탐색 가능
* 만약 정점이 10개가 넘어간다면, 비트마스크를 이용한 dp 문제로 변환하여 해결 가능
*/

#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> items;
pair<int, int> start;
pair<int, int> end;
char map[51][51];
bool visited[51][51];
bool path[5];
int row, col;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int graph[7][7];

int ret = 987654321;

void bfs(int item) {

   memset(visited, false, sizeof(visited));

   queue<pair<pair<int, int>, int>> q;
   q.push({ items[item], 0 });
   visited[items[item].first][items[item].second] = true;

   int find = 0;

   while (q.empty() == false) {
      int curX = q.front().first.first;
      int curY = q.front().first.second;
      int dist = q.front().second;
      q.pop();

      if (map[curX][curY] == 'S' || map[curX][curY] == 'X' || map[curX][curY] == 'E') {
         find++;
         for (int i = 0; i < items.size(); i++)
         {
            if (items[i].first == curX && items[i].second == curY) {
               graph[item][i] = dist;
               graph[i][item] = dist;
               break;
            }
         }
      }

      if (find == items.size())
         return;


      for (int i = 0; i < 4; i++) {
         int newX = curX + dx[i];
         int newY = curY + dy[i];

         if (visited[newX][newY] || newX < 0 || newX >= row || newY < 0 || newY >= col)
            continue;

         if (map[newX][newY] == '#')
            continue;

         visited[newX][newY] = true;
         q.push({ { newX, newY }, dist + 1 });
      }
   }

}



void dfs(int idx, int dist, int cnt) {
   if (cnt == items.size() - 2)
   {
      ret = min(ret, dist + graph[idx][items.size() - 1]);
      return;
   }

   for (int i = 1; i < items.size() - 1; i++) {
      if (path[i] == true || dist >= ret)
         continue;

      path[i] = true;

      dfs(i, dist + graph[idx][i], cnt + 1);

      path[i] = false;

   }
}

void solve() {
   for (int i = 0; i < items.size(); i++)
      bfs(i);

   dfs(0, 0, 0);

   cout << ret << endl;
}

int main()
{
   cin >> col >> row;

   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         cin >> map[i][j];

         if (map[i][j] == 'S')
         {
            items.push_back({ i, j });
            start = { i, j };
         }
      }
   }

   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {

         if (map[i][j] == 'X')
            items.push_back({ i, j });

         else if (map[i][j] == 'E')
            ::end = { i, j };
      }
   }

   items.push_back(::end);

   solve();
}