# Commit Message Convention

## Introduction
github에서 의사소통에 오해를 방지하고 내용을 쉽게 이해하기 위해서 Commit Message Style을 지켜서 작성하기로 했다. 기존의 [Udacity Git Commit Message Style Guide](https://udacity.github.io/git-styleguide/)의 원칙을 거의 대부분 번역해서 가져왔다. 기존에 잘 만들어져 있는 규칙을 사용하는 것이 직접 만드는 것보다 더 편하기 때문이다.   
(엔지니어는 지금 바퀴를 재발명해야 할 상황인지 고민해야 한다.)

## Message Structure
메시지의 전체적인 구조는 제목, 본문으로 나누고 각 파트는 한 칸 띄어 작성한다.
```
type: Subject,#footer // 제목

body // 본문(세부 내용)
```
- type: 커밋의 종류를 적는다. type 유형은 아래에 수록.
- Subject: 코드의 수정사항을 50글자 내외로 간략하게 작성한다. 영문으로 작성한다. 한글로 작성하는 건 허용한다. 영문으로 할 땐 명령문의 형태로 쓴다. 특수 문자는 사용하지 않는다. 첫 글자는 대문자로 작성한다.
- footer: 해당 commit이 포함되는 issue 티켓 번호를 작성한다. 본래 Udacity Convention에서는 body 이후에 footer을 작성하였으나, 가독성을 고려하여 변경하였다. 반드시 #number 형태로 첨부해야 한다(해당 이슈로 가는 링크가 생겨 연동할 수 있다). ','로 구분하며 해당 커밋이 해결(resolve)한 이슈를 가장 먼저 적고, 같이 볼 만한 이슈는 ','를 적고 뒤에 적는다.
```
type: Subject,#resolved_issue_number, #see_also_issue_number1, #see_also_issue_number2

body
```
- body: commit의 추가적인 설명이다. Subject에서 간략하게 적었던 내용을 길게 풀어서 작성한다. 한글이든, 영어든 편한 언어로 적도록 한다. Subject로 충분한 의사소통이 가능하다 판단하면 생략할 수 있다. 한 줄 당 72자 내로 작성하며, 최대한 상세히 작성한다.   
해당 내용은 다음을 지켜서 적는다.
```
무엇을 고쳤습니다. (O)
어디를 고쳤습니다. (O)
왜 고쳤습니다. (O)
어떻게 고쳤습니다. (X)
```
type
- feat: 새로운 기능(feature)을 추가한 경우
- fix: 버그를 고친 경우
- docs: 문서를 수정하거나 추가한 경우
- style: 코드 포맷팅, 세미 콜론 누락 수정 같이 코딩 스타일을 정리하거나 오타를 고치는 경우
- refactor: 코드를 [리팩토링](https://nesoy.github.io/articles/2018-05/Refactoring)하는 경우
- test: 테스트 추가, 테스트 리팩토링 (프로덕션 코드는 변경하지 말 것)

##Caution
> type: Subject 와 같이 type에 콜론(':')을 붙여 적는다.
> 커밋 형식을 지켜서 적는 이유는 해당 커밋이 어떤 이슈를 해결하려고 만들었는지 알기 위해서 이슈번호를 적는다. 본문 내용도 그에 맞춰서 적으면 될 것 이다.
> 형식이니만큼 너무 어렵게 생각하지 말고 적을 것을 권장한다.

## Example
1. 실행 파일 UI에 현재 옥타브를 표시하는 기능을 추가한 경우
```
feat: Add Octave status UI, #17, #14

main.c 파일에 옥타브 상태 출력 기능 추가
function.c 파일에 <해당 기능 관련 함수> 추가 (기능 전체 미완성인 경우 일부 함수만 적어도 됨. 기왕이면 함수 모듈 하나는 완성하고 커밋 권장)
설명과 관련된 link 모두 첨부
```
2. 코드 스타일이 통일되지 않은 부분에 대해 리포맷팅할 경우
```
style: Reformatting code indent, #21

코드의 들여쓰기가 각기 다른 방식으로 되어 있어서 통일함.
```
3. 내용이 추가된 것은 없지만, 파일 생성 후 모듈을 분리하고 파일들을 링킹한 경우
```
refactor: Split procedure and function, #33

기존엔 function과 procedure을 구분하지 않았으나 프로그램이 점차 복잡해짐에 따라 절차가 중복되거나 복잡해지는 문제가 발생.
특정 계산을 수행하는 건 function.c로, 특정 작업을 수행하는 모듈은 새로 생성한 procedure.c에 저장함.
```
> 이는 단지 예시일 뿐, Subject와 body 부분은 헷갈린다면 자율적으로 작성한다(형식을 만든 이유가 좀 더 쉽게 커밋을 작성하기 위함인데 주객전도될 필요 없음).
