#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	set<int> S;
	int num;
	cin >> num;
	S.insert(num);
	while (1)
	{
		string str = to_string(num);
		int temp = 0;
		for (char ch : str)
		{
			int tmp = ch - '0';
			temp += (tmp * tmp);
		}
		if (temp == 1)
		{
			cout << "HAPPY";
			break;
		}
		if (S.count(temp))
		{
			cout << "UNHAPPY";
			break;
		}
		num = temp;
		S.insert(temp);
	}

	return 0;
}