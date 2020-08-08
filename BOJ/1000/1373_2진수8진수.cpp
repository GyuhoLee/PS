#include <bits/stdc++.h>
using namespace std;

string N, ans;

void MakeAns(int idx)
{
	if (idx < 0) return;
	MakeAns(idx - 3);
	int temp = 0;
	int val = 1;
	for (int i = 0; i < 3; i++)
	{
		if (idx < 0) break;
		temp += (N[idx] - '0') * val;
		idx--;
		val *= 2;
	}
	char attach = temp + '0';
	ans += attach;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;
	int st = N.size() - 1;
	MakeAns(st);
	cout << ans << '\n';

	return 0;
}