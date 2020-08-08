#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int* arr = new int[num];
    for(int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    int max = 0;
    int min = 1000000;
    for(int i = 0; i < num; i++)
    {
        if(max < arr[i]) max = arr[i];
        if(min > arr[i]) min = arr[i];
    }
    cout << max * min;
    
    return 0;
}