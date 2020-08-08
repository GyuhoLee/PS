#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int min_num = 100;
    int idx = -1;
    int num[3];
    for(int i = 0; i < 3; i++)
    {
        cin >>  num[i];
        if(min_num > num[i])
        {
            min_num = num[i];
            idx = i;
        }
    }
    if(num[0] + num[1] + num[2] >= 100) cout << "OK";
    else
    {
        string str;
        switch(idx)
        {
            case 0: str = "Soongsil"; break;
            case 1: str = "Korea"; break;
            default: str = "Hanyang"; break;
        }
        cout << str;
    }
    
    return 0;
}