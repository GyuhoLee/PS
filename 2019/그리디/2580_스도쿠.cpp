#include <iostream>
#include <algorithm>
using namespace std;

int arr[9][9];
bool complete = false;
void input();
void solve(int x, int y);
void print();
bool check(int x, int y, int num);

int main() {
	input();
	solve(0, 0);

	return 0;
}

void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}
}

void solve(int x, int y) {
	if (complete) return;
	if (arr[x][y]) {
		if (x == 8 && y == 8) {
			complete = true;
			print();
		}
		else if (y == 8)
			solve(x + 1, 0);
		else
			solve(x, y + 1);
	}
	else {
		for (int i = 1; i < 10; i++) {
			if (check(x, y, i)) {
				arr[x][y] = i;
				if (x == 8 && y == 8) {
					complete = true;
					print();
				}
				else if (y == 8)
					solve(x + 1, 0);
				else
					solve(x, y + 1);
				arr[x][y] = 0;
			}
		}
	}
}

bool check(int x, int y, int num) {
	bool answer = true;
	for (int i = 0; i < 9; i++) {
		if (arr[x][i] == num) answer = false;
		if (arr[i][y] == num) answer = false;
	}
	int row = x / 3;
	int col = y / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[row * 3 + i][col * 3 + j] == num)
				answer = false;
		}
	}
	return answer;
}

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}