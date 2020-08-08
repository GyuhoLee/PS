#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(i, a, b) for(int i = a; i < b; i++)
#define MS(a, b) memset(a, b, sizeof(a))

int N;
pair<int, int> arr[26];

void preorder(int num)
{
	if (num == -1) return;
	char ch = num + 'A';
	cout << ch;
	preorder(arr[num].first);
	preorder(arr[num].second);
}

void inorder(int num)
{
	if (num == -1) return;
	inorder(arr[num].first);
	char ch = num + 'A';
	cout << ch;
	inorder(arr[num].second);
}

void postorder(int num)
{
	if (num == -1) return;
	postorder(arr[num].first);
	postorder(arr[num].second);
	char ch = num + 'A';
	cout << ch;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	F(i, 0, N)
	{
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.') arr[a - 'A'].first = b - 'A';
		else arr[a - 'A'].first = -1;
		if (c != '.') arr[a - 'A'].second = c - 'A';
		else arr[a - 'A'].second = -1;
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);

	return 0;
}