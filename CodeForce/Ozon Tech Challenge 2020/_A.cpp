#include <bits/stdc++.h>
using namespace std;

int T, N;
int a[100], b[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++) cin >> a[i];
		for (int i = 0; i < N; i++) cin >> b[i];
		sort(a, a + N);
		sort(b, b + N);
		for (int i = 0; i < N; i++) cout << a[i] << ' ';
		cout << '\n';
		for (int i = 0; i < N; i++) cout << b[i] << ' ';
		cout << '\n';
	}



	return 0;
}