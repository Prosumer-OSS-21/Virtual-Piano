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

# Branch Naming Convention

## Introduction
우리 팀은 `Git flow branch naming convention`을 따르기로 했다.
Git flow는 실제 개발 팀에서도 자주 사용하는 전략이다. [우아한 형제들 블로그](https://techblog.woowahan.com/2553/)
다만 우리 팀에서 아직 버전 관리에 미숙한 사람도 있고 당장 배포하면서 수정할 필요가 없어 브랜치 이름만 가져오기로 했다. 개발이 완성되었을 때 배포해도 되기 때문이다.

## Branch Structure
브랜치의 전체적인 구조는 타입과 이슈 티켓번호로 이루어져 있다.

```
type/#issue number
```

__type__
- main : 제품으로 출시될 수 있는 브랜치, 배포(Release) 버전의 소스가 들어있다.
- feature : 기능을 개발할 때 따는 브랜치
- docs : 문서를 수정하거나 추가하는 브랜치
- style : 코드 포맷 변경, 세미 콜론 누락 등 자잘한 코드 수정을 하는 브랜치
- refactor : 새로운 기능이나 버그 수정없이 현재 구현을 개선한 브랜치
- test : 테스트 추가, 테스트 리팩토링(프로덕션 코드 변경X)
- hotfix : 출시 버전에서 발생한 버그를 수정하는 브랜치, main branch의 오류사항을 수정하는 브랜치
- composition : 웹페이지 화면의 구성을 변경할 경우(레이아웃, 배경 색 등)

## Caution
- 브랜치 생성 전에 issue를 생성하고 티켓번호를 얻는다.
- 제목과 이슈의 티켓번호 사이에는 `/`를 항상 붙인다.
- merge한 branch는 바로바로 삭제해준다.
- main 브랜치엔 티켓번호를 붙이지 않는다.

## Example
>티켓번호는 예시이고 다를 수 있다.

1. 새로운 문서를 추가하는 브랜치
```
docs/#9
```

2. 새로운 기능 혹은 내용을 변경하는 브랜치
```
feature/#2
```

3. 웹페이지 구성을 변경하는 브랜치
```
composition/#24
```

4. 출시 전에 버그를 수정하는 브랜치
```
hotfix/#1
```

# Issue Naming Convention

## Introduction
프로젝트를 진행할 때 어떠한 새로운 수정사항이 생기면 issue를 만들고 시작한다. 따라서 issue는 해당 수정사항을 나타내는 지표가 된다. 해당 네이밍 컨벤션은 Udacity Commit Message Style에서 Issue convention에 맞게 형식을 구성하였다.

## Name Structure
이름의 구조는 commit message의 제목 부분과 유사하다. type이 [] 내에 위치해있고, 그 뒤로 subject를 작성한다.

```
[type] Subject
```

- type : 어떤 종류의 issue인지를 명시한다. commit message convention에서의 type 종류에서 issue 만의 특성을 고려하여 추가하거나 삭제하였다. 아래에 구체적인 type의 종류가 나와있으니 참고하여 작성한다. 이는 반드시 []내에 적도록 한다.
- Subject : 해당 issue에서 수정할 사항을 간략하게 명시한다. 글자수는 50글자가 넘어가지 않도록 하며, 한글 또는 영어로 작성한다. 영어로 작성할 경우에는 명령문의 형태로 하며, 첫 글자는 대문자로 한다.

__type__
- feat : 새로운 기능을 추가할 경우, 웹페이지에 새로운 내용을 추가할 경우
- composition : 웹페이지 화면의 구성을 변경할 경우 (레이아웃, 배경 색 등)
- fix : 버그를 고치는 것이 목적인 경우
- docs : 문서화 진행 중인 문서를 수정하거나 추가할 경우
- offer : 프로젝트 관련하여 어떠한 사항을 제안하고 싶을 경우
- refactor : 코드 포맷 변경, 세미 콜론 누락 등 자잘한 코드를 수정, 새로운 기능이나 버그 수정없이 현재 구현을 개선하고자 할 경우
- test : 테스트 추가, 테스트 리팩토링(프로덕션 코드 변경 X)을 할 목적인 경우

## Caution
> issue name에는 수정사항을 간략하게 적지만, 실제 issue 내용을 적는 부분(본문)에서는 구체적으로 작성한다. 예컨대 다음과 같은 내용이 들어가야 한다.
- 어떠한 이유로 해당 issue를 생성하였는지
- 해당 issue에서는 어떤 내용을 수정할 것인지

> issue naming 에서의 type은 단순히 issue를 생성할 때 코드에서 수정하고자 하는 부분의 목적을 명시하는 역할이다. 만약 feat type의 issue를 생성하였다면, 이 issue에 따르는 commit 가운데 feat type이 commit이 존재할 수 있다. 웹사이트에 새로운 내용을 추가하려고 feat type으로 issue를 생성한 뒤 코드를 수정하다가 오류가 발견되어 fix type의 commit을 해당 issue에 추가하여도 된다. issue의 type과 commit의 type은 아무런 상관이 없다. 이를 헷갈리지 말아야 한다.

> commit과 달리 issue는 제안(offer)하는 경우가 있으므로, offer type을 추가하였고, 웹페이지에 내용을 추가하는 issue와 화면 구성을 변경하는 issue가 구분되어 있는 것을 고려하여, feat type 외에 composition type을 추가하였다.

> issue의 특성상 commit에서의 style이나 refactor과 같은 type은 잘 사용될 일이 없을 수도 있다. 하지만 만약을 대비하여 모든 경우에 type 종류를 정해놓기 위해 두 가지를 합쳐 refactor type을 정해놓았다.

## Example
1. 웹페이지에서 Branches라는 부분에 내용을 추가하고자 하는 경우
```
[refactor] midi_open 함수 구조 변형 -> 제목

목적 :
midi_open함수에서 콜백 함수를 제거해도 동일 동작을 수행하도록 코드를 짠다.
콜백 함수는 아직 배우지 않은 함수이고 우리 수준에서 수정이 가능하도록 만들 필요가 있으므로 제거한다.
```

2. 여러가지 프로젝트의 convention을 문서로 정리하는 경우
```
[docs] convention 문서화 -> 제목

목적 :
프로젝트를 진행하며 생기는 convention을 하나의 문서로 정리한다.
commit message convention에 대해서 우선 .md 확장자 파일로 작성토록 한다. -> 본문
```

# Coding Style Convention
## Introduction
사람마다 변수 이름을 선언하는 방법, 들여쓰기를 하는 방법이 다 다르다. 우리 팀은 스타일이 다르면 혼란이 생길 거라 예측했다. 따라서 코딩 스타일을 정했고 다음에 기재한다.

## Indentation

들여쓰기의 경우 K&R 방식, ALLMAN 방식이 있는데 우리는 그 중 ALLMAN 방식을 쓰기로 했다. 코드 블록을 구분짓기 쉽고, 주석 처리할 때 깔끔하기 때문이다.

## Variable & Function

변수와 함수 이름은 snake 스타일을 사용하기로 했다. 글자가 조금 길어지기는 하나 ( _ ) 가 띄어쓰기처럼 보여서 가독성이 훨씬 좋기 때문이다.

## Example
1. 들여쓰기
```
if(condion)
{
    body
}
```
2. 변수 & 함수
```
char word_list[10];

function_one(condition)
{
    body of the function
}
```

