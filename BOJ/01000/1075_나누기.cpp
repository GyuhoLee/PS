#include <bits/stdc++.h>
using namespace std;

int A, B;
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, F;
	cin >> N >> F;
	N /= 100;
	N *= 100;
	int i;
	for (i = 0; i < 100; i++)
	{
		if ((N + i) % F == 0) break;
	}
	if (i == 0) cout << "00";
	else if (i < 10) cout << "0" << i;
	else cout << i;

	return 0;
}