#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	string str;
	cin >> str;

    int cnt = 1;
    bool L = true;
    for (int i = 0; i < str.length(); i++)

        if (str[i] == 'S') cnt++;
        else
        {
            L = !L;
            if (L) cnt++;
        }

    cout << min(cnt, N) << "\n";

    return 0;
}