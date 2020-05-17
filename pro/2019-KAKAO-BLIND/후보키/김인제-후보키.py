'''
DFS 로 조합을 뽑은 후 후보키의 조건인 유일성과 최소성을 만족하는지 확인
유일성 만족 조건: 후보키 만으로 모든 row 를 구별 가능
최소성 만족 조건: 이전에 뽑은 후보키의 조합을 현재 뽑은 후보키의 조합이 포함하면 안됨
'''

visited = []
permutation = []

def dfs(idx, count):
    if count == 0:
        permutation.append([x for x in visited])
        return
        
    for i in range(idx, len(visited)):
        
        if visited[idx]:
            continue
        
        visited[i] = True
        dfs(i+1, count-1)
        visited[i] = False
        

def solution(relation):
    answer = 0
    global visited
    global permutation
    
    ret = set()
    
    for n in range(1, len(relation[0]) + 1):
        visited = [False for _ in range(len(relation[0]))]
        permutation = []
        

        
        dfs(0, n)
        
        for perm in permutation:
            _set = set()
            
            for row in relation:
                key = ""
                
                for i in range(len(row)):
                    if perm[i]:
                        key += row[i]
            
                if key in _set:
                    break
                    
                _set.add(key)
                
            if len(_set) == len(relation):
                # print(perm, ret)
                
                temp = ""
                for i in perm:
                    if i:
                        temp += "1"
                    else:
                        temp += "0"
                
                if len(ret) == 0:
                    ret.add(temp)
                    continue
                
                flag = False
                
                
                for key in ret:
                    count = ""
                    for i in range(len(key)):
                        if key[i] == "1" and temp[i] == "1":
                            count += "1"
                        else:
                            count += "0"
                    
                    if count == key:
                        flag = True
                        break
                    
                if not flag:
                    ret.add(temp)

                
        
    return len(ret)