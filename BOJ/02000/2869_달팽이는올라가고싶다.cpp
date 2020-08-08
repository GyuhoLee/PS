#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int A, B, V;
	cin >> A >> B >> V;
	int cnt = (V - B - 1) / (A - B) + 1;
	
	cout << cnt;
	return 0;
}
