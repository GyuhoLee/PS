#include <iostream>
using namespace std;

int main(){
    int num[31];
    for(int i = 1; i <= 30; i++) num[i] = 0;
    for(int i = 0; i < 28; i++){
        int n;
        cin >> n;
        num[n] = 1;
    }
    for(int i = 1; i <= 30; i++){
        if(num[i] == 0) cout << i << endl;
    }
    
    return 0;
}