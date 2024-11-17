#include<bits/stdc++.h>

using namespace std;

class node{
	private:
	    int bac;
	    float heso;
	    node *next;
	public:
	    node(){ 
	        next = NULL;
	    }                                           
	    node(float hs, int b, node *n = NULL){ 
	        this->heso = hs; 
	        this->bac = b; 
	        this->next = n;    
	    } 
	    void set_bac(int b){ 
	        this->bac = b;
	    }                                    
	    void set_heso(float hs){
	        this->heso = hs;
	    }                      
	    void set_next(node *n = NULL){
	        this->next = n;    
	    }                      
	    int get_bac(){
	        return bac;        
	    } 
	    float get_heso(){
	        return heso;    
	    }
	    node *get_next(){
	        return next;    
	    }
};

class dathuc{
	private:
	    node *head; 
	    node *tail;
	public:
	    dathuc(){
	        head = tail = NULL;    
	    }
	    
	    int size(){
	        int num = 0;
	        node *p = head;
	        while (p != NULL){
	            num++;
	            p = p->get_next();
	        }
	        return num;    
	    }
	    
	    void rut_gon(){
	        sort();
	        node *p = head;
	        while (p != NULL && p->get_next() != NULL){
	            if (p->get_bac() == p->get_next()->get_bac()){
	                p->set_heso(p->get_heso() + p->get_next()->get_heso());
	                node *temp = p->get_next();
	                p->set_next(temp->get_next());
	                delete temp;
	            } 
				else
	                p = p->get_next();
	        }
	    }
	    
	    void sort(){
	        for(node *p=head; p!=tail; p=p->get_next())
	            for(node *q=p->get_next(); q!=NULL; q=q->get_next())
	                if(q->get_bac() < p->get_bac()){
	                    float t_hs = p->get_heso();
	                    int t_b = p->get_bac();
	                    p->set_heso(q->get_heso());
	                    p->set_bac(q->get_bac());
	                    q->set_heso(t_hs);
	                    q->set_bac(t_b);
	                }
	    }
	
	    void push_back(float heso, int bac){
	        if(heso != 0){
	            if(size() == 0)    
	                head = tail = new node(heso, bac, NULL);
	            else{
	                node *p = new node(heso, bac, NULL);
	                tail->set_next(p);
	                tail = tail->get_next();
	            }
	        }
	    }
	
	    friend istream& operator >> (istream &is, dathuc &d){
	        cout << "Nhap so luong phan tu da thuc: ";
	        int n;
	        is >> n;
	        for (int i=0; i<n; i++){
	            cout << "Nhap phan tu thu " << i+1 << ": " << endl;
	            int bac;
	            float hs;
	            cout << "Nhap he so: "; 
	            is >> hs;
	            cout << "Nhap bac: "; 
	            is >> bac;
	            d.push_back(hs, bac);
	        }
	        return is;
	    }
	
	    friend ostream& operator << (ostream &os, dathuc &d){
	        if (d.size() == 0){
	            os << "0" << endl;
	            return os;
	        }
	        d.rut_gon();
	        bool first_term = true;
	        for (node *p=d.head; p!=NULL; p=p->get_next()){
	            if (p->get_heso() != 0){
	                if (!first_term) 
						os << " + ";
	                if (p->get_heso() == -1 && p->get_bac() != 0) 
						os << "-";
	                else if (p->get_heso() != 1 || p->get_bac() == 0) 
						os << p->get_heso();
	                if (p->get_bac() > 0){
	                    os << "x";
	                    if (p->get_bac() > 1) 
							os << "^" << p->get_bac();
	                }
	                first_term = false;
	            }
	        }
	        return os;
	    }
	    
	    dathuc operator + (dathuc dt2){
	        dathuc dt3;
	        node *p = this->head;
	        node *q = dt2.head;
	        while(p != NULL && q != NULL){
	            if(p->get_bac() == q->get_bac()){
	                dt3.push_back(p->get_heso() + q->get_heso(), p->get_bac());
	                p = p->get_next();
	                q = q->get_next();
	            } 
				else if(p->get_bac() > q->get_bac()){
	                dt3.push_back(p->get_heso(), p->get_bac());
	                p = p->get_next();
	            } 
				else{
	                dt3.push_back(q->get_heso(), q->get_bac());
	                q = q->get_next();
	            }
	        }
	        while(p != NULL && q == NULL){
	            dt3.push_back(p->get_heso(), p->get_bac());
	            p = p->get_next();
	        }
	        while(q != NULL && p == NULL){
	            dt3.push_back(q->get_heso(), q->get_bac());
	            q = q->get_next();
	        }
	        return dt3;
	    }
	    
	    dathuc operator - (dathuc dt2){
	        dathuc dt3;
	        node *p = this->head;
	        node *q = dt2.head;
	        while (p != NULL && q != NULL){
	            if (p->get_bac() == q->get_bac()){
	                dt3.push_back(p->get_heso() - q->get_heso(), p->get_bac());
	                p = p->get_next();
	                q = q->get_next();
	            } 
				else if(p->get_bac() > q->get_bac()){
	                dt3.push_back(p->get_heso(), p->get_bac());
	                p = p->get_next();
	            } 
				else{
	                dt3.push_back(-q->get_heso(), q->get_bac());
	                q = q->get_next();
	            }
	        }
	        while(p != NULL && q == NULL){
	            dt3.push_back(p->get_heso(), p->get_bac());
	            p = p->get_next();
	        }
	        while(q != NULL && p == NULL){
	            dt3.push_back(-q->get_heso(), q->get_bac());
	            q = q->get_next();
	        }
	        return dt3;
	    }
	    
	    dathuc operator * (dathuc dt2){
	        dathuc dt3;
	        for(node *p=this->head; p!=NULL; p=p->get_next()){
	            dathuc t;
	            for (node *q = dt2.head; q != NULL; q = q->get_next()){
	                t.push_back(p->get_heso() * q->get_heso(), p->get_bac() + q->get_bac());
	            }
	            dt3 = dt3 + t;
	        }
	        return dt3;
	    }
};

int main(){
    dathuc d1, d2, dTong, dHieu, dTich;
    cout << "Moi nhap da thuc 1" << endl;
    cin >> d1;
    cout << endl << "Moi nhap da thuc 2" << endl;
    cin >> d2;
    cout << "Da thuc d1: " << d1 << endl;
    cout << "Da thuc d2: " << d2 << endl;
    dTong = d1 + d2;
    cout << "Tong hai da thuc: " << dTong << endl;
    dHieu = d1 - d2;
    dTich = d1 * d2;
    cout << "Hieu hai da thuc: " << dHieu << endl;
    cout << "Tich hai da thuc: " << dTich << endl;
    string tenFile;
    cout << "Moi nhap ten file can luu: ";
    cin.ignore();
    getline(cin, tenFile);
    ofstream file(tenFile);
    if (file.is_open()){
        file << "Tong hai da thuc: " << dTong << endl;
        file << "Hieu hai da thuc: " << dHieu << endl;
        file << "Tich hai da thuc: " << dTich << endl;
        
        file.close();
        cout << "Da ghi da thuc ra file '" << tenFile << "'!'"<< endl;
    } 
	else
        cout << "Khong the mo file!" << endl;
    return 0;
}
