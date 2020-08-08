#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long int N;
vector<long long int> arr(1000);

void setting();

int main()
{
	cin >> N;
	setting();
	int i = 1;
	while (N > arr[i])
	{
		i++;
	}
	printf("%d", i);
	return 0;
}

void setting()
{
	long long int two = 2;
	long long int index = 1;
	while (arr[index - 1] <= N)
	{
		two *= 2;
		arr[index] = (index + 1) * (two - 1) + index;
		index++;
	}
}