#include <iostream>
using namespace std;

int main(){
    int num[4];
    for(int i = 0; i < 3; i++){
        cin >> num[0] >> num[1] >> num[2] >> num[3];
        int stoma = 0;
        int back = 0;
        for(int j = 0; j < 4; j++){
            if(num[j] == 0) stoma++;
            else back++;
        }
        char answer;
        switch(stoma){
            case 0 :
                answer = 'E';
                break;
            case 1 : 
                answer = 'A';
                break;
            case 2 :
                answer = 'B';
                break;
            case 3 :
                answer = 'C';
                break;
            case 4 :
                answer = 'D';
                break;
        }
        cout << answer << endl;
    }
    
    return 0;
}