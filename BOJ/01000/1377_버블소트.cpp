#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
 
int main(void)
{
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
    {
         cin >> v[i].first;
         v[i].second = i;
    }
    sort(v.begin(), v.end());
    int result = 0;
    for (int i = 0; i < N; i++)
    {
         result = max(result, v[i].second - i);
    }
    cout << result + 1 << "\n";
    return 0;
}