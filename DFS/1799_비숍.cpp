#include <iostream>
using namespace std;

int map[10][10];
int colors[10][10];
bool visited[100];
static int n;
int ans[2];
int dy[4] = { -1, -1, 1, 1 };
int dx[4] = { -1, 1, 1, -1 };

void solve();
void dfs(int v, int cnt, int color);
bool check(int c, int r);


int main() {
	solve();
}

void solve() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &map[i][j]);
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					colors[i][j] = 1;
				}
			}
			else {
				if (j % 2 != 0) {
					colors[i][j] = 1;
				}
			}
		}
	}
	dfs(-1, 0, 1);
	dfs(-1, 0, 0);
	printf("%d", ans[0] + ans[1]);
}

void dfs(int v, int cnt, int color) {
	if (ans[color] < cnt) {
		ans[color] = cnt;
	}

	for (int i = v + 1; i < n * n; i++) {
		int c = i / n;
		int r = i % n;

		if (colors[c][r] != color) {
			continue;
		}

		if (map[c][r] == 1) {
			if (check(c, r)) {
				visited[i] = true;
				dfs(i, cnt + 1, color);
			}
		}
	}
	if (v == -1) return;
	visited[v] = false;
}

bool check(int c, int r) {
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + r;
		int ny = dy[i] + c;
		int v = ny * n + nx;

		for (int j = 1; j < n; j++) {
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (visited[v]) {
					return false;
				}
			}
			nx += dx[i];
			ny += dy[i];
			v = ny * n + nx;
		}
	}
	return true;
}