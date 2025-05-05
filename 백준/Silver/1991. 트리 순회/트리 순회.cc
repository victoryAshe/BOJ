#include <iostream>
#include <vector>
using namespace std;

struct Node
{
public:
	char val;
	Node* left = NULL;
	Node* right = NULL;
	Node(int v) { val = v; }
};

void pre(Node* n)
{
	cout << n->val;
	if (n->left != nullptr)
		pre(n->left);
	if (n->right != nullptr)
		pre(n->right);
}

void in(Node* n)
{
	if (n->left != nullptr)
		in(n->left);
	cout << n->val;
	if (n->right != nullptr)
		in(n->right);
}

void post(Node* n)
{
	if (n->left != nullptr)
		post(n->left);
	if (n->right != nullptr)
		post(n->right);
	cout << n->val;
}

int main()
{
	// 노드 만들기
	int N;
	cin >> N;

	vector<Node> tree;
	for (int i = 0; i < N; i++)
	{
		Node* node = new Node('A' + i);
		tree.push_back(*node);
	}

	for (int i = 0; i < N; i++)
	{
		char v, l, r;
		cin >> v >> l >> r;

		int Vidx = v - 'A';

		if (l != '.')
		{
			int Lidx = l - 'A';
			tree[Vidx].left = &tree[Lidx];
		}
		if (r != '.')
		{
			int Ridx = r - 'A';
			tree[Vidx].right = &tree[Ridx];
		}
	}

	pre(&tree[0]);
	cout << endl;

	in(&tree[0]);
	cout << endl;

	post(&tree[0]);
	cout << endl;
	return 0;
}
