'''
https://programmers.co.kr/learn/courses/30/lessons/17686
파일명을 주어진 조건에 따라 전처리, 변형, 파싱한 후 정렬
출력 시 에는 전처리 전의 원래의 파일명을 출력해야 함
'''

def solution(files):
    answer = []
    
    for file in files:
        head = ""
        number = ""
        tail = ""
        
        last = 0
        for (idx, char) in enumerate(file):
            if char.isdigit():
                
                for _idx in range(idx, len(file)):
                    if file[_idx].isdigit():
                        number += file[_idx]
                    else:
                        last = _idx
                        break
                    
                break
            
            head += char
        
        if last != 0:
            tail = file[last:]
        
        
        origin_number = number
        origin_head = head

        answer.append([head.lower(), int(number), tail, origin_head, origin_number])
        
    
    answer.sort(key = lambda x: [ x[0], x[1] ])

    result = []
    
    for token in answer:
        result.append(token[-2] + token[-1] + token[2])
    
    print(result)
    
    
    return result