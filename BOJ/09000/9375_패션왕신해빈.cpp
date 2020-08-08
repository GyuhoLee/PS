#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		unordered_map<string, int> arr;
		for (int i = 0; i < N; i++)
		{
			string name, kind;
			cin >> name >> kind;
			if (arr.find(kind) == arr.end())
				arr.insert(make_pair(kind, 1));
			else
				arr[kind]++;
		}
		int result = 1;
		for (auto kind : arr)
			result *= (kind.second + 1);
		result -= 1;
		printf("%d\n", result);
	}

	return 0;
}