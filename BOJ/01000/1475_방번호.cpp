#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if(N == 1000000)
        cout << '6' << endl;
    else if(N == 0)
        cout << '1' << endl;
    else
    {
        int num[7];
        int zero = 0;
        for(int i = 6; i > 0; i--)
        {
            int jegop = 1;
            for(int j = 1; j < i; j++)
            {
                jegop *= 10;
            }
            num[i] = (N / jegop) % 10;
            if(zero == 0 && num[i] == 0)
                num[i] = 11;
            else
                zero = 1;
        }
        int ans[10];
        for(int i = 0; i < 10; i++)
        {
            ans[i] = 0;
        }
        for(int i = 1; i <= 6; i++)
        {
            if(num[i] == 11)
                continue;
            else
            {
                int temp =num[i];
                ans[temp]++;
            }
        }
        ans[6] += ans[9];
        if(ans[6] % 2 == 1)
            ans[6] = ans[6] / 2 + 1;
        else
            ans[6] /= 2;
        int best = 0;
        for(int i = 0; i < 9; i++)
        {
            if(best < ans[i])
                best = ans[i];
        }
        cout << best << endl;
    }
    
    
    return 0;
}