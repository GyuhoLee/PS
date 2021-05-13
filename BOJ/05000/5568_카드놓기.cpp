#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N, K;
string str;
set<string> S;
vector<string> v;

void solve(int cnt, int bit, string ans)
{
	if (cnt == K)
	{
		S.insert(ans);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if ((1 << i) & bit) continue;
		solve(cnt + 1, bit | (1 << i), ans + v[i]);
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		v.push_back(str);
	}
	solve(0, 0, "");
	cout << S.size();

	return 0;
}