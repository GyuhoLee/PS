#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#include <string.h>
#include <limits.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	vector<char> A, B, C;
	for (int i = 0; i < 33; i++)
	{
		A.push_back('A');
		A.push_back('B');
		A.push_back('C');
	}
	A.push_back('A');
	for (int i = 0; i < 25; i++)
	{
		B.push_back('B');
		B.push_back('A');
		B.push_back('B');
		B.push_back('C');
	}
	for (int i = 0; i < 16; i++)
	{
		C.push_back('C');
		C.push_back('C');
		C.push_back('A');
		C.push_back('A');
		C.push_back('B');
		C.push_back('B');
	}
	C.push_back('C');
	C.push_back('C');
	C.push_back('A');
	C.push_back('A');

	int N;
	cin >> N;
	int iA = 0, iB = 0, iC = 0;
	for (int i = 0; i < N; i++)
	{
		char temp;
		cin >> temp;
		if (A[i] == temp) iA++;
		if (B[i] == temp) iB++;
		if (C[i] == temp) iC++;
	}
	int answer = max(iA, max(iB, iC));
	cout << answer << '\n';
	if (iA == answer) cout << "Adrian\n";
	if (iB == answer) cout << "Bruno\n";
	if (iC == answer) cout << "Goran\n";
	

	return 0;
}