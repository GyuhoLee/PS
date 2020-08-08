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
	cout.tie(0);

	string str, answer;
	getline(cin, str);
	int happy = 0, sad = 0;
	int status = 0;
	for (char ch : str)
	{
		if (ch == ':') status = 1;
		else if (ch == '-' && status == 1) status = 2;
		else if (ch == ')' && status == 2) happy++;
		else if (ch == '(' && status == 2) sad++;
		else status = 0;
	}
	if (!happy && !sad) answer = "none";
	else if (happy > sad) answer = "happy";
	else if (sad > happy) answer = "sad";
	else answer = "unsure";
	cout << answer;

	return 0;
}