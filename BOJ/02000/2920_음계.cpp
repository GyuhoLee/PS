#include <iostream>
using namespace std;

int main(){
    int melody[8];
    int temp = 0;
    for(int i = 0; i < 8; i++){
        cin >> melody[i];
    }
    for(int i = 0; i < 8; i++){
        if(i == 7 && melody[i] == 8){
            cout << "ascending" << endl;
            temp = 1;
        }
        else if(i + 1 == melody[i]){
            continue;
        }
        else{
            break;
        }
    }
    for(int i = 0; i < 8; i++){
         if(i == 7 && melody[i] == 1){
            cout << "descending" << endl;
            temp = 1;
        }
        else if(i + melody[i] == 8){
            continue;
        }
        else{
            break;
        }
    }
    if(temp == 0){
        cout << "mixed" << endl;
    }
    
    return 0;
}