#include <iostream>
#include <algorithm>
using namespace std;

int T;
    int i;
    int num = 0;
    int x;

int Sosu(int n);

int main()
{
    scanf("%d", &T);
    for(i = 0; i < T; i++){
        scanf("%d ", &x);
        if(Sosu(x)){
            num++;
        }
    }
    printf("%d", num);
}

int Sosu(int n)
{
    int i;
    if(n == 1) return 0;
    if(n == 2) return 1;
    for(i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}