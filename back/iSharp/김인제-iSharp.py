# https://www.acmicpc.net/submit/3568/20444084
# 변수의 type 을 뒤집을 때, [] 을 뒤집으면 ][ 이 되는데
# 정답은 [] 를 뒤집어도 [] 가 되어야 함을 유의

s = input()
s = s.replace(',', '')
s = s.split(' ')

_type = s[0]
s.pop(0)

for _s in s:
    
    name = ""
    varType = ""

    for i in range(len(_s)):
        if ('a' <= _s[i] and _s[i] <='z') or  ('A' <= _s[i] and _s[i] <='Z'):
            name += _s[i]
        elif _s[i] == '[':
            varType += ']'
        elif _s[i] == ']':
            varType += '['
        elif _s[i] != ';':
            varType += _s[i]
            

    varType = varType[::-1]



    print(_type+varType+' '+name+';')

