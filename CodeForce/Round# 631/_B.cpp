#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(i, a, b) for(int i = a; i < b; i++)
#define MS(a, b) memset(a, b, sizeof(a))

int arr[200001];
bool Left[200001];
bool Right[200001];
set<int> S;
set<int> S2;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		v.clear();
		int N;
		cin >> N;
		F(i, 1, N + 1)
		{
			cin >> arr[i];
			Left[i] = false;
			Right[i] = false;
		}
		S.clear();
		S2.clear();
		F(i, 1, N)
		{
			if (S2.count(arr[i])) break;
			S.insert(i);
			S2.insert(arr[i]);
			if (S == S2) Left[i] = true;
		}
		S.clear();
		S2.clear();
		for (int i = N; i >= 1; i--)
		{
			int num = N - i + 1;
			if (S2.count(arr[i])) break;
			S.insert(num);
			S2.insert(arr[i]);
			if (S == S2) Right[num] = true;
		}

		F(i, 1, N)
		{
			if (Left[i] && Right[N - i])
			{
				v.push_back({ i, N - i });
			}
		}
		cout << v.size() << '\n';
		for (auto s : v)
		{
			cout << s.first << ' ' << s.second << '\n';
		}
	}

	return 0;
}