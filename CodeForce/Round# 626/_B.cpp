#include <bits/stdc++.h>
using namespace std;

int A[40000];
int B[40000];
int N, M, K;
vector<int> vA;
vector<int> vB;

int cntA(int num)
{

	int ret = 0;
	for (int i = vA.size() - 1; i >= 0; i--)
	{
		if (vA[i] >= num)
		{
			ret += (vA[i] - num + 1);
		}
		else break;
	}
	return ret;
}

int cntB(int num)
{
	int ret = 0;
	for (int i = vB.size() - 1; i >= 0; i--)
	{
		if (vB[i] >= num)
		{
			ret += (vB[i] - num + 1);
		}
		else break;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	vector<int> v;
	for (int i = 1; i <= max(N, M); i++)
	{
		if (K % i == 0)
		{
			v.push_back(i);
		}
	}
	int cont = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (A[i]) cont++;
		else
		{
			if (cont == 0) continue;
			vA.push_back(cont);
			cont = 0;
		}
	}
	if (cont != 0) vA.push_back(cont);
	cont = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> B[i];
		if (B[i]) cont++;
		else
		{
			if (cont == 0) continue;
			vB.push_back(cont);
			cont = 0;
		}
	}
	if (cont != 0) vB.push_back(cont);
	sort(vA.begin(), vA.end());
	sort(vB.begin(), vB.end());
	long long int answer = 0;
	for (auto s : v)
	{
		answer += (cntA(s) * cntB(K / s));
	}
	cout << answer;



	return 0;
}