'''
https://programmers.co.kr/learn/courses/30/lessons/17678
매 버스 출발 시간 마다 가능한 탑승객을 태우고, 마지막 버스 출발 시간에서 자신이 탑승할 수 있는 가장 늦은 순서를 구함
'''

def solution(n, t, m, timetable):
    answer = ''
    
    cache = {}
    
    
    for idx, timestamp in enumerate(timetable):
        time = int(timestamp[:2]) * 60 + int(timestamp[3:])
        timetable[idx] = time
        
        if time in cache.keys():
            cache[time] += 1
        else:
            cache[time] = 1
            
    timetable.sort()
    

    
    start = 9 * 60 # bus start at 9:00AM
    
    bus_times = [start + (x * t) for x in range(n)]
    
    
    for time in bus_times:
        prev = time
    
        if time == bus_times[-1]:
            
            if  timetable[0] > time or len(timetable) < m:
                answer = time
                break
            
            prev = 0
            count = 0
            
            # timetable[0] <= time and len(timetable) >= m
            for i in range(m):
                if timetable[i] <= time:
                    prev = timetable[i]
                    count += 1
                    
            answer = prev - 1
            
            break
        
        for num in range(m):
            if len(timetable) > 0 and timetable[0] <= time:
                prev = timetable[0]
                timetable.pop(0)
            
        


    hour = int(answer / 60)
    if hour < 10:
        hour = "0" + str(hour)
    else:
        hour = str(hour)
        
    second = answer % 60
    if second < 10:
        second = "0" + str(second)
    else:
        second = str(second)
    
    answer = hour + ":" + second
    
    return answer