#include <iostream>
#include <algorithm>
using namespace std;

int arr[36] = { 0, 2, 4, 6, 8, 10,
				12, 14, 16, 18, 20,
				22, 24, 26, 28, 30,
				32, 34, 36, 38, 0,
				13, 16, 19, 0, 22, 24, 0,
				28, 27, 26, 25, 30,
				35, 40, 0 };
int dice[10];
int answer = 0;
struct Node
{
	int piece[4];
	int start;
	int idx;
	int cnt;
	Node(int a[], int b, int c, int d) : start(b), idx(c), cnt(d)
	{
		for (int i = 0; i < 4; i++) piece[i] = a[i];
	}
};

void DFS(Node node)
{
	if (node.idx == 10)
	{
		answer = max(answer, node.cnt);
		return;
	}

	for (int i = 0; i <= node.start; i++)
	{
		if (node.piece[i] == 35) continue;
		int tempCnt = node.cnt;
		int tempPiece = node.piece[i];
		switch (tempPiece)
		{
		case 5: tempPiece = 20; break;
		case 10: tempPiece = 24; break;
		case 15: tempPiece = 27; break;
		}
		for (int j = 0; j < dice[node.idx]; j++)
		{
			if (tempPiece == 23 || tempPiece == 26) tempPiece = 31;
			else if (tempPiece == 19) tempPiece = 34;
			else if (tempPiece == 35) break;
			else tempPiece++;
		}
		tempCnt += arr[tempPiece];
		if (tempPiece == 35 || (tempPiece != node.piece[0] && tempPiece != node.piece[1] && tempPiece != node.piece[2] && tempPiece != node.piece[3]))
		{
			int tempArr[4] = { node.piece[0] , node.piece[1] ,node.piece[2] ,node.piece[3] };
			tempArr[i] = tempPiece;
			int tempStart = 3;
			for (int j = 0; j < 4; j++)
			{
				if (tempArr[j] == 0)
				{
					tempStart = j;
					break;
				}
			}
			DFS(Node(tempArr, tempStart, node.idx + 1, tempCnt));
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10; i++) cin >> dice[i];
	int temp[4] = { 0, 0, 0, 0 };
	DFS(Node(temp, 0, 0, 0));
	cout << answer;
	return 0;
}