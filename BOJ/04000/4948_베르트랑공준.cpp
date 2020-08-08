#include <iostream>
using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        int* num = new int[2*n+1];
        num[1] = 1;
        int count = 0;
        for(int i = 2; i <= 2 * n; i++)
            num[i] = 0;
        for(int i = 2; i <= 2 * n; i++){
            if(num[i] == 0){
                int temp = i;
                for(int j = 2; temp * j <= 2 * n; j++)
                    num[temp*j] = 1;
            }
        }
        for(int i = n + 1; i <= 2 * n; i++){
            if(num[i] == 0){
                count++;
            }
        }
        cout << count << endl;
   }
    
    
    return 0;
}