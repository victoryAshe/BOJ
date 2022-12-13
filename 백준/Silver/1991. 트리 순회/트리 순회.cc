// 트리 순회: https://www.acmicpc.net/problem/1991
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct Node
{
public:
	char val;
	Node* left = NULL;
	Node* right = NULL;
	Node(int v)
	{
		val = v;
	}
};

struct findNode : public binary_function<Node, char, bool>
{
public:
	bool operator()(const Node a, char b) const
	{
		return (a.val == b);
	}
};

void pre(Node *n)
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

	// 노드 연결
	for (int i = 0; i < N; i++)
	{
		char v, l, r;
		cin >> v >> l >> r;

		int Vidx = find_if(tree.begin(), tree.end(), bind2nd(findNode(), v)) - tree.begin();

		if (l != '.')
		{
			int Lidx = 
				find_if(tree.begin(), tree.end(), bind2nd(findNode(), l)) - tree.begin();
			tree[Vidx].left = &tree[Lidx];
		}
		if (r != '.')
		{
			int Ridx = 
				find_if(tree.begin(), tree.end(), bind2nd(findNode(), r)) - tree.begin();
			tree[Vidx].right = &tree[Ridx];
		}
	}

	// 각각의 순회에 대한 출력
	pre(&tree[0]);
	cout << endl;

	in(&tree[0]);
	cout << endl;

	post(&tree[0]);
	cout << endl;
	return 0;
}
