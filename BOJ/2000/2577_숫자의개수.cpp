#include <iostream>
using namespace std;

int main(){
    long long A, B, C;
    cin >> A;
    cin >> B;
    cin >> C;
    long long answer = A * B * C;
    // 7 ~ 9 자리수
    int rep[10];
    int size;
    if(answer < 10000000)
        size = 7;
    else if(answer < 100000000)
        size = 8;
    else
        size = 9;
    for(int i = 1; i <= size; i++){
        int jegop = 1;
        for(int j = 1; j < i; j++){
            jegop *= 10;
        }
        rep[i] = (answer / jegop) % 10;
    }
    int soo[10];
    for(int i = 0; i < 10; i++){
        soo[i] = 0;
        for(int j = 1; j <= size; j++){
            if(rep[j] == i){
                soo[i]++;
            }
        }
        cout << soo[i] << endl;
    }
    
    return 0;
}