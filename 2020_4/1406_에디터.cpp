#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

list<char> L;
int M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str >> M;
	for (auto c : str) L.push_back(c);
	auto iter = L.end();
	while (M--)
	{
		char ch;
		cin >> ch;
		switch (ch)
		{
		case 'L':
			if (iter == L.begin()) break;
			iter--;
			break;
		case 'D':
			if (iter == L.end()) break;
			iter++;
			break;
		case 'B':
			if (iter == L.begin()) break;
			iter--;
			iter = L.erase(iter);
			break;
		case 'P':
			char c;
			cin >> c;
			L.insert(iter, c);
			break;
		}
	}
	for (auto c : L)
	{
		cout << c;
	}

	return 0;
}