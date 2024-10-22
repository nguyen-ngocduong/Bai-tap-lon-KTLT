#include<bits/stdc++.h>
#include "QuanLyThongBao.h"

using namespace std;

// Constructor
ThongBao::ThongBao() {}
ThongBao::ThongBao(
    string madatphong, string ngaydat,
    string ngaytra, string maphong,
    string loaiphong, string hang,
    string mkh, string tenkh,
    string cmnd, string dob,
    string diachi, string email
) : KhachHang(mkh, tenkh, cmnd, dob, diachi, email), // Khởi tạo lớp cha
    Phong(maphong, loaiphong, hang) // Khởi tạo lớp cha
{
    this->madatphong = madatphong;
    this->ngaydat = ngaydat;
    this->ngaytra = ngaytra;
}
// Nhập thông tin
void ThongBao::nhapthongtin() {
    cout << "Ma Phieu: ";
    cin >> madatphong;
    cout << "Ngay Dat Phong: ";
    cin >> ngaydat;
    cout << "Ngay Tra Phong: ";
    cin >> ngaytra;
    KhachHang::nhapthongtin(); // Gọi phương thức nhập thông tin từ lớp KhachHang
    Phong::nhapthongtin(); // Gọi phương thức nhập thông tin từ lớp Phong
}
//lưu thông tin vào file 

// Lưu thông tin vào file
void ThongBao::themthongtin() {
    ofstream outFile("logs/ThongBao.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Thong Bao Dat Phong" << endl;
        outFile << "Ma Dat Phong: " << madatphong << endl;
        outFile << "Ngay Dat: " << ngaydat << endl;
        outFile << "Ngay Tra: " << ngaytra << endl;
        outFile << "Ma Phong: " << getMaPhong() << endl; // Sử dụng getter
        outFile << "Loai Phong: " << getLoaiPhong() << endl; // Sử dụng getter
        outFile << "Hang Phong: " << getHang() << endl; // Sử dụng getter
        outFile << "Ma Khach Hang: " << getMaKhachHang() << endl; // Sử dụng getter
        outFile << "Ten Khach Hang: " << getTen() << endl; // Sử dụng getter
        outFile << "CMND: " << getCMND() << endl; // Sử dụng getter
        outFile << "Ngay Sinh: " << getDoB() << endl; // Sử dụng getter
        outFile << "Dia Chi: " << getDiaChi() << endl; // Sử dụng getter
        outFile << "Email: " << getEmail() << endl; // Sử dụng getter
        outFile << "-------------------------------------" << endl;
        outFile.close();
    } else {
        cerr << "Khong The Mo File De Luu Thong Bao." << endl;
    }
}

void ThongBao::docthongbao() {
    ifstream infile("logs/ThongBao.txt");
    if(infile.is_open()) {
        string line;
        while(getline(infile, line)){
            cout << line <<endl;
        }
        infile.close();
    }
    else {
        cerr << "Khong The Mo File De Luu Thong Bao." << endl;
    }
}

void ThongBao::xuatphieu() {
    cout<<"-------------------------------------------------------\n";
    cout<<"\t	PHIEU DAT PHONG	\n\n";
    cout << "Ma Phieu: " << madatphong << endl;
    cout << "Ngay Dat: " << ngaydat << endl;
    cout << "Ngay Tra: " << ngaytra << endl;
    cout<<"\t	Thong Tin Dat Phong:\n\n";
    cout << "Ma Phong: " << getMaPhong() << endl;
    cout << "Loai Phong: " << getLoaiPhong() << endl;
    cout << "Hang: " << getHang() << endl;
    cout<<"\t	Thong Tin Khach Hang:\n\n";
    cout << "Ma Khach Hang: " << getMaKhachHang() << endl;
    cout << "Ten Khach Hang: " << getTen() << endl;
    cout << "CMND: " << getCMND() << endl;
    cout << "Ngay Sinh: " << getDoB() << endl;
    cout << "Dia Chi: " << getDiaChi() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "------------------------------------" << endl;
}

void ThongBao::xoakhachhangquahan(){
    // Lấy thời gian hiện tại
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;
    // Chuyển đổi ngày trả phòng thành định dạng int
    int Ngaytra = stoi(ngaytra.substr(0,2));
    int thangtra = stoi(ngaytra.substr(3,2));
    int namtra = stoi(ngaytra.substr(6,4));
    // Nếu ngày trả phòng đã qua thì xóa khách hàng
    if (namtra < currentYear || (namtra == currentYear && thangtra < currentMonth) || 
        (namtra == currentYear && thangtra == currentMonth && Ngaytra < currentDay)) {
        vector<KhachHang> danhSach; 
        KhachHang::xoakhachhang(danhSach, getTen());
        cout << "Da xoa khach hang " << getTen() << endl;
    }
}

void ThongBao::thongBaoTraPhong() {
    cout << "-------------------------------------------------------\n";
    cout << "\tTHONG BAO TRA PHONG\n\n";
    cout << "Ma Phieu: " << madatphong << endl;
    cout << "Ma Khach Hang: " << getMaKhachHang() << endl;
    cout << "Ten Khach Hang: " << getTen() << endl;
    cout << "Ma Phong: " << getMaPhong() << endl;
    cout << "Ngay Tra: " << ngaytra << endl;
    cout << "Cam On Quy Khach Da Su Dung Dich Vu Cua Chung Toi!\n";
    cout << "Chuc Quy Khach Mot Ngay Tot lanh!\n";
    cout << "-------------------------------------------------------\n";
}