'''
https://programmers.co.kr/learn/courses/30/lessons/17684
해쉬맵을 사용하여 압축 로직 구현
'''
def solution(msg):
    answer = []
    
    cache = {}
    
    for offset in range(26):
        alphabet = chr( ord('A') + offset )
        cache[alphabet] = offset + 1
        
    idx = 27
    word = ""
    
    for char in msg:
        word += char

        
        if word not in cache.keys():
            
            answer.append(cache[word[:-1]])
            cache[word] = idx
            idx += 1
            word = char
    
    answer.append(cache[word])
            
    
    return answer