#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[101];
int temp[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++) arr[i] = i;
    while(M--)
    {
        int a, b;
        cin >> a >> b;
        int j = b;
        for(int i = a; i <= b; i++)
        {
            temp[i] = arr[j];
            j--;
        }
        for(int i = a; i <= b; i++) arr[i] = temp[i];
    }
    for(int i = 1; i <= N; i++) cout << arr[i] << ' ';

    return 0;
}