#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr[1001];
	arr[1] = 1;
	int num = 2;
	int cnt = 0;
	FUP(i, 2, 1000)
	{
		arr[i] = num;
		cnt++;
		if (cnt == num)
		{
			cnt = 0;
			num++;
		}
	}
	int A, B;
	cin >> A >> B;
	int answer = 0;
	FUP(i, A, B) answer += arr[i];
	cout << answer;

	return 0;
}