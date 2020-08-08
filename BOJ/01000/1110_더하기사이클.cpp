#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int temp = N;
    int count = 0;
    while(1){
        int ten = temp / 10;
        int one = temp % 10;
        temp = one * 10 + ((ten + one) % 10);
        count++;
        if (temp == N)
            break;
    }
    cout << count << endl;

    return 0;   
}