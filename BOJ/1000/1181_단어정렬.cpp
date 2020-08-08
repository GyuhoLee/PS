#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string arr[20000];

bool compare(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N, compare);
	string before = "";
	for (int i = 0; i < N; i++)
	{	
		if(before != arr[i])
			cout << arr[i] << '\n';
		before = arr[i];
	}

	return 0;
}