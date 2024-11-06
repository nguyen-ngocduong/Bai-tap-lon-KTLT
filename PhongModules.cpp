// PhongModules.cpp
#include<bits/stdc++.h>
#include "Phong.h"
using namespace std;

Phong::Phong() {}

Phong::Phong(string maKH, string ma,  string ngayDat, string ngayTra, string trangThai)
    : MaKhachHang(maKH),MaPhong(ma), NgayDatPhong(ngayDat), NgayTraPhong(ngayTra), TrangThai(trangThai) {}

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
    ifstream infile("logs/Phong.txt");
    vector<string> phongDaDat;
    string line;
    if(infile.is_open()){
        while(getline(infile, line)){
            stringstream ss(line);
            string makh, maphong, ngaydat, ngaytra, trangthai;
            getline(ss, makh, ',');
            getline(ss, maphong, ',');
            getline(ss, ngaydat, ',');
            getline(ss, ngaytra, ',');
            getline(ss, trangthai, ',');

            phongDaDat.push_back(maphong); // Lưu mã phòng đã đặt
        }
        infile.close();
    }
    else {
        cout << "Khong The Mo File!";
        return;
    }
    string tmp;
    cout << "Nhap Ma Phong: ";
    cin.ignore();
    getline(cin, tmp);

    // Kiểm tra xem mã phòng đã có trong danh sách phòng đã đặt chưa
    if (find(phongDaDat.begin(), phongDaDat.end(), tmp) != phongDaDat.end()) {
        cout << "Xin loi! Phong nay da co khach hang khac dat." << endl;
        return; 
    }
    Phong p;
    p.setMaPhong(tmp);
    p.setMaKhachHang(maKhachHang); 
    p.setNgayDatPhong(ngayDat); 
    p.setNgayTraPhong(ngayTra); 
    p.setTrangThai("Da Dat"); 

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
    if (!file) {
        cout << "Khong the mo file de luu!\n";
        return;
    }
    for (const auto& ds : danhsachPhong) {
        // Tạo dòng thông tin
        string line;
        if (!ds.getMaKhachHang().empty()) line += ds.getMaKhachHang() + ",";
        if (!ds.getMaPhong().empty()) line += ds.getMaPhong() + ",";
        if (!ds.getNgayDatPhong().empty()) line += ds.getNgayDatPhong() + ",";
        if (!ds.getNgayTraPhong().empty()) line += ds.getNgayTraPhong() + ",";
        if (!ds.getTrangThai().empty()) line += ds.getTrangThai();

        // Kiểm tra xem dòng có dữ liệu không trước khi ghi
        if (!line.empty() && line.back() == ',') {
            line.pop_back(); // Xóa dấu phẩy cuối nếu có
        }

        if (!line.empty()) {
            file << line << "\n"; // Ghi vào file
        }
    }

    file.close();
    cout << "Danh sach da duoc luu vao file thanh cong!\n";
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

void Phong::xoaphong(const string& maPhongCanXoa) {
    ifstream infile1("logs/Phong.txt");
    vector<string> phongConLai;
    string line;
    bool phongDaXoa = false;

    if (!infile1) {
        cerr << "Khong the mo file Phong.txt!" << endl;
        return;
    }

    while (getline(infile1, line)) {
        stringstream ss(line);
        string maKhachHang, maPhong, ngayDat, ngayTra, trangThai;

        getline(ss, maKhachHang, ',');
        getline(ss, maPhong, ',');
        getline(ss, ngayDat, ',');
        getline(ss, ngayTra, ',');
        getline(ss, trangThai, ',');

        if (maPhong != maPhongCanXoa) {
            phongConLai.push_back(line); // Giữ lại các phòng không bị xóa
        } else {
            phongDaXoa = true;
        }
    }
    infile1.close();

    if (phongDaXoa) {
        ofstream outfile1("logs/Phong.txt");
        for (const auto& phong : phongConLai) {
            outfile1 << phong << endl;
        }
        outfile1.close();
        cout << "Phong " << maPhongCanXoa << " da duoc xoa khoi Phong.txt." << endl;
    } else {
        cout << "Khong tim thay phong can xoa trong Phong.txt!" << endl;
    }

    // Cập nhật file danh_sach_phong.txt
    ifstream infile2("logs/danh_sach_phong.txt");
    vector<string> danhSachPhongCapNhat;

    if (!infile2) {
        cerr << "Khong the mo file danh_sach_phong.txt!" << endl;
        return;
    }

    while (getline(infile2, line)) {
        stringstream ss(line);
        string maPhong, soNguoi, trangThai, gia;

        getline(ss, maPhong, ',');
        getline(ss, soNguoi, ',');
        getline(ss, trangThai, ',');
        getline(ss, gia, ',');

        if (maPhong == maPhongCanXoa) {
            trangThai = "Trong"; 
        }

        danhSachPhongCapNhat.push_back(maPhong + "," + soNguoi + "," + trangThai + "," + gia);
    }
    infile2.close();

    ofstream outfile2("logs/danh_sach_phong.txt");
    if (outfile2.is_open()) {
        for (const auto& phong : danhSachPhongCapNhat) {
            outfile2 << phong << endl;
        }
        outfile2.close();
        cout << "Trang thai cua phong " << maPhongCanXoa << " trong danh_sach_phong.txt da duoc cap nhat thanh 'trong'." << endl;
    } else {
        cerr << "Khong the mo file danh_sach_phong.txt de ghi!" << endl;
    }
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
void Phong::kiemtraphong() {
    ifstream infile1("logs/Phong.txt");
    vector<string> phongDaDat;
    string line;
    if(!infile1) {
        cerr << "Khong The Mo File!" << endl;
        return;
    }
    else {
        while (getline(infile1, line)) {
            stringstream ss(line);
            string maKhachHang, maPhong, ngayDat, ngayTra, trangThai;

            getline(ss, maKhachHang, ',');
            getline(ss, maPhong, ',');
            getline(ss, ngayDat, ',');
            getline(ss, ngayTra, ',');
            getline(ss, trangThai, ',');

            phongDaDat.push_back(maPhong); // Lưu mã phòng đã đặt
        }
        infile1.close();
    }
    ifstream infile2("logs/danh_sach_phong.txt");
    vector<string> danhSachPhong;
    vector<string> danhSachPhongCapNhat;
    if (infile2.is_open()) {
        while (getline(infile2, line)) {
            stringstream ss(line);
            string maPhong, soNguoi, trangThai, gia;

            getline(ss, maPhong, ',');
            getline(ss, soNguoi, ',');
            getline(ss, trangThai, ',');
            getline(ss, gia, ',');

            // Kiểm tra xem mã phòng có trong danh sách phòng đã đặt không
            if (find(phongDaDat.begin(), phongDaDat.end(), maPhong) != phongDaDat.end()) {
                // Nếu phòng đã được đặt, cập nhật trạng thái thành "da dat"
                trangThai = "da dat";
            }

            // Lưu lại dòng đã cập nhật
            danhSachPhongCapNhat.push_back(maPhong + "," + soNguoi + "," + trangThai + "," + gia);
        }
        infile2.close();
    } else {
        cout << "Khong the mo file danh_sach_phong.txt!" << endl;
        return;
    }
    // Ghi lại danh sách phòng đã cập nhật vào file
    ofstream fileGhiLai("logs/danh_sach_phong.txt");
    if (fileGhiLai.is_open()) {
        for (const auto& phong : danhSachPhongCapNhat) {
            fileGhiLai << phong << endl; // Ghi lại các phòng đã cập nhật
        }
        fileGhiLai.close();
        cout << "Da cap nhat trang thai phong trong danh_sach_phong.txt!" << endl;
    } else {
        cout << "Khong the mo file de ghi!" << endl;
    }
}