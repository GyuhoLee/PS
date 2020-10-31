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

#define SIZE 9999
int prime[SIZE + 1];
int T, S, ans;
bool visited[10000];

void eratosthenes()
{
    FUP(i, 2, SIZE) prime[i] = i;
    FUP(i, 2, sqrt(SIZE))
    {
        // 이미 체크된 수의 배수들은 합성수임이 자명
        if (prime[i] == 0) continue;
        // i를 제외한 i의 배수들을 0으로 체크
        for (int j = i + i;j <= SIZE;j += i) prime[j] = 0;
    }
    FUP(i, 1, 1000) prime[i] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    eratosthenes();
    CIN(T);
    while (T--)
    {
        MS(visited, false);
        CIN2(S, ans);
        queue<pair<int, int>> q;
        q.push({ S, 0 });
        visited[S] = true;
        bool ok = false;
        while (!q.empty())
        {
            int num = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if (num == ans)
            {
                COUT(cnt);
                ENDL;
                ok = true;
                break;
            }
            FUP(i, 0, 9)
            {
                int tmp = num % 1000;
                int tmp2 = i * 1000 + tmp;
                if (prime[tmp2] && !visited[tmp2])
                {
                    q.push({ tmp2, cnt + 1 });
                    visited[tmp2] = true;
                }
                tmp2 = num - tmp;
                tmp = num % 100;
                tmp2 = tmp2 + tmp + i * 100;
                if (prime[tmp2] && !visited[tmp2])
                {
                    q.push({ tmp2, cnt + 1 });
                    visited[tmp2] = true;
                }
                tmp2 = num - tmp + i * 10 + num % 10;
                if (prime[tmp2] && !visited[tmp2])
                {
                    q.push({ tmp2, cnt + 1 });
                    visited[tmp2] = true;
                }
                tmp2 = num / 10 * 10 + i;
                if (prime[tmp2] && !visited[tmp2])
                {
                    q.push({ tmp2, cnt + 1 });
                    visited[tmp2] = true;
                }
            }
        }
        if (!ok) COUT("Impossible\n");
    }

	return 0;
}