#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    while(true)
    {
        string str;
        cin >> str;
        if(str[0] == '#') break;
        int y = 0;
        int n = 0;
        double total = 0;
        int a = 0;
        for(auto s : str)
        {
            total++;
            switch(s)
            {
                case 'Y': y++; break;
                case 'N': n++; break;
                case 'A': a++; break;
            }
        }
         string answer;
            if(a >= total / 2) answer = "need quorum";
            else if(y > n) answer = "yes";
            else if(y == n) answer = "tie";
            else answer = "no";
            cout << answer << '\n';
    }
}