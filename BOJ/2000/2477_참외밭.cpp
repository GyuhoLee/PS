#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int K;
pair<int, int> arr[6];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> K;
	int idx = -1;
	FUP(i, 0, 5)
	{
		cin >> arr[i].first >> arr[i].second;
		if (idx == -1 && i > 1 && arr[i - 2].first == arr[i].first) idx = i;
	}
	if (idx == 2 && arr[idx - 1].first != arr[idx + 1].first)
	{
		pair<int, int> temp = arr[4];
		pair<int, int> temp2 = arr[5];
		FDOWN(i, 3, 0)
		{
			arr[i + 2] = arr[i];
		}
		arr[0] = temp;
		arr[1] = temp2;
		idx = 3;
	}
	else if (idx == 5)
	{
		pair<int, int> temp = arr[0];
		FUP(i, 0, 4)
		{
			arr[i] = arr[i + 1];
		}
		arr[5] = temp;
		idx = 4;
	}
	else if (idx == -1)
	{
		pair<int, int> temp = arr[4];
		pair<int, int> temp2 = arr[5];
		FDOWN(i, 3, 0)
		{
			arr[i + 2] = arr[i];
		}
		arr[0] = temp;
		arr[1] = temp2;
		idx = 2;
	}
	int total = (arr[idx - 2].second + arr[idx].second) * (arr[idx - 1].second + arr[idx + 1].second);
	total -= (arr[idx].second * arr[idx - 1].second);
	cout << total * K;

	return 0;
}