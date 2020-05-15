'''
해쉬맵에 유저의 유니크 아이디와 닉네임을 저장 후 갱신
'''

def solution(record):
    answer = []
    logs = []
    uid_table = {}
    
    for log in record:
        tokens = log.split()
        
        command = tokens[0]
        uid = tokens[1]
        
        logs.append([uid, command])
        
        if command != "Leave":
            name = tokens[2]
            uid_table[uid] = name
            
    for log in logs:
        uid = log[0]
        command = log[1]

        
        if command == "Leave":
            answer.append(uid_table[uid]+"님이 나갔습니다.")
        elif command == "Enter":
            answer.append(uid_table[uid]+"님이 들어왔습니다.")
            
    
    
    return answer