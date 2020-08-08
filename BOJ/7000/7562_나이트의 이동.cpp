#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x;
	int y;
	int time;

	point()
	{
		time = 0;
	}

	point(int dx, int dy, int dTime)
	{
		x = dx;
		y = dy;
		time = dTime;
	}

	void add(int dx, int dy, int dTime)
	{
		x = dx;
		y = dy;
		time = dTime;
	}

	int search()
	{
		return x * 1000 + y;
	}

	bool operator==(point p)
	{
		if (x == p.x && y == p.y) return true;
		else return false;
	}

	bool operator!=(point p)
	{
		if (x == p.x && y == p.y) return false;
		else return true;
	}
};

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		vector<bool> place(300000, true);
		int l;
		cin >> l;
		vector<point> v;
		point start, goal;
		cin >> start.x >> start.y;
		cin >> goal.x >> goal.y;
		v.push_back(start);
		place[start.search()] = false;
		while (v[0] != goal)
		{
			point temp = v[0];
			point temp2;
			v.erase(v.begin());
			if (temp == goal) break;
			if (temp.x > 1 && temp.y > 0)
			{
				temp2.add(temp.x - 2, temp.y - 1, temp.time + 1);
				if (place[temp2.search()])
				{
					v.push_back(temp2);
					place[temp2.search()] = false;
				}
			}
			if (temp.x > 0 && temp.y > 1)
			{
				temp2.add(temp.x - 1, temp.y - 2, temp.time + 1);
				if (place[temp2.search()])
				{
					v.push_back(temp2);
					place[temp2.search()] = false;
				}
			}
			if (temp.x < l - 1 && temp.y > 1)
			{
				temp2.add(temp.x + 1, temp.y - 2, temp.time + 1);
				if (place[temp2.search()])
				{
					v.push_back(temp2);
					place[temp2.search()] = false;
				}
			}
			if (temp.x < l - 2 && temp.y > 0)
			{
				temp2.add(temp.x + 2, temp.y - 1, temp.time + 1);
				if (place[temp2.search()])
				{
					v.push_back(temp2);
					place[temp2.search()] = false;
				}
			}
			if (temp.x < l - 1 && temp.y < l - 2)
			{
				temp2.add(temp.x + 1, temp.y + 2, temp.time + 1);
				if (place[temp2.search()])
				{
					v.push_back(temp2);
					place[temp2.search()] = false;
				}
			}
			if (temp.x < l - 2 && temp.y < l - 1)
			{
				temp2.add(temp.x + 2, temp.y + 1, temp.time + 1);
				if (place[temp2.search()])
				{
					v.push_back(temp2);
					place[temp2.search()] = false;
				}
			}
			if (temp.x > 0 && temp.y < l - 2)
			{
				temp2.add(temp.x - 1, temp.y + 2, temp.time + 1);
				if (place[temp2.search()])
				{
					v.push_back(temp2);
					place[temp2.search()] = false;
				}
			}
			if (temp.x > 1 && temp.y < l - 1)
			{
				temp2.add(temp.x - 2, temp.y + 1, temp.time + 1);
				if (place[temp2.search()])
				{
					v.push_back(temp2);
					place[temp2.search()] = false;
				}
			}
		}
		cout << v[0].time << endl;
		v.clear();
		place.clear();
	}

	return 0;
}