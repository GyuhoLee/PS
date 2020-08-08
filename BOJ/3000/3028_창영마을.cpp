#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

struct Person
{
	string name;
	int D, M, Y;
	Person(string n, int d, int m, int y) :name(n), D(d), M(m), Y(y) {}
};
vector<Person> person;

bool cmp(Person a, Person b)
{
	if (a.Y > b.Y) {
		return true;
	}
	else if (a.Y == b.Y) {
		if (a.M > b.M) {
			return true;
		}
		else if (a.M == b.M) {
			return a.D > b.D;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr[3] = { 1, 0, 0 };
	string str;
	cin >> str;
	for (auto s : str)
	{
		switch (s)
		{
		case 'A': swap(arr[0], arr[1]);
			break;
		case 'B': swap(arr[1], arr[2]);
			break;
		case 'C': swap(arr[0], arr[2]);
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (arr[i]) cout << i + 1;
	}
	


	return 0;
}