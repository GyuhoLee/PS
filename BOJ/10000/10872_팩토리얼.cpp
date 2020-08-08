#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int answer = 1;
    for(int i = 1; i <= num; i++)
        answer *= i;
    cout << answer << '\n';
    return 0;
}