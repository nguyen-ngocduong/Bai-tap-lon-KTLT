#include<bits/stdc++.h>
#include "KhachHang.h"

using namespace std;

KhachHang::KhachHang() {} // khởi tạo KhachHang()

KhachHang::KhachHang(string MKH, string ten, string cmnd, string ns, string dc, string mail)
    : MaKhachHang(MKH), Ten(ten), CMND(cmnd), DoB(ns), DiaChi(dc), Email(mail){}

void KhachHang::luuDanhSachKhachHang(const vector<KhachHang>& danhSach) {
    ofstream file("logs/khachhang.txt");
    if (!file) {
        cerr << "Khong the mo tep de luu du lieu." << endl;
        return;
    }
    for (const auto& kh : danhSach) {
        file << kh.getMaKhachHang()<< "," << kh.getTen() << "," << kh.getDoB() << "," << kh.getDiaChi() << ","  
             << kh.getEmail() << "," << kh.getCMND() << endl;
    }
    file.close(); // Đảm bảo tệp được đóng
}

    void KhachHang::hienThi(int soThuTu) const {
    cout << soThuTu << ". MKH: " << MaKhachHang << ", Ten: " << Ten 
         << ", DoB: " << DoB << ", Dia Chi: " << DiaChi 
         << ", Email: " << Email << ", CCCD: " << CMND << endl;    }

void KhachHang::themkhachhang(vector<KhachHang>& danhSach) {
    KhachHang kh;
    string temp;
    cin.ignore();
    cout << "Nhap Ma Khach Hang: ";
    
    getline(cin, temp);
    kh.setMaKhachHang(temp);
    cout << "Nhap Ten: ";
    
    getline(cin, temp);
    kh.setTen(temp);

    cout << "Nhap Ngay Sinh: ";
    
    getline(cin, temp);
    kh.setDoB(temp);

    cout << "Nhap Dia Chi: ";
    
    getline(cin, temp);
    kh.setDiaChi(temp);
    
    cout << "Nhap email: ";
    
    getline(cin, temp);
    kh.setEmail(temp);
    
    cout << "Nhap so CCCD: ";
    
    getline(cin, temp);
    kh.setCMND(temp);

    danhSach.push_back(kh);
    luuDanhSachKhachHang(danhSach);
}
// void KhachHang::docdanhsach() {
//     ifstream file("logs/KhachHang.txt");
//     if (file.is_open()) {
//         string line;
//         while (getline(file, line)) {
//             cout << line << endl;  // Display the line as it is, since it's already in the desired format
//         }
//         file.close();
//     } else {
//         cout << "Khong The Mo File De Doc Danh Sach Khach Hang!" << endl;
//     }
// }
void KhachHang::docdanhsach(vector<KhachHang>& danhSach) {
    ifstream file("logs/khachhang.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string makh, ten, dob, diachi, email, cmnd;

            getline(ss, makh, ','); // Đọc mã khách hàng
            getline(ss, ten, ','); // Đọc tên
            getline(ss, dob, ','); // Đọc ngày sinh
            getline(ss, diachi, ','); // Đọc địa chỉ
            getline(ss, email, ','); // Đọc email
            getline(ss, cmnd); // Đọc CMND

            // Tạo đối tượng KhachHang và hiển thị
            KhachHang kh(makh, ten, cmnd, dob, diachi, email);
            kh.hienThi(1); // Hoặc số thứ tự thích hợp
        }
        file.close();
    } else {
        cout << "Khong The Mo File De Doc Danh Sach Khach Hang!" << endl;
    }
}

void KhachHang::xoakhachhang(vector<KhachHang>& danhSach, const string& ten) {
    for (size_t i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i].getTen() == ten) {
            danhSach.erase(danhSach.begin() + i);
            luuDanhSachKhachHang(danhSach);
            cout << "Da xoa khach hang: " << ten << endl;
            return;
        }
    }
    cout << "Khong tim thay khach hang voi ten: " << ten << endl;
}
void KhachHang::timKiemKhachHang(const vector<KhachHang>& danhSach, const string& ten) {
    for (size_t i = 0; i < danhSach.size(); i++) {
        if (danhSach[i].getTen() == ten) {
            danhSach[i].hienThi(i + 1);
            return;
        }
    }
    cout << "Khong tim thay khach hang voi ten: " << ten << endl;
}

void KhachHang::suaKhachHang(vector<KhachHang>& danhSach, const string& ten) {
    for (auto& kh : danhSach) {
        if (kh.getTen() == ten) {
            string temp;
            cout << "Nhap thong tin moi cho khach hang " << ten << ":" << endl;
            cout << "Ten: ";
            getline(cin, temp);
            kh.setTen(temp);

            cout << "Nhap Ngay Sinh: ";
            getline(cin, temp);
            kh.setDoB(temp);
            
            cout << "Dia chi: ";
            getline(cin, temp);
            kh.setDiaChi(temp);
            
            cout << "Email: ";
            getline(cin, temp);
            kh.setEmail(temp);
            
            cout << "So CCCD: ";
            getline(cin, temp);
            kh.setCMND(temp);
            
            luuDanhSachKhachHang(danhSach);
            return;
        }
    }
    cout << "Khong tim thay khach hang voi ten: " << ten << endl;
}

void KhachHang::nhapthongtin() {
    cout << "Nhap Ma Khach Hang: ";
    cin.ignore(); // Để bỏ qua ký tự newline còn lại trong buffer
    getline(cin, MaKhachHang); // Giả sử makhachhang là biến thành viên của lớp

    cout << "Nhap Ten Khach Hang: ";
    getline(cin, Ten); // Giả sử tenkh là biến thành viên của lớp

    cout << "Nhap CMND: ";
    getline(cin, CMND); // Giả sử cmnd là biến thành viên của lớp

    cout << "Nhap Ngay Sinh (dd/mm/yyyy): ";
    getline(cin, DoB); // Giả sử dob là biến thành viên của lớp

    cout << "Nhap Dia Chi: ";
    getline(cin, DiaChi); // Giả sử diachi là biến thành viên của lớp

    cout << "Nhap Email: ";
    getline(cin, Email); // Giả sử email là biến thành viên của lớp
}