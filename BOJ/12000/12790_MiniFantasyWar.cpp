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

	int T;
	cin >> T;
	while (T--)
	{
		int HP, MP, attack, defence, a, b, c, d;
		cin >> HP >> MP >> attack >> defence >> a >> b >> c >> d;
		HP += a;
		MP += b;
		attack += c;
		defence += d;
		HP = max(HP, 1);
		MP = max(MP, 1);
		attack = max(attack, 0);
		cout << HP + 5 * MP + 2 * attack + 2 * defence << '\n';
	}

	return 0;
}