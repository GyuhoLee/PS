#include <iostream>
#include <algorithm>
using namespace std;

int N, MOD = 1000000000;
long long arr[101][10][1 << 10];

long long solve(int n) {
    long long ret = 0;
    for(int i = 0; i < 10; i++) {
        ret += arr[n][i][(1 << 10) - 1];
        ret %= MOD;
    }
    return ret;
}

int main() {
    cin >> N;
    for(int i = 1; i < 10; i++) {
        arr[1][i][1 << i] = 1;
    }

    for(int i = 1; i < 100; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 1; k < (1 << 10); k++) {
                if(j != 0) {
                    int bit = k | (1 << (j - 1));
                    arr[i + 1][j - 1][bit] = (arr[i + 1][j - 1][bit] + arr[i][j][k]) % MOD;
                }
                if (j != 9) {
                    int bit = k | (1 << (j + 1));
                    arr[i + 1][j + 1][bit] = (arr[i + 1][j + 1][bit] + arr[i][j][k]) % MOD;
                }
            }
        }
    }

   cout << solve(N);

	return 0;
}