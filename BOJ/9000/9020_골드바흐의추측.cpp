#include <iostream>

int main() {
	int T, n;
	int not_prime_nums[10001] = { 0,1,0, };

	for (int p = 2; p <= 10000; p++) {
		if (not_prime_nums[p] == 0) {
			for (int i = 2; p * i <= 10000; i++)
				not_prime_nums[p * i] = 1;
		}
	}
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		for (int i = n / 2; i > 0; i--) {
			if (not_prime_nums[i] == 0 && not_prime_nums[n - i] == 0) {
				printf("%d %d\n", i, n - i);
				break;
			}
		}

	}

	return 0;
}