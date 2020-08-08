#include <iostream>
using namespace std;

int main()
{
   int t;
    cin >> t;
    for(int k = 0; k < t; k++)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int a = 0, b = 0;
        while(a < n && b < m)
        {
            if(a * m + x == b * n + y) break;
            a * m + x < b * n + y ? a++ : b++;
        }
        if (a == n || b == m) cout << -1;
        else cout << a * m + x;
        cout << '\n';
    }
    
    return 0;
}