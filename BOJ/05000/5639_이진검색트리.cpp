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

struct node
{
	int num;
	node* left, * right, * parent;
	node()
	{
		left = right = parent = NULL;
	}
	node(int n)
	{
		left = right = parent = NULL;
		num = n;
	}

};

node* root, *now;
int idx;

node* Insert(node* r, node* n)
{
	if (r == NULL) return n;
	if (n->num < r->num) r->left = Insert(r->left, n);
	else r->right = Insert(r->right, n);
	return r;
}

void Print(node* n)
{
	if (n->left != NULL) Print(n->left);
	if (n->right != NULL) Print(n->right);
	COUT(n->num);
	ENDL;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> idx;
	root = new node();
	root->num = idx;
	now = root;
	while (cin >> idx)
	{
		now = Insert(now, new node(idx));
	}
	Print(root);

	return 0;
}