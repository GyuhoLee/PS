#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//cout.tie(0);

	double score = 0.0;
	string str;
	cin >> str;
	if (str == "F")
	{
		printf("0.0");
		return 0;
	}
	switch (str[0])
	{
	case 'A': score += 4;
		break;
	case 'B': score += 3;
		break;
	case 'C':score += 2;
		break;
	case 'D':score += 1;
		break;
	}
	switch (str[1])
	{
	case '+': score += 0.3;
		break;
	case '-': score -= 0.3;
		break;
	}
	printf("%.1f", score);
	

	return 0;
}