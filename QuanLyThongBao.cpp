#include<bits/stdc++.h>
#include "QuanLyThongBao.h"

using namespace std;

void ThongBao::saveNotification(const string &message){
    ofstream outfile("logs/ThongBao.txt", ios::app);
    if(outfile.is_open()){
        outfile << message << endl;
    }
    else {
        cerr << "Khong The Mo File De Luu!" << endl;
    }
}

void ThongBao::GuiThongBaoDatPhong(const string &filePhong, const string &fileKhachHang) {
    ifstream phongfile(filePhong);
    ifstream khachhangfile(fileKhachHang);
    string room, customer, line;
    while(getline(phongfile, room)&& getline(khachhangfile, customer)) {
        stringstream roomStream(room);
        string makh, soPhong, ngayDat, ngayTra, trangThai;
        getline(roomStream, makh, ',');
        getline(roomStream, soPhong, ',');
        getline(roomStream, ngayDat, ',');
        getline(roomStream, ngayTra, ',');
        getline(roomStream, trangThai, ',');

        stringstream cusStream(customer);
        string maKH, tenKH, ngaySinh, diaChi, email, cmnd;
        getline(cusStream, maKH, ',');
        getline(cusStream, tenKH, ',');
        getline(cusStream, ngaySinh, ',');
        getline(cusStream, diaChi, ',');
        getline(cusStream, email, ',');
        getline(cusStream, cmnd, ',');
        string message = "Chuc Mung Khach Hang: " + tenKH + " (Mã: " + maKH + ") Da Dat Phong: " + soPhong + " Tu " + ngayDat + " Den " + ngayTra + " Thanh Cong. Chuc Quy Khach Co Trai Nghiem Tot Tai Khach San Chung Toi!";
        noidungthongbao.push_back(message);
        cout << message << endl;
        saveNotification(message); //lưu vào file;
    }
    phongfile.close();
    khachhangfile.close();
}

void ThongBao::DanhGiaKhachSan(const string &fileKhachHang){
    ifstream infile(fileKhachHang);
    string customer;
    while(getline(infile, customer)) {
        stringstream customerStream(customer);
        string makh, tenKH, ngaySinh, diaChi, email, cmnd;
        getline(customerStream, makh, ',');
        getline(customerStream, tenKH, ',');
        getline(customerStream, ngaySinh, ',');
        getline(customerStream, diaChi, ',');
        getline(customerStream, email, ',');
        getline(customerStream, cmnd, ',');

        string message = "Khach Hang: " + tenKH + "(Ma: " + makh + ")" + "Co Email La: " + email + " Vui Long Truy Cap Vao Trang Web: https://danhgiakhachsann.com/ De Danh Gia Cho Chung Toi Va Neu Co Gop Y Xin Vui Long Viet Thu Qua Email: KhachSanChungToi@gmail.com!\n";
        noidungthongbao.push_back(message);
        cout << message << endl;
        cout << "\t========Xin Chan Thanh Cam On Quy Khach!========\n" << endl;
        saveNotification(message);
    }
    infile.close();
}

chrono::system_clock::time_point stringToDate(const string &dateStr) {
    tm tm = {};
    istringstream ss(dateStr);
    ss >> get_time(&tm, "%d/%m/%Y"); // Định dạng ngày tháng
    return chrono::system_clock::from_time_t(mktime(&tm));
}

void ThongBao::ThongBaoThanhToan(const string &filePhong) {
    ifstream phongfile(filePhong);
    string room;

    // Ngày hiện tại
    auto today = std::chrono::system_clock::now();

    while (getline(phongfile, room)) {
        stringstream ss(room);
        string makh, soPhong, ngayNhan, ngayTra, trangThai;
        getline(ss, makh, ','); 
        getline(ss, soPhong, ','); // Lấy mã phòng
        getline(ss, ngayNhan, ',');
        getline(ss, ngayTra, ',');
        getline(ss, trangThai, ',');

        // Chuyển đổi chuỗi ngày trả phòng thành time_point
        auto returnDate = stringToDate(ngayTra);

        // Kiểm tra xem ngày trả phòng đã qua chưa
        if (today >= returnDate) {
            // Gửi thông báo thanh toán
            string message = "Khach hang o phong so " + soPhong + " vui long thanh toan tien phong.";
            noidungthongbao.push_back(message);
            cout << message << endl;
            saveNotification(message); // Lưu vào file
        }
    }
    phongfile.close(); 
}

void ThongBao::guiThongBaoKiemTraPhong(const string &filephong){
    ifstream infile(filephong);
    string room;
    while(getline(infile, room)){
        stringstream ss(room);
        string makh, soPhong, ngayNhan, ngayTra, trangThai;
        getline(ss, makh, ','); // lấy mã khách hàng
        getline(ss, soPhong, ','); //lấy mã phòng
        getline(ss, ngayNhan, ',');
        getline(ss, ngayTra, ',');// lấy ngày trả 
        getline(ss, trangThai, ',');
        string message = "Thong Bao Den Nhan Vien: Khach Hang Co Ma: " + makh + " Da Tra Phong: " + soPhong + "Vao Ngay: " + ngayTra +" De Nghi Len Kiem Tra Phong! Xin Cam On!";
        
        noidungthongbao.push_back(message);
        cout << message << endl;
        saveNotification(message); //lưu vào file;
    }
    infile.close();
}

void ThongBao::GuiThongBaoLuongThuong(const string &fileNhanVien){
    ifstream infile(fileNhanVien);
    string nhanvien;
    while(getline(infile, nhanvien)) {
        stringstream nv(nhanvien);
        string ten, chucvu, hieusuat;
        int luong;
        // Đọc thông tin từ mỗi dòng
        getline(nv, ten, ',');
        getline(nv, chucvu, ',');
        nv >> luong; // Đọc lương
        nv.ignore(); // Bỏ qua dấu phẩy
        getline(nv, hieusuat, ','); // Đọc hiệu suất

        string message = "Nhan vien: " + ten + " (Chuc vu: " + chucvu + ") da duoc nhan luong thuong: " + to_string(luong) + " VND.";
        noidungthongbao.push_back(message);
        cout << "\t=====Thong Bao Tra Luong Cho Nhan Vien=====\n";
        cout << message << endl;
        saveNotification(message);
    }
    infile.close();
}

void ThongBao::saveNotifications(){
    ofstream outfile("logs/ThongBao.txt");
    if(!outfile.is_open()) {
        cout << "Khong the mo file ThongBao.txt de ghi." << endl;
        return;
    }
     for (const auto& message : noidungthongbao) {
        outfile << message << endl; // Ghi từng thông báo vào file
    }

    outfile.close();
}


void ThongBao::ThongBaoDichVuKH(const string &filedichvu, const string &filephong){
    ifstream infile1(filedichvu);
    ifstream infile2(filephong);
    string dichvu;
    // Đảm bảo cả hai file đều mở thành công
    if (!infile1.is_open() || !infile2.is_open()) {
        cout << "Khong the mo mot trong hai file." << endl;
        return;
    }
    // Đọc tất cả các dịch vụ
    vector<string> dichVuList;
    while(getline(infile1, dichvu)) {
        dichVuList.push_back(dichvu);
    }
    // Đọc thông tin từ file phòng
    vector<string> phongList;
    while(getline(infile2, dichvu)){
        phongList.push_back(dichvu);
    }
    // Lặp qua từng phòng để xử lý từng khách hàng
    for(const auto& p : phongList) {
        stringstream ss(p);
        string makh, soPhong, ngayNhan, ngayTra, trangThaiPhong;

        getline(ss, makh, ',');  // Lấy mã khách hàng
        getline(ss, soPhong, ',');      // Lấy số phòng
        getline(ss, ngayNhan, ',');
        getline(ss, ngayTra, ',');
        getline(ss, trangThaiPhong, ',');  // Lấy trạng thái phòng
        // Kiểm tra trạng thái phòng
        if(trangThaiPhong == "Da Dat") {
            cout << "Khach hang " << makh << " o phong " << soPhong << " co the yeu cau dich vu:";
            // Hiển thị danh sách dịch vụ
            cout << "Danh sach dich vu:" << endl;
            for(size_t i = 0; i<dichVuList.size() ; i++) {
                stringstream dv(dichVuList[i]);
                string tendv;
                getline(dv, tendv, ','); // lấy tên dv
                cout << i+1 <<". "<< tendv << endl; // hiển thị số dịch vụ
            }
            // Yêu cầu người dùng chọn dịch vụ
            int choice;
            cout << "Nhap dich vu ban lua chon: 1-" << dichVuList.size() <<  "): ";
            cin >> choice;
            if(choice < 1 || choice > dichVuList.size()) {
                cout << "lua chon khong hop le!" << endl;
                continue; // chuyênr qua hàng tiếp theo
            }
            // Lấy dịch vụ đã chọn
            string selectedService = dichVuList[choice-1];
            stringstream dvStream(selectedService);
            string tendv, trangthaiDichVu;
            int gia;
            getline(dvStream, tendv, ',');// lấy tên dịch vụ
            cin >> gia;
            dvStream.ignore();
            getline(dvStream, trangthaiDichVu, ','); // lấy trạng thái dịch vụ
            // Kiểm tra trạng thái dịch vụ và thông báo
            if(trangthaiDichVu == "hoat dong") {
                // Tạo thông báo nếu dịch vụ hoạt động
                string message = "Thong Bao Den Nhan Vien: Khach Hang Co Ma " + makh + " O Phong: " + soPhong + " Yeu Cau Dich Vu: " + tendv;
                noidungthongbao.push_back(message);
                cout << message << endl;
                saveNotification(message);
            }
            else if(trangthaiDichVu == "ngung") {
                string message = "Xin loi Khach Hang Co Ma " + makh + " O Phong: " + soPhong + ", Dich Vu: " + tendv + " hien khong kha dung.";
                noidungthongbao.push_back(message);
                cout << message << endl;
                saveNotification(message);
            }
        }
        else {
            cout <<  "Khach hang " << makh << " o phong " << soPhong << " chua dat phong." << endl;
        }
    }
    // Lưu tất cả thông báo vào file sau khi xử lý xong
    // saveNotifications();

    infile1.close();
    infile2.close();
}
