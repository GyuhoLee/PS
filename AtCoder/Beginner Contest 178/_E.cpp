#include <bits/stdc++.h>
#define N 200001
#define SW 1
using namespace std;
typedef long long ll;
ll n, cnt, p1, p2, mx = 0;
const double PI = acos(-1);
struct point {
    ll x, y;
    bool operator<(const point& r)const {
        return x < r.x || (x == r.x && y < r.y);
    }
    ll ccw(point p, point q) { // 벡터 외적
        return (p.x - x) * (q.y - y) - (p.y - y) * (q.x - x);
    }
} a[N], convex[N];
void convexhull() {
    scanf("%lld", &n);
    ll i;
    for (i = 1;i <= n;i++)
        scanf("%lld %lld", &a[i].x, &a[i].y);
    // sort O(nlogn)
    sort(a + 1, a + 1 + n);
    //convexhull O(n)
    // convex에 볼록다각형의 꼭짓점 좌표를 저장한다.
    for (i = 1;i <= n;i++) {
        for (;cnt >= 2 && convex[cnt - 1].ccw(convex[cnt], a[i]) <= 0;--cnt);
        convex[++cnt] = a[i];
    }
    for (p2 = cnt, i = n - 1;i >= 1;--i) {
        for (;cnt >= p2 + 1 && convex[cnt - 1].ccw(convex[cnt], a[i]) <= 0;--cnt);
        convex[++cnt] = a[i];
    }
    // cnt는 볼록 외피 꼭짓점 갯수
    p1 = 1;cnt--;
}
ll cal_dis() {
    // 볼록 다각형 두 점 사이의 거리구하기
    return abs(convex[p1].x - convex[p2].x) + abs(convex[p1].y - convex[p2].y);
}
void rotating_calipers()
{
    ll i;
    ll x1, y1, x2, y2, xx1, yy1, xx2, yy2;
    double cos1, cos2;

    // x1과 y1은 왼쪽 캘리퍼스의 벡터, x2와 y2는 오른쪽 캘리퍼스이 벡터
    x1 = x2 = 0;
    y1 = -1, y2 = 1;
    //p1은 초기에 왼쪽에 있는 캘리퍼스가 볼록다각형의 접해있는 점, p2는 오른쪽에 있는 캘리퍼스가 다각형의 접해있는 점

    for (i = 1;i <= cnt;i++) {
        mx = max(mx, cal_dis());
        //다각형의 변의 벡터인 xx1,yy1,xx2,yy2를 구한다.
        xx1 = (convex[p1 % cnt + 1].x - convex[p1].x);yy1 = (convex[p1 % cnt + 1].y - convex[p1].y);
        xx2 = (convex[p2 % cnt + 1].x - convex[p2].x);yy2 = (convex[p2 % cnt + 1].y - convex[p2].y);

        //벡터의 내적으로 두 벡터 사이각의 코사인을 구한다.
        // 각도는 항상 180도 미만이므로 각이 작을 수록 코사인 값이 크다.
        cos1 = (double)(x1 * xx1 + y1 * yy1) / sqrt(x1 * x1 + y1 * y1) / sqrt(xx1 * xx1 + yy1 * yy1);
        cos2 = (double)(x2 * xx2 + y2 * yy2) / sqrt(x2 * x2 + y2 * y2) / sqrt(xx2 * xx2 + yy2 * yy2);

        if (cos1 > cos2) {// cos의 실수 오차를 없애고 싶으면 양변 제곱해서 통분 하면 된다.

            //왼쪽 캘리퍼스가 볼록 다각형에 접해있는 점(p1)을  반시계로  하나 이동 시키고
            // 다각형 변의 벡터가 캘리퍼스의 벡터가 된다.
            p1 = p1 % cnt + 1;
            x1 = xx1;y1 = yy1;

            // 오른쪽 캘리퍼스는 왼쪽 캘리퍼스와 방향만 반대고 평행
            x2 = -x1;y2 = -y1;
        }
        else {

            //오른쪽 캘리퍼스가 볼록 다각형에 접해있는 점(p2)을  반시계로  하나 이동 시키고
               // 다각형 변의 벡터가 캘리퍼스의 벡터가 된다.
            p2 = p2 % cnt + 1;
            x2 = xx2;y2 = yy2;
            x1 = -x2;y1 = -y2;
        }
    }
    printf("%lld\n", mx);
}
int main() {
    convexhull();
    rotating_calipers();
}