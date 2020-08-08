#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    string str2;
    cin >> str;
    cin >> str2;
    if(str.size() < str2.size()) cout << "no" << endl;
    else cout << "go" << endl;
    
    return 0;
}