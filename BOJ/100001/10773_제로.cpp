#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> arr;
	while (N--)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			if (!arr.empty()) arr.pop_back();
		}
		else arr.push_back(temp);
	}
	int answer = 0;
	for (int i = 0; i < arr.size(); i++) answer += arr[i];
	printf("%d", answer);

	return 0;
}