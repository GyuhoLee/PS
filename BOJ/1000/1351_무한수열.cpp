#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

long long int N, P, Q;
map<long long int, long long int> arr;


long long int solve(long long int num)
{
	if (arr.count(num))
	{
		return arr[num];
	}
	arr[num] = solve(num / P) + solve(num / Q);
	return arr[num];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> P >> Q;
	arr[0] = 1;
	printf("%lld", solve(N));
}