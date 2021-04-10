#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	map<string, string> table;
	int N, M;
	cin >> N >> M;
	while (N--)
	{
		string a, b;
		cin >> a >> b;
		table[a] = b;
	}
	while (M--)
	{
		string a;
		cin >> a;
		cout << table[a] << '\n';
	}

	return 0;
}