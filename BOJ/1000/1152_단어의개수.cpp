#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    int size = str.length();
    int count = 1;
    for(int i = 0; i < size; i++){
        if(str.at(i) == ' ')
            count++;
    }
    if(str.at(0) == ' ')
        count--;
    if(str.at(size-1) == ' ')
        count--;
    cout << count << endl;
    
    return 0;
}