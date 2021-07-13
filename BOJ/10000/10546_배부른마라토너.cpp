#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> M1, M2;
int N;
string str;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		M1[str]++;
	}
	for (int i = 1; i < N; i++)
	{
		cin >> str;
		M2[str]++;
	}
	for (auto p : M1)
	{
		if (M2.count(p.first) == 0 || p.second != M2[p.first])
		{
			cout << p.first;
			break;
		}
	}

	return 0;
}