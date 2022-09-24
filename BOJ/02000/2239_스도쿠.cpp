#include <iostream>
using namespace std;

char board[9][9];
bool finished = false;

bool check(int i, int j, char c) {
	for (int k = 0; k < 9; k++) {
		if (board[i][k] == c || board[k][j] == c) return false;
	}
	int i3 = i / 3 * 3, j3 = j / 3 * 3;
	for (int ii = i3; ii < i3 + 3; ii++) {
		for (int jj = j3; jj < j3 + 3; jj++) {
			if (board[ii][jj] == c) return false;
		}
	}

	return true;
}

void loop(int i, int j) {
	if (finished) return;

	if (++j == 9) {
		j = 0;
		++i;
	}

	if (i == 9) {
		finished = true;
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++)
				cout << board[i][j];
			cout << '\n';
		}
		return;
	}

	if (board[i][j] != '0') {
		loop(i, j);
		return;
	}

	for (char c = '1'; c <= '9'; c++) {
		if (check(i, j, c)) {
			board[i][j] = c;
			loop(i, j);
			board[i][j] = '0';
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];
	loop(0, -1);

	return 0;
}