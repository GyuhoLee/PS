#include <iostream>
using namespace std;

long long pow(long long a, long long b, long long c)
{
    if(b == 0) return 1;
    if(b & 1) return (pow(a, b -1, c) * a) % c;
    else
    {
        long long x = pow(a, b / 2, c);
        return (x * x) % c;
    }
}
int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);
}