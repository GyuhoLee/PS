#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> S;
	for (auto s : moves)
	{
		s -= 1;
		if (board[board.size() - 1][s] == 0) continue;
		for (int i = 0; i < board.size(); i++)
		{
			if (board[i][s] != 0)
			{
				if (!S.empty() && S.top() == board[i][s])
				{
					answer += 2;
					board[i][s] = 0;
					S.pop();
				}
				else
				{
					S.push(board[i][s]);
					board[i][s] = 0;
				}
				break;
			}
		}
	}
	return answer;
}