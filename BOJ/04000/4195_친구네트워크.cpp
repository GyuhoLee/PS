#include <bits/stdc++.h>
using namespace std;

int T, F;
map<string, string> root;
map<string, int> M;

string find(string x)
{
	if (!root.count(x))
	{
		root[x] = x;
		M[x] = 1;
	}
	if (root[x] == x) return x;
	else
	{
		root[x] = find(root[x]);
		return root[x];
	}
}

void merge(string x, string y)
{
	x = find(x);
	y = find(y);
	root[y] = x;
	M[x] += M[y];
}
	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		root.clear();
		cin >> F;
		while (F--)
		{
			string str1, str2;
			cin >> str1 >> str2;
			string temp = find(str1);
			if (temp != find(str2)) merge(temp, str2);
			cout << M[temp] << '\n';
		}
		
	}

	return 0;
}