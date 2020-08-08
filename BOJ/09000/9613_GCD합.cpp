#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, arr[100];

int GCD(int a, int b) {
    if (a < b) swap(a, b);
    int tmp;
    while (b)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int T;
    CIN(T);
    while (T--)
    {
        ll answer = 0;
        CIN(N);
        FUP(i, 0, N - 1) CIN(arr[i]);
        FUP(i, 0, N - 2)
        {
            FUP(j, i + 1, N - 1)
            {
                answer += GCD(arr[i], arr[j]);
            }
        }
        COUT(answer);
        ENDL;
    }

	return 0;
}