'''
https://programmers.co.kr/learn/courses/30/lessons/64062
우선순위 큐와 유니온파인드 알고리즘을 사용하여 NlogN 에 구현
징검다리에서 더이상 건너지 못하는 돌 들이 양옆에 존재할 때 마다 유니온 파인드로 합쳐줌
'''

import heapq

root = [x for x in range(200001)]
rank = [0 for x in range(200001)]
cache = [0 for x in range(200001)]
count = [1 for x in range(200001)]

def find(x):
    if root[x] == x:
        return x
    else:
        root[x] = find(root[x])
        return root[x]
    
def merge(x, y):
    x = find(x)
    y = find(y)
    
    if x == y:
        return 0
    
    if rank[x] < rank[y]:
        root[x] = y
        count[y] += count[x]
        
    else:
        root[y] = x
        count[x] += count[y]
        
        
    if rank[x] == rank[y]:
        rank[x] += 1
        
    return max(count[x], count[y])

    

def solution(stones, k):
    answer = 0
    
    
    h = []
    
    
    for (idx, stone) in enumerate(stones):
        heapq.heappush(h, (stone, idx))
    

        
    prev = 0
    
    while len(h) > 0:
        
        top = h[0]
       
        #answer += (top[0] - prev)
        answer = top[0]
        prev = top[0]
        
        while top == h[0]:
            idx = h[0][1]
            cache[idx] = 1
            
            
            
            result = 1
            
            if idx == 0:
                if cache[idx+1] == 1:
                    result = merge(idx, idx + 1)
            elif idx == len(stones) - 1:
                 if cache[idx - 1] == 1:
                    result = merge(idx-1, idx)
            else:
                if cache[idx-1] == 1 and cache[idx+1] == 1:
                    result = merge(idx-1, idx)
                    result = merge(idx, idx+1)
                elif cache[idx - 1] == 1:
                    result = merge(idx-1, idx)
                elif cache[idx + 1] == 1:
                    result = merge(idx, idx+1)
                    
            assert(result != 0)
            
            if result >= k:
                return answer
                
            heapq.heappop(h)
        
            
        
    return answer