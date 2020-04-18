# 1. 목적
  -  알고리즘 코딩 테스트 전에 문제를 풀 때 비슷한 문제 발견 시 예전 문제 비교 필요
  -  다른 사람 코드 비교 용이
  -  포트폴리오 활용 가능?

# 2. 저장소 파일 구조
  ***(1)로컬 저장소 파일 구조 요약 사진***
 
![ㅇㅇ](https://user-images.githubusercontent.com/59609682/79632331-820b9d00-8199-11ea-8c25-a9c1006c96f9.jpeg)


  ***(2)로컬 저장소 파일 사진***
  <div>
<img width="615" alt="스크린샷 2020-04-18 오후 4 58 20" src="https://user-images.githubusercontent.com/59609682/79631740-ff351300-8195-11ea-86b3-4b9051cdd722.png">
</div>

---

# 3. Git 전략
### 원격 브랜치(origin[로컬저장소 이름])에 있는 브랜치 리스트 정리
* ***master 브랜치*** : 1주 한번 스터디 끝나기전에 develop merge
* ***develop 브랜치*** : 스터디 전에 각자 원격(ex : origin/ysh) 브랜치로 pull request 한후 merge
* ***ysh, kjb, kij, jdh 개인 브랜치*** <---- 이 브랜치로 pull request 해야합니다.

# 4. Git pull request ->merge 하기 까지 순서 정리

### 작업 전 아래 확인 필수

  * 로컬 저장소(git clone한 파일 위치로 이동 --> 저장소 이름이 algorithm이기 때문에 로컬에 algorithm 파일안으로 터미널로 이동하셔야 합니다.)
   > [위사진참고] ex: usr/desktop/algorithm  **터미널 명령어  cd usr/desktop/algorithm**
  * 로컬 저장소에서 **터미널 명령어 git branch** 입력시에 자신의 로컬 브랜치에 색깔이 들어와야 됨 (아래사진 참고) 

<img width="92" alt="qq" src="https://user-images.githubusercontent.com/59609682/79634830-fcdbb480-81a7-11ea-872d-fc4d06a7f04b.png">

* master만 있으면 **터미널 명령어 git branch ysh** 개인 로컬 브랜치를 만들고, **터미널 명령어 git checkout ysh** 입력

### 코드 작업 후에 위에 로컬 저장소 위치에서 터미널 명령어
1. **git add .** 
2. **git commit -m "쓰고 싶은메시지 입력"**
3. **git fetch origin**
4. **git rebase -i origin/develop**  (rebase)
5. **esc 입력후 :wq (충돌 나면 해결 후 git rebase --continue 완료)**
6. 이건 추후 결정인데 로컬 커밋이 여러번 했다면 하나 커밋으로 줄여서 pull request 필요 (ex : 자신이 로컬에서 3번 커밋을 했으면 git rebase -i HEAD~3)으로 하나로 커밋을 합친후 push ) <----나중에 얘기해요
---
7. 원격 저장소 간 후에 아래사진에 **Pull request** 클릭
<img width="454" alt="pull" src="https://user-images.githubusercontent.com/59609682/79635225-b471c600-81aa-11ea-84e6-cbecd44af5a1.png">

---
8. 오른쪽 옆에 **초록색 New pull request** 클릭
<img width="996" alt="crp" src="https://user-images.githubusercontent.com/59609682/79635246-db2ffc80-81aa-11ea-92f7-3afc7138018c.png">

---
9. **base : develop / compare : 개인브랜치이름** 변경 
<img width="800" alt="pr" src="https://user-images.githubusercontent.com/59609682/79635433-dc155e00-81ab-11ea-9a4d-26d6d2f83ffa.png">

---

