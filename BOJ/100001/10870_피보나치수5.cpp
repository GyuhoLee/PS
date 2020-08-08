#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num[46];
    num[0] = 0;
    num[1] = 1;
    for(int i = 2; i <= 45; i++)
        num[i] = num[i-2] + num[i-1];
    cout << num[n] << endl;
    
    return 0;
}