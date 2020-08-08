#include <iostream>
 
int n, x, arr[102], idx = 0, swap_temp;
int main()
{
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) { arr[i - 1] = i; }
    for (int i = 0; i < n; ++i) { 
        idx = i;
        scanf("%d", &x);
        
        if (!x)
            continue;
        else {
            for (int i = 0; i < x; ++i) {
                swap_temp = arr[idx];
                arr[idx] = arr[idx + i - x];
                arr[idx + i - x] = swap_temp;
            }
        }
    }
 
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    return 0;
}

