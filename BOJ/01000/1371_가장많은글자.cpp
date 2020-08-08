#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int arr[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(arr, 0);
	string str;
	while (cin >> str) 
	{
		for (int i = 0; i < str.size(); i++) 
		{
			if (str[i] >= 'a' && str[i] <= 'z') arr[str[i] - 'a']++;
		}
		str.clear();
	}
	int answer = 0;
	for (int i = 0; i < 26; i++) answer = max(answer, arr[i]);

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == answer)
		{
			char temp = 'a' + i;
			cout << temp;
		}
	}
	return 0;
}