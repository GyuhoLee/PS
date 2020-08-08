#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n += 4;
    int g[2001];
    bool u[2001];
    g[0] = 0;
    g[1] = 0;
    int max = 0;
    for (int i = 2; i <= n; i++)
    {
        memset(u, false, sizeof(u));
        for (int j = 2; j < i - 2; j++) {
            u[g[j] ^ g[i - 1 - j]] = true;
        }
        int j = 0;
        while (u[j]) j++;
        g[i] = j;
        if (max < j) max = j;
    }
    int answer = g[n] > 0 ? 1 : 2;
    cout << answer;
    return 0;

}
