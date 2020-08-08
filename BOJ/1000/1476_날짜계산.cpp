#include <iostream>
using namespace std;

int main()
{
	int E, S, M;
	cin >> E >> S >> M;
	int mE = 0, mS = 0, mM = 0;
	int i = 0;
	while (1)
	{
		i++;
		mE++;
		mS++;
		mM++;
		if (mE > 15) mE = 1;
		if (mS > 28) mS = 1;
		if (mM > 19) mM = 1;
		if (mE == E && mS == S && mM == M) break;
	}
	cout << i;
	
	return 0;
}