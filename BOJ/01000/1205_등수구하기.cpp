#include <iostream>
#include <algorithm>
using namespace std;

int arr[50], N, score, P;

int main()
{
	cin >> N >> score >> P;
	arr[P - 1] = -1;
	for (int i = 0; i < N; i++) cin >> arr[i];
	if (arr[P - 1] >= score) cout << -1;
	else
	{
		for (int i = 0; i < P; i++)
		{
			if (arr[i] <= score)
			{
				cout << i + 1;
				break;
			}
		}
	}



	return 0;
}