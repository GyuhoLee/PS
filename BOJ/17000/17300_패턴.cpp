#include <bits/stdc++.h>
using namespace std;

int L;
int arr[9];
bool pw[10];
bool ok = true;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(pw, false, sizeof(pw));
	cin >> L;
	for (int i = 0; i < L; i++) cin >> arr[i];
	pw[arr[0]] = true;
	for (int i = 1; i < L; i++)
	{
		if (pw[arr[i]]) ok = false;
		if (arr[i] - arr[i - 1] == 2 && arr[i] % 3 == 0 && !pw[arr[i] - 1]) ok = false;
		if (arr[i] - arr[i - 1] == -2 && arr[i] % 3 == 1 && !pw[arr[i] + 1]) ok = false;
		if (arr[i] - arr[i - 1] == 6 && arr[i] > 6 && !pw[arr[i] - 3]) ok = false;
		if (arr[i] - arr[i - 1] == -6 && arr[i] < 4 && !pw[arr[i] + 3]) ok = false;
		if (arr[i] + arr[i - 1] == 10 && !pw[5]) ok = false;
		pw[arr[i]] = true;
	}
	if (ok) cout << "YES";
	else cout << "NO";

	return 0;
}