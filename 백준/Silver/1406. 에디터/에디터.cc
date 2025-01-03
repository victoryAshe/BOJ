#include <iostream>
using namespace std;

struct Node {
public:
	char c = '_';
	Node* prev = nullptr;
	Node* next = nullptr;
	Node(char _c) : c(_c) {};
	Node() {};
};

Node nodes[600001];

Node head = Node();
Node* p = &head;
int idx = 0;

void Solution(string& s)
{
	char c;
	cin >> c;

	if (c == 'L')
	{
		if (p != &head)
		{
			p = p->prev;
		}
	}
	else if (c == 'D')
	{
		if (p->next != nullptr)
		{
			p = p->next;
		}
	}
	else if (c == 'B')
	{
		if (p != &head)
		{
			if (p->next != nullptr)
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
			}
		    else p->prev->next = nullptr;

			p = p->prev;
		}
	}
	else if (c == 'P')
	{
		char q;
		cin >> q;
		nodes[idx].c = q;

		if (p->next != nullptr)
		{
			p->next->prev = &nodes[idx];
			nodes[idx].next = p->next;
		}	
		nodes[idx].prev = p;
		p->next = &nodes[idx];
		p = p->next;
		idx++;
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int M;
	cin >> M;

	for (char c : s)
	{
		nodes[idx].c = c;
		p->next = &nodes[idx];
		nodes[idx].prev = p;
		p = p->next;
		idx++;
	}

	for (int i = 0; i < M; i++)
	{
		Solution(s);
	}

	
	p = head.next;
	while (p != nullptr)
	{
		cout << p->c;
		p = p->next;
	}
	
	return 0;
}