#include <bits/stdc++.h>
using namespace std;

int N, K;
string key, temp;
char password[10][10];
pair<char, int> P[10];
int cnt[10];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> key;
	K = key.length();
	cin >> temp;
	for (int i = 0; i < K; i++)
	{
		P[i].first = key[i];
		P[i].second = i;
	}
	sort(P, P + K);
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < K; j++)
		{
			if (P[j].second == i) cnt[i] = j;
		}
	}
	N = temp.length() / K;
	int idx = 0;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			password[j][i] = temp[idx];
			idx++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << password[i][cnt[j]];
		}
	}



	return 0;
}