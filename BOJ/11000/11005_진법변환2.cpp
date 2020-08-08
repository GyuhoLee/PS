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

	int N, B;
	stack <int> s;
	cin >> N >> B;
	while (N)
	{
		s.push(N % B);
		N /= B;
	}

	while (!s.empty())
	{
		if (s.top() < 10)
		{
			cout << s.top();
		}
		else
		{
			char ch = s.top() - 10 + 'A';
			cout << ch;
		}
		s.pop();
	}

	printf("\n");


	return 0;
}