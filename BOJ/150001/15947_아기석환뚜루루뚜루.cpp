#include <iostream> 
using namespace std; 
int main() { 
    int input; 
     int repeat; 
     int say; 
    cin >> input; 
    input--; 
    repeat = input / 14; 
    int tururu = 2 + repeat; 
    say = input % 14; 
    if (say == 0 || say == 12) cout << "baby"; 
    else if (say == 1 || say == 13) cout << "sukhwan"; 
    else if (say == 4) cout << "very"; 
    else if (say == 5) cout << "cute"; 
    else if (say == 8) cout << "in"; 
    else if (say == 9) cout << "bed"; 
    else { 
        tururu -= say % 2; 
        if (tururu >= 5) cout << "tu+ru*" << tururu; 
        else { 
            cout << "tu"; 
            for (int i = 0; i < tururu; i++) 
                cout << "ru"; 
        } 
    } 
    return 0; 
}
