// PhongModules.cpp
#include<bits/stdc++.h>
#include "Phong.h"
using namespace std;

Phong::Phong() {}

Phong::Phong(string ma, string maKH, string ngayDat, string ngayTra, string trangThai)
    : MaPhong(ma), MaKhachHang(maKH), NgayDatPhong(ngayDat), NgayTraPhong(ngayTra), TrangThai(trangThai) {}

void Phong::nhapthongtin()  {
    cin.ignore();
    cout << "Nhap Ma Khach Hang: ";
    getline(cin, MaKhachHang);
    cout << "Nhap Ma Phong: ";
    getline(cin,MaPhong);
    cout << "Nhap Ngay Dat Phong: ";
    getline(cin,NgayDatPhong);
    cout << "Nhap Ngay Tra Phong: ";
}
void Phong::themphong(vector<Phong>& danhsachPhong, const string& maKhachHang, const string& ngayDat, const string& ngayTra) {
    Phong p;
    string temp;

    cout << "Nhap Ma Phong: ";
    cin.ignore();
    getline(cin, temp);
    p.setMaPhong(temp);

    p.setMaKhachHang(maKhachHang); // Gán mã khách hàng
    p.setNgayDatPhong(ngayDat); // Gán ngày đặt phòng
    p.setNgayTraPhong(ngayTra); // Gán ngày trả phòng
    p.setTrangThai("Da Dat"); // Gán trạng thái (có thể thay đổi nếu cần)

    danhsachPhong.push_back(p);
    luudanhsach(danhsachPhong);
}

void Phong::docdanhsach(vector<Phong>& danhsachPhong) {
    ifstream file("logs/Phong.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string makh, maphong, ngaydat, ngaytra, trangthai;

            getline(ss, makh, ','); 
            getline(ss, maphong, ','); 
            getline(ss, ngaydat, ','); 
            getline(ss, ngaytra, ','); 
            getline(ss, trangthai, ','); 

            Phong p(makh, maphong, ngaydat, ngaytra, trangthai);
            danhsachPhong.push_back(p);
        }
        file.close();
    } else {
        cout << "Khong The Mo File De Doc Danh Sach Khach Hang!" << endl;
    }
}

void Phong::luudanhsach(const vector<Phong>& danhsachPhong) {
    ofstream file("logs/Phong.txt");
    if (file.is_open()) {
        for (const auto& ds : danhsachPhong) {
            file << ds.getMaKhachHang() << "," << ds.getMaPhong() << "," << ds.getNgayDatPhong() << "," << ds.getNgayTraPhong() << "," << ds.getTrangThai() << "\n";
        }
        file.close();
        cout << "Danh sach da duoc luu vao file thanh cong!\n";
    } else {
        cout << "Khong the mo file de luu!\n";
    }
}


void Phong::xuatthongtin(vector<Phong>& danhsachPhong) {
    for(const auto& phong : danhsachPhong){
        cout << "Ma Khach Hang: " << phong.getMaKhachHang() <<endl;
        cout << "Ma Phong: "<< phong.getMaPhong() << endl;
        cout << "Ngay Dat: " << phong.getNgayDatPhong() << endl;
        cout << "Ngay Tra: " << phong.getNgayTraPhong() << endl;
        cout << "Trang Thai: " << phong.getTrangThai() << endl;
    }
}

void Phong::xoaphong(vector<Phong>& danhsachPhong, const string& MaPhong) {
    for(unsigned int i = 0; i < danhsachPhong.size(); i++){
        if(danhsachPhong[i].MaPhong == MaPhong){
            danhsachPhong.erase(danhsachPhong.begin() + i);
            cout << "Xoa Phong Thanh Cong!" << endl;
            luudanhsach(danhsachPhong);
            return;
        }
    }
    cout << "Khong Tim Thay Phong Can Xoa!" << endl;
}

void Phong:: suaphong(vector<Phong>& danhsachPhong, const string& MaPhong) {
    for(auto& ma : danhsachPhong) {
        if(ma.getMaPhong() == MaPhong) {
            string temp;
            cout << "Nhap Ma Khach Hang: ";
            cin.ignore();
            getline(cin, temp);
            cout << "Nhap Ma Phong Khach Hang Dang Su Dung: " << MaPhong  << endl;
            cout << "Nhap Ma Phong Ban Muon Doi: ";
            getline(cin, temp);
            bool dacokhach = false;
            for(const auto& phong : danhsachPhong) {
                if(phong.getMaPhong() == temp){
                    dacokhach = true;
                    break;
                }
            }
            if(dacokhach) {
                cout << "Phong Nay Da Co Khach Hang Khac Dat!" << endl;
                return;
            }
            // Nếu không, cập nhật thông tin phòng
            ma.setMaPhong(temp);
            cout << "Nhap Ngay Dat Phong: ";
            getline(cin, temp);
            ma.setNgayDatPhong(temp); // Cập nhật loại phòng
            cout << "Nhap Ngay Tra Phong: ";
            getline(cin, temp);
            ma.setNgayTraPhong(temp); // Cập nhật loại phòng
            cout << "Da Doi Thanh Cong!" << endl;

            luudanhsach(danhsachPhong);
            return;
        }
    }
    cout << "Khong Tim Thay Phong Voi Ma: " << MaPhong << endl;
}


void Phong::timkiemphong(const string& MaPhong) {
    ifstream file("logs/Phong.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file de doc!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        // Tách các trường bằng dấu phẩy
        stringstream ss(line);
        string makh, maphong, ngaydat, ngaytra, trangthai;

        getline(ss, makh, ','); 
        getline(ss, maphong, ','); 
        getline(ss, ngaydat, ','); 
        getline(ss, ngaytra, ','); 
        getline(ss, trangthai, ',');

        // Kiểm tra xem mã phòng có khớp không
        if (maphong == MaPhong) {
            found = true; // Nếu tìm thấy, đặt found = true
            cout << "Tim Thay Phong:" << endl;
            cout << "Ma Khach Hang: " << makh << endl;
            cout << "Ma Phong: " << maphong << endl;
            cout << "Ngay Dat: " << ngaydat << endl;
            cout << "Ngay Tra: " << ngaytra << endl;
            cout << "Trang Thai: " << trangthai << endl;
            break; // Thoát vòng lặp sau khi tìm thấy
        }
    }

    if (!found) {
        cout << "Khong Tim Thay Phong Voi Ma: " << MaPhong << endl;
    }
    
    file.close(); // Đóng tệp
}
