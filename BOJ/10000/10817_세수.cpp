#include <iostream>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    if(A >= B && A >= C)
    {
        if(B>C)
            cout << B << endl;
        else
            cout << C << endl;
    }
    else if(A <= B && A <= C){
        if(B>C)
            cout << C << endl;
        else
            cout << B << endl;
    }
    else
        cout << A << endl;
    
    return 0;
}