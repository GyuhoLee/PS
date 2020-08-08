#include <iostream>
using namespace std;

int main()
{
	long long A, B, C, D;
	cin >> A >> B >> C >> D;
	long long sum = B + D;
	if (B < 10) sum += A * 10;
	else if (B < 100) sum += A * 100;
	else if (B < 1000) sum += A * 1000;
	else if (B < 10000) sum += A * 10000;
	else if (B < 100000) sum += A * 100000;
	else if (B < 1000000) sum += A * 1000000;
	if (D < 10) sum += A * 10;
	else if (D < 100) sum += C * 100;
	else if (D < 1000) sum += C * 1000;
	else if (D < 10000) sum += C * 10000;
	else if (D < 100000) sum += C * 100000;
	else if (D < 1000000) sum += C * 1000000;

	cout << sum;
	
	return 0;
}