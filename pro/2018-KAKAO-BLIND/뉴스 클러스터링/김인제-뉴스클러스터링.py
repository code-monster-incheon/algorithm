'''
https://programmers.co.kr/learn/courses/30/lessons/17677
해쉬맵으로 합집합, 교집합 구현
'''
def solution(str1, str2):
    answer = 0
    
    mul = 65536
    
    if len(str2) == 0:
        return mul
    
    hash1 = {}
    hash2 = {}
    
    for i in range(len(str1) - 1):
        temp = str1[i:i+2]
        
        if not temp.isalpha():
            continue;
        
        temp = temp.lower()
        
        if temp in hash1.keys():
            hash1[temp] += 1
        else:
            hash1[temp] = 1
    
    for i in range(len(str2) - 1):
        temp = str2[i:i+2]
        
        if not temp.isalpha():
            continue;
        
        temp = temp.lower()

        
        if temp in hash2.keys():
            hash2[temp] += 1
        else:
            hash2[temp] = 1
    
    intersect = 0
    union = 0
    
    for key in hash1.keys():
        if key in hash2.keys():
            intersect += min(hash1[key], hash2[key])
            union += max(hash1[key], hash2[key])
        else:
            union += hash1[key]
            
    for key in hash2.keys():
        if key not in hash1.keys():
            union += hash2[key]
    
    
    if (intersect + union) == 0:
        return mul
    

    
    jaccard = intersect / union
    
    
    
    return int(jaccard * mul)