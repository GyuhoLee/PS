#include <bits/stdc++.h>
using namespace std;

int a[1025][1025], zero = 0, one = 0;

void solve(int y, int x, int n)
{
    int num = a[y][x];
    bool ok = true;
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (num != a[i][j])
            {
                ok = false;
                break;
            }
        }
        if (!ok) break;
    }
    if (ok)
    {
        num == 1 ? one++ : zero++;
    }
    else
    {
        solve(y, x, n / 2);
        solve(y + n / 2, x, n / 2);
        solve(y, x + n / 2, n / 2);
        solve(y + n / 2, x + n / 2, n / 2);
    }
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            a[i + 1][j + 1] = arr[i][j];
        }
    }
    solve(1, 1, arr.size());
    answer.push_back(zero);
    answer.push_back(one);

    return answer;
}