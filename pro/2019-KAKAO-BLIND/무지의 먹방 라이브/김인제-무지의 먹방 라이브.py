'''
1.  우선순위 큐로 가장 적게 남은 음식을 받아 옴
2.  음식이 다 떨어졌거나 k 번 순회 후에는 우선순위 큐에 남아있는 음식을 
    전부 꺼낸 후 idx 로 정렬하여 원하는 k 번째의 음식을 반환함
'''

import heapq

def solution(food_times, k):
    answer = 0
    h = []
    
    for idx in range(len(food_times)):
        food = [food_times[idx], idx+1]
        heapq.heappush(h, food)
        
    
    prev = 0
    
    while len(h) > 0:
        top = h[0]
        food = top[0] - prev
        
        if top[0] == prev:
            heapq.heappop(h)
            continue
        
        if food * len(h) <= k:
            k -= food * len(h)
        else:
            remain = []
            
            while len(h) > 0:
                remain.append(h[0][1])
                heapq.heappop(h)
            
            remain.sort()
            
            return remain[k % len(remain)]
        
        prev = top[0]
        heapq.heappop(h)
    
    return -1