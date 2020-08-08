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

	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		int arr[100][100];
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) cin >> arr[i][j];
		int answer = 0;
		for (int j = 0; j < M; j++)
		{
			int emt = N - 1;
			for (int i = N - 1; i >= 0; i--)
			{
				if (arr[i][j])
				{
					answer += (emt - i);
					emt--;
				}
			}
		}
		cout << answer << '\n';
	}


	return 0;
}