#include<iostream>
using namespace std;

int main(){
    int M , N;
    cin >> M;
    cin >> N;
    int small = 0;
    int sum = 0;
    for(int i = M; i <= N; i++){
        if(i == 1) continue;
        int temp = 0;
        for(int j = 2; j < i; j++){
           if(i % j == 0){
               temp = 1;
           }
        }
        if(temp == 0){
            sum += i;
            if(small == 0) small = i;
        }
    }
    if(sum == 0) cout << -1 << endl;
    else cout << sum << endl << small << endl;
    
    
    
    return 0;
}