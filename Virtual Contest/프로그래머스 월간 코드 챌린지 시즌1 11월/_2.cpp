#include <bits/stdc++.h>
using namespace std;

string tenConvertTwo(long long num)
{
    long long result = 0;
    for (long long i = 1; num > 0; i *= 10)
    {
        long long binary = num % 2;
        result += binary * i;
        num /= 2;
    }
    return to_string(result);
}

vector<int> solution(string s)
{
    vector<int> answer = { 0, 0 };
    while (s != "1")
    {
        cout << s << endl;
        answer[0]++;
        long long cnt = 0;
        for (char ch : s)
        {
            if (ch == '0') answer[1]++;
            else cnt++;
        }
        s = tenConvertTwo(cnt);
        if (cnt == 1) break;
    }
    return answer;
}