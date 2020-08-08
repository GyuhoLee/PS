#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int num[100];
    int notcute = 0;
    int cute = 0;
    for(int i=0; i<N; i++){
        cin >>num[i];
        if(num[i] == 0){
            notcute++;
        }
        if(num[i] == 1){
            cute++;
        }
    }
    if(notcute > cute){
        cout << "Junhee is not cute!" << endl;
    }
    else if(cute > notcute){
        cout << "Junhee is cute!" << endl;
    }
    
}