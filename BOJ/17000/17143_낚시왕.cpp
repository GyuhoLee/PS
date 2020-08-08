#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

struct shark
{
	int y, x;
	int s, d;
	shark(int yy, int xx, int ss, int dd) : y(yy), x(xx), s(ss), d(dd) {}
};

int R, C, M;
int arr[101][101];
map<int, shark> fish;
int human = 0;
int answer = 0;
//»óÇÏ¿ìÁÂ 1234   -> »ó¿ìÇÏÁÂ 0123
int dy[4] = { -1,0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void input()
{
	memset(arr, 0, sizeof(arr));
	cin >> R >> C >> M;
	while (M--)
	{
		int yy, xx, ss, dd, zz;
		cin >> yy >> xx >> ss >> dd >> zz;
		switch (dd)
		{
		case 2: break;
		case 3: dd = 1; break;
		default: dd = dd - 1; break;
		}
		switch (dd)
		{
		case 0:
		case 2:
			ss = ss % ((R - 1) * 2);
			break;
		default:
			ss = ss % ((C - 1) * 2);
		}
		fish.insert(make_pair(zz, shark(yy, xx, ss, dd)));
		arr[yy][xx] = zz;
	}
}

void fishing()
{
	for (int i = 1; i <= R; i++)
	{
		if (arr[i][human])
		{
			answer += arr[i][human];
			fish.erase(arr[i][human]);
			arr[i][human] = 0;
			return;
		}
	}
}

void moving()
{
	memset(arr, 0, sizeof(arr));
	for (auto iter : fish)
	{
		int ny = iter.second.y;
		int nx = iter.second.x;
		for (int i = 0; i < iter.second.s; i++)
		{
			ny = ny + dy[iter.second.d];
			nx = nx + dx[iter.second.d];
			if (ny < 1 || nx < 1 || ny > R || nx > C)
			{
				iter.second.d = fish.find(iter.first)->second.d = (fish.find(iter.first)->second.d + 2 )% 4;
				ny = ny + 2 * dy[iter.second.d];
				nx = nx + 2 * dx[iter.second.d];
			}
		}
		fish.find(iter.first)->second.y = ny;
		fish.find(iter.first)->second.x = nx;
		if (arr[ny][nx])
		{
			fish.erase(arr[ny][nx]);
		}
		arr[ny][nx] = iter.first;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	while (human != C)
	{
		human++;
		fishing();
		moving();
	}
	cout << answer;

	return 0;
}