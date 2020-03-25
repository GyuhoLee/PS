#include <bits/stdc++.h>
using namespace std;
#define y first
#define x second

int N, M, K;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
string answer = "";
pair<int, int> arr[200];
int yy = 0, xx = 0;

struct Node
{
	int sy, sx, ey, ex;
};

Node node[200];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> node[i].sy >> node[i].sx;
	}
	for (int i = 0; i < K; i++)
	{
		cin >> node[i].ey >> node[i].ex;
		arr[i].y = node[i].ey - node[i].sy;
		arr[i].x = node[i].ex - node[i].sx;
	}
	sort(arr, arr + K);
	for (int i = 0; i < K; i++)
	{
		if (arr[i].y - yy < 0)
		{
			for (int j = 0; j < -(arr[i].y - yy); j++)
				answer += "U";
		}
		else
		{
			for (int j = 0; j < (arr[i].y - yy); j++)
				answer += "D";
		}
		yy = arr[i].y;
		if (arr[i].x - xx < 0)
		{
			for (int j = 0; j < -(arr[i].x - xx); j++)
				answer += "L";
		}
		else
		{
			for (int j = 0; j < (arr[i].x - xx); j++)
				answer += "R";
		}
		xx = arr[i].x;
	}
	cout << answer.size() << '\n' << answer;




	return 0;
}