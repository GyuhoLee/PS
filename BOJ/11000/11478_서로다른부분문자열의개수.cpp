#include <iostream>
#include <set>
#include <string>
using namespace std;

string S;
set<string> sets;

int main() {
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		string str = "";
		for (int j = i; j < S.length(); j++) {
			str += S[j];
			sets.insert(str);
		}
	}
	cout << sets.size();

	return 0;
}