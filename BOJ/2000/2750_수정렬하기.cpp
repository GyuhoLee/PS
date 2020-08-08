#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int* num = new int[N];
    for(int i = 0; i < N; i++)
        cin >> num[i];
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(num[i] > num[j]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for(int i = 0; i < N; i++)
        cout << num[i] << endl;
    
    return 0;
}