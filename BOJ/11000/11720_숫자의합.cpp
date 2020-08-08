#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    char cha;
    int count = 0;
    for(int i = 0; i < N; i++){
        cin >> cha;
        count += cha - '0';
    }
    cout << count;
    
    return 0;
}