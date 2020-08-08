#include<stdio.h>
#include<stdlib.h>

long long r, c, count = 0, k = 1;

void Z(long long x, long long y, long long size);

int main()
{
	long long n;
	scanf("%lld %lld %lld", &n, &r, &c);

	for (int i = 0; i<n; i++)
		k *= 2;
	Z(0, 0, k);

	return 0;
}
void Z(long long x, long long y, long long size)
{
	if (x == r && y == c) {
		printf("%lld", count);
		exit(0);
	}
	if (size == 1)
	{
		count++;
		return;
	}
	if (r >= x + size) {
		count += size*size;
		return;
	}
	if (c >= y + size) {
		count += size*size;
		return;
	}
	
	long long half = size / 2;
	Z(x, y, half);
	Z(x, y + half, half);
	Z(x + half, y, half);
	Z(x + half, y + half, half);

}