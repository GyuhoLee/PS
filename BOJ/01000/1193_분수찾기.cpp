#include <iostream>
using namespace std;

int main(){
    int X;
    cin >> X;
    int count = 1;
    int son = 0;
    int mom = 0;
    for(int i = 1; i <= 10000000; i++){
        if(count >= X){
            if(i % 2 == 0){
                son = i - (count - X);
                mom = i + 1 - son;
            }
            else{
                mom = i - (count - X);
                son = i + 1 - mom;
            }
            cout << son << '/' << mom << endl;
            break;
        }
        count = count + i + 1;
    }
    
    return 0;
}