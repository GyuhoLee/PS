#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000000000

vector<string> str;
vector <ll> num;
int numIdx = 0;
bool quit = false;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		str.clear();
		num.clear();
		while (true)
		{
			string temp;
			cin >> temp;
			if (temp == "QUIT")
			{
				quit = true;
				break;
			}
			else if (temp == "END") break;
			else if (temp == "NUM")
			{
				ll tempN;
				cin >> tempN;
				num.push_back(tempN);
			}
			str.push_back(temp);
		}
		if (quit) break;
		int N;
		cin >> N;
		while (N--)
		{
			numIdx = 0;
			stack<ll> S;
			ll temp;
			cin >> temp;
			S.push(temp);
			bool ERR = false;
			for (auto s : str)
			{
				if (s == "NUM")
				{
					S.push(num[numIdx]);
					numIdx++;
				}
				else if (s == "POP")
				{
					if (S.empty())
					{
						ERR = true;
						break;
					}
					S.pop();
				}
				else if (s == "INV")
				{
					if (S.empty())
					{
						ERR = true;
						break;
					}
					ll top = S.top();
					S.pop();
					S.push(-top);
				}
				else if (s == "DUP")
				{
					if (S.empty())
					{
						ERR = true;
						break;
					}
					ll top = S.top();
					S.push(top);
				}
				else
				{
					if (S.size() < 2)
					{
						ERR = true;
						break;
					}
					ll one = S.top();
					S.pop();
					ll two = S.top();
					S.pop();
					if (s == "SWP")
					{
						S.push(one);
						S.push(two);
					}
					else if (s == "ADD") S.push(two + one);
					else if (s == "SUB") S.push(two - one);
					else if (s == "MUL") S.push(two * one);
					else if (s == "DIV")
					{
						if (one == 0)
						{
							ERR = true;
							break;
						}
						int isMinus = 1;
						if (two * one < 0) isMinus = -1;
						if (two < 0) two *= -1;
						if (one < 0) one *= -1;
						temp = abs(two) / abs(one);
						temp *= isMinus;
						S.push(temp);
					}
					else if (s == "MOD")
					{
						if (one == 0)
						{
							ERR = true;
							break;
						}
						int isMinus = 1;
						if (two < 0)
						{
							isMinus = -1;
							two *= -1;
						}
						if (one < 0) one *= -1;
						temp = two % one;
						temp *= isMinus;
						S.push(temp);
					}
					if (S.top() > MAX || S.top() < -MAX)
					{
						ERR = true;
						break;
					}
				}
			}
			if (ERR || S.size() != 1)
			{
				cout << "ERROR\n";
				continue;
			}
			cout << S.top() << '\n';
		}
		cout << '\n';
	}


	return 0;
}