#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int C;
        cin >> C;
        int Q, D, N, P;
        Q = C / 25;
        C %= 25;
        D = C / 10;
        C %= 10;
        N = C / 5;
        C %= 5;
        P = C;
        cout << Q << ' ' << D << ' ' << N << ' ' << P << endl;
    }
    
    return 0;
}