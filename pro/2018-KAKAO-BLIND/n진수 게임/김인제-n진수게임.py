'''
https://programmers.co.kr/learn/courses/30/lessons/17687
메모리 초과를 막기 위해 전체 배열을 미리 생성하는 것 이 아닌, 
각 숫자 마다 몇칸이 필요한지를 계산 후 그 안에 골라야하는 숫자가 있는지 확인
'''
import math

def solution(n, t, m, p):
    answer = ''
    
    idx = 0
    count = 1
    numbers = []

    while len(answer) < t:
        temp = []
        num = idx
        offset = 1
        
        while num / n >= 1:
            temp.append(num % n)
            num /= n
            num = math.floor(num)
            offset += 1
        
        temp.append(num)
        
        temp.reverse()
        
        
        # print(idx, temp, count, offset)
        
            
        for i in range(count, count + offset):
            turn =  m if i % m == 0 else i % m
            
            if turn == p:
                result = temp[i - count]
                # print(result)
                
                if result >= 10:
                    result = ord('A') + result - 10
                    result = chr(result)
                    
                else:
                    result = str(result)
                    
                answer += result
                
                if len(answer) == t:
                    break
                
        
        count += offset  
        idx += 1

        
    return answer