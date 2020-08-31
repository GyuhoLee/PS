#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1001][1001], i, j;
vector<char> answer;

int main() {
	cin >> s1 >> s2;
    for (i = 1;  i <= s1.size(); i++)
        for (j = 1; j <= s2.size(); j++)
            dp[i][j] = max({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1])});
    cout << dp[i - 1][j - 1] << '\n';

	i = s1.size();
	j = s2.size();

	while (i >= 1 && j >= 1) {
		if (dp[i][j] == dp[i - 1][j]) i--;
		else if (dp[i][j] == dp[i][j - 1]) j--;
		else 
		{
			answer.push_back(s1[i - 1]);
			i--; j--;
		}
	}
	for (auto iter = answer.rbegin(); iter != answer.rend(); iter++) cout << *iter;

    return 0;
}
