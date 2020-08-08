#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//R == 0 // G == 1 // B == 2
vector<vector<int>> arr;
vector<vector<bool>> check;
int count1 = 0;
int count2 = 0;
int N;

void change1(int i, int j);
void change2(int i, int j);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<int> vTemp;
		vector<bool> vTemp2(N, false);
		check.push_back(vTemp2);
		string sTemp;
		cin >> sTemp;
		for (int j = 0; j < N; j++)
		{
			switch (sTemp[j])
			{
			case 'R':
				vTemp.push_back(0);
				break;
			case 'G':
				vTemp.push_back(1);
				break;
			case 'B':
				vTemp.push_back(2);
				break;
			}
		}
		arr.push_back(vTemp);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j])
			{
				check[i][j] = true;
				change1(i,j);
				count1++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check[i][j])
			{
				check[i][j] = false;
				change2(i, j);
				count2++;
			}
		}
	}

	cout << count1 << " " << count2;
	

	return 0;
}

void change1(int i, int j)
{
	bool status[4] = { 0, 0, 0, 0 };
	//상하좌우 ( 1111)

	//상 확인
	if (i)
	{
		if (arr[i - 1][j] == arr[i][j] && !check[i - 1][j])
		{
			check[i - 1][j] = true;
			status[2] = true;
		}
	}

	//좌 확인
	if (j)
	{
		if (arr[i][j] == arr[i][j - 1] && !check[i][j - 1])
		{
			check[i][j - 1] = true;
			status[0] = true;
		}
	}

	//우 확인
	if (j < N - 1)
	{
		if (arr[i][j] == arr[i][j + 1] && !check[i][j + 1])
		{
			check[i][j + 1] = true;
			status[1] = true;
		}
	}

	//하 확인
	if (i < N - 1)
	{
		if (arr[i + 1][j] == arr[i][j] && !check[i + 1][j])
		{
			check[i + 1][j] = true;
			status[3] = true;
			change1(i + 1, j);
		}
	}
	if (j < N - 1 && status[1]) change1(i, j + 1);
	if (i && status[2]) change1(i - 1, j);
	if (j && status[0]) change1(i, j - 1);

}

void change2(int i, int j)
{
	bool status[4] = { 0, 0, 0, 0 };
	//상하좌우 ( 1111)

	//상 확인
	if (i)
	{
		if (arr[i - 1][j] / 2 == arr[i][j] / 2 && check[i - 1][j])
		{
			check[i - 1][j] = false;
			status[2] = true;
		}
	}

	//좌 확인
	if (j)
	{
		if (arr[i][j] / 2 == arr[i][j - 1] / 2 && check[i][j - 1])
		{
			check[i][j - 1] = false;
			status[0] = true;
		}
	}

	//우 확인
	if (j < N - 1)
	{
		if (arr[i][j] / 2 == arr[i][j + 1] / 2 && check[i][j + 1])
		{
			check[i][j + 1] = false;
			status[1] = true;
		}
	}

	//하 확인
	if (i < N - 1)
	{
		if (arr[i + 1][j] / 2 == arr[i][j] / 2 && check[i + 1][j])
		{
			check[i + 1][j] = false;
			status[3] = true;
			change2(i + 1, j);
		}
	}
	if (j < N - 1 && status[1]) change2(i, j + 1);
	if (i && status[2]) change2(i - 1, j);
	if (j && status[0]) change2(i, j - 1);

}