#include <iostream>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int A, B;
        char temp;
        cin >> A >> temp >> B;
        printf("%d\n", A + B);
    }
    
    return 0;
}