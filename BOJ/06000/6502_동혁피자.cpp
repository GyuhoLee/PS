#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int count = 1;
    while (true)
    {
        int r, w, l;
        cin >> r;
        if (r == 0)  break;
        cin >> w >> l;
        double cand = pow(w, 2) + pow(l, 2);
        cout << "Pizza " << count << " ";
        if (!(r * 2 >= sqrt(cand)))
            cout << "does not fit on the table." << ENDL;
        else
            cout << "fits on the table." << ENDL;
        count++;
    }

	return 0;
}