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
	int arr[200][3];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}
	for (int j = 0; j < 3; j++)
	{
	    int visited[101];
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++) visited[arr[i][j]]++;
		for (int i = 0; i < N; i++)
		{
			if (visited[arr[i][j]] > 1) arr[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) cout << arr[i][0] + arr[i][1] + arr[i][2] << '\n';


	return 0;
}