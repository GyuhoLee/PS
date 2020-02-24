#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, pair<int, int>>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 10000; i++)
	{
		int j = 1;
		while (i * j <= 10000)
		{
			int k = 1;
			while (j * k <= 10000)
			{
				v.push_back(make_pair(i, make_pair(j, k)));
				k++;
			}
			j++;
		}
	}
	cout << v.size();
	int T;
	cin >> T;
	while (T--)
	{
		cout << "a";
	}

}