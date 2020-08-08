#include<iostream>
#include<queue>
using namespace std;
             
int N, M, V;                    
int mat[1001][1001];
int visit[1001];
 
void dfs(int v)
{
    printf("%d ", v);
    visit[v] = 1;
    for(int i=1; i<=N; i++)
    {
        if(visit[i] == 1 || mat[v][i] == 0) continue;
        dfs(i);   
    }
}
 
void bfs(int v)
{
    queue<int> q;   
    q.push(v);
    visit[v] = 0; 
    while(!q.empty())
    {
        v = q.front();
        printf("%d ", q.front());
        q.pop();
        for(int i=1; i<=N; i++)
        {
            if(visit[i] == 0 || mat[v][i] == 0) continue;
            q.push(i);
            visit[i] = 0;
        }
    }
}
 
int main()
{
    int x, y;
    cin >> N >> M >> V;
    for(int i=0; i<M; i++)
    {
        cin >> x >> y;            
        mat[x][y] = mat[y][x] = 1;
    }
    dfs(V);            
    printf("\n");
    bfs(V);
    return 0;
}
