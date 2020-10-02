#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int left[1000000], right[1000000];

int solution(vector<int> a) {
    int answer = 2;
    int len = a.size();
    if (a.size() <= 3) return len;
    left[0] = a[0];
    for (int i = 1; i < len - 1; i++)
    {
        left[i] = min(left[i - 1], a[i]);
    }
    right[len - 1] = a[len - 1];
    for (int i = len - 2; i > 0; i--)
    {
        right[i] = min(right[i + 1], a[i]);
    }
    for (int i = 1; i < len - 1; i++)
    {
        if (left[i] < a[i] && right[i] < a[i]) continue;
        answer++;
    }
    return answer;
}