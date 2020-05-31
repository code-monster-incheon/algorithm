"""
스택 활용
"""

def solution(s):
    answer = 987654321
    
    if len(s) == 1:
        return 1
    
    for offset in range(1, int(len(s) / 2) + 1):
    

        tokens = []

        idx = 0
        token = ""

        while idx < len(s):
            token += s[idx]
            idx += 1

            if len(token) == offset:
                tokens.append(token)
                token = ""

        if len(token) > 0:
            tokens.append(token)
        


        ret = 0

        while len(tokens) > 0:
            top = tokens[0]
            sameCount = 0

            while len(tokens) > 0 and top == tokens[0]:
                sameCount += 1
                tokens.pop(0)


            if sameCount > 1:
                ret += len(str(sameCount))
                ret += len(top)

            else:
                ret += len(top)

        answer = min(answer, ret)
        

        
        
    
    return answer