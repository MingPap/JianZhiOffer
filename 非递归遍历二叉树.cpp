#include<iostream>
#include<stack>

using namespace std;

struct node {
	int val;
	node* left;
	node* right;
	node(int x) :val(x), left(nullptr), right(nullptr) {};
};

//非递归中序
void INorder(node* root)
{
	if (root == nullptr)
		return;
	stack<node*> s;
	node* p = root;
	while (p||!s.empty())
	{
		while (p)                       //可以改成 if else语句
		{
			s.push(p);
			p = p->left;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			cout << p->val << endl;
			p = p->right;
		}
	}
	cout << endl;
}

//非递归前序

void pre(node* root)
{
	if (root == nullptr)
		return;
	stack<node*> s;
	node*p = root;
	while (p||!s.empty())
	{
		while (p)
		{
			cout << p->val << endl;
			s.push(p);
			p = p->left;
		}

		if(!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
	cout << endl;
}

//后序遍历

void post(node*root)
{
	if (root == nullptr)
		return;
	stack<node*>s;
	node* p = root, *r = nullptr;
	while (p||!s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			if (p->right&&p->right != r)
			{
				p = p->right;
				s.push(p);
				p = p->left;
			}
			else
			{
				p = s.top();
				s.pop();
				cout << p->val << endl;
				r = p;
				p = nullptr;
			}
		}
	}
	cout << endl;
}


int main()
{
	node n1(1), n2(2), n3(3),n4(4),n5(5),n6(6),n7(7);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n3.right = &n7;

	INorder(&n1);
	pre(&n1);
	post(&n1);

	system("pause");
}
