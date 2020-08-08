#include <iostream>
using namespace std;

int main(){
    int num[15000];
    for(int i = 1; i <= 10000; i++){
        num[i] = 0;
    }
    for(int i = 1; i <= 10000; i++){
        int temp = 0;
        if(i < 10)
            temp = i + i;
        else if(i < 100)
            temp = i + (i / 10) + (i % 10);
        else if(i < 1000)
            temp = i + (i / 100) + ((i / 10) % 10) + (i % 10);
        else if(i < 10000)
            temp = i + (i / 1000) + ((i / 100) % 10) + ((i / 10) % 10) + (i % 10);
        else
            temp = 10001;
        num[temp] = 1;
    }
    for(int i = 1; i <= 10000; i++){
        if(num[i] == 0){
            cout << i << endl;
        }
    }
    
    return 0;
}