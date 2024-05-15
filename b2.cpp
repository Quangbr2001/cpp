  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>

 using namespace std;

 class VanDongVien {
 private:
     string hoten;
     int tuoi;
     string monthidau;
     double cannang;
     double chieucao;

 public:
     // Hàm thiết lập không tham số
     VanDongVien() {
         hoten = "";
         tuoi = 0;
         monthidau = "";
         cannang = 0.0;
         chieucao = 0.0;
     }

     // Hàm thiết lập 5 tham số
     VanDongVien(string ho, int t, string mon, double cn, double cc) {
         hoten = ho;
         tuoi = t;
         monthidau = mon;
         cannang = cn;
         chieucao = cc;
     }

     // Hàm hủy
     ~VanDongVien() {}

     // Nạp chồng toán tử nhập >>
     friend istream& operator>>(istream& is, VanDongVien& vdv);

     // Nạp chồng toán tử xuất <<
     friend ostream& operator<<(ostream& os, const VanDongVien& vdv);

     // Nạp chồng toán tử so sánh >
     bool operator>(const VanDongVien& other) const {
         if (chieucao > other.chieucao) {
             return true;
         } else if (chieucao == other.chieucao && cannang > other.cannang) {
             return true;
         }
         return false;
     }
 };

 // Nạp chồng toán tử nhập >>
 istream& operator>>(istream& is, VanDongVien& vdv) {
     cout << "Nhap ho ten: ";
     getline(is, vdv.hoten);
     cout << "Nhap tuoi: ";
     is >> vdv.tuoi;
     is.ignore(); // Loại bỏ ký tự '\n' sau khi nhập tuổi
     cout << "Nhap mon thi dau: ";
     getline(is, vdv.monthidau);
     cout << "Nhap can nang (kg): ";
     is >> vdv.cannang;
     cout << "Nhap chieu cao (m): ";
     is >> vdv.chieucao;
     return is;
 }
 // Nạp chồng toán tử xuất <<
 ostream& operator<<(ostream& os, const VanDongVien& vdv) {
     os << "Ho ten: " << vdv.hoten << endl;
     os << "Tuoi: " << vdv.tuoi << endl;
     os << "Mon thi dau: " << vdv.monthidau << endl;
     os << "Can nang: " << vdv.cannang << " kg" << endl;
     os << "Chieu cao: " << vdv.chieucao << " m" << endl;
     return os;
 }

 int main() {
     // Khai báo đối tượng lớp VanDongVien sử dụng hàm thiết lập 5 tham số
     VanDongVien p("Nguyen Van A", 25, "Bong da", 70.5, 1.75);
     cout << "Thong tin van dong vien p:" << endl;
     cout << p << endl;

     // Nhập danh sách vận động viên
     int n;
     cout << "Nhap so luong van dong vien: ";
     cin >> n;
     cin.ignore(); // Loại bỏ ký tự '\n' sau khi nhập n
     vector<VanDongVien> danhsach(n);
     cout << "Nhap thong tin cac van dong vien:" << endl;
     for (int i = 0; i < n; i++) {
         cout << "Van dong vien " << i + 1 << ":" << endl;
         cin >> danhsach[i];
     }

     // Hiển thị danh sách đã nhập
     cout << "Danh sach van dong vien:" << endl;
     for (const auto& vdv : danhsach) {
         cout << vdv << endl;
     }

     // Sắp xếp danh sách theo thứ tự tăng dần
     sort(danhsach.begin(), danhsach.end(), [](const VanDongVien& a, const VanDongVien& b) {
         return !(a > b);
     });

     // Hiển thị danh sách đã sắp xếp
     cout << "Danh sach van dong vien sau khi sap xep:" << endl;
     for (const auto& vdv : danhsach) {
         cout << vdv << endl;
     }

     return 0;
 }