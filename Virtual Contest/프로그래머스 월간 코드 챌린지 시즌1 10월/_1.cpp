#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str = "";
    int num = 1;
    while (num <= n)
    {
        num *= 3;
    }
    num /= 3;
    while (n)
    {
        str += ((char)(n / num));
        n %= num;
        num /= 3;
    }
    num = 1;
    for (int i = 0; i < str.size(); i++)
    {
        answer += ((int)str[i] * num);
        num *= 3;
    }
    return answer;
}