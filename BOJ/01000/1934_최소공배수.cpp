#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int a, b;
        cin >> a >> b;
        int small;
        if(a < b) small = a;
        else small = b;
        int devine = 1;
        for(int i = 2; i <= small; i++){
            if(a % i == 0 && b % i == 0) devine = i;
        }
        int multiply = a * b / devine;
        cout << multiply << endl;
    }
    
    return 0;
}