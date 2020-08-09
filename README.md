# PS

* 2018년부터의 PS 공부를 정리한 저장소입니다.
  
* 백준 아이디 : [gyuho965][bojid]

* 코드포스 아이디 : [gyuho965][cfid1] , [GyuhoLee][cfid2] (두 개를 번갈아가며 사용중입니다.)

* 메일 : <gyuho965@gmail.com>  (코드 질문 환영합니다.)
  
* 아래부터는 각 폴더에 대한 설명입니다.
<br><br>
--------
### BOJ

* PS 문제들이 모여있는 [백준사이트][boj]에서 풀이한 문제들을 정리해놓은 폴더입니다. 

* 각 문제 번호를 1000으로 나누어 정리하였습니다.

* 2020년 8월 9일에 대대적인 폴더 정리를 하여 커밋 메시지가 초기화되었습니다.

* 주로 C++ 언어를 사용하였습니다.

* Big number 문제, 별찍기류의 문제들은 Python3을 사용하기도 했습니다.

* 가끔 Java 코드가 있기도 합니다.

* 3년동안 쌓아온 폴더이기에 옛날과 지금의 코드 스타일이 많이 다릅니다.

* 최근의 코드 스타일은 최상단에 id를 통해 확인하실 수 있습니다. 

* 아래는 제가 쓰는 코드의 기본 템플릿입니다.

   >  ```c++
   >  #include <bits/stdc++.h>
   >  using namespace std;
   >  #define ll long long int
   >  #define FUP(i, a, b) for(int i = a; i <= b; i++)
   >  #define FDOWN(i, a, b) for(int i = a; i >= b; i--)
   >  #define MS(a, b) memset(a, b, sizeof(a))
   >  #define ALL(v) v.begin(), v.end()
   >  #define CIN(a) cin >> a;
   >  #define CIN2(a, b) cin >> a >> b
   >  #define CIN3(a, b, c) cin >> a >> b >> c
   >  #define COUT(a) cout << a
   >  #define COUT2(a, b) cout << a << ' ' << b
   >  #define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
   >  #define ENDL cout << '\n'
   >  int dy[4] = { -1, 1, 0, 0 };
   >  int dx[4] = { 0, 0, 1, -1 };
   >  
   >  
   >  int main()
   >  {
   >  	ios_base::sync_with_stdio(false);
   >  	cin.tie(0);
   >  	cout.tie(0);
   >  
   >  	// 문제 풀이   
   >  
   >  	return 0;
   >  }
   >  ```

   * 대회를 자주 나가다보니 타이핑을 빠르게 하는 것도 중요하게 생각했습니다.
   
   * 자주 쓰는 문법들을 매크로 함수를 정의하여 사용했습니다.
   
   * 입출력 속도를 stdio 와 동일시 하였습니다.
   
   * 소숫점 자리 출력이나 정수를 한 자리씩 입력 받는 문제에서는 scanf, printf를 사용하기도 합니다.
   
   * dy, dx는 배열에서 상하좌우를 의미합니다.
<br><br>
---------------------
### Codeforce

* 언급하였듯이 두 개의 ID를 번갈아가며 사용중입니다.

  * 두 번 해당 Rating을 달성해야 실력이라고 생각하기 때문입니다.
  
  * Contest는 더 낮은 Rating의 ID로 참여하고 있습니다.
  
* 아래는 Contest의 Commit 예시입니다.

>  <img src="https://user-images.githubusercontent.com/12527673/89731797-ce4e5600-da84-11ea-92e7-0fd5a1cef1a9.png" width="700px" align="left">
>
>  폴더의 이름은 Contest의 이름을 나타냅니다.
>  커밋 메시지는 맞춘 문제수 / 전체 문제수, 등수 / 총 참여 인원 수를 의미합니다.

* 현재는 1900점인 Candidate Master를 목표로 공부하고 있습니다.
<br><br>
--------------------
### Note

* 대회에 나가기 위한 Team Note를 작성중입니다.

* *기울기* 는 공부를 완료하였으나 아직 코드화시키지 않은 알고리즘입니다.

* ~~취소선~~ 은 아직 공부하지 못한 알고리즘입니다.


1. 
<br><br>
-------------------------
### Virtual Contest

* 문제가 공개된 대회 및 코딩 테스트에 참여하여 정리해놓은 폴더입니다.

* 실제 기간에 참여하지 못한 대회는 동일한 시간과 환경에서 진행했습니다.
<br>
##### SHAKE! 2019

>2019년에 진행된  경인지역 6개대학 연합 프로그래밍 경시대회인 SHAKE! 입니다.
>
>2020년 3월 17일에 16시 50분 ~ 20시 50분으로 시간을 정하고 가상으로 대회에 참여했습니다.
>
>문제 목록은 [여기][shake2019]에서 확인할 수 있습니다.
>
>> A  : 17시 01분 solve
>>
>> B :  4 failed, 18시 57분 solve
>>
>> C : 1 failed, 19시 26분 solve
>>
>> F : 2 failed, 17시 48분 solve
>>
>> H : 2 failed, 18시 08분 solve
>
>첫 가상 대회라 그런지 failed를 많이 낸 것이 아쉬웠습니다.
<br>
#####  2019 Winter Kakao Internship Test

> 2020년 3월 28일 [프로그래머스][2019kakao]에서 진행된 2019년 겨울 Kakao 인턴십 코딩 테스트 실전 모의고사입니다.
>
> 500점 만점을 받아 참여자 3025명 중 16등을 하였습니다. (참가자 \#120980입니다.)
>
> 문제는 [여기][2019kakaoproblem]에서 하단 "2019 카카오 개발자 겨울 인턴십" 필터 설정을 통해 볼 수 있습니다.
>

  
<br><br>
-------------

[bojid]: https://www.acmicpc.net/user/gyuho965 "visit"
[cfid1]: https://codeforces.com/profile/gyuho965 "visit"
[cfid2]: https://codeforces.com/profile/GyuhoLee "visit"
[boj]: https://www.acmicpc.net	""visit""
[shake2019]: https://www.acmicpc.net/category/detail/2041 "visit"
[2019kakao]: https://programmers.co.kr/competitions/145/kakao-internship-test "visit"
[2019kakaoproblem]: https://programmers.co.kr/learn/challenges?tab=all_challenges "visit"

