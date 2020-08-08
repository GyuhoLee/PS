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

	int a, b;
	cin >> a >> b;
	string temp;
	if (a < 2) temp = "Before";
	else if (a > 2) temp = "After";
	else
	{
		if (b < 18) temp = "Before";
		else if (b > 18) temp = "After";
		else temp = "Special";
	}
	cout << temp;


	return 0;
}