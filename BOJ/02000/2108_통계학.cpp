#include <iostream>
#include <algorithm>
using namespace std;

int arr[500000];
int visited[8001];
 
int main()
{
    int N;
    cin >> N;
    long double sum = 0;
    int maxNum = -4000, minNum = 4000;
    for (int i = 0; i < N; i++)
    {
         cin >> arr[i];
         sum += arr[i];
         visited[arr[i] + 4000]++;
         maxNum = max(maxNum, arr[i]);
         minNum = min(minNum, arr[i]);
    }
	long double average = sum / N;
    if (average >= 0) cout << int(average + 0.5) << "\n";
    else cout << int(average - 0.5) << "\n";
    sort(arr, arr + N);
    cout << arr[N / 2] << "\n";
    int num = -1;
    int cur = 0;
    bool second = false;
    for(int i=0; i <= 8000; i++)
    {
        if (cur < visited[i])
        {
             cur = visited[i];
             num = i;
             second = false;
         }
         else if (cur == visited[i] && !second)
         {
              num = i;
              second = true;
         }
    }
    cout << num - 4000 << "\n";
    cout << maxNum - minNum << "\n";

    return 0;

}