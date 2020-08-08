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

	string str;
	int N;
	cin >> str >> N;
	int num = 1;
	int answer = 0;
	FDOWN(i, str.size() - 1, 0)
	{
		int temp;
		if (str[i] >= '0' && str[i] <= '9')
		{
			temp = str[i] - '0';
		}
		else
		{
			temp = str[i] - 'A' + 10;
		}
		answer += (temp * num);
		num *= N;
	}
	cout << answer;


	return 0;
}