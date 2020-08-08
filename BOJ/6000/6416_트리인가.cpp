#include <bits/stdc++.h>
using namespace std;

int T = 1;
bool tree = true;
int u, v;
int root = 0;
int edge = 0;
map<int, int> M;
int num;

int findRoot(int x)
{
	if (M[x] == x) return x;
	if (M[x] == num) return -1;
	else return(findRoot(M[x]));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> u >> v;
		if (u + v < 0) break;
		else if (u + v == 0)
		{
			if ((M.empty()) || (tree && root == 1 && M.size() == edge + 1)) printf("Case %d is a tree.\n", T);
			else printf("Case %d is not a tree.\n", T);

			M.clear();
			tree = true;
			root = 0;
			edge = 0;
			T++;
			continue;
		}
		if (u == v) tree = false;
		edge++;
		if (M.count(v))
		{
			if (M[v] == v)
			{
				root--;
				M[v] = u;
			}
			else tree = false;
		}
		else
		{
			M[v] = u;
			if (!M.count(u))
			{
				M[u] = u;
				root++;
			}
		}
		num = u;
		if (findRoot(u) == -1) tree = false;
	}



	return 0;
}