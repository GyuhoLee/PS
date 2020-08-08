#include <iostream>
#include <string>
using namespace std;

int main(){
    int A;
    cin >> A;
    for(int i = 0; i < A; i++){
        string str;
        cin >> str;
        int size = str.length();
        int cont = 1;
        int score = 0;
        for(int j = 0; j < size; j++){
            if(str.at(j) == 'O'){
                score += cont;
                cont++;
            }
            else if(str.at(j) == 'X'){
                cont = 1;
            }
        }
        cout << score << endl;
    }
    
    
    return 0;
}