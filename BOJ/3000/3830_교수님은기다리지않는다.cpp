#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int N, M;
int arr[100001];
long long int num[100001];

int update(int x)
{
	if (arr[x] == x) return x;
	int R = update(arr[x]);
	num[x] += num[arr[x]];
	arr[x] = R;
	return arr[x];
}

void merge(int a, int b, int w)
{
	int pA = arr[a];
	int pB = arr[b];
	if (pA == pB) return;
	arr[pB] = pA;
	num[pB] = num[a] + w - num[b];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> N >> M;
		if (!(N + M)) break;
		for (int i = 1; i <= N; i++)
		{
			arr[i] = i;
			num[i] = 0;
		}
		while (M--)
		{
			char c;
			int a, b, w;
			cin >> c >> a >> b;
			update(a);
			update(b);
			if (c == '!')
			{
				cin >> w;
				merge(a, b, w);
			}
			else
			{
				if (arr[a] == arr[b]) cout << num[b] - num[a] << '\n';
				else cout << "UNKNOWN\n";
			}
		}
	}

	return 0;
}