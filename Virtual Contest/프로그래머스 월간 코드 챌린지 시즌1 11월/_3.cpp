#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();
    vector<int> dp(n, 0);
    vector<bool> one(n, false);
    vector<bool> two(n, false);
    one[a[0]] = true;
    for (int i = 1; i < n; i++)
    {
        if (i > 1 && a[i - 2] != a[i]) two[a[i - 2]] = false;
        if (one[a[i - 1]] == true && a[i - 1] != a[i])
        {
            dp[a[i - 1]] += 2;
            one[a[i - 1]] = false;
            two[a[i - 1]] = true;
        }
        if (one[a[i]] == false && a[i - 1] != a[i])
        {
            if (two[a[i]])
            {
                one[a[i]] = true;
                two[a[i]] = false;
            }
            else dp[a[i]] += 2;
        }
        else one[a[i]] = true;
    }
    for (int i = 0; i < n; i++)
    {
        answer = max(answer, dp[i]);
    }

    return answer;
}