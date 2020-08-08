#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define MOD 200000

int N, M;
string str, str2;
long long int two[4001];
vector<int> arr[200001];

void input()
{
	cin >> str >> str2;
	N = str.length();
	M = str2.length();
	two[0] = 1;
	for (int i = 1; i <= 4000; i++)
	{
		two[i] = (two[i - 1] * 2) % MOD;
	}
}

void RabinCarp()
{
	int L = N > M ? M : N;
	int low = 0, high = L + 1;
	while (low + 1 < high)
	{
		int mid = (low + high) / 2;
		vector<int> v[MOD];
		long long int num;
		bool found = false;
		for (int i = 0; i <= N - mid; i++)
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
			v[num].push_back(i);
		}
		for (int i = 0; i <= M - mid; i++)
		{
			if (i == 0)
			{
				int temp = 0;
				for (int j = 0; j < mid; j++)
				{
					temp = temp + ((int)str2[j] * two[mid - j - 1]);
					temp %= MOD;
				}
				num = temp;
			}
			else
			{
				num = (num + MOD - ((long long int)str2[i - 1] * two[mid - 1])) * 2 + (long long int)str2[i + mid - 1];
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
						if (str2[i + j] != str[k + j])
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