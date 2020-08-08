#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    bool A = true;
    bool B = true;
    int N1, N2;
    cin >> N1 >> N2;
    while(N1--)
    {
        int a, b;
        cin >> a >> b;
        if(a != b) A = false;
    }
    while(N2--)
    {
        int a, b;
        cin >> a >> b;
        if(a != b) B = false;
    }
    if(A && B) cout << "Accepted";
    else if (A) cout << "Why Wrong!!!";
    else cout << "Wrong Answer";
    

    return 0;
}