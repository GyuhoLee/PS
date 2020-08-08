#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    double num[1000];
    int count = 0;
    for(int i = 0; i < N; i++){
        cin >> num[i];
        if(num[i] > count){
            count = num[i];
        }
    }
    double sum = 0;
    for(int i = 0; i < N; i++){
        num[i] = (num[i] / count) * 100.00;
        sum += num[i];
    }
    cout << sum / (double)N << endl;
    
    
    return 0;
} 