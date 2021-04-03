#include <iostream>
using namespace std;
#define ll long long int

ll T, d, n, s, p;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> d >> n >> s >> p;
		s *= n;
		p *= n;
		p += d;
		if (s > p) cout << "parallelize\n";
		else if (s < p) cout << "do not parallelize\n";
		else cout << "does not matter\n";
	}

	return 0;
}