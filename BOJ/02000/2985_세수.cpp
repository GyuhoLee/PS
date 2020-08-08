#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    char cha = '0';
    if(a + b == c) cha = '+';
    else if (a - b == c) cha = '-';
    else if (a / b == c) cha = '/';
    else if (a * b == c) cha = '*';
    char cha2;
    if(a == b + c) cha2 = '+';
    if(a == b - c) cha2 = '-';
    if(a == b / c) cha2 = '/';
    if(a == b * c) cha2 = '*';
    if(cha != '0') cout << a << cha << b << '=' << c << endl;
    else cout << a << '=' << b << cha2 << c << endl;
    
    return 0;
}