#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;
int T, N;
int g[500001], tg[500001], sa[500001];
int r[500001], lcp[500001];

bool cmp(int a, int b)
{
	if (g[a] == g[b]) return g[a + T] < g[b + T];
	else return g[a] < g[b];
}

void suffix()
{
	T = 1;
	N = str.length();
	for (int i = 0; i < N; i++)
	{
		sa[i] = i;
		g[i] = str[i] - 'a';
	}
	while (T <= N)
	{
		g[N] = -1;
		sort(sa, sa + N, cmp);
		tg[sa[0]] = 0;
		for (int i = 1; i < N; i++)
		{
			if (cmp(sa[i - 1], sa[i])) tg[sa[i]] = tg[sa[i - 1]] + 1;
			else tg[sa[i]] = tg[sa[i - 1]];
		}
		for (int i = 0; i < N; i++) g[i] = tg[i];
		T *= 2;
	}
	for (int i = 0; i < N; i++) cout << sa[i] + 1 << ' ';
	cout << '\n';
}

void LCP()
{
	for (int i = 0; i < N; i++) r[sa[i]] = i;
	int len = 0;
	for (int i = 0; i < N; i++)
	{
		int k = r[i];
		if (k)
		{
			int j = sa[k - 1];
			while (str[j + len] == str[i + len]) len++;
			lcp[k] = len;
			if (len) len--;
		}
	}
	cout << "x";
	for (int i = 1; i < N; i++) cout << ' ' << lcp[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	suffix();
	LCP();

	return 0;
}