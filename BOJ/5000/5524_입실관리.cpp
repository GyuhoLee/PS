#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--)
    {
    	string str;
    	cin >> str;
    	for(auto s : str)
    	{
    		if(s <= 'Z') s = s + ('a' - 'A');
    		cout << s;
    	}
    	cout << '\n';
    }

    return 0;
}