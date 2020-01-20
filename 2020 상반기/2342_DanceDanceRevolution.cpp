#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int num = 1;	//그냥 입력받을 변수
int cnt = 0;	//발판을 누른 갯수 카운팅
int arr[100001][5][5];	//i번째상태에서, j와 k는 각 발의 상태. 값을 가지는 경우 그 상태가 존재
int answer = 1000000;

void input()
{
	scanf_s("%d", &num);
}

void DP()
{
	//처음 입력은 무조건 발 하나를 가운데에서 옮겨야 됨.(2)
	if (cnt == 1)	
	{
		arr[1][num][0] = 2;
		return;
	}


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)	//모든 발 상태 확인
		{
			if (arr[cnt - 1][i][j])	// 직전에 발 상태가 존재하는 경우,
			{
				if (i == num || j == num)	//만약 그 전에 한 발이라도 들어온 값을 밟고 있다면, 발 상태는 변하지 않고 힘 1만 더해주면 된다.
				{
					//if else문을 써준 이유는, 직전의 다른 발 상태에서 똑같이 이번 발 상태가 될 수 있으므로, 두 개중 최솟값으로 정해줘야된다. 
					if (!arr[cnt][i][j]) arr[cnt][i][j] = arr[cnt - 1][i][j] + 1;
					else arr[cnt][i][j] = min(arr[cnt][i][j], arr[cnt - 1][i][j] + 1);
				}
				else
				{
					//위 if else문은 j를 옮기는 것.
					if (!j) // j가 초기 상태(0)이면 무조건 힘은 2이다.
					{
						arr[cnt][i][num] = arr[cnt - 1][i][j] + 2;
					}
					else 
					{
						int temp = (abs(j - num) == 2) ? 4 : 3; // 발판이 서로 마주보고 있으면, 차이는 2이다.

						//if else문을 써준 이유는, 직전의 다른 발 상태에서 똑같이 이번 발 상태가 될 수 있으므로, 두 개중 최솟값으로 정해줘야된다.
						if (!arr[cnt][i][num]) arr[cnt][i][num] = arr[cnt - 1][i][j] + temp;
						else arr[cnt][i][num] = min(arr[cnt][i][num], arr[cnt - 1][i][j] + temp);
					}

					//이것은 i를 옮기는 것.
					int temp2 = (abs(i - num) == 2) ? 4 : 3;	// 발판이 서로 마주보고 있으면, 차이는 2이다.

					//if else문을 써준 이유는, 직전의 다른 발 상태에서 똑같이 이번 발 상태가 될 수 있으므로, 두 개중 최솟값으로 정해줘야된다.
					if (!arr[cnt][num][j]) arr[cnt][num][j] = arr[cnt - 1][i][j] + temp2;
					else arr[cnt][num][j] = min(arr[cnt][num][j], arr[cnt - 1][i][j] + temp2);
				}
			}
		}
	}
}

void find()
{
	//바로 0을 입력받은 경우.
	if (cnt == 1)
	{
		answer = 0;
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[cnt - 1][i][j])	//0이 아닌 경우에만
			{
				answer = min(arr[cnt - 1][i][j], answer);	//모든 발 상태를 확인.
			}
		}
	}
}

int main()
{
	while (num)
	{
		input();
		cnt++;
		DP();
	}
	find();
	printf("%d", answer);

	return 0;
}