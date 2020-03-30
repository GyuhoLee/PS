#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 200000;
	vector<int> temp(stones);
	sort(temp.begin(), temp.end());
	int Start = 0;
	int End = temp.size() - 1;
	int mid;
	while (Start <= End)
	{
		mid = (Start + End) / 2;
		bool ok = true;
		int cont = 0;
		for (int i = 0; i < stones.size(); i++)
		{
			if (stones[i] - temp[mid] < 0)
			{
				cont++;
				if (cont >= k)
				{
					ok = false;
					break;
				}
			}
			else cont = 0;
		}
		if (ok) Start = mid + 1;
		else End = mid - 1;
	}

	answer = temp[Start - 1];
	return answer;
}

int main()
{
	vector<int> v;
	for (int i = 200000; i > 0; i--)
		v.push_back(i);
	cout << solution(v, 100000);
}