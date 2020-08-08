#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int R;
    int count = 0;
    for(int i = 0; i < 10000000; i++){
        if((6 * count) +1 >= N){
            cout << i + 1 << endl;
            break;
        }
        count = count + i + 1;
    }
    
    return 0;
}