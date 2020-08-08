#include <iostream>
using namespace std;

int main(){
    int n, T;
    cin >> n >> T;
    int* num = new int [n];
    for(int i = 0; i < n; i++) cin >> num[i];
    int count = 0;
    int temp;
    for(int i = 0; i < n; i++){
        count += num[i];
        if(count > T){
            temp = i;
            break;
        }
    }
    cout << temp << endl;
    
    return 0;
}