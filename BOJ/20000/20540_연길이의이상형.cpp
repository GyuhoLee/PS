#include <iostream>
#include <map>
#include <string>
using namespace std;
map<char, char> M = { {'E','I'},{'I','E'},{'S','N'},{'N','S'},{'T','F'},{'F','T'},{'J','P'},{'P','J'} };
int main()
{
	string str;
	cin >> str;
	for (char ch : str) cout << M[ch];
}