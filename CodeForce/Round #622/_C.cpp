#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int arr[1000];
	int left[1000];
	int right[1000];
	memset(left, 0, sizeof(left));
	memset(right, 0, sizeof(right));
	for (int i = 0; i < N; i++) cin >> arr[i];
	int answer = 0;
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = arr[i];
		left[i] = arr[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (temp > arr[j]) temp = arr[j];
			left[i] += temp;
		}
		temp = arr[i];
		for (int j = i + 1; j < N; j++)
		{
			if (temp > arr[j]) temp = arr[j];
			right[i] += temp;
		}
		if (answer < left[i] + right[i])
		{
			answer = left[i] + right[i];
			idx = i;
		}
	}
	int arr2[1000];
	arr2[idx] = arr[idx];
	int temp = arr[idx];
	for (int j = idx - 1; j >= 0; j--)
	{
		if (temp > arr[j]) temp = arr[j];
		arr2[j] = temp;
	}
	temp = arr[idx];
	for (int j = idx + 1; j < N; j++)
	{
		if (temp > arr[j]) temp = arr[j];
		arr2[j] = temp;
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr2[i] << ' ';
	}
	
	

	return 0;
}