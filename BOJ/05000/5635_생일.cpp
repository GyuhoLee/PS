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

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string a;
		int d, m, y;
		cin >> a >> d >> m >> y;
		person.push_back(Person(a, d, m, y));
	}
	sort(person.begin(), person.end(), cmp);
	cout << person.front().name << '\n' << person.back().name;
	


	return 0;
}