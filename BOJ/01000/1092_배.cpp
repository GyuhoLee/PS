#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, crane[50], num, ans = 0;
vector<int> box, tmp;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> crane[i];
	sort(crane, crane + N);
	cin >> M;
	while (M--)
	{
		cin >> num;
		box.push_back(num);
	}
	sort(box.begin(), box.end(), greater<int>());

	while (!box.empty())
	{
		tmp.clear();
		ans++;
		int i = N - 1, j = 0;
		if (crane[i] < box[j])
		{
			cout << -1;
			return 0;
		}
		while (j < box.size())
		{
			num = box[j++];
			if (i == -1 || crane[i] < num) tmp.push_back(num);
			else i--;
		}
		box = tmp;
	}
	cout << ans;

	return 0;
}