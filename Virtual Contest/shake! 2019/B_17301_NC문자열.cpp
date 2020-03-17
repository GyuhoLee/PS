#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define DIV 1000000007

int T;
ll N = 0, C = 0, NC = 0, CN = 0;
ll answer = 1, Left = 1, Right = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	ll temp = 1;
	for (int i = T; i >= 1; i--)
	{
		temp = temp * i % DIV;
		answer = (answer + temp) % DIV;
	}
	while (T--)
	{
		string str;
		cin >> str;
		bool haveN = false;
		bool haveC = false;
		bool isNC = false;
		for (auto s : str)
		{
			if (s == 'N') haveN = true;
			if (s == 'C')
			{
				haveC = true;
				if (haveN) isNC = true;
			}
		}
		if (isNC) NC++;
		else if (haveN && haveC) CN++;
		else if (haveN) N++;
		else C++;
	}
	temp = 1;
	for (int i = C; i >= 1; i--)
	{
		temp = temp * i % DIV;
		Left = (Left + temp) % DIV;
	}
	temp = 1;
	for (int i = N; i >= 1; i--)
	{
		temp = temp * i % DIV;
		Right = (Right + temp) % DIV;
	}
	answer = answer + DIV - (Left * Right % DIV * (CN + 1) % DIV);
	answer %= DIV;
	cout << answer << '\n';

	return 0;
}