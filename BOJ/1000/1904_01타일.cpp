#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long int num[1000001];
    num[0] = 0;
    num[1] = 1;
    num[2] = 2;
    for(int i = 3; i <= 1000000; i++)
        num[i] = (num[i-2] + num[i-1]) % 15746;
    cout << num[n] << endl;
    
    return 0;
}