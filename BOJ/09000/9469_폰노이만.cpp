#include <iostream>
using namespace std;

int main()
{
	int P, N;
	double A, B, D, F;
	cin >> P;
	while (P--)
	{
		cin >> N >> D >> A >> B >> F;
		printf("%d %.6f\n", N, D / (A + B) * F);
	}

	return 0;
}