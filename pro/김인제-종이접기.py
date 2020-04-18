'''
https://programmers.co.kr/learn/courses/30/lessons/62049

종이를 접는 과정에서 전의 단계에서 접은 종이는 다음 단계에서도 접혀있어야 함
전 단계에서 접은 종이의 양 옆으로 0, 1 이 번갈아 가면서 새롭게 접히게 됨
'''

def solution(n):
    
    answer = []
    
    for i in range(n):
        if i == 0:
            answer.append(0)
        else:
            folds = [0]
            
            for j in range(len(answer)):
                folds.append(answer[j])
                
                if (j % 2) == 0:
                    folds.append(1)
                else:
                    folds.append(0)
            
            answer = folds
                
    return answer