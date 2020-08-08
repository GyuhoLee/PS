#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
   int N;
   cin >> N;
   vector<int> v;
   for(int j = 1; j <= N; j++)
   {
   	bool ok = true;
   	for(int i = 0; i < 10; i++)
   	{
   		int temp;
   		cin >> temp;
   		if(temp != (i % 5) + 1) ok = false;
   	}
   	if(ok) v.push_back(j);
   }
   for (auto s : v) cout << s << '\n';

    return 0;
}