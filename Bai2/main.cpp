#include  <iostream>
using namespace std;
struct Node
{
	int data;
	Node* pLeft;
	Node* pRight;
};
typedef struct Node* Tree;
void KhoiTaoTree(Tree& t)
{
	t = NULL;
}
Node* KhoiTaoNode(int x)
{
	Node* p = new Node();
	if (p == NULL)
		return NULL;
	else
	{
		p->data = x;
		p->pLeft = p->pRight = NULL;
	}
	return p;
}
int ThemNodeVaoCay(Tree& t, int x)
{
	if (t == NULL)
	{
		Node* p = new Node;
		if (p == NULL)
			return -1;
		p->data = x;
		p->pLeft = p->pRight = NULL;
		t = p;
		return 1;
	}
	else
	{
		if (x < t->data)
			ThemNodeVaoCay(t->pLeft, x);
		if (x > t->data)
			ThemNodeVaoCay(t->pRight, x);
		if (t->data == x)
			return -1;
	}
}
void DuyetLRN(Tree t)
{
	if (t != NULL)
	{
		DuyetLRN(t->pLeft);
		DuyetLRN(t->pRight);
		cout << t->data << " ";
	}
}
bool soCP(int n) {
	int i = 0;
	while (i * i <= n) {
		if (i * i == n) {
			return true;
		}
		++i;
	}
	return false;
}
void InSoCP(Tree t)
{
	if (t != NULL)
	{
		if (soCP(t->data))
			cout << t->data << " ";
		InSoCP(t->pLeft);
		InSoCP(t->pRight);
	}
}
void InNodeLevelK(Tree t, int k)
{
	if (t == NULL || k < 0)
		return;
	if (k == 0)
	{
		cout << t->data << " ";
		return;
	}

	InNodeLevelK(t->pLeft, k - 1);
	InNodeLevelK(t->pRight, k - 1);

}
void menu(Tree & t)
{
	int luachon;
	while (1)
	{
		cout << "\n\n\t\t===========MENU===========";
		cout << "\n\t1.In ket qua phep duyet theo LNR";
		cout << "\n\t2.In cac node o level k";
		cout << "\n\t3.In ra cac so chinh phuong";
		cout << "\n\n\t\t===========END===========";
		cout << "\nNhap lua chon : ";
		cin >> luachon;
		if (luachon == 1)
		{
			cout << "Duyet theo LRN : ";
			DuyetLRN(t);
			system("pause");
		}
		else if (luachon == 2)
		{
			int k;
			cout << "Nhap level k : ";
			cin >> k;
			cout << "Cac node o level : " << k << end;
			InNodeLevelK(t, k);
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << "Cac so chinh phuong : ";
			InSoCP(t);
			system("pause");
		}
		else
			break;
	}
}
int main()
{
	Tree t;
	KhoiTaoTree(t);
	int n;
	cout << "Nhap so node : ";
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap gia tri node : ";
		cin >> x;
		ThemNodeVaoCay(t, x);
	}
	menu(t);
}