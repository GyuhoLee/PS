#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int R;
        cin >> R;
        string str;
        cin >> str;
        int size = str.length();
        for(int j = 0; j < size; j++){
            for(int m = 0; m < R; m++){
                cout << str.at(j);
            } // for R
        } // for size
        cout << endl;
    } //for T
    
    return 0;
}