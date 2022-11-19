#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include"string"
using namespace std;
struct hanghoa {
	char maHH[10];
	char ten[50];
	int soLuong;
	int donGia;
};

typedef struct Node* nodeptr;
struct Node {
	Node* link;
	hanghoa data;

};
struct List {
	nodeptr first;
	nodeptr last;
};

//them,xoa,sua,tim,hien_thi,doc+ghi_file,
void khoitao(List& list);
nodeptr taoNode(hanghoa hh);
bool ktTrungMa(List& list, hanghoa hh);
void nhap(List list,hanghoa &hh);
void hienthi(hanghoa hh);
void them(List& list, hanghoa hh);
void xoa(List& list, char x[]);
void sua(List& list, char s[]);
void hienThiDanhSachHangHoa(List& list);
void tim(List& list, char t[]);
void menu();
void docfile(const char* filename, List& list);
void ghifile(const char* filename, List& list);
int sosanh(List& list, char t[]);
string ChuyenDoi(int v);

