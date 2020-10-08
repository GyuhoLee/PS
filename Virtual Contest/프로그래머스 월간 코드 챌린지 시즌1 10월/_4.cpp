#include <bits/stdc++.h>
using namespace std;
#define SIZE 23158

int arr[SIZE][SIZE];

long long solution(string s)
{
    long long answer = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        arr[i][i] = 0;
    }
    for (int plus = 1; plus < n; plus++)
    {
        for (int i = 0; i + plus < n; i++)
        {
            int j = i + plus;
            if (s[i] != s[j]) arr[i][j] = j - i;
            else arr[i][j] = max(arr[i + 1][j], arr[i][j - 1]);
            answer += arr[i][j];
        }
    }
    return answer;
}