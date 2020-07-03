'''
https://programmers.co.kr/learn/courses/30/lessons/67258

보석 배열의 길이가 10만 이므로, 2중 for 문으로는 해결 불가능
앞에서부터 한번씩만 훑고 지나가는 슬라이딩 윈도우 방식으로 해결

자료구조의 set 과 map 을 사용하여 현재 구간의 보석 정보 저장
'''

def solution(gems):
    answer = []
    gem_set = set(gems)

    count_dict = {}
    count_set = set()
    
    # 슬라이딩 윈도우의 현재 구간의 lo, hi
    lo = 0
    hi = 0
    
    finalLow = 0
    finalHi = 0
    length = 987654321


    foundPathUsing = 0
    
    # 슬라이딩 윈도우의 lo 전진
    for lo in range(len(gems)):
        foundPath = False
        
        # 슬라이딩 윈도우의 hi 전진
        for hi in range(foundPathUsing, len(gems)):

            # hi 값을 슬라이딩 윈도우에 추가
            if gems[hi] not in count_dict.keys():
                count_dict[gems[hi]] = 1
                count_set.add(gems[hi])
            else:
                count_dict[gems[hi]] += 1
                
            # 현재 슬라이딩 윈도우가 모든 보석을 포함하고 있다면
            if len(count_set) == len(gem_set):

                # 가장 짧은 구간만 저장
                if abs(hi - lo) < length:
                    length = abs(hi - lo)
                    finalHi = hi
                    finalLow = lo
                    
                # 슬라이딩 윈도우의 상한을 찾았으므로 break
                foundPath = True
                foundPathUsing = hi
                break
        
        # 가능한 슬라이딩 윈도우가 없다면, lo를 증가시켜도 소용 없으므로 break
        if not foundPath:
            break
        
        # 슬라이딩 윈도우에 lo 제거
        if gems[lo] in count_dict.keys():
            if count_dict[gems[lo]] == 1:
                del count_dict[gems[lo]]
                count_set.remove(gems[lo])
            else:
                count_dict[gems[lo]] -= 1

        # 슬라이딩 윈도우에 현재의 hi 제거 (다음 hi 반복문에서 추가되므로)                
        if gems[foundPathUsing] in count_dict.keys():
            if count_dict[gems[foundPathUsing]] == 1:
                del count_dict[gems[foundPathUsing]]
                count_set.remove(gems[foundPathUsing])
            else:
                count_dict[gems[foundPathUsing]] -= 1

    return [finalLow+1, finalHi+1]