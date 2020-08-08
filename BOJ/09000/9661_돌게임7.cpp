#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll N;
	cin >> N;
	if (N % 5 == 2 || N % 5 == 0) cout << "CY";
	else cout << "SK";

	return 0;
}