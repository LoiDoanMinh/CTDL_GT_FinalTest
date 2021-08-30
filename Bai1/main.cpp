#include <iostream>
#include <string>
using namespace std;
struct MatHang
{
	int MaSP;
	string TenSP;
	int SoLuong;
	int NamSX;
	int DonGia;
};
struct node
{
	MatHang data;
	node* pNext;
};
struct list
{
	node* pHead;
	node* pTail;
};
node* KhoiTaoNode(MatHang x);
void KhoiTaoList(list& l);
void Input(MatHang& x);
void Ouput(MatHang x);
void ThemVaoCuoi(list& l, node* p);
void NhapMatHangTail(list& l);
void Xuat(list l);
void SapXepMatHangMaSPTangDan(list& l);
void menu(list& l);
int main()
{
	list l;
	KhoiTaoList(l);
	menu(l);

}
void menu(list& l)
{
	int luachon;
	while (1)
	{
		cout << "\n\n\t\t===========MENU===========";
		cout << "\n\t1.Nhap danh sach mat hang (them vao cuoi) va xuat.";
		cout << "\n\t2.";
		cout << "\n\t3.Sap xep mat hang theo chieu ma san pham tang dan ";
		cout << "\n\n\t\t===========END===========";
		cout << "\nNhap lua chon : ";
		cin >> luachon;
		if (luachon == 1)
		{
			NhapMatHangTail(l);
			Xuat(l);
			system("pause");
		}
		else if (luachon == 2)
		{
			system("pause");
		}
		else if (luachon == 3)
		{
			SapXepMatHangMaSPTangDan(l);
			Xuat(l);
			system("pause");
		}
		else
			break;
	}
}
node* KhoiTaoNode(MatHang x)
{
	node* p = new node();
	if (p == NULL)
		return NULL;
	else
	{
		p->data = x;
		p->pNext = NULL;
		return p;
	}
}
void KhoiTaoList(list& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void Input(MatHang& x)
{
	cout << "\nNhap ma san pham : ";
	cin >> x.MaSP;
	cin.ignore();
	cout << "Nhap ten san pham : ";
	getline(cin, x.TenSP);
	cout << "Nhap so luong : ";
	cin >> x.SoLuong;
	cout << "Nhap nam san xuat : ";
	cin >> x.NamSX;
	cout << "Nhap don gia : ";
	cin >> x.DonGia;
}
void Ouput(MatHang x)
{
	cout << "\nMa san pham : " << x.MaSP << endl;
	cout << "Ten san pham : " << x.TenSP << endl;
	cout << "So luong : " << x.SoLuong << endl;
	cout << "Nam san xuat : " << x.NamSX << endl;
	cout << "Don gia : " << x.DonGia << endl;
}
void ThemVaoCuoi(list& l, node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void NhapMatHangTail(list& l)
{
	int n;
	cout << "\nNhap so luong mat hang : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		MatHang x;
		Input(x);
		node* p = KhoiTaoNode(x);
		ThemVaoCuoi(l,p);
	}
}
void Xuat(list l)
{
	for (node* p = l.pHead; p != NULL; p = p->pNext)
	{
		Ouput(p->data);
	}
}
void SapXepMatHangMaSPTangDan(list& l)
{
	for (node* k = l.pHead; k != NULL; k = k->pNext)
	{
		for (node* q = k->pNext; q != NULL; q = q->pNext)
		{
			if (q->data.MaSP < k->data.MaSP)
			{
				swap(q->data, k->data);
			}
		}
	}
}

