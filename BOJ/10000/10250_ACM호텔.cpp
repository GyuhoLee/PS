#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int H, W, N;
        cin >> H >> W >> N;
        int repH, repW;
        for(int j = 1; j <= H * N; j++){
            if(H * j >= N){
                repW = j;
                repH = H - (H * j - N);
                break;
            }
        }
        cout << repH;
        if(repW < 10){
            cout << '0' << repW << endl;
        }
        else{
            cout << repW << endl;
        }
    }
    
    return 0;
}