// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/17679

#include <string.h>
#include <vector>
#include <iostream>

 using namespace std;
 bool v[31][31];
 int cnt = 0;


 int solution(int m, int n, vector<string> board) {

     bool test = false;
     
     while(true)
     {
         test = false;
         memset(v, false, sizeof(v));
     
         for(int i = 0; i < m; i++)
         {
             for(int j = 0; j < n; j++)
             {
                 if(board[i][j] != '0'
                    && j + 1 < n
                    && i + 1 < m
                    && board[i][j] == board[i][j + 1]
                    && board[i][j] == board[i+1][j+1]
                    && board[i][j] == board[i+1][j])
                 {
                     
                     v[i][j] = v[i+1][j+1] = v[i+1][j] = v[i][j+1] = true;
                     test = true;
                 }
             }
         } // 색칠하기
         
         for(int i = 0; i < m; i++)
         {
             for(int j = 0; j < n; j++)
             {
                 if(v[i][j])
                 {
                     cnt++;
                 }
             }
         }
         
         for(int i = 0; i < n; i++)
         {
             string str = "";
             for(int j = m - 1; j >= 0; j--)
             {
                 if(!v[j][i])
                 {
                     str += board[j][i];
                 }
             }
             
             for(int j = m - 1; j >= 0; j--)
             {
                 board[j][i] = '0';
             }
             
             for(int j = 0; j < str.size(); j++)
             {
                 board[m - 1 - j][i] = str[j];
             }
         
         }
         
         
         if(!test)
         {
             break;
         }
         
     }
     return cnt;
 }
