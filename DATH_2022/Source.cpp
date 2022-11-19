#include"header.h"
void nhap(List list,hanghoa &hh) {
	
	do {
		cout << "MA HANG HOA: ";
		cin >> hh.maHH;
	} while (sosanh(list, hh.maHH) == 1);
	cin.ignore();
	cout << "\nNHAP TEN HANG: ";
	cin >> hh.ten;
	cout << "\nSO LUONG: ";
	cin >> hh.soLuong;
	cout << "\nGIA: ";
	cin >> hh.donGia;

}

int isEmpty(List list)
{
	if (list.first == NULL)
		return 1;
	return 0;
}


void khoitao(List& list) {
	list.first = list.last = NULL;
}

nodeptr taoNode(hanghoa hh) {
	nodeptr p = new Node;
	if (p == NULL)
		return NULL;
	p->data = hh;
	p->link = NULL;
	return p;
}
void hienthi(hanghoa hh) {
	cout << "\nMa hang hoa: " << hh.maHH;
	cout << "\nTen hang hoa: " << hh.ten;
	cout << "\nSo luong hang la: " << hh.soLuong;
	cout << "\nGia: " << ChuyenDoi(hh.donGia) << " Vnd";
}

void hienThiDanhSachHangHoa(List& list) {
	nodeptr node_temp = list.first;
	if (!isEmpty(list)) {
		do {
			hienthi(node_temp->data);
			cout << "\n-------------";
			node_temp = node_temp->link;
		} while (node_temp != list.first);
	}
	else {
		cout << "\nKhong co hang hoa nao";
	}

}

int sosanh(List &list, char m[]) {
	if (isEmpty(list)) {
		cout << "\nKhong co hang hoa";
		return 0;
	}

	nodeptr node_i = list.first;
	do {
		if (strcmp(node_i->data.maHH, m) == 0) {
			return 1; //đã tìm thấy hàng hoá thoát khỏi hàm
		}
		node_i = node_i->link;
	} while (node_i != list.first);
	return 0;
}

void them(List& list, hanghoa hh) {
	nodeptr p = taoNode(hh);
	if (isEmpty(list)) {
		list.first = list.last = p;
		list.first->link = list.last->link = list.first;
	}
	else {
		if (sosanh(list, hh.maHH) != 1) {

			list.last->link = p;
			p->link = list.first;
			list.first = p;
		}
		else
			cout << "\nMa hang da ton tai!!";
	}
}

void xoa(List& list, char x[]) {
	if (isEmpty(list)) {
		cout << "\nKhong co hang hoa de xoa";
		return;
	}
	nodeptr node_i = list.first, node_prev = NULL;
	if (list.first == list.first->link) {
		if (strcmp(list.first->data.maHH, x) == 0) {
			list.first = NULL;
			delete node_i;
			node_i = NULL;
		}
		return;
	}
	do
	{
		node_prev = node_i;
		node_i = node_i->link;
		if (strcmp(node_i->data.maHH, x) == 0)
		{
			node_prev->link = node_i->link;
			if (node_i == list.first) { 
				list.first = node_prev;
			}
			delete node_i;
			node_i = NULL;
			node_i = node_prev->link;
		}

	} while (node_i != list.first);
}

void suaNode(nodeptr& node, hanghoa hh) {
	node->data = hh;
}

void sua(List& list, char s[]) {
	if (isEmpty(list)) {
		cout << "\nKhong co hang hoa de sua";
		return;
	}
	nodeptr node_i = list.first;
	do {
		if (strcmp(node_i->data.maHH, s) == 0) {
			cout << "\nThong tin hang hoa cu: ";
			hienthi(node_i->data);
			cout << "\n-------------";
			cout << "\nNhap lai san pham: " << endl;
			hanghoa new_hanghoa;
			nhap(list,new_hanghoa); 
			suaNode(node_i, new_hanghoa); 
			return;
		}
		node_i = node_i->link;
	} while (node_i != list.first);
	cout << "\nMa hang hoa khong ton tai";
}

void tim(List& list, char t[]) {
	if (isEmpty(list)) {
		cout << "\nKhong co hang hoa de tim";
		return;
	}
	nodeptr node_i = list.first;
	do {
		if (strcmp(node_i->data.maHH, t) == 0) {
			hienthi(node_i->data); 
			return; 
		}
		node_i = node_i->link;
	} while (node_i != list.first);
	cout << "\nMa hang hoa khong ton tai";
}



void menu() {
	cout << "\n1. Hien thi danh sach hang hoa .";
	cout << "\n2. Them hang hoa.";
	cout << "\n3. Xoa hang hoa.";
	cout << "\n4. Sua thong tin san pham.";
	cout << "\n5. Tim kiem thong tin hang hoa.";
	cout << "\n6. Ghi file.";
	cout << "\n7. Doc file.";
	cout << "\n0. Thoat chuong trinh.";
}

void docfile(const char* filename, List& list) {
	hanghoa hh;
	FILE *f = fopen(filename, "rb");
	if (f != NULL) {
		while (!feof(f)) {
			fscanf(f, "%s\n", &hh.maHH);
			fscanf(f, "%s\n", &hh.ten);
			char soluong[10];
			fgets(soluong, 10, f);
			hh.soLuong = atof(soluong);
			char dongia[10];
			fgets(dongia, 10, f);
			hh.donGia = atof(dongia);
			them(list, hh);
		}
		fclose(f);
	}
}

void  ghifile(const char *filename, List &list)
{
	if (isEmpty(list)) {
		cout << "\nKhong co hang hoa de luu";
		return;
	}
	FILE *f = fopen(filename, "w+");
	nodeptr a = list.first;
	do {
		hanghoa chon = a->data;
		fprintf(f, "%s\n", chon.maHH);
		fprintf(f, "%s\n", chon.ten);
		fprintf(f, "%d\n", chon.soLuong);
		fprintf(f, "%d\n", chon.donGia);
		a = a->link;
	} while (a != list.first);
	fclose(f);
}

string ChuyenDoi(int v) {
	string s = std::to_string(v);
	int n = s.length() - 3;
	int end = (v >= 0) ? 0 : 1;
	while (n > end) {
		s.insert(n, ",");
		n -= 3;
	}
	return s;
}
