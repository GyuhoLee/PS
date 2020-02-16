#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define MOD 200000

int L;
string str;
long long int two[200001];
vector<int> arr[200001];

void input()
{
	cin >> str;
	L = str.length();
	two[0] = 1;
	for (int i = 1; i <= 200000; i++)
	{
		two[i] = (two[i - 1] * 2) % MOD;
	}
}

void RabinCarp()
{
	int low = 0, high = L;
	while (low + 1 < high)
	{
		int mid = (low + high) / 2;
		vector<int> v[MOD];
		long long int num;
		bool found = false;
		for (int i = 0; i <= L - mid; i++)
		{
			if (i == 0)
			{
				int temp = 0;
				for (int j = 0; j < mid; j++)
				{
					temp = temp + ((int)str[j] * two[mid - j - 1]);
					temp %= MOD;
				}
				num = temp;
			}
			else
			{
				num = (num + MOD - ((long long int)str[i - 1] * two[mid - 1])) * 2 + (long long int)str[i + mid - 1];
				if (num < 0)
				{
					num = MOD - (-num % MOD);
				}
				num %= MOD;
			}
			if (!v[num].empty())
			{
				for (auto k : v[num])
				{
					bool same = true;
					for (int j = 0; j < mid; j++)
					{
						if (str[i + j] != str[k + j])
						{
							same = false;
							break;
						}
					}
					if (same)
					{
						found = true;
						break;
					}
				}
			}
			if (found) break;
			v[num].push_back(i);
		}
		if (found) low = mid;
		else high = mid;
	}
	cout << low;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	RabinCarp();

	return 0;
}