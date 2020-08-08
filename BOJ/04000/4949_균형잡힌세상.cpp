#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	while (1)
	{
		string str;
		getline(cin, str);
		if (str == ".") break;
		int s_left = 0, s_right = 0;
		int b_left = 0, b_right = 0;
		bool perfect = true;
		vector<int> arr;
		for (int i = 0; i < str.length(); i++)
		{
			switch (str[i])
			{
			case '[':
				b_left++;
				arr.push_back(1);
				break;
			case '(':
				s_left++;
				arr.push_back(0);
				break;
			case ')':
				s_right++;
				if (!arr.empty() && arr.back()) perfect = false;
				if (!arr.empty()) arr.pop_back();
				break;
			case ']':
				b_right++;
				if (!arr.empty() && !arr.back()) perfect = false;
				if(!arr.empty()) arr.pop_back();
				break;
			}
			if (s_left < s_right || b_left < b_right) perfect = false;
		}
		if (s_left != s_right || b_left != b_right) perfect = false;
		if (perfect) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}