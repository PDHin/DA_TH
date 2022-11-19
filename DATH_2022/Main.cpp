
#include"Source.cpp"
int main() {
	nodeptr node;
	hanghoa hh;
	List list;
	khoitao(list);
	int n;
	cout << "\nCHUONG TRINH QUAN LI HANG HOA.";
	do {
		cout << "\n*********************************";
		menu();
		cout << "\nHay chon chuc nang ban muon thuc hien: ";
		cout << "\nHay nhap 0 de thoat chuong trinh.";
		cout << "\nBan nhap so: ";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "\nDanh sach hang hoa";
			hienThiDanhSachHangHoa(list);
			break;

		case 2:
			cout << "\nNhap thong tin hang hoa can them: " << endl;
				nhap(list,hh);
				them(list,hh);
			break;
		case 3:
			char x[10];
			cout << "\nNhap ma hang ban muon xoa: ";
			cin >> x;
			xoa(list, x);
			break;
		case 4:
			char s[10];
			cout << "\nNhap ma hang ma ban muon sua: ";
			cin >> s;
			sua(list, s);
			break;
		case 5:
			char t[10];
			cout << "\nNhap ma hang ma ban muon tim: ";
			cin >> t;
			tim(list, t);
			break;
		case 6:
			ghifile("dshh.txt", list);
		case 7:
			docfile("dshh.txt", list);

		default:
			break;
		}
		cout << endl;
	} while (n != 0);
	return 0;
}
