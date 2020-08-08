#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    string str;
    cin >> N;
    cin >> str;
    int answer = 0;
    for(auto s : str)
    {
        answer += (int)s - 'A' + 1;
    }
    cout << answer;
    
}