#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a = 1;
    int b = 0;
    for(int i = 0; i < n; i++){
        int temp = a;
        a = b;
        b = temp + b;
    }
    cout << a << ' ' << b << endl;
    
    return 0;
}