#include <iostream>
using namespace std;

int arr[500 * 500], N, M, B, T = 2e9, H;

int main()
{
	cin >> N >> M >> B;
	N *= M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for(int h = 0; h <= 256; h++)
	{
		int b = B, t = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] < h)
			{
				t += h - arr[i];
				b -= h - arr[i];
			}
			else
			{
				t += (2 * (arr[i] - h));
				b += arr[i] - h;
			}
		}
		if (b >= 0)
		{
			if (t <= T)
			{
				T = t;
				H = h;
			}
		}
	}
	cout << T << " " << H;

	return 0;
}