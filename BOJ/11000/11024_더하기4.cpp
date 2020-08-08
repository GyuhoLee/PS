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

	int T;
	cin >> T;
	cin.ignore();
	while (T--)
	{
		string N;
		getline(cin, N);
		string tmp = "";
		int sum = 0;
		FUP (i, 0, N.size() - 1)
		{
			tmp += N[i];
			if (N[i] == ' ' || i == N.size() - 1)
			{
				sum += stoi(tmp);
				tmp = "";
			}
		}
		cout << sum << ENDL;
	}

	return 0;
}