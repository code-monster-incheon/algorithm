'''
직접 파싱 규칙을 만들면 통과하지 못하는 까다로운 테스트 케이스가 존재함
따라서 정규표현식을 사용해야 함!

정규표현식을 처음 사용해봤고 정규표현식을 적용해도 원하는 파싱 결과가 안나오는 경우가 있어서
시간이 오래걸렸던 문제, 정규표현식을 알았다면 굉장히 쉽게 해결 가능
'''

import re

def solution(word, pages):
    answer = 0
    
    htmls = []
    scores = {}
    
    for page in pages:



        html = page
        p = re.compile("<meta property=\"og:url\" content=\"https://[\S]*\"/>")
        html = p.findall(html)
        


        if len(html) > 0:
            html = [url.split("https://")[1][:-3] for url in html]


        links = page
        p = re.compile("<a href=\"https://[.]*\">")
        links = p.findall(links)
        
        contents = page
        
        if len(links) > 0:
            links = [url.split("a href=\"https://")[1].split(">")[0][:-1] for url in links]
            
        for link in links:
            if link in contents:
                contents = contents.replace(link, ' ')
        print(html)
        print(links)
        

        score = float(0.0)
        
        _content = ""
        for char in contents.lower():
            
            if ord(char) < ord('a') or ord(char) > ord('z'):
                _content += " "
            else:
                _content += char
        
        words = _content.split(" ")

        
        for _word in words:
            if word.lower() == _word:
                score += float(1.0)
                
        if html[0] in scores.keys():
            scores[html[0]] += score
        else:
            scores[html[0]] = score
        
        for link in links:
            
            if link in scores.keys():
                scores[link] += float(score) / float(len(links))
            else:
                scores[link] = float(score) / float(len(links))
        



        htmls.append(html[0])
        
        
    _max = -1
    

    for (idx, html) in enumerate(htmls):
        print(html, scores[html])
        if _max < scores[html]:
            _max = scores[html]
            answer = idx
        
    return answer