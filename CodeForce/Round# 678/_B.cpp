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

#define SIZE 3000
int arr[SIZE + 1];

void eratosthenes()
{
    arr[1] = 0;
    FUP(i, 2, SIZE) arr[i] = i;
    FUP(i, 2, sqrt(SIZE))
    {
        // 이미 체크된 수의 배수들은 합성수임이 자명
        if (arr[i] == 0) continue;
        // i를 제외한 i의 배수들을 0으로 체크
        for (int j = i + i;j <= SIZE;j += i) arr[j] = 0;
    }
}

int T, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    eratosthenes();
    CIN(T);
    while (T--)
    {
        CIN(N);
        int num = 0;
        FUP(i, 1, 2500)
        {
            if (arr[i] == 0 && arr[i + N - 1] != 0)
            {
                num = i;
                break;
            }
        }
        FUP(i, 0, N - 1)
        {
            FUP(j, 0, N - 1)
            {
                if (i == j) COUT2(num, "");
                else COUT("1 ");
            }
            ENDL;
        }
    }

	return 0;
}