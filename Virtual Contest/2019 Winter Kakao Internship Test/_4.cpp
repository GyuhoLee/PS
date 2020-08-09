#include <string>
#include <vector>
#include <map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	map<long long, long long> M;
	for (auto num : room_number)
	{
		vector<long long> v;
		long long i = num;
		v.push_back(num);
		while (true)
		{
			if (M.count(i))
			{
				v.push_back(i);
				i = M[i];
				continue;
			}
			for (auto n : v)
			{
				M[n] = i + 1;
			}
			M[i] = i + 1;
			answer.push_back(i);
			break;
		}
	}
	return answer;
}