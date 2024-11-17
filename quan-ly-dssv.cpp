#include <bits/stdc++.h>

using namespace std;

class SinhVien{
	private:
	    int ma;
	    string hoTen, lop, queQuan, ntn;
	    float diem;
	public:
		void setMa(int ma){
			this->ma = ma;
		}
	    void setSv(int ma, string hoTen, string ntn, string lop, string queQuan, float diem){ 
			this->ma = ma;
			this->hoTen = hoTen;
			this->ntn = ntn;
			this->lop = lop;
			this->queQuan = queQuan;
			this->diem = diem;
		}
	    friend ostream & operator << (ostream &os, const SinhVien &sv){
		    os << "Ma sinh vien: " << sv.ma << endl;
		    os << "Ho va ten: " << sv.hoTen << endl; 
		    os << "Ngay sinh: " << sv.ntn << endl;
		    os << "Lop: " << sv.lop << endl;
		    os << "Que quan: " << sv.queQuan << endl;
		    os << "Diem: " << sv.diem << endl;
		    return os;
		}
	    friend istream & operator >> (istream &is, SinhVien &sv){
	        cout << "Nhap ho va ten: ";
	        is.ignore();
	        getline(is, sv.hoTen);
	        cout << "Nhap ngay sinh: ";
	        is >> sv.ntn;
	        cout << "Nhap lop: ";
	        is.ignore();
	        getline(is, sv.lop);
	        cout << "Nhap que quan: ";
	        getline(is, sv.queQuan);
	        cout << "Nhap diem: ";
	        is >> sv.diem;
	        return is;
	    }
	    int getMa(){ 
			return ma; 
		}
	    float getDiem(){ 
			return diem; 
		}
		string getLop(){
			return lop;
		}
		bool operator < (const SinhVien &other)const{
	        return this->diem < other.diem;
	    }
	    bool operator > (const SinhVien &other)const{
        	return this->diem > other.diem;
   		}
};

class DanhSachSinhVien{
	private:
	    vector<SinhVien> danhSach;
	public:
		bool kiemTraMaSinhVien(int ma){
		    for (auto &sv : danhSach)
		        if (sv.getMa() == ma)
		            return true; 
		    return false;
		}
		bool danhSachSinhVienRong(){
	        return danhSach.empty();
	    }
	    void docFile(string tenFile){
	    	cout << "Moi nhap ten file: ";
	    	cin.ignore();
	    	getline(cin, tenFile);
	    	ifstream file(tenFile);
	    	if(!file){
	    		cout << endl << "Khong the truy cap den file!";
	    		return;
			}
			while(!file.eof()){	
				int ma, namSinh;
	            string hoTen, lop, queQuan, ntn;
	            float diem;
	            file >> ma;
	            file.ignore();
	            getline(file, hoTen);
	            file >> ntn;
	            file.ignore();
	            getline(file, lop);
	            getline(file, queQuan);
	            file >> diem;
	            file.ignore();
				
				if(file){
	            	SinhVien sv;
	                sv.setSv(ma, hoTen, ntn, lop, queQuan, diem);
	                themSinhVien(sv);
	            }
			}
			file.close();
			cout << endl << "Da doc danh sach sinh vien tu file " << tenFile << " thanh cong!" << endl;
		}
	    void themSinhVien(SinhVien &sv){
	        danhSach.push_back(sv);
	    }
	    void xuatDanhSach(){
		    if (danhSach.empty())
		        cout << "Danh sach sinh vien rong!" << endl;
			else
		        for (auto &sv : danhSach){
		            cout << "Danh sach thong tin sinh vien" << endl;
		            cout << sv << endl; 
		        }
		}
		void xuatDanhSachTheoLop(){
	        string lop;
	        cout << "Nhap ten lop can xuat danh sach sinh vien: ";
	        cin.ignore();
	        getline(cin, lop);
	        cout << endl;
	        int f = 0;
	        for(auto &sv : danhSach){
	            if (sv.getLop() == lop){
	                cout << sv << endl;
	                f = 1;
	            }
	        }
	        if(f == 0)
	            cout << "Khong co sinh vien nao thuoc lop " << lop << endl;
	    }
	    void xuatDSnSVCaoNhat(int ans){
	    	if(ans > danhSach.size()){
	    		cout << "So luong sinh vien can xuat lon hon so luong sinh vien trong du lieu!" << endl;
	    		return;
			}
			sapXepGiamDan();
			cout << "Danh sach " << ans << " sinh vien co diem cao nhat la" << endl;
			for(int i=0; i<ans; i++)
				cout << danhSach[i] << endl;
		}
	    void sapXepTangDan(){
	        sort(danhSach.begin(), danhSach.end());
	    }
		void sapXepGiamDan(){
		    sort(danhSach.begin(), danhSach.end(), greater<SinhVien>());
		}
	    SinhVien timMaxDiem(){
	        return *max_element(danhSach.begin(), danhSach.end());
	    }
	    SinhVien timMinDiem(){
	        return *min_element(danhSach.begin(), danhSach.end());
	    }
	    void xoaSinhVien(int ma){
	    	if (danhSach.empty()){
	    		cout << "Danh sach sinh vien rong!" << endl;
	    		return;
			}
		    for(auto it=danhSach.begin(); it!= danhSach.end(); it++){
		        if(it->getMa() == ma){
		            it = danhSach.erase(it);
		            cout << "Da xoa sinh vien co ma sinh vien " << ma << endl;
		            return;
		        }
		    }
    		cout << "Khong tim thay sinh vien co ma sinh vien " << ma << endl;
		}
	    SinhVien* timKiem(int ma){
	        for(auto &sv : danhSach)
	            if(sv.getMa() == ma) 
					return &sv;
	        return NULL;
	    }
	    vector<SinhVien> locSinhVienTheoDiem(int x, int y){
		    vector<SinhVien> ketQua;
		    for (auto &sv : danhSach)
		        if (sv.getDiem() >= x && sv.getDiem() < y)
		            ketQua.push_back(sv);
		    return ketQua;
		}
		vector<SinhVien> locSinhVienGioi(int x){
		    vector<SinhVien> ketQua;
		    for (auto& sv : danhSach)
		        if (sv.getDiem() >= x)
		            ketQua.push_back(sv);
		    return ketQua;
		}
		void suaSinhVien(int ma){
	        SinhVien *sv = timKiem(ma);
	        if(sv != NULL){
	            string hoTen, lop, queQuan, ntn;
	            float diem;
	            int ma;
	            cout << "Nhap ma sinh vien moi: ";
	            cin >> ma;
	            cout << "Nhap ho va ten moi: ";
	            cin.ignore(); 
	            getline(cin, hoTen);
	            cout << "Nhap ngay sinh moi: ";
	            cin >> ntn;
	            cout << "Nhap lop moi: ";
	            cin.ignore(); 
	            getline(cin, lop);
	            cout << "Nhap que quan moi: ";
	            getline(cin, queQuan);
	            cout << "Nhap diem moi: ";
	            cin >> diem;
	            sv->setSv(ma, hoTen, ntn, lop, queQuan, diem);
	            cout << "Da cap nhat thong tin sinh vien!" << endl;
	        } 
			else
	            cout << "Khong tim thay sinh vien co ma " << ma << endl;
	    }
};

class App{
	private:
	    DanhSachSinhVien danhSach;
	public:
	    void menu(){
	        int choice;
	        do{
	            cout << "\n===== Chuong trinh quan ly thong tin sinh vien =====\n";
	            cout << " 1. Them sinh vien" << endl;
	            cout << " 2. Xuat danh sach" << endl;
	            cout << " 3. Xuat danh sach sinh vien theo lop" << endl;
	            cout << " 4. Xuat danh sach n sinh vien co diem cao nhat" << endl;
	            cout << " 5. Sap xep danh sach theo diem tu thap den cao" << endl;
	            cout << " 6. Sap xep danh sach theo diem tu cao xuong thap" << endl;
	            cout << " 7. Tim sinh vien diem cao nhat" << endl;
	            cout << " 8. Tim sinh vien diem thap nhat" << endl;
	            cout << " 9. Tim kiem sinh vien theo ma" << endl;
	            cout << "10. Xoa sinh vien theo ma" << endl;
	            cout << "11. Danh sach sinh vien co diem loai Kem" << endl;
	            cout << "12. Danh sach sinh vien co diem loai Trung binh" << endl;
	            cout << "13. Danh sach sinh vien co diem loai Kha" << endl;
	            cout << "14. Danh sach sinh vien co diem loai Gioi" << endl;
	            cout << "15. Sua thong tin sinh vien" << endl;
	            cout << "16. Doc thong tin sinh vien tu file" << endl;
	            cout << " 0. Thoat" << endl;
	            cout << endl << "Nhap lua chon: ";
	            cin >> choice;
				cout << endl;
	            switch(choice){
	                case 1:{
					    int ans;
						cout << "Nhap so luong sinh vien muon them: ";
						cin >> ans;
						for(int i=0; i<ans; i++){
						    SinhVien sv;
						    int ma;
						    do{
						    	cout << "Nhap thong tin sinh vien thu " << i+1 << endl;
								cout << "Nhap ma sinh vien: ";
						        cin >> ma;
						        if (danhSach.kiemTraMaSinhVien(ma))
						            cout << "Ma sinh vien da ton tai. Vui long nhap lai!" << endl;
						        else {
						            sv.setMa(ma);
						            break;
						        }
						    } 
							while(true);
						    cin >> sv;
						    danhSach.themSinhVien(sv);
						}
						cout << endl << "Da them thong tin thanh cong!" << endl;
						break;
					}
	                case 2:
	                    danhSach.xuatDanhSach();
	                    break;
	            	case 3:
	            		if(danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else
	            			danhSach.xuatDanhSachTheoLop();
	            		break;
	            	case 4:
	            		if(danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else{
							int ans;
	            			cout << "So luong sinh vien cao diem nhat can xuat la: ";
	            			cin >> ans;
	            			danhSach.xuatDSnSVCaoNhat(ans);
						}
	            		break;
	                case 5:
	                	if(danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else{
		                    danhSach.sapXepTangDan();
		                    cout << "Da sap xep danh sach theo diem tang dan!" << endl;
	                	}
	                    break;
	                case 6:
	                	if(danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else{
						    danhSach.sapXepGiamDan();
						    cout << "Da sap xep danh sach theo diem giam dan." << endl;
						}
					    break;
	                case 7:
	                	if(danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else{
		                    cout << "Thong tin sinh vien co diem cao nhat" << endl;
		                    cout << danhSach.timMaxDiem() << endl;
		            	}
	                    break;
	                case 8:
	                	if (danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else{
		                    cout << "Thong tin sinh vien co diem thap nhat" << endl;
		                    cout << danhSach.timMinDiem() << endl;
		            	}
	                    break;
	                case 9:{
	                	if(danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else{
		                   int ma;
		                    cout << "Nhap ma sinh vien can tim: ";
		                    cin >> ma;
		                    SinhVien *sv = danhSach.timKiem(ma);
		                    if(sv != NULL)
		                        cout << "Thong tin sinh vien vua tim" << endl << *sv << endl;
		                    else
		                        cout << "Khong tim thay sinh vien co ma " << ma << endl;
		                }
	                    break;
	                }
	                case 10:{
	                	if(danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else{
		                   int ma;
		                    cout << "Nhap ma sinh vien can xoa: ";
		                    cin >> ma;
		                    danhSach.xoaSinhVien(ma); 
		                }
	                    break;
	                }
	                case 11:{
	                	if(danhSach.danhSachSinhVienRong())
		                    cout << "KDanh sach sinh vien rong!" << endl; 
						else{
		                   	vector<SinhVien> dsDiem = danhSach.locSinhVienTheoDiem(0, 4);
						    cout << "Danh sach sinh vien co diem loai Kem" << endl << endl;
						    for (auto &sv : dsDiem)
					        	cout << sv << endl;
		                }
					    break;
					}	
					case 12:{
						if(danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else{
		                   	vector<SinhVien> dsDiem = danhSach.locSinhVienTheoDiem(4, 6);
						    cout << "Danh sach sinh vien co diem loai Trung binh" << endl << endl;
						    for (auto &sv : dsDiem)
						        cout << sv << endl;
		                }
					    break;
					}
					case 13:{
						if(danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else{
		                   	vector<SinhVien> dsDiem = danhSach.locSinhVienTheoDiem(6, 8);
						    cout << "Danh sach sinh vien co diem loai Kha" << endl << endl;
						    for (auto &sv : dsDiem)
						        cout << sv << endl;
		                }
					    break;
					}
					case 14:{
						if(danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else{
		                   	vector<SinhVien> dsDiem = danhSach.locSinhVienGioi(8);
						    cout << "Danh sach sinh vien co diem loai Gioi" << endl << endl;
						    for (auto &sv : dsDiem)
						        cout << sv << endl;
		                }
					    break;
					}
					case 15:{
						if(danhSach.danhSachSinhVienRong())
		                    cout << "Danh sach sinh vien rong!" << endl; 
						else{
		                   	int ma;
		                    cout << "Nhap ma sinh vien can sua: ";
		                    cin >> ma;
		                    danhSach.suaSinhVien(ma);
		                }
						break;
					}
					case 16:{
						string tenFile;
						danhSach.docFile(tenFile);
						break;
					}
	                case 0:
	                    cout << "Thoat chuong trinh!" << endl;
	                    break;
	                default:
	                    cout << "Vui long nhap lua chon hop le!" << endl;
	            }
	        } 
			while(choice != 0);
	    }
};

int main(){
    App app;
    app.menu();
    return 0;
}
