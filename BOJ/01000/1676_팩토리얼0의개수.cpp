#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int answer = 0;
	for (int i = N; i >= 5; i--)
	{
        if(i % 125 == 0) answer += 3;
		else if (i % 25 == 0) answer += 2;
		else if (i % 5 == 0) answer++;
	}
	printf("%d", answer);

	return 0;
}