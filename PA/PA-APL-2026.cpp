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

int jmlP = 0, jmlK = 0, jmlUser = 0;
int userAktif = -1;

void garis(){
    cout << CYAN << "=================================================\n" << RESET;
}

void header(string judul){
    garis();
    cout << YELLOW << "   " << judul << RESET << endl;
    garis();
}

void validasiAngka(int &x){
    if(!(cin >> x)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw "Input harus angka!";
    }
}

void menuLogin(){
    header("MENU LOGIN");
    cout << "1. Login Admin\n";
    cout << "2. Login User\n";
    cout << "3. Keluar\n";
    garis();
    cout << "Pilih: ";
}

void menuUserLogin(){
    header("USER ACCESS");
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Kembali\n";
    garis();
    cout << "Pilih: ";
}

void inputLogin(string role){
    header("LOGIN " + role);
}

void menuAdmin(){
    header("MENU ADMIN");
    cout << "1. Tambah Pembalap\n";
    cout << "2. Lihat Pembalap\n";
    cout << "3. Lihat Kontrak\n";
    cout << "4. Hapus Pembalap\n";
    cout << "5. Hapus Kontrak\n";
    cout << "6. Tambah Kontrak\n";
    cout << "7. Edit Kontrak\n";
    cout << "8. Search Data\n";
    cout << "9. Keluar\n";
    garis();
    cout << "Pilih: ";
}

void menuUser(){
    header("MENU USER");
    cout << "1. Menu Driver\n";
    cout << "2. Menu Team\n";
    cout << "3. Menu Profil\n";
    cout << "4. Keluar\n";
    garis();
    cout << "Pilih: ";
}

void menuDriverUI(){
    header("MENU DRIVER");
    cout << "1. Lihat Driver\n";
    cout << "2. Tampilkan Driver Favorit\n";
    cout << "3. Tambah Driver Favorit\n";
    cout << "4. Edit Driver Favorit\n";
    cout << "5. Hapus Driver Favorit\n";
    cout << "6. Kembali\n";
    garis();
    cout << "Pilih: ";
}

void menuTeamUI(){
    header("MENU TEAM");
    cout << "1. Lihat Team\n";
    cout << "2. Tampilkan Team Favorit\n";
    cout << "3. Tambah Team Favorit\n";
    cout << "4. Edit Team Favorit\n";
    cout << "5. Hapus Team Favorit\n";
    cout << "6. Kembali\n";
    garis();
    cout << "Pilih: ";
}

void menuProfilUI(){
    header("MENU PROFIL");
    cout << "1. Edit Username/Password\n";
    cout << "2. Hapus Akun\n";
    cout << "3. Lihat Profil\n";
    cout << "4. Kembali\n";
    garis();
    cout << "Pilih: ";
}

void menuSort(){
    header("LIHAT PEMBALAP");
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    garis();
    cout << "Pilih: ";
}

int cariIndexPembalapById(int id){
    for(int i = 0; i < jmlP; i++){
        if(p[i].id == id){
            return i;
        }
    }
    return -1;
}

void tambahPembalap(){
    try{
        if(jmlP >= MAX) throw "Data penuh!";

        header("TAMBAH PEMBALAP");

        cout << "ID: ";
        validasiAngka(p[jmlP].id);

        if(cariIndexPembalapById(p[jmlP].id) != -1){
            throw "ID pembalap sudah digunakan!";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nama: ";
        getline(cin, p[jmlP].nama);
        if(p[jmlP].nama.empty()) throw "Nama kosong!";

        cout << "Tim: ";
        getline(cin, p[jmlP].tim);
        if(p[jmlP].tim.empty()) throw "Tim kosong!";

        jmlP++;
        cout << GREEN << "Berhasil menambahkan pembalap\n" << RESET;

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void tampilPembalap(){
    header("DATA PEMBALAP");

    if(jmlP == 0){
        cout << RED << "Belum ada data pembalap\n" << RESET;
        return;
    }

    cout << left
         << setw(5) << "ID"
         << setw(30) << "Nama"
         << setw(25) << "Team" << endl;

    garis();

    for(int i = 0; i < jmlP; i++){
        cout << left
             << setw(5) << p[i].id
             << setw(30) << p[i].nama
             << setw(25) << p[i].tim
             << endl;
    }
}

void tampilTeam(){
    header("DATA TEAM");

    if(jmlP == 0){
        cout << RED << "Belum ada data team\n" << RESET;
        return;
    }

    cout << left
         << setw(5) << "ID"
         << setw(30) << "Driver"
         << setw(25) << "Team" << endl;

    garis();

    for(int i = 0; i < jmlP; i++){
        cout << left
             << setw(5) << p[i].id
             << setw(30) << p[i].nama
             << setw(25) << p[i].tim
             << endl;
    }
}

void tampilDriverFavorit(){
    header("DRIVER FAVORIT");

    if(users[userAktif].favDriver.empty()){
        cout << RED << "Belum ada driver favorit\n" << RESET;
    }else{
        cout << "Username       : " << users[userAktif].username << endl;
        cout << "Driver Favorit: " << users[userAktif].favDriver << endl;
    }
}

void tampilTeamFavorit(){
    header("TEAM FAVORIT");

    if(users[userAktif].favTeam.empty()){
        cout << RED << "Belum ada team favorit\n" << RESET;
    }else{
        cout << "Username    : " << users[userAktif].username << endl;
        cout << "Team Favorit: " << users[userAktif].favTeam << endl;
    }
}

void sortAsc(){
    for(int i = 0; i < jmlP - 1; i++){
        for(int j = 0; j < jmlP - i - 1; j++){
            if(p[j].nama > p[j + 1].nama){
                swap(p[j], p[j + 1]);
            }
        }
    }
}

void sortDesc(){
    for(int i = 0; i < jmlP - 1; i++){
        for(int j = 0; j < jmlP - i - 1; j++){
            if(p[j].nama < p[j + 1].nama){
                swap(p[j], p[j + 1]);
            }
        }
    }
}

void hapusPembalap(){
    try{
        if(jmlP == 0) throw "Data pembalap kosong!";

        header("HAPUS PEMBALAP");

        int id;
        cout << "ID: ";
        validasiAngka(id);

        for(int i = 0; i < jmlP; i++){
            if(p[i].id == id){
                for(int j = i; j < jmlP - 1; j++){
                    p[j] = p[j + 1];
                }

                jmlP--;
                cout << GREEN << "Pembalap berhasil dihapus\n" << RESET;
                return;
            }
        }

        throw "ID tidak ditemukan!";

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void tambahKontrak(){
    try{
        if(jmlK >= MAX) throw "Data penuh!";

        header("TAMBAH KONTRAK");

        cout << "ID Kontrak: ";
        validasiAngka(k[jmlK].idKontrak);

        cout << "ID Pembalap: ";
        validasiAngka(k[jmlK].idPembalap);

        if(cariIndexPembalapById(k[jmlK].idPembalap) == -1){
            throw "ID pembalap tidak ditemukan!";
        }

        cout << "Tahun: ";
        validasiAngka(k[jmlK].tahun);

        cout << "Nilai: ";
        validasiAngka(k[jmlK].nilai);

        jmlK++;
        cout << GREEN << "Kontrak berhasil ditambahkan\n" << RESET;

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void tampilKontrak(){
    header("DATA KONTRAK");

    if(jmlK == 0){
        cout << RED << "Belum ada data kontrak\n" << RESET;
        return;
    }

    cout << left
         << setw(12) << "ID Kontrak"
         << setw(12) << "ID Driver"
         << setw(20) << "Nama Driver"
         << setw(10) << "Tahun"
         << setw(15) << "Nilai" << endl;

    garis();

    for(int i = 0; i < jmlK; i++){
        int idx = cariIndexPembalapById(k[i].idPembalap);
        string namaDriver = "-";

        if(idx != -1){
            namaDriver = p[idx].nama;
        }

        cout << left
             << setw(12) << k[i].idKontrak
             << setw(12) << k[i].idPembalap
             << setw(20) << namaDriver
             << setw(10) << k[i].tahun
             << setw(15) << k[i].nilai
             << endl;
    }
}

void hapusKontrak(){
    try{
        if(jmlK == 0) throw "Data kontrak kosong!";

        header("HAPUS KONTRAK");

        int id;
        cout << "ID Kontrak: ";
        validasiAngka(id);

        for(int i = 0; i < jmlK; i++){
            if(k[i].idKontrak == id){
                for(int j = i; j < jmlK - 1; j++){
                    k[j] = k[j + 1];
                }

                jmlK--;
                cout << GREEN << "Kontrak berhasil dihapus\n" << RESET;
                return;
            }
        }

        throw "ID tidak ditemukan!";

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void editKontrak(){
    try{
        if(jmlK == 0) throw "Data kontrak kosong!";

        header("EDIT KONTRAK");

        int id;
        cout << "ID Kontrak: ";
        validasiAngka(id);

        for(int i = 0; i < jmlK; i++){
            if(k[i].idKontrak == id){
                cout << "Tahun baru: ";
                validasiAngka(k[i].tahun);

                cout << "Nilai baru: ";
                validasiAngka(k[i].nilai);

                cout << GREEN << "Kontrak berhasil diedit\n" << RESET;
                return;
            }
        }

        throw "ID tidak ditemukan!";

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void searchData(){
    header("SEARCH DATA");

    if(jmlP == 0){
        cout << RED << "Data pembalap masih kosong\n" << RESET;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string cari;
    cout << "Cari Nama: ";
    getline(cin, cari);

    bool ketemu = false;

    for(int i = 0; i < jmlP; i++){
        if(p[i].nama == cari){
            cout << GREEN << "Ditemukan\n" << RESET;
            cout << "ID   : " << p[i].id << endl;
            cout << "Nama : " << p[i].nama << endl;
            cout << "Team : " << p[i].tim << endl;
            ketemu = true;
        }
    }

    if(!ketemu){
        cout << RED << "Data tidak ditemukan\n" << RESET;
    }
}

void registerUser(){
    try{
        if(jmlUser >= MAX) throw "User penuh!";

        header("REGISTER");

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Username: ";
        getline(cin, users[jmlUser].username);

        if(users[jmlUser].username.empty()){
            throw "Username kosong!";
        }

        for(int i = 0; i < jmlUser; i++){
            if(users[i].username == users[jmlUser].username){
                throw "Username sudah digunakan!";
            }
        }

        cout << "Password: ";
        getline(cin, users[jmlUser].password);

        if(users[jmlUser].password.empty()){
            throw "Password kosong!";
        }

        users[jmlUser].favDriver = "";
        users[jmlUser].favTeam = "";

        jmlUser++;
        cout << GREEN << "Registrasi berhasil!\n" << RESET;

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

bool loginUser(){
    try{
        if(jmlUser == 0){
            throw "Belum ada akun! Silakan register dulu.";
        }

        string u, pw;

        header("LOGIN USER");

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Username: ";
        getline(cin, u);

        if(u.empty()){
            throw "Username kosong!";
        }

        cout << "Password: ";
        getline(cin, pw);

        if(pw.empty()){
            throw "Password kosong!";
        }

        for(int i = 0; i < jmlUser; i++){
            if(users[i].username == u && users[i].password == pw){
                userAktif = i;
                cout << GREEN << "Login berhasil!\n" << RESET;
                return true;
            }
        }

        throw "Username / Password salah!";

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
        return false;
    }
}

void menuDriver(){
    int pilih;

    do{
        try{
            menuDriverUI();
            validasiAngka(pilih);

            if(pilih == 1){
                tampilPembalap();
            }
            else if(pilih == 2){
                tampilDriverFavorit();
            }
            else if(pilih == 3){
                if(jmlP == 0) throw "Data pembalap kosong!";

                tampilPembalap();

                int id;
                cout << "Masukkan ID driver favorit: ";
                validasiAngka(id);

                int idx = cariIndexPembalapById(id);

                if(idx == -1){
                    throw "ID driver tidak ditemukan!";
                }

                users[userAktif].favDriver = p[idx].nama;

                cout << GREEN << "Driver favorit berhasil ditambahkan: "
                     << users[userAktif].favDriver << "\n" << RESET;
            }
            else if(pilih == 4){
                if(jmlP == 0) throw "Data pembalap kosong!";

                tampilPembalap();

                int id;
                cout << "Masukkan ID driver favorit baru: ";
                validasiAngka(id);

                int idx = cariIndexPembalapById(id);

                if(idx == -1){
                    throw "ID driver tidak ditemukan!";
                }

                users[userAktif].favDriver = p[idx].nama;

                cout << GREEN << "Driver favorit berhasil diubah menjadi: "
                     << users[userAktif].favDriver << "\n" << RESET;
            }
            else if(pilih == 5){
                users[userAktif].favDriver = "";
                cout << GREEN << "Driver favorit berhasil dihapus\n" << RESET;
            }
            else if(pilih != 6){
                throw "Menu salah!";
            }

        }catch(const char* e){
            cout << RED << "Error: " << e << RESET << endl;
        }

    }while(pilih != 6);
}

void menuTeam(){
    int pilih;

    do{
        try{
            menuTeamUI();
            validasiAngka(pilih);

            if(pilih == 1){
                tampilTeam();
            }
            else if(pilih == 2){
                tampilTeamFavorit();
            }
            else if(pilih == 3){
                if(jmlP == 0) throw "Data team kosong!";

                tampilTeam();

                int id;
                cout << "Masukkan ID driver dari team favorit: ";
                validasiAngka(id);

                int idx = cariIndexPembalapById(id);

                if(idx == -1){
                    throw "ID driver/team tidak ditemukan!";
                }

                users[userAktif].favTeam = p[idx].tim;

                cout << GREEN << "Team favorit berhasil ditambahkan: "
                     << users[userAktif].favTeam << "\n" << RESET;
            }
            else if(pilih == 4){
                if(jmlP == 0) throw "Data team kosong!";

                tampilTeam();

                int id;
                cout << "Masukkan ID driver dari team favorit baru: ";
                validasiAngka(id);

                int idx = cariIndexPembalapById(id);

                if(idx == -1){
                    throw "ID driver/team tidak ditemukan!";
                }

                users[userAktif].favTeam = p[idx].tim;

                cout << GREEN << "Team favorit berhasil diubah menjadi: "
                     << users[userAktif].favTeam << "\n" << RESET;
            }
            else if(pilih == 5){
                users[userAktif].favTeam = "";
                cout << GREEN << "Team favorit berhasil dihapus\n" << RESET;
            }
            else if(pilih != 6){
                throw "Menu salah!";
            }

        }catch(const char* e){
            cout << RED << "Error: " << e << RESET << endl;
        }

    }while(pilih != 6);
}

void menuProfil(){
    int pilih;

    do{
        try{
            menuProfilUI();
            validasiAngka(pilih);

            if(pilih == 1){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Username baru: ";
                getline(cin, users[userAktif].username);

                if(users[userAktif].username.empty()){
                    throw "Username tidak boleh kosong!";
                }

                cout << "Password baru: ";
                getline(cin, users[userAktif].password);

                if(users[userAktif].password.empty()){
                    throw "Password tidak boleh kosong!";
                }

                cout << GREEN << "Profil berhasil diedit\n" << RESET;
            }
            else if(pilih == 2){
                for(int i = userAktif; i < jmlUser - 1; i++){
                    users[i] = users[i + 1];
                }

                jmlUser--;
                userAktif = -1;

                cout << GREEN << "Akun berhasil dihapus\n" << RESET;
                return;
            }
            else if(pilih == 3){
                header("DATA PROFIL");
                cout << "Username    : " << users[userAktif].username << endl;
                cout << "Fav Driver  : ";

                if(users[userAktif].favDriver.empty()){
                    cout << "-\n";
                }else{
                    cout << users[userAktif].favDriver << endl;
                }

                cout << "Fav Team    : ";

                if(users[userAktif].favTeam.empty()){
                    cout << "-\n";
                }else{
                    cout << users[userAktif].favTeam << endl;
                }
            }
            else if(pilih != 4){
                throw "Menu salah!";
            }

        }catch(const char* e){
            cout << RED << "Error: " << e << RESET << endl;
        }

    }while(pilih != 4);
}

void dataDefault(){
    p[0] = {1, "Lewis Hamilton", "Ferrari"};
    p[1] = {2, "Charles Leclerc", "Ferrari"};

    p[2] = {3, "Lando Norris", "McLaren"};
    p[3] = {4, "Oscar Piastri", "McLaren"};

    p[4] = {5, "Max Verstappen", "Red Bull Racing"};
    p[5] = {6, "Isack Hadjar", "Red Bull Racing"};

    p[6] = {7, "George Russell", "Mercedes"};
    p[7] = {8, "Andrea Kimi Antonelli", "Mercedes"};

    p[8] = {9, "Sergio Perez", "Cadillac"};
    p[9] = {10, "Valtteri Bottas", "Cadillac"};

    p[10] = {11, "Fernando Alonso", "Aston Martin"};
    p[11] = {12, "Lance Stroll", "Aston Martin"};

    p[12] = {13, "Nico Hulkenberg", "Audi (Sauber)"};
    p[13] = {14, "Gabriel Bortoleto", "Audi (Sauber)"};

    p[14] = {15, "Alexander Albon", "Williams"};
    p[15] = {16, "Carlos Sainz Jr.", "Williams"};

    p[16] = {17, "Pierre Gasly", "Alpine"};
    p[17] = {18, "Franco Colapinto", "Alpine"};

    p[18] = {19, "Esteban Ocon", "Haas"};
    p[19] = {20, "Oliver Bearman", "Haas"};

    p[20] = {21, "Liam Lawson", "Racing Bulls"};
    p[21] = {22, "Arvid Lindblad", "Racing Bulls"};

    jmlP = 22;

    k[0] = {101, 1, 2026, 50000000};
    k[1] = {102, 5, 2028, 60000000};
    k[2] = {103, 7, 2027, 45000000};
    k[3] = {104, 3, 2026, 35000000};
    k[4] = {105, 11, 2026, 30000000};
    k[5] = {106, 15, 2027, 25000000};

    jmlK = 6;
}

int main(){
    int pilih;

    dataDefault();

    do{
        try{
            menuLogin();
            validasiAngka(pilih);

            if(pilih == 1){
                string u, pw;

                inputLogin("ADMIN");

                cout << "Username: ";
                cin >> u;

                cout << "Password: ";
                cin >> pw;

                if(!(u == "admin" && pw == "123")){
                    throw "Login admin gagal!";
                }

                int m;

                do{
                    try{
                        menuAdmin();
                        validasiAngka(m);

                        if(m == 1){
                            tambahPembalap();
                        }
                        else if(m == 2){
                            int s;

                            menuSort();
                            validasiAngka(s);

                            if(s == 1){
                                sortAsc();
                            }
                            else if(s == 2){
                                sortDesc();
                            }
                            else{
                                throw "Pilihan salah!";
                            }

                            tampilPembalap();
                        }
                        else if(m == 3){
                            tampilKontrak();
                        }
                        else if(m == 4){
                            hapusPembalap();
                        }
                        else if(m == 5){
                            hapusKontrak();
                        }
                        else if(m == 6){
                            tambahKontrak();
                        }
                        else if(m == 7){
                            editKontrak();
                        }
                        else if(m == 8){
                            searchData();
                        }
                        else if(m == 9){
                            break;
                        }
                        else{
                            throw "Menu tidak tersedia!";
                        }

                    }catch(const char* e){
                        cout << RED << "Error: " << e << RESET << endl;
                    }

                }while(true);
            }
            else if(pilih == 2){
                int u;

                do{
                    try{
                        menuUserLogin();
                        validasiAngka(u);

                        if(u == 1){
                            registerUser();
                        }
                        else if(u == 2){
                            if(loginUser()){
                                int m;

                                do{
                                    try{
                                        menuUser();
                                        validasiAngka(m);

                                        if(m == 1){
                                            menuDriver();
                                        }
                                        else if(m == 2){
                                            menuTeam();
                                        }
                                        else if(m == 3){
                                            menuProfil();

                                            if(userAktif == -1){
                                                break;
                                            }
                                        }
                                        else if(m == 4){
                                            userAktif = -1;
                                            break;
                                        }
                                        else{
                                            throw "Menu tidak valid!";
                                        }

                                    }catch(const char* e){
                                        cout << RED << "Error: " << e << RESET << endl;
                                    }

                                }while(true);
                            }
                        }
                        else if(u == 3){
                            break;
                        }
                        else{
                            throw "Pilihan salah!";
                        }

                    }catch(const char* e){
                        cout << RED << "Error: " << e << RESET << endl;
                    }

                }while(true);
            }
            else if(pilih == 3){
                cout << GREEN << "Terima kasih\n" << RESET;
            }
            else{
                throw "Menu tidak tersedia!";
            }

        }catch(const char* e){
            cout << RED << "Error: " << e << RESET << endl;
        }

    }while(pilih != 3);

    return 0;
}