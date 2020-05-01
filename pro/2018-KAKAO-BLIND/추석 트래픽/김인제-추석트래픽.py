'''
https://programmers.co.kr/learn/courses/30/lessons/17676
우선순위 큐와 정렬을 사용하여 해결
'''

import heapq

def solution(lines):
    answer = 0
    
    list = []
    heap = []
    
    for line in lines:
        tokens = line.split()
    
        
        times = tokens[1].split(':')
        
        end = float(times[0]) * 3600 + float(times[1]) * 60 + float(times[2])
        
        offset = tokens[2][:-1]
        
        start = end - float(offset) + float(0.001)

        list.append([start, end])
        
    list.sort()
    count = 0
    

        
        
    for timestamp in list:
        prev = 0
        
        start = timestamp[0]
        end = timestamp[1]
    
        
        while heap:
            # print(heap[0] , start)
            temp1 = int(heap[0] * 1000)
            temp2 = int(start * 1000)
            
            
            if temp1 + 1000 <= temp2:
                #print(heap[0] , start)
                prev += 1
                heapq.heappop(heap)
                
            else:
                break
        
        heapq.heappush(heap, end)
        
        count -= prev
        count += 1
        
        answer = max(answer, count)
    
    return answer