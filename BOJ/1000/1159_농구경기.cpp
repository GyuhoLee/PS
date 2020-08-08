#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int arr[26];
	memset(arr, 0, sizeof(arr));
	while (N--)
	{
		string str;
		cin >> str;
		arr[str[0] - 'a']++;
	}
	bool found = false;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] >= 5)
		{
			found = true;
			cout << (char)(i + 'a');
		}
	}
	if (!found) cout << "PREDAJA";

	return 0;
}