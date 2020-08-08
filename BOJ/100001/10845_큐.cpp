#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	queue<int> arr;
	int N;
	cin >> N;
	while (N--)
	{
		string temp;
		cin >> temp;
		int temp2;
		if (temp == "push")
		{
			cin >> temp2;
			arr.push(temp2);
		}
		else if (temp == "pop")
		{
			if (arr.empty()) temp2 = -1;
			else
			{
				temp2 = arr.front();
				arr.pop();
			}
			printf("%d\n", temp2);
		}
		else if (temp == "size") printf("%d\n", arr.size());
		else if (temp == "empty")
		{
			if (arr.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (temp == "front")
		{
			if (arr.empty()) printf("-1\n");
			else printf("%d\n", arr.front());
		}
		else if (temp == "back")
		{
			if (arr.empty()) printf("-1\n");
			else printf("%d\n", arr.back());
		}
	}

	return 0;
}