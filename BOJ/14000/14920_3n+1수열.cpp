#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    int count = 0;
    while(1){
        count++;
        if(a == 1) break;
        else if(a % 2 == 0) a /= 2;
        else a = a * 3 + 1;
    }
    cout << count << endl;
    
    return 0;
}