#include <iostream>
using namespace std;

int main()
{
	char ch[16];
	cin >> ch;
	int i = 0;
	int count = 0;
	while (1)
	{
		if (ch[i] == NULL) break;
		count++;
		switch (ch[i])
		{
		case 'A':
		case 'B':
		case 'C':
			count += 2;
			break;
		case 'D':
		case 'E':
		case 'F':
			count += 3;
			break;
		case 'G':
		case 'H':
		case 'I':
			count += 4;
			break;
		case 'J':
		case 'K':
		case 'L':
			count += 5;
			break;
		case 'M':
		case 'N':
		case 'O':
			count += 6;
			break;
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			count += 7;
			break;
		case 'T':
		case 'U':
		case 'V':
			count += 8;
			break;
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			count += 9;
			break;
		}
		i++;

	}
	cout << count;

	return 0;
}