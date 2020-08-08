#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int num = 0;
    for(int i = 1; i <= N; i++)
        num += i;
    cout << num << endl;
    
    return 0;
}