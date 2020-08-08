#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

#define size 100000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    
    string strA, strB;
    int A[size], B[size];

    cin >> strA >> strB;
    FUP(i, 0, size - 1)
    {
        A[i] = strA[i] - '0';
        B[i] = strB[i] - '0';
    }

    FUP(i, 0, size - 1)
        cout << (A[i] && B[i]);
    cout << '\n';

    FUP(i, 0, size - 1)
        cout << (A[i] || B[i]);
    cout << '\n';

    FUP(i, 0, size - 1)
        cout << (A[i] != B[i]);
    cout << '\n';

    FUP(i, 0, size - 1)
        cout << !A[i];
    cout << '\n';

    FUP(i, 0, size - 1)
        cout << !B[i];
    cout << '\n';


	return 0;
}