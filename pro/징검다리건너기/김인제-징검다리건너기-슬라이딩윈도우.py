'''
https://programmers.co.kr/learn/courses/30/lessons/64062
슬라이딩 윈도우와 우선순위 큐를 사용하여 NlogN 에 구현
'''

import heapq
from collections import deque

def solution(stones, k):
    visited = {}
    window = deque(stones[:k])
    h = []
    
    for stone in window:
        if stone in visited.keys():
            visited[stone] += 1
        else:
            visited[stone] = 1

        heapq.heappush(h, (-stone))
    
    
    loc_max = -h[0]
    global_min = loc_max

    
    for i in range(k, len(stones)):
        leftpop = window.popleft()
        rightappend = window.append(stones[i])
        
        visited[leftpop] -= 1
        
        if stones[i] in visited.keys():
            visited[stones[i]] += 1
        else:
            visited[stones[i]] = 1
            
        heapq.heappush(h, (-stones[i]))
    
        
        if leftpop == -h[0]:
            
            while visited[-h[0]] == 0:
                heapq.heappop(h)
                
            loc_max = -h[0]
            global_min = min(global_min, loc_max)

        
    return global_min