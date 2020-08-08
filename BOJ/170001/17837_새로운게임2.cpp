#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Chess
{
	int y, x, d;
	Chess(int yy, int xx, int dd) : y(yy), x(xx), d(dd) {}
};

int N, K;
int arr[12][12];
vector<Chess> piece;
vector<int> chess[12][12];
int answer = 0;
bool found = false;
//¿ìÁÂ»óÇÏ ¤Ñ> ¿ì»óÁÂÇÏ
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

void input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	int yy, xx, dd;
	for (int i = 0; i < K; i++)
	{
		cin >> yy >> xx >> dd;
		switch (dd)
		{
		case 1: dd = 0; break;
		case 2: break;
		case 3: dd = 1; break;
		case 4: dd = 3; break;
		}
		piece.push_back(Chess(yy - 1, xx - 1, dd));
		chess[yy - 1][xx - 1].push_back(i);
	}
}

void solve()
{
	for (int i = 0; i < K; i++)
	{
		int yy = piece[i].y;
		int xx = piece[i].x;
		int ny = yy + dy[piece[i].d];
		int nx = xx + dx[piece[i].d];
		
		int color;
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
		{
			piece[i].d = (piece[i].d + 2) % 4;
			ny = yy + dy[piece[i].d];
			nx = xx + dx[piece[i].d];
			if (arr[ny][nx] == 2) continue;
			color = arr[ny][nx];
		}
		else color = arr[ny][nx];

		if (color == 2)
		{
			piece[i].d = (piece[i].d + 2) % 4;
			ny = yy + dy[piece[i].d];
			nx = xx + dx[piece[i].d];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || arr[ny][nx] == 2) continue;
			color = arr[ny][nx];
		}
		
		vector<int>::iterator num;
		for (auto iter = chess[yy][xx].begin(); iter != chess[yy][xx].end(); iter++)
		{
			if (*iter == i)
			{
				num = iter;
				break;
			}
		}
		if (color == 0)
		{
			for(auto iter = num; iter != chess[yy][xx].end(); iter++)
			{
				chess[ny][nx].push_back(*iter);
				piece[*iter].y = ny;
				piece[*iter].x = nx;
				if (chess[ny][nx].size() == 4)
				{
					found = true;
					return;
				}
			}
			chess[yy][xx].erase(num, chess[yy][xx].end());
		}
		else if (color == 1)
		{
			for (auto iter = chess[yy][xx].rbegin(); iter != chess[yy][xx].rend(); iter++)
			{
				chess[ny][nx].push_back(*iter);
				piece[*iter].y = ny;
				piece[*iter].x = nx;
				if (chess[ny][nx].size() == 4)
				{
					found = true;
					return;
				}
				if (*iter == i)
				{
					break;
				}
			}
			chess[yy][xx].erase(num, chess[yy][xx].end());
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	while (answer <= 1000 && !found)
	{
		solve();
		answer++;
	}
	if (answer > 1000) answer = -1;
	cout << answer;

	return 0;
}