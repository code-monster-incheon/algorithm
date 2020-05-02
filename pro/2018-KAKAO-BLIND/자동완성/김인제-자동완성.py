'''
https://programmers.co.kr/learn/courses/30/lessons/17685
사용하기 적합한 자료구조는 Trie 이나 문자열의 길이가 너무 많아서 메모리 초과 날 가능성이 높음
문자열을 사전 순으로 정렬 후 앞, 뒤의 문자열 과 비교하는 방식으로 구현
'''

def solution(words):
    answer = 0
    
    words.sort()
    
    
    count = 0
    
    if words[0] in words[1]:
        answer += len(words[0])
    else:
        length = min(len(words[0]), len(words[1]))
        
        for i in range(length):
            if words[0][i] == words[1][i]:
                count += 1
            else:
                break
    
        answer += count + 1
        
    
    count = 0
        
    if words[-2] in words[-1]:
        answer += len(words[-2]) + 1
    else:
        length = min(len(words[-2]), len(words[-1]))
        
        for i in range(length):
            if words[-2][i] == words[-1][i]:
                count += 1
            else:
                break
                
        answer += count + 1
        

                
    for (idx, cur) in enumerate(words):
        if idx == 0 or idx == len(words) - 1:
            continue
        
        prev = words[idx - 1]
        next = words[idx + 1]
        
        length = min(len(prev), len(cur))
        
        prevPrefix = 0
        for i in range(length):
            if prev[i] == cur[i]:
                prevPrefix += 1
            else:
                break
        
        length = min(len(cur), len(next))
        
        nextPrefix = 0
        for i in range(length):
            if cur[i] == next[i]:
                nextPrefix += 1
            else:
                break
        
        ret = max(prevPrefix, nextPrefix) + 1
        ret = min(ret, len(cur))
        
        answer += ret
            
    
    return answer