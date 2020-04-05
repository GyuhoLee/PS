#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int L, C;
vector<int> v;
vector<char> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> C;
	FUP(i, 1, L) v.push_back(1);
	FUP(i, 1, C - L) v.push_back(0);
	FUP(i, 1, C)
	{
		char ch;
		cin >> ch;
		arr.push_back(ch);
	}
	sort(ALL(arr));
	do
	{
		int ja = 0;
		int mo = 0;
		string str = "";
		FUP (i, 0, C - 1)
		{
			if (v[i])
			{
				str += arr[i];
				if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') mo++;
				else ja++;
			}
		}
		if (ja >= 2 && mo >= 1) cout << str << '\n';

	} while (prev_permutation(ALL(v)));

	return 0;
}