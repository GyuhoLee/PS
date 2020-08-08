#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int arr[2000000];
int front = 0;
int back = 0;

int main()
{
    ios::sync_with_stdio(true);
    cin.tie(NULL);
	scanf("%d", &N);
	while (N--)
	{
		string temp;
		cin >> temp;
		if (!temp.compare("push"))
		{
			int num;
			scanf("%d", &num);
			arr[back] = num;
			back++;
		}
		else if (!temp.compare("pop"))
		{
			if (back - front == 0)
			{
				printf("-1\n");
				continue;
			}
			printf("%d\n", arr[front]);
			front++;
		}
		else if (!temp.compare("size"))
		{
			printf("%d\n", back - front);
		}
		else if (!temp.compare("empty"))
		{
			if (back - front == 0) printf("1\n");
			else printf("0\n");
		}
		else if (!temp.compare("front"))
		{
			if (back - front == 0) printf("-1\n");
			else printf("%d\n", arr[front]);
		}
		else
		{
			if (back - front == 0) printf("-1\n");
			else printf("%d\n", arr[back - 1]);
		}
	}
}