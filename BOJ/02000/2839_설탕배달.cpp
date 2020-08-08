#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int a = num/5;
    int na = num % 5;
    int no = -1;
    if(na == 0)
        cout << a << endl;
    else if (num == 4 || num == 7)
        cout << no << endl;
    else if (na ==1)
        cout << a+1 << endl;
    else if (na == 2)
        cout << a+2 << endl;
    else if (na == 3)
        cout << a+1 << endl;
    else if (na ==4)
        cout << a+2 << endl;
    
    return 0;
}