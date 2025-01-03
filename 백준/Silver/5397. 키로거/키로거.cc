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

Node nodes[1000001];

void Solution(string& s)
{
	Node head = Node('_');
	Node* p = &head;
	
	int idx = 0;

	for (char c: s)
	{
		if (c == '<')
		{
			if (p != &head)
			{
				p = p->prev;
			}
		}
		else if (c == '>')
		{
			if (p->next != nullptr)
			{
				p = p->next;
			}
		}
		else if (c == '-')
		{
			if (p != &head)
			{
				p->prev->next = p->next;
				if (p->next != nullptr) p->next->prev = p->prev;
				p = p->prev;
			}
		}
		else
		{
			nodes[idx] = Node(c);
			if (p->next != nullptr)
			{
				nodes[idx].next = p->next;
				p->next->prev = &nodes[idx];
			}
			nodes[idx].prev = p;

			p->next = &nodes[idx];
			p = p->next;
			idx++;
		}
	}
	
	p = head.next;
	while (p != nullptr)
	{
		cout << p->c;
		p = p->next;
	}
	cout << "\n";
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;
		Solution(s);
	}

	return 0;
}