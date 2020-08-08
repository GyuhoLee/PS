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
	float total = 0;
	int total_num = 0;
	int N;
	cin >> N;
	while (N--)
	{

		float score = 0.0;
		int num;
		string temp, str;
		cin >> temp >> num >> str;
		if (str == "F")
		{
			total_num += num;
			continue;
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
		total_num += num;
		total += (score * num);
	}
	float answer = total / total_num;
	answer += 0.000000000001;
	printf("%.2f", answer);
	

	return 0;
}