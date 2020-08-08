#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, K;
list<int> L;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	FUP(i, 1, N) L.push_back(i);
	auto iter = L.begin();
	cout << "<";
	while (L.size() > 1)
	{
		FUP(i, 1, K - 1)
		{
			iter++;
			if (iter == L.end()) iter = L.begin();
		}
		cout << *iter << ", ";
		iter = L.erase(iter);
		if (iter == L.end()) iter = L.begin();
	}
	cout << L.front() << ">";



	return 0;
}