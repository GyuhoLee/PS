# PS

* 2018년부터의 PS 공부를 정리한 저장소입니다.
* 백준 아이디 : [gyuho965][bojid]
* 코드포스 아이디 : [gyuho965][cfid1] , [GyuhoLee][cfid2] (두 개를 번갈아가며 사용중입니다.)
* 앳코더 아이디 : [gyuho965][acid]
* 메일 : <gyuho965@gmail.com> 
* 아래부터는 각 폴더에 대한 설명입니다.

<br><br>
--------

### Awards

🥇 2019 경희대학교 봄 프로그래밍 경시대회 실천상

🥇 2020 브랜디 코드네임B 장려상

🥇 2020 경희대학교 가을 프로그래밍 경시대회 최우수상

<br><br>
---------------------
### BOJ


[![solved.ac tier](http://mazassumnida.wtf/api/generate_badge?boj=gyuho965)](https://solved.ac/gyuho965)


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
   >  #define FUP(i, a, b) for(int i = a; i < b; i++)
   >  #define FDOWN(i, a, b) for(int i = a; i > b; i--)
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
   
   * dy, dx는 인접 행렬에서 상하좌우를 의미합니다.
   
<br><br>
---------------------
### Codeforce

* 언급하였듯이 두 개의 ID를 번갈아가며 사용중입니다.

  * 두 번 해당 Rating을 달성해야 실력이라고 생각하기 때문입니다.
  
  * Contest는 더 낮은 Rating의 ID로 참여하고 있습니다.
  
* 아래는 Contest의 Commit 예시입니다.

>  <img src="https://user-images.githubusercontent.com/12527673/89731797-ce4e5600-da84-11ea-92e7-0fd5a1cef1a9.png" width="700px" align="left"> <br>
>  
>  <br>
>
>  폴더의 이름은 Contest의 이름을 나타냅니다.
>
>  커밋 메시지는 맞춘 문제수 / 전체 문제수, 등수 / 총 참여 인원 수를 의미합니다.

* 현재는 1900점인 Candidate Master를 목표로 공부하고 있습니다.

<br><br>
--------------------
### Virtual Contest

* 문제가 공개된 대회 및 코딩 테스트에 참여하여 정리해놓은 폴더입니다.

* 실제 기간에 참여하지 못한 대회는 동일한 시간과 환경에서 진행했습니다.


<br>

#####  2019 Winter Kakao Internship Test

> 2020년 3월 28일 [프로그래머스][2019kakao]에서 진행된 2019년 겨울 Kakao 인턴십 코딩 테스트 실전 모의고사입니다.
>
> 500점 만점을 받아 참여자 3025명 중 16등을 하였습니다. (참가자 \#120980입니다.)
>
> 문제는 [여기][2019kakaoproblem]에서 하단 "2019 카카오 개발자 겨울 인턴십" 필터 설정을 통해 볼 수 있습니다.
>

<br>

##### 2020 프로그래머스 월간 코드 챌린지 시즌1 9월

>  2020년 진행된 프로그래머스 월간 코드 챌린지 시즌1의 9월 미션입니다.
>
>  [여기][monthly] 에서 해당 챌린지를 확인할 수 있습니다.
>
>  <img src="https://user-images.githubusercontent.com/12527673/92882588-0281b180-f44b-11ea-8e85-c1e94e248f53.png" align="left"> <br> <br>
>
>  <br>
>
>  4944명의 참가자중 28위에 랭크되었습니다.
>

<br>

##### 2020 프로그래머스 월간 코드 챌린지 시즌1 10월

>  2020년 진행된 프로그래머스 월간 코드 챌린지 시즌1의 10월 미션입니다.
>
>  [여기][monthly] 에서 해당 챌린지를 확인할 수 있습니다.
>
>  <img src="https://user-images.githubusercontent.com/12527673/95553467-9e520d80-0a49-11eb-888c-a6805238cf30.png" align="left"> <br> <br>
>
>  <br>
>
>  6196명의 참가자중 22위에 랭크되었습니다.
>

<br>

##### 2020 프로그래머스 월간 코드 챌린지 시즌1 11월

>  2020년 진행된 프로그래머스 월간 코드 챌린지 시즌1의 11월 미션입니다.
>
>  [여기][monthly] 에서 해당 챌린지를 확인할 수 있습니다.
>
>  <img src="https://user-images.githubusercontent.com/12527673/98322837-bf4b5580-202b-11eb-8839-3680e97b82ad.png" align="left"> <br> <br>
>
>  <br>
>
>  6915명의 참가자중 81위에 랭크되었습니다.
>

<br><br>
-------------
### Note

* 대회에 나가기 위한 Team Note를 작성중입니다.

* *기울기* 는 공부를 완료하였으나 아직 코드화시키지 않은 알고리즘입니다.

* ~~취소선~~ 은 아직 공부하지 못한 알고리즘입니다.

* 목차는 KAIST 더불어민규당 팀의 [팀노트](https://github.com/koosaga/DeobureoMinkyuParty)를 참고했습니다.

<br>

#### 1. Search and Sort

   1.1 Binary Search
    
   1.2 Topology Sort
    

#### 2. Shortest Path

   2.1 Dijkstra
    
   2.2 Floyd-Warshall
    
   2.3 Bellman-Ford
    

#### 3. Math

   3.1 Euclidean, Extended Euclidean

   3.2 Sieve of Eratosthenes

   3.3 ~~FFT/NTT~~

   3.4 ~~NTT Polynomial Division~~

   3.5 ~~Kitamasa~~

   3.6 ~~Gaussian Elimination~~

   3.7 ~~Simplex Algorithm~~

   3.8 ~~Pentagonal Number Theorem~~

   3.9 ~~De Bruijn Sequence~~

   3.10 ~~Discrete Kth root~~

   3.11 ~~Miller-Ribin Test + Pollard Rho Factorization~~

   3.12 ~~Highly Composite Numbers, Large Prime~~

#### 4. Flows, Matching

   4.1 ~~Ford-Fulkerson~~

   4.2 ~~MCMF~~

   4.3 ~~Hopcroft-Karp~~

   4.4 ~~Dinic~~

   4.5 ~~Circulation Problem~~

   4.6 ~~Min Cost Circulation~~

   4.7 ~~Gomory-Hu Tree~~

   4.8 ~~Blossom Algorithm~~

#### 5. Graph

   5.1 LCA

   5.2 ~~SCC~~

   5.3 ~~BCC~~

   5.4 ~~2-SAT~~

   5.5 ~~Splay Tree + Link-Cut Tree~~

   5.6 ~~Offline Dynamic MST~~

   5.7 ~~Dominator Tree~~

   5.8 ~~Global Min-Cut~~

   5.9 ~~Edmond's Directed MST~~

   5.10 ~~Vising's Theorem~~

#### 6. String

   6.1 KMP

   6.2 ~~tries~~

   6.3 *Rabin-Karp*

   6.4 *Suffix Array*

   6.5 ~~Manacher~~

   6.6 ~~Aho-Corasick~~

   6.7 ~~EER Tree~~

   6.8 ~~Circular LCS~~

#### 7. Geometry

   7.1 CCW

   7.2 *Flane Sweeping*

   7.3 ~~Sphere~~

   7.4 ~~Smallest Enclosing Circle~~

   7.5 Convex Hull

   7.6 ~~3D Convex Hull~~

   7.7 ~~Half-plane Intersection~~

   7.8 ~~Point-in-polygon~~

   7.9 ~~KD Tree~~

#### 8. Data Structure

   8.1 Union Find

   8.2 ~~Order statistic tree~~

   8.3 ~~Fenwick Tree~~

   8.4 Segment Tree with Lazy Propagation

   8.5 ~~Minium Spanning Tree~~

   8.6 ~~MO's Algorithm~~

   8.6 ~~Sqrt Decomposition~~

   8.7 ~~Centroid decomposition~~

   8.8 ~~HLD~~

   8.9 ~~BBST~~

   8.10 ~~Persistent Segment Tree~~

   8.11 ~~Splay Tree~~

   8.12 ~~Link/Cut Tree~~

<br><br>
-------------------------


[bojid]: https://www.acmicpc.net/user/gyuho965 "visit"

[cfid1]: https://codeforces.com/profile/gyuho965 "visit"

[cfid2]: https://codeforces.com/profile/GyuhoLee "visit"

[acid]: https://atcoder.jp/users/gyuho965 "visit"

[boj]: https://www.acmicpc.net	"visit"

[shake2019]: https://www.acmicpc.net/category/detail/2041 "visit"

[2019kakao]: https://programmers.co.kr/competitions/145/kakao-internship-test "visit"

[2019kakaoproblem]: https://programmers.co.kr/learn/challenges?tab=all_challenges "visit"

[monthly]: https://programmers.co.kr/competitions/417/monthly-code-challenge-s1?utm_source=programmers&utm_medium=learn_competition417&utm_campaign=competition417 "visit"
