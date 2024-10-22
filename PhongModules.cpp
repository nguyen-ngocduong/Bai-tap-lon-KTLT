// PhongModules.cpp
#include<bits/stdc++.h>
#include "Phong.h"
using namespace std;

Phong::Phong() {}

Phong::Phong(string ma, string loai, string hang)
    : MaPhong(ma), LoaiPhong(loai),  Hang(hang) {}

void Phong::nhapthongtin()  {
    cin.ignore();
    cout << "Nhap Ma Phong: ";
    getline(cin,MaPhong);
    cout <<  " Nhap Loai Phong: ";
    getline(cin, LoaiPhong);
    cout << " Nhap Hang: ";
    getline(cin, Hang);
}
void Phong::themphong(vector<Phong>& danhsachPhong)  {
    Phong p;
    string temp;

    cout << "Nhap Ma Phong: ";
    cin.ignore();
    getline(cin, temp);
    p.setMaPhong(temp);

    cout << "Nhap Loai Phong: ";
    getline(cin, temp);
    p.setLoaiPhong(temp);

    cout << "Nhap Hang: ";
    getline(cin, temp);
    p.setHang(temp);

    danhsachPhong.push_back(p);
    luudanhsach(danhsachPhong);
}

void Phong::docdanhsach() {
    ifstream file("logs/Phong.txt");
    if(file.is_open()) {
        string line; //Khai báo một chuỗi line để lưu từng dòng được đọc từ tệp tin.
        while(getline(file,line)) {
            if (line.size() < 9) {
                cout << "Dong khong hop le cho Ma Phong: " << line << endl;
                continue;
            }
            string MaPhong = line.substr(9);

            if (!getline(file, line) || line.size() < 12) {
                cout << "Dong khong hop le cho Loai Phong: " << line << endl;
                break;
            }
            string LoaiPhong = line.substr(12);

            if (!getline(file, line) || line.size() < 7) {
                cout << "Dong khong hop le cho Hang: " << line << endl;
                break;
            }
            string Hang = line.substr(7);

            // Tạo đối tượng phòng và thêm vào danh sách
            Phong phong(MaPhong, LoaiPhong, Hang);
            danhsachPhong.push_back(phong);
        }
        file.close();
    }
    else {
        cout << "Khong the mo file de doc danh sach da dang ky!" <<endl;
    }
}

void Phong::luudanhsach(const vector<Phong>& danhsachPhong) {
    ofstream file("logs/Phong.txt");
    if(file.is_open()) {
        for(const auto& phong : danhsachPhong){
            file << "Ma Phong: " << phong.getMaPhong() << endl;
            file << "Loai Phong: " << phong.getLoaiPhong() << endl;
            file << "Hang: " << phong.getHang() << endl;
            file << "---------------------------------------------" << endl;
        }
        file.close();
        cout << "Luu Danh Sach Dang Ky Phong Thanh Cong!" << endl;
    } else {
        cout << "Khong The Mo File!" << endl;
    }
}


void Phong::xuatthongtin(vector<Phong>& danhsachPhong) {
    for(const auto& phong : danhsachPhong){
        cout << "Ma Phong: " << phong.getMaPhong() <<endl;
        cout << "Loai Phong: "<< phong.getLoaiPhong() << endl;
        cout << "Hang: " << phong.getHang() << endl;
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
            cout << "Nhap Ma Phong Khach Hang Dang Su Dung " << MaPhong << ":" << endl;
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
            cout << "Nhap Loai Phong: ";
            getline(cin, temp);
            ma.setLoaiPhong(temp); // Cập nhật loại phòng
            cout << "Nhap Hang: ";
            getline(cin, temp);
            ma.setHang(temp); // Cập nhật loại phòng
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
    while (getline(file, line) ) {
        if (line.find("Ma Phong: " + MaPhong) != string::npos && line.size()>=9) {
            found = true; // Nếu tìm thấy, đặt found = true
            cout << "Tim Thay Phong: " << line << endl;

            // In ra thông tin phòng (các dòng tiếp theo)
            getline(file, line); // Đọc dòng loại phòng
            if(!line.empty()) cout << line << endl; 
            getline(file, line); // Đọc dòng hạng phòng
            if(!line.empty()) cout << line << endl; 
            // Đọc dòng phân cách
            getline(file, line);
            break; // Thoát vòng lặp sau khi tìm thấy
        }
    }

    if (!found) {
        cout << "Khong Tim Thay Phong Voi Ma: " << MaPhong << endl;
    }
    
    file.close(); // Đóng tệp
}

