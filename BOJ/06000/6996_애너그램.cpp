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

	int T;
	cin >> T;
	while (T--)
	{
		string A, B;
		cin >> A >> B;
		int a[26], b[26];
		MS(a, 0);
		MS(b, 0);
		for (char ch : A) a[ch - 'a']++;
		for (char ch : B) b[ch - 'a']++;
		bool same = true;
		FUP(i, 0, 25)
		{
			if (a[i] != b[i])
			{
				same = false;
				break;
			}
		}
		if (same) cout << A << " & " << B << " are anagrams.\n";
		else cout << A << " & " << B << " are NOT anagrams.\n";
	}

    return 0;
}