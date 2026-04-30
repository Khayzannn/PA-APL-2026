#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

const int MAX = 50;

struct Pembalap{
    int id;
    string nama;
    string tim;
};

struct Kontrak{
    int idKontrak;
    int idPembalap;
    int tahun;
    int nilai;
};

struct User{
    string username;
    string password;
};

Pembalap p[MAX];
Kontrak k[MAX];
User users[MAX];

int jmlP = 0, jmlK = 0, jmlUser = 0;

void garis(){
    cout << CYAN << "=================================================\n" << RESET;
}

void validasiAngka(int &x){
    if(!(cin >> x)){
        cin.clear();
        cin.ignore(1000, '\n');
        throw "Input harus angka!";
    }
}

void registerUser(){
    try{
        if(jmlUser >= MAX) throw "User penuh!";

        cin.ignore();
        cout << "Username: ";
        getline(cin, users[jmlUser].username);
        if(users[jmlUser].username.empty()) throw "Username tidak boleh kosong!";

        cout << "Password: ";
        getline(cin, users[jmlUser].password);
        if(users[jmlUser].password.empty()) throw "Password tidak boleh kosong!";

        for(int i=0;i<jmlUser;i++){
            if(users[i].username == users[jmlUser].username){
                throw "Username sudah digunakan!";
            }
        }

        jmlUser++;
        cout << GREEN << "Registrasi berhasil!\n" << RESET;

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

bool loginUser(){
    try{
        string u, pw;
        cin.ignore();

        cout << "Username: ";
        getline(cin, u);

        cout << "Password: ";
        getline(cin, pw);

        for(int i=0;i<jmlUser;i++){
            if(users[i].username == u && users[i].password == pw){
                cout << GREEN << "Login User berhasil!\n" << RESET;
                return true;
            }
        }

        throw "Username / Password salah!";

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
        return false;
    }
}

int login(){
    int pilihan;

    while(true){
        try{
            garis();
            cout << YELLOW << "         MENU LOGIN\n" << RESET;
            garis();
            cout << "1. Admin\n";
            cout << "2. User\n";
            cout << "Pilih: ";

            validasiAngka(pilihan);

            if(pilihan == 1){
                string u,pw;
                cout << "Username : "; cin >> u;
                cout << "Password : "; cin >> pw;

                if(u=="admin" && pw=="123"){
                    cout << GREEN << "Login Admin berhasil!\n" << RESET;
                    return 1;
                }else{
                    throw "Login admin gagal!";
                }
            }
            else if(pilihan == 2){
                int pilihUser;

                while(true){
                    try{
                        cout << "\n1. Register\n";
                        cout << "2. Login\n";
                        cout << "Pilih: ";
                        validasiAngka(pilihUser);

                        if(pilihUser == 1){
                            registerUser();
                        }
                        else if(pilihUser == 2){
                            if(loginUser()){
                                return 2;
                            }
                        }
                        else{
                            throw "Pilihan tidak valid!";
                        }

                    }catch(const char* e){
                        cout << RED << "Error: " << e << RESET << endl;
                    }
                }
            }
            else{
                throw "Pilihan hanya 1 atau 2!";
            }

        }catch(const char* e){
            cout << RED << "Error: " << e << RESET << endl;
        }
    }
}

void tampilPembalap(){
    garis();
    cout << YELLOW << "DATA PEMBALAP\n" << RESET;
    garis();

    if(jmlP==0){
        cout << RED << "Belum ada data\n" << RESET;
        return;
    }

    cout << CYAN << left << setw(5)<<"ID"<<setw(20)<<"Nama"<<setw(15)<<"Tim"<< RESET << endl;
    garis();

    for(int i=0;i<jmlP;i++){
        cout << setw(5)<<p[i].id
             << setw(20)<<p[i].nama
             << setw(15)<<p[i].tim << endl;
    }
}

void tampilKontrak(){
    garis();
    cout << YELLOW << "DATA KONTRAK\n" << RESET;
    garis();

    if(jmlK==0){
        cout << RED << "Belum ada data\n" << RESET;
        return;
    }

    cout << CYAN << setw(5)<<"ID"<<setw(10)<<"ID_P"<<setw(10)<<"Tahun"<<setw(10)<<"Nilai"<< RESET << endl;
    garis();

    for(int i=0;i<jmlK;i++){
        cout<<setw(5)<<k[i].idKontrak
            <<setw(10)<<k[i].idPembalap
            <<setw(10)<<k[i].tahun
            <<setw(10)<<k[i].nilai<<endl;
    }
}

void tambahPembalap(){
    try{
        if(jmlP>=MAX) throw "Data penuh!";

        cout<<"ID   : ";
        validasiAngka(p[jmlP].id);

        cin.ignore();
        cout<<"Nama : ";
        getline(cin,p[jmlP].nama);
        if(p[jmlP].nama.empty()) throw "Nama tidak boleh kosong!";

        cout<<"Tim  : ";
        getline(cin,p[jmlP].tim);
        if(p[jmlP].tim.empty()) throw "Tim tidak boleh kosong!";

        jmlP++;
        cout<<GREEN<<"Berhasil ditambah\n"<<RESET;

    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
    }
}

void updatePembalap(){
    try{
        int id;
        cout<<"ID: ";
        validasiAngka(id);

        for(int i=0;i<jmlP;i++){
            if(p[i].id==id){
                cin.ignore();

                cout<<"Nama baru: ";
                getline(cin,p[i].nama);
                if(p[i].nama.empty()) throw "Nama kosong!";

                cout<<"Tim baru : ";
                getline(cin,p[i].tim);
                if(p[i].tim.empty()) throw "Tim kosong!";

                cout<<GREEN<<"Update berhasil\n"<<RESET;
                return;
            }
        }

        throw "ID tidak ditemukan!";

    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
    }
}

void hapusPembalap(){
    try{
        int id;
        cout<<"ID: ";
        validasiAngka(id);

        for(int i=0;i<jmlP;i++){
            if(p[i].id==id){
                for(int j=i;j<jmlP-1;j++) p[j]=p[j+1];
                jmlP--;
                cout<<GREEN<<"Terhapus\n"<<RESET;
                return;
            }
        }

        throw "ID tidak ditemukan!";

    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
    }
}

void tambahKontrak(){
    try{
        if(jmlK>=MAX) throw "Data kontrak penuh!";

        cout<<"ID Kontrak : ";
        validasiAngka(k[jmlK].idKontrak);

        cout<<"ID Driver  : ";
        validasiAngka(k[jmlK].idPembalap);

        cout<<"Tahun      : ";
        validasiAngka(k[jmlK].tahun);

        cout<<"Nilai      : ";
        validasiAngka(k[jmlK].nilai);

        jmlK++;
        cout<<GREEN<<"Kontrak ditambah\n"<<RESET;

    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
    }
}

void sortNama(){
    for(int i=0;i<jmlP-1;i++){
        for(int j=0;j<jmlP-i-1;j++){
            if(p[j].nama > p[j+1].nama){
                swap(p[j],p[j+1]);
            }
        }
    }
    cout<<GREEN<<"Sorting Nama ASC\n"<<RESET;
}

void cariID(){
    try{
        int id;
        cout<<"Cari ID: ";
        validasiAngka(id);

        for(int i=0;i<jmlP;i++){
            if(p[i].id==id){
                cout<<GREEN<<"Ditemukan: "<<p[i].nama<<RESET<<endl;
                return;
            }
        }

        throw "Data tidak ditemukan!";

    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
    }
}

void cariNama(){
    try{
        string nama;
        cin.ignore();

        cout<<"Cari Nama: ";
        getline(cin,nama);

        if(nama.empty()) throw "Nama kosong!";

        for(int i=0;i<jmlP;i++){
            if(p[i].nama==nama){
                cout<<GREEN<<"Ditemukan ID: "<<p[i].id<<RESET<<endl;
                return;
            }
        }

        throw "Data tidak ditemukan!";

    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
    }
}

void menu(){
    garis();
    cout<<YELLOW<<"   SISTEM MANAJEMEN PEMBALAP\n"<<RESET;
    garis();
    cout<<"1. Tambah Pembalap\n";
    cout<<"2. Lihat Pembalap\n";
    cout<<"3. Update Pembalap\n";
    cout<<"4. Hapus Pembalap\n";
    cout<<"5. Tambah Kontrak\n";
    cout<<"6. Lihat Kontrak\n";
    cout<<"7. Sorting Nama\n";
    cout<<"8. Cari ID\n";
    cout<<"9. Cari Nama\n";
    cout<<"10. Keluar\n";
    garis();
}

int main(){
    int role = login();
    if(role == 0) return 0;

    int pilih;

    do{
        try{
            menu();
            cout<<"Pilih: ";
            validasiAngka(pilih);

            switch(pilih){
                case 1:
                    if(role==1) tambahPembalap();
                    else throw "User tidak punya akses!";
                    break;

                case 2: tampilPembalap(); break;

                case 3:
                    if(role==1) updatePembalap();
                    else throw "User tidak punya akses!";
                    break;

                case 4:
                    if(role==1) hapusPembalap();
                    else throw "User tidak punya akses!";
                    break;

                case 5:
                    if(role==1) tambahKontrak();
                    else throw "User tidak punya akses!";
                    break;

                case 6: tampilKontrak(); break;
                case 7: sortNama(); break;
                case 8: cariID(); break;
                case 9: cariNama(); break;

                case 10:
                    cout<<GREEN<<"Terima kasih\n"<<RESET;
                    break;

                default:
                    throw "Menu tidak valid!";
            }

        }catch(const char* e){
            cout<<RED<<"Error: "<<e<<RESET<<endl;
        }

    }while(pilih!=10);

    return 0;
}