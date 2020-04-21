#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool prime[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(prime, true);
	prime[0] = false;
	prime[1] = false;
	for (int i = 4; i <= 1000000; i += 2)
	{
		prime[i] = false;
	}
	for(int i = 3; i < 500000; i += 2)
	{
		if (!prime[i]) continue;
		int num = i * 2;
		while (num <= 1000000)
		{
			prime[num] = false;
			num += i;
		}
	}

	while (1)
	{
		int num;
		cin >> num;
		if (!num) break;
		bool found = false;
		for (int i = 3; i <= num / 2; i += 2)
		{
			if (prime[i] && prime[num - i])
			{
				found = true;
				cout << num << " = " << i << " + " << num - i << '\n';
				break;
			}
		}
		if (!found) cout << "Goldbach's conjecture is wrong.\n";
	}



	return 0;
}