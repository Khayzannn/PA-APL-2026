#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
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
    string favDriver;
    string favTeam;
};

Pembalap p[MAX];
Kontrak k[MAX];
User users[MAX];

int jmlP=0, jmlK=0, jmlUser=0;
int userAktif=-1;

void garis(){
    cout<<CYAN<<"=================================================\n"<<RESET;
}

void header(string judul){
    garis();
    cout<<YELLOW<<"   "<<judul<<RESET<<endl;
    garis();
}

void validasiAngka(int &x){
    if(!(cin>>x)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        throw "Input harus angka!";
    }
}

void menuLogin(){
    header("MENU LOGIN");
    cout<<"1. Login Admin\n";
    cout<<"2. Login User\n";
    cout<<"3. Keluar\n";
    garis();
    cout<<"Pilih: ";
}

void menuUserLogin(){
    header("USER ACCESS");
    cout<<"1. Register\n";
    cout<<"2. Login\n";
    cout<<"3. Kembali\n";
    garis();
    cout<<"Pilih: ";
}

void inputLogin(string role){
    header("LOGIN " + role);
}

void menuAdmin(){
    header("MENU ADMIN");
    cout<<"1. Tambah Pembalap\n";
    cout<<"2. Lihat Pembalap\n";
    cout<<"3. Lihat Kontrak\n";
    cout<<"4. Hapus Pembalap\n";
    cout<<"5. Hapus Kontrak\n";
    cout<<"6. Tambah Kontrak\n";
    cout<<"7. Edit Kontrak\n";
    cout<<"8. Search Data\n";
    cout<<"9. Keluar\n";
    garis();
    cout<<"Pilih: ";
}

void menuUser(){
    header("MENU USER");
    cout<<"1. Menu Driver\n";
    cout<<"2. Menu Team\n";
    cout<<"3. Menu Profil\n";
    cout<<"4. Keluar\n";
    garis();
    cout<<"Pilih: ";
}

void menuDriverUI(){
    header("MENU DRIVER");
    cout<<"1. Lihat Driver\n";
    cout<<"2. Tambah Driver Favorit\n";
    cout<<"3. Edit Driver Favorit\n";
    cout<<"4. Hapus Driver Favorit\n";
    cout<<"5. Kembali\n";
    garis();
    cout<<"Pilih: ";
}

void menuTeamUI(){
    header("MENU TEAM");
    cout<<"1. Lihat Team\n";
    cout<<"2. Tambah Team Favorit\n";
    cout<<"3. Edit Team Favorit\n";
    cout<<"4. Hapus Team Favorit\n";
    cout<<"5. Kembali\n";
    garis();
    cout<<"Pilih: ";
}

void menuProfilUI(){
    header("MENU PROFIL");
    cout<<"1. Edit Username/Password\n";
    cout<<"2. Hapus Akun\n";
    cout<<"3. Lihat Profil\n";
    cout<<"4. Kembali\n";
    garis();
    cout<<"Pilih: ";
}

void menuSort(){
    header("LIHAT PEMBALAP");
    cout<<"1. Ascending\n";
    cout<<"2. Descending\n";
    garis();
    cout<<"Pilih: ";
}

void tambahPembalap(){
    try{
        if(jmlP>=MAX) throw "Data penuh!";
        header("TAMBAH PEMBALAP");
        cout<<"ID: "; validasiAngka(p[jmlP].id);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Nama: "; getline(cin,p[jmlP].nama);
        if(p[jmlP].nama.empty()) throw "Nama kosong!";
        cout<<"Tim: "; getline(cin,p[jmlP].tim);
        if(p[jmlP].tim.empty()) throw "Tim kosong!";
        jmlP++;
        cout<<GREEN<<"Berhasil\n"<<RESET;
    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
    }
}

void tampilPembalap(){
    header("DATA PEMBALAP");
    if(jmlP==0){
        cout<<RED<<"Belum ada data pembalap\n"<<RESET;
        return;
    }
    for(int i=0;i<jmlP;i++){
        cout<<setw(5)<<p[i].id<<setw(20)<<p[i].nama<<setw(15)<<p[i].tim<<endl;
    }
}

void sortAsc(){
    for(int i=0;i<jmlP-1;i++)
        for(int j=0;j<jmlP-i-1;j++)
            if(p[j].nama>p[j+1].nama) swap(p[j],p[j+1]);
}

void sortDesc(){
    for(int i=0;i<jmlP-1;i++)
        for(int j=0;j<jmlP-i-1;j++)
            if(p[j].nama<p[j+1].nama) swap(p[j],p[j+1]);
}

void hapusPembalap(){
    try{
        if(jmlP==0) throw "Data pembalap kosong!";
        header("HAPUS PEMBALAP");
        int id; cout<<"ID: "; validasiAngka(id);
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
        if(jmlK>=MAX) throw "Data penuh!";
        header("TAMBAH KONTRAK");
        cout<<"ID: "; validasiAngka(k[jmlK].idKontrak);
        cout<<"ID Pembalap: "; validasiAngka(k[jmlK].idPembalap);
        cout<<"Tahun: "; validasiAngka(k[jmlK].tahun);
        cout<<"Nilai: "; validasiAngka(k[jmlK].nilai);
        jmlK++;
        cout<<GREEN<<"Berhasil\n"<<RESET;
    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
    }
}

void tampilKontrak(){
    header("DATA KONTRAK");
    if(jmlK==0){
        cout<<RED<<"Belum ada data kontrak\n"<<RESET;
        return;
    }
    for(int i=0;i<jmlK;i++){
        cout<<k[i].idKontrak<<" "<<k[i].idPembalap<<" "<<k[i].tahun<<" "<<k[i].nilai<<endl;
    }
}

void hapusKontrak(){
    try{
        if(jmlK==0) throw "Data kontrak kosong!";
        header("HAPUS KONTRAK");
        int id; cout<<"ID: "; validasiAngka(id);
        for(int i=0;i<jmlK;i++){
            if(k[i].idKontrak==id){
                for(int j=i;j<jmlK-1;j++) k[j]=k[j+1];
                jmlK--;
                cout<<GREEN<<"Terhapus\n"<<RESET;
                return;
            }
        }
        throw "ID tidak ditemukan!";
    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
    }
}

void editKontrak(){
    try{
        if(jmlK==0) throw "Data kontrak kosong!";
        header("EDIT KONTRAK");
        int id; cout<<"ID: "; validasiAngka(id);
        for(int i=0;i<jmlK;i++){
            if(k[i].idKontrak==id){
                cout<<"Tahun baru: "; validasiAngka(k[i].tahun);
                cout<<"Nilai baru: "; validasiAngka(k[i].nilai);
                cout<<GREEN<<"Berhasil\n"<<RESET;
                return;
            }
        }
        throw "ID tidak ditemukan!";
    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
    }
}

void searchData(){
    header("SEARCH DATA");
    if(jmlP==0){
        cout<<RED<<"Data pembalap masih kosong\n"<<RESET;
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string cari;
    cout<<"Cari Nama: "; getline(cin,cari);
    bool ketemu=false;
    for(int i=0;i<jmlP;i++){
        if(p[i].nama==cari){
            cout<<"Ditemukan: "<<p[i].nama<<endl;
            ketemu=true;
        }
    }
    if(!ketemu) cout<<RED<<"Data tidak ditemukan\n"<<RESET;
}

void registerUser(){
    try{
        if(jmlUser>=MAX) throw "User penuh!";
        header("REGISTER");
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Username: "; getline(cin,users[jmlUser].username);
        if(users[jmlUser].username.empty()) throw "Username kosong!";
        cout<<"Password: "; getline(cin,users[jmlUser].password);
        if(users[jmlUser].password.empty()) throw "Password kosong!";
        jmlUser++;
        cout<<GREEN<<"Registrasi berhasil!\n"<<RESET;
    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
    }
}

bool loginUser(){
    try{
        if(jmlUser==0) throw "Belum ada akun! Silakan register dulu.";
        string u,pw;
        header("LOGIN USER");
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Username: "; getline(cin,u);
        if(u.empty()) throw "Username kosong!";
        cout<<"Password: "; getline(cin,pw);
        if(pw.empty()) throw "Password kosong!";
        for(int i=0;i<jmlUser;i++){
            if(users[i].username==u && users[i].password==pw){
                userAktif=i;
                cout<<GREEN<<"Login berhasil!\n"<<RESET;
                return true;
            }
        }
        throw "Username / Password salah!";
    }catch(const char* e){
        cout<<RED<<"Error: "<<e<<RESET<<endl;
        return false;
    }
}

void menuDriver(){
    int pilih;
    do{
        try{
            menuDriverUI();
            validasiAngka(pilih);

            if(pilih==1){
                tampilPembalap();
            }
            else if(pilih==2){
                if(jmlP==0) throw "Data pembalap kosong!";
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Driver favorit: ";
                getline(cin,users[userAktif].favDriver);
            }
            else if(pilih==3){
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Edit driver favorit: ";
                getline(cin,users[userAktif].favDriver);
            }
            else if(pilih==4){
                users[userAktif].favDriver="";
            }
            else if(pilih!=5) throw "Menu salah!";

        }catch(const char* e){
            cout<<RED<<"Error: "<<e<<RESET<<endl;
        }
    }while(pilih!=5);
}

void menuTeam(){
    int pilih;
    do{
        try{
            menuTeamUI();
            validasiAngka(pilih);

            if(pilih==1){
                header("DATA TEAM");
                if(jmlP==0){
                    cout<<RED<<"Belum ada data team\n"<<RESET;
                }else{
                    for(int i=0;i<jmlP;i++){
                        cout<<"- "<<p[i].tim<<endl;
                    }
                }
            }
            else if(pilih==2){
                if(jmlP==0) throw "Data team kosong!";
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Team favorit: ";
                getline(cin,users[userAktif].favTeam);
            }
            else if(pilih==3){
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Edit team favorit: ";
                getline(cin,users[userAktif].favTeam);
            }
            else if(pilih==4){
                users[userAktif].favTeam="";
            }
            else if(pilih!=5) throw "Menu salah!";

        }catch(const char* e){
            cout<<RED<<"Error: "<<e<<RESET<<endl;
        }
    }while(pilih!=5);
}

void menuProfil(){
    int pilih;
    do{
        try{
            menuProfilUI();
            validasiAngka(pilih);

            if(pilih==1){
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Username baru: ";
                getline(cin,users[userAktif].username);
                cout<<"Password baru: ";
                getline(cin,users[userAktif].password);
            }
            else if(pilih==2){
                for(int i=userAktif;i<jmlUser-1;i++) users[i]=users[i+1];
                jmlUser--;
                return;
            }
            else if(pilih==3){
                header("DATA PROFIL");
                cout<<"Username: "<<users[userAktif].username<<endl;
                cout<<"Fav Driver: "<<users[userAktif].favDriver<<endl;
                cout<<"Fav Team: "<<users[userAktif].favTeam<<endl;
            }
            else if(pilih!=4) throw "Menu salah!";

        }catch(const char* e){
            cout<<RED<<"Error: "<<e<<RESET<<endl;
        }
    }while(pilih!=4);
}

int main(){
    int pilih;

    do{
        try{
            menuLogin();
            validasiAngka(pilih);

            if(pilih==1){
                string u,pw;
                inputLogin("ADMIN");
                cout<<"Username: "; cin>>u;
                cout<<"Password: "; cin>>pw;

                if(!(u=="admin" && pw=="123"))
                    throw "Login admin gagal!";

                int m;
                do{
                    try{
                        menuAdmin();
                        validasiAngka(m);

                        if(m==1) tambahPembalap();
                        else if(m==2){
                            int s;
                            menuSort();
                            validasiAngka(s);
                            if(s==1) sortAsc();
                            else if(s==2) sortDesc();
                            else throw "Pilihan salah!";
                            tampilPembalap();
                        }
                        else if(m==3) tampilKontrak();
                        else if(m==4) hapusPembalap();
                        else if(m==5) hapusKontrak();
                        else if(m==6) tambahKontrak();
                        else if(m==7) editKontrak();
                        else if(m==8) searchData();
                        else if(m==9) break;
                        else throw "Menu tidak tersedia!";

                    }catch(const char* e){
                        cout<<RED<<"Error: "<<e<<RESET<<endl;
                    }

                }while(true);
            }

            else if(pilih==2){
                int u;
                do{
                    try{
                        menuUserLogin();
                        validasiAngka(u);

                        if(u==1){
                            registerUser();
                        }
                        else if(u==2){
                            if(loginUser()){
                                int m;
                                do{
                                    try{
                                        menuUser();
                                        validasiAngka(m);

                                        if(m==1) menuDriver();
                                        else if(m==2) menuTeam();
                                        else if(m==3) menuProfil();
                                        else if(m==4) break;
                                        else throw "Menu tidak valid!";

                                    }catch(const char* e){
                                        cout<<RED<<"Error: "<<e<<RESET<<endl;
                                    }

                                }while(true);
                            }
                        }
                        else if(u==3) break;
                        else throw "Pilihan salah!";

                    }catch(const char* e){
                        cout<<RED<<"Error: "<<e<<RESET<<endl;
                    }

                }while(true);
            }

            else if(pilih==3){
                cout<<GREEN<<"Terima kasih\n"<<RESET;
            }
            else{
                throw "Menu tidak tersedia!";
            }

        }catch(const char* e){
            cout<<RED<<"Error: "<<e<<RESET<<endl;
        }

    }while(pilih!=3);

    return 0;
}