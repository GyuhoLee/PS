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

	int T = 100;
	while (T--)
	{
		string str;
		getline(cin, str);
		if (str.length() == 0) break;
		int arr[4] = { 0, 0, 0, 0 };
		for (auto s : str)
		{
			if (s >= 'a' && s <= 'z')
			{
				arr[0]++;
			}
			else if (s >= 'A' && s <= 'Z')
			{
				arr[1]++;
			}
			else if (s == ' ') arr[3]++;
			else arr[2]++;
		}
		FUP(i, 0, 3) cout << arr[i] << ' ';
		cout << '\n';
	}
	return 0;
}