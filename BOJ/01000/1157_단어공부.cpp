#include <iostream>
using namespace std;

int main()
{
	char ch[1000001];
	cin >> ch;
	int i = 0;
	int arr[26];
	for (int j = 0; j < 26; j++) arr[j] = 0;
	while (1)
	{
		if (ch[i] == NULL) break;
		int temp = (int)ch[i];
		if (temp > 96) temp -= 32;
		arr[temp - 65]++;
		i++;
	}
	int max = 0;
	char answer = '?';
	for (int j = 0; j < 26; j++)
	{
		if (max < arr[j])
		{
			max = arr[j];
			answer = char(j + 65);
		}
		else if (max == arr[j]) answer = '?';
	}
	cout << answer;


	return 0;
}