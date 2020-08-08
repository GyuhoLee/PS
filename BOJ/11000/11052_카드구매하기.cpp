#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
   int N;
   cin >> N;
   int arr[1001];
   int dp[1001];
   for(int i = 1; i <= N; i++)
   {
   	cin >> arr[i];
    dp[i] = arr[i];
   }
   for(int i = 2; i <= N; i++)
   {
   	for(int j = 1; j < i; j++)
   	{
   		dp[i] = max(dp[i], dp[j] + arr[i - j]);
   	}
   }
   cout << dp[N];
   
    return 0;
}