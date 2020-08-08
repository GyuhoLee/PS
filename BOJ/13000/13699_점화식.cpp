#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll T[36];
	memset(T, 0, sizeof(T));
	T[0] = 1;
	for (int i = 1; i <= 35; i++)
	{
		for (int j = 0; j < i; j++)
		{
			T[i] += (T[j] * T[i - j - 1]);
		}
	}
	int N;
	cin >> N;
	cout << T[N];
	

	return 0;
}