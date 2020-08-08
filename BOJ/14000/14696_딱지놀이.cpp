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
	while (N--)
	{
		int arrA[5] = { 0, 0, 0, 0, 0 };
		int arrB[5] = { 0, 0, 0, 0, 0 };
		int A, B;
		cin >> A;
		FUP(i, 1, A)
		{
			int num;
			cin >> num;
			arrA[num]++;
		}
		cin >> B;
		FUP(i, 1, B)
		{
			int num;
			cin >> num;
			arrB[num]++;
		}
		FDOWN(i, 4, 0)
		{
			if (i == 0) cout << "D\n";
			else if (arrA[i] > arrB[i])
			{
				cout << "A\n";
				break;
			}
			else if (arrB[i] > arrA[i])
			{
				cout << "B\n";
				break;
			}
		}
	}

    return 0;
}