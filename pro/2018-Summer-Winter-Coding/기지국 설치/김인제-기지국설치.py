'''
https://programmers.co.kr/learn/courses/30/lessons/12979

자세한 풀이는 https://programmers.co.kr/learn/questions/11844 참조
'''

import math

def solution(n, stations, w):
    answer = 0
    
    # 전파가 안통하는 구간의 (시작점, 끝점) 의 모음
    segments = []
    
  
    # 좌표1 ~ 첫번째 안테나 사이의 전파가 안통하는 구간
    if stations[0] - w - 1 >= 1:
        segments.append([1, stations[0]-w-1])
    
    # 첫번째 안테나 ~ 마지막 안테나 사이의 전파가 안통하는 구간
    for i in range(len(stations) - 1):
        start = stations[i] + w + 1
        end = stations[i+1] - w - 1
        
        if start <= end:
            segments.append([start, end])
    
    # 마지막 안테나 ~ 좌표n 까지 전파가 안통하는 구간
    if stations[-1] + w + 1 <= n:
        segments.append([stations[-1] + w + 1, n])

    # 전파가 안통하는 구간 마다
    for segment in segments:
      	# 구간의 길이
        length = segment[1] - segment[0] + 1
        
        # 구간의 길이가 1대의 안테나 설치로 커버 가능한 경우
        if length <= w*2 + 1:
            answer += 1
        # 구간의 길이를 커버할 수 있는 만큼의 안테나 설치
        # 한대의 안테나가 커버할 수 있는 너비는 1 + w*2
        # -> 안테나의설치위치 + 양옆으로 w 만큼 = 1 + w*2
        # 안테나의 개수는 소수점이 나올수 없으므로, 올림처리
        else:
            answer += math.ceil(length / (w*2 + 1))
        

    return answer