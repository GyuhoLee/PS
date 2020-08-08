#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	int arr[100];
	int temp[100];
	for (int i = 1; i <= N; i++) arr[i] = i;
	while (M--)
	{
		int a, b, m;
		cin >> a >> b >> m;
		int j = a;
		for (int i = m; i <= b; i++) temp[j++] = arr[i];
		for (int i = a; i < m; i++) temp[j++] = arr[i];
		for (int i = a; i <= b; i++) arr[i] = temp[i];
	}
	for (int i = 1; i <= N; i++) cout << arr[i] << ' ';



	return 0;
}