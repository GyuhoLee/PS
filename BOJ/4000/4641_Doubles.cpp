#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#include <string.h>
#include <limits.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	bool escape = true;
	vector<int> v;
	while (escape)
	{
		v.clear();
		int temp;
		while (escape)
		{
			cin >> temp;
			if (temp == -1)
			{
				escape = false;
				break;
			}
			if (!temp) break;
			v.push_back(temp);
		}
		if (!escape) break;
		sort(v.begin(), v.end());
		int answer = 0;
		for (int i = 0; i < v.size() - 1; i++)
		{
			for(int j = i + 1; j < v.size(); j++)
			{
				if (v[i] * 2 == v[j]) answer++;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}