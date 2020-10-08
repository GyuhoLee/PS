#include <bits/stdc++.h>
using namespace std;
vector<int> edge[250001];
int dist[250001], dist2[250001];

void DFS(int now)
{
    for (int next : edge[now])
    {
        if (dist[next] != -1) continue;
        dist[next] = dist[now] + 1;
        DFS(next);
    }
}

void DFS2(int now)
{
    for (int next : edge[now])
    {
        if (dist2[next] != -1) continue;
        dist2[next] = dist2[now] + 1;
        DFS2(next);
    }
}

int solution(int n, vector<vector<int>> edges)
{
    int answer = 0;
    for (auto v : edges)
    {
        edge[v[0]].push_back(v[1]);
        edge[v[1]].push_back(v[0]);
    }
    for (int i = 1; i <= n; i++) dist[i] = -1;
    dist[1] = 0;
    DFS(1);
    int first = -1, fIdx = -1, second = -1, sIdx = -1;
    for (int i = 1; i <= n; i++)
    {
        if (first < dist[i])
        {
            second = first;
            sIdx = fIdx;
            first = dist[i];
            fIdx = i;
        }
        else if (second < dist[i])
        {
            second = dist[i];
            sIdx = i;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        dist[i] = -1;
        dist2[i] = -1;
    }
    dist[fIdx] = 0;
    DFS(fIdx);
    dist2[sIdx] = 0;
    DFS2(sIdx);
    for (int i = 1; i <= n; i++)
    {
        if (i == fIdx || i == sIdx) continue;
        int arr[3] = { dist[i], dist2[i], dist[sIdx] };
        sort(arr, arr + 3);
        answer = max(answer, arr[1]);
    }

    return answer;
}