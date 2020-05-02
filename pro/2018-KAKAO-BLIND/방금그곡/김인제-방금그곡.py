'''
https://programmers.co.kr/learn/courses/30/lessons/17683
문자열 전처리 문제
'''

def solution(m, musicinfos):
    answer = ''
    
    musics = []
    
    m = list(m)
    m.reverse()
    
    offset = ord('F') - ord('A') + 1
    
    _m = []
    
    
    for i in range(len(m)):
        if m[i] == '#':
            m[i+1] = chr( ord(m[i+1]) + offset )
        else:
            _m.append(m[i]) 
    _m.reverse()
        
    _musics = []
    
    _m = ''.join(_m)
    
    for music in musicinfos:
        music = music.split(',')
        
        start = int(music[0][:2]) * 60 + int(music[0][3:])
        end = int(music[1][:2]) * 60 + int(music[1][3:])
        duration = end - start
        title = music[2]
        
        temp = []
        
        _music = list(music[3])
        _music.reverse()
        
        for i in range(len(_music)):
            if _music[i] == '#':
                _music[i+1] = chr( ord(_music[i+1]) + offset )
            else:
                temp.append(_music[i]) 

        temp.reverse()
        
        if duration > len(temp):
            temp *= int(duration / len(temp)) + 1
        
        temp = temp[:duration]
        temp = ''.join(temp)
        
        
        _musics.append([-(duration), start, title, temp])
    
    
    result = "(None)"
    _min = 987654321
    
  
    
    for music in _musics:
        duration = music[0]
        info = music[-1]
        title = music[2]
    
        
        if _m in info:
            if duration < _min:
                _min = duration
                result = title
                
    
    return result