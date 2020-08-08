#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int arr1[6] = { 500, 300, 200, 50, 30, 10 };
int arr2[5] = { 512, 256, 128, 64, 32 };
vector<int> v1;
vector<int> v2;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	v1.push_back(0);
	FUP(i, 0, 5)
	{
		FUP(j, 0, i)
		{
			v1.push_back(arr1[i]);
		}
	}
	v2.push_back(0);
	int j = 1;
	FUP(i, 0, 4)
	{
		FUP(k, 1, j)
		{
			v2.push_back(arr2[i]);
		}
		j *= 2;
	}
	int T;
	cin >> T;
	while (T--)
	{
		int answer = 0;
		int A, B;
		cin >> A >> B;
		if (A < v1.size()) answer += v1[A];
		if (B < v2.size()) answer += v2[B];
		if (answer == 0) cout << "0\n";
		else cout << answer << "0000\n";
	}
	


	return 0;
}