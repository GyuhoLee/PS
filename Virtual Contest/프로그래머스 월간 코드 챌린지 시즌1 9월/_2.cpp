#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
int dy[3] = { 1, 0, -1 };
int dx[3] = { 0, 1, -1 };
int arr[1001][1001];

vector<int> solution(int n) {
    vector<int> answer;
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= n; i++) arr[i][1] = i;
    for (int i = 2; i <= n; i++) arr[n][i] = n + i - 1;
    int num = n + n;
    for (int i = n - 1; i >= 2; i--) arr[i][i] = num++;
    if (n > 3)
    {
        int direct = 0, y = 3, x = 2;
        while (true)
        {
            arr[y][x] = num;
            int ny = y + dy[direct];
            int nx = x + dx[direct];
            if (arr[ny][nx] == 0)
            {
                y = ny;
                x = nx;
                num++;
                continue;
            }
            direct = (direct + 1) % 3;
            ny = y + dy[direct];
            nx = x + dx[direct];
            if (arr[ny][nx] == 0)
            {
                y = ny;
                x = nx;
                num++;
                continue;
            }
            else break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            answer.push_back(arr[i][j]);
        }
    }


    return answer;
}