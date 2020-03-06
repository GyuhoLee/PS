#include <bits/stdc++.h>
using namespace std;

int A, B;
bool visited[10000];
queue<pair<int, string>> q;

void D(int num, string str)
{
	int temp = num * 2;
	temp %= 10000;
	if (visited[temp]) return;
	q.push({ temp, str + 'D' });
	visited[temp] = true;
}

void S(int num, string str)
{
	int temp = (num + 9999) % 10000;
	if (visited[temp]) return;
	q.push({ temp, str + 'S' });
	visited[temp] = true;
}

void L(int num, string str)
{
	int temp = num / 1000;
	num *= 10;
	num %= 10000;
	num += temp;
	if (visited[num]) return;
	q.push({ num, str + 'L' });
	visited[num] = true;
}

void R(int num, string str)
{
	int temp = num % 10;
	num /= 10;
	num += (temp * 1000);
	if (visited[num]) return;
	q.push({ num, str + 'R' });
	visited[num] = true;
}

void BFS()
{
	memset(visited, 0, sizeof(visited));
	while (!q.empty()) q.pop();
	q.push({ A, "" });
	visited[A] = true;
	while (!q.empty())
	{
		int num = q.front().first;
		string str = q.front().second;
		if (num == B)
		{
			cout << str << '\n';
			return;
		}
		q.pop();
		D(num, str);
		S(num, str);
		L(num, str);
		R(num, str);
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
		cin >> A >> B;
		BFS();
	}

	return 0;
}