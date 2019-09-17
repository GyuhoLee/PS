#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int min_count = 100000;
int N, K;
vector<int> arr(100001, 100000);

void answer(int now, int count, int status);
//status 0 : 3개다 봄, 1: -1하지말기, 2: +1하지말기

int main()
{
	cin >> N >> K;
	if (N == 0)
	{
		N++;
		answer(N, 1, 2);
	}
	else
	{
		answer(N, 0, 0);
	}

	cout << min_count;
	return 0;
}

void answer(int now, int count, int status)
{
	if (arr[now] <= count ) return;
	arr[now] = count;
	if (K == now)
	{
		if (count < min_count) min_count = count;
		return;
	}
	else if (K < now)
	{
		count = count + now - K;
		if (count < min_count) min_count = count;
		return;
	}
	else if(now == 0 || count >= min_count)
	{
		return;
	}
	else
	{
		count++;
		switch (status)
		{
		case 0:
			if(now <= 50000) answer(2 * now, count, 0);
			if (now < 100000) answer(now + 1, count, 1);
			answer(now - 1, count, 2);
			break;
		case 1:
			if (now <= 50000) answer(2 * now, count, 0);
			if (now < 100000) answer(now + 1, count, 1);
			break;
		case 2:
			if (now <= 50000) answer(2 * now, count, 0);
			answer(now - 1, count, 2);
		}
		

	}
}