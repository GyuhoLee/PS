#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

struct Student
{
	string name;
	int korean, english, math;
};

bool compare(Student a, Student b)
{
	if (a.korean == b.korean)
	{
		if (a.english == b.english)
		{
			if (a.math == b.math)
			{
				return a.name < b.name;
			}
			else return a.math > b.math;
		}
		else return a.english < b.english;
	}
	else return a.korean > b.korean;
}

int N;
vector<Student> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	v.resize(N);
	FUP(i, 0, N - 1)
	{
		CIN(v[i].name);
		CIN3(v[i].korean, v[i].english, v[i].math);
	}
	sort(ALL(v), compare);
	FUP(i, 0, N - 1)
	{
		COUT(v[i].name);
		ENDL;
	}

	return 0;
}