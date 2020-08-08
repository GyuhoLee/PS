#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    double before;
    double num;
    cin >> before;
    while(1)
    {
    	cin >> num;
    	if(num == 999) break;
    	printf("%.2f\n", num - before);
    	before = num;
    }

    return 0;
}