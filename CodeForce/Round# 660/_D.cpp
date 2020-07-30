#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N;
ll arr[200001], b[200001], answer = 0;
vector<vector<int>> vt;
stack<int> st;
int visited[200001];

void DFS(int v)
{
    visited[v] = true;
    for (auto i : vt[v])
    {
        if (visited[i])
            continue;
        DFS(i);
    }
    st.push(v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    CIN(N);
    vt.resize(N + 1);
    MS(visited, 0);
    FUP(i, 1, N) CIN(arr[i]);
    FUP(i, 1, N)
    {
        int num;
        CIN(num);
        b[i] = num;
        if (num == -1 || arr[i] == 0) continue;
        if (arr[i] < 0)
        {
            vt[num].push_back(i);
        }
        else
        {
            vt[i].push_back(num);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
            DFS(i);
    }
    queue<int> q;
    while (st.size())
    {
        q.push(st.top());
        answer += arr[st.top()];
        arr[b[st.top()]] += arr[st.top()];
        st.pop();
    }
    COUT(answer);
    ENDL;
    while (!q.empty())
    {
        COUT2(q.front(), "");
        q.pop();
   }

	return 0;
}