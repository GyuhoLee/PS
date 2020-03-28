#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[200000];
map<int,int> M;
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	bool ok = false;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (M.count(arr[i]))
		{
			M[arr[i]]++;
			if (M[arr[i]] >= K) ok = true;
		}
		else M[arr[i]] = 1;
	}
	if (ok)
	{
		cout << "0";
		return 0;
	}
	sort(arr, arr + N);



	return 0;
}