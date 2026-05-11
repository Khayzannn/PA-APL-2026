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

struct Pembalap {
    int id;
    string nama;
    string tim;
};

struct Kontrak {
    int idKontrak;
    int idPembalap;
    int tahun;
    int nilai;
};

struct User {
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
<<<<<<< HEAD

void garis(){
=======
int inputMenu();

void garis() {
>>>>>>> 2f398df (revisi 2)
    cout << CYAN << "=================================================\n" << RESET;
}

void header(string judul) {
    garis();
    cout << YELLOW << "   " << judul << RESET << endl;
    garis();
}

<<<<<<< HEAD
void validasiAngka(int &x){
    if(!(cin >> x)){
=======
void validasiAngka(int &x) {
    if (!(cin >> x)) {
>>>>>>> 2f398df (revisi 2)
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw "Input harus angka!";
    }
}

<<<<<<< HEAD
string ubahKeLower(string teks){
    transform(teks.begin(), teks.end(), teks.begin(), ::tolower);
    return teks;
}

int cariIndexPembalapById(int id){
    for(int i = 0; i < jmlP; i++){
        if(p[i].id == id){
            return i;
        }
    }
    return -1;
}

int cariIndexKontrakById(int idKontrak){
    for(int i = 0; i < jmlK; i++){
        if(k[i].idKontrak == idKontrak){
            return i;
        }
    }
    return -1;
}

bool validasiTahun4Digit(int tahun){
    return tahun >= 1000 && tahun <= 9999;
}

bool validasiNilaiMinimal6Digit(int nilai){
    return nilai >= 100000;
}

void menuLogin(){
=======
void menuLogin() {
>>>>>>> 2f398df (revisi 2)
    header("MENU LOGIN");
    cout << "1. Login Admin\n";
    cout << "2. Login User\n";
    cout << "3. Keluar\n";
    garis();
    cout << "Pilih: ";
}

void menuUserLogin() {
    header("USER ACCESS");
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Kembali\n";
    garis();
    cout << "Pilih: ";
}

void inputLogin(string role) {
    header("LOGIN " + role);
}

void menuAdmin() {
    header("MENU ADMIN");
    cout << "1. Tambah Pembalap\n";
    cout << "2. Lihat Pembalap\n";
<<<<<<< HEAD
    cout << "3. Edit Pembalap\n";
    cout << "4. Lihat Kontrak\n";
    cout << "5. Hapus Pembalap\n";
    cout << "6. Hapus Kontrak\n";
    cout << "7. Tambah Kontrak\n";
    cout << "8. Edit Kontrak\n";
    cout << "9. Search Data\n";
    cout << "10. Keluar\n";
=======
    cout << "3. Lihat Kontrak\n";
    cout << "4. Hapus Pembalap\n";
    cout << "5. Hapus Kontrak\n";
    cout << "6. Tambah Kontrak\n";
    cout << "7. Edit Kontrak\n";
    cout << "8. Search Data\n";
    cout << "9. Keluar\n";
>>>>>>> 2f398df (revisi 2)
    garis();
    cout << "Pilih: ";
}

void menuUser() {
    header("MENU USER");
    cout << "1. Menu Driver\n";
    cout << "2. Menu Team\n";
    cout << "3. Menu Profil\n";
<<<<<<< HEAD
    cout << "4. Search Data\n";
    cout << "5. Lihat Kontrak Driver\n";
    cout << "6. Keluar\n";
=======
    cout << "4. Keluar\n";
>>>>>>> 2f398df (revisi 2)
    garis();
    cout << "Pilih: ";
}

void menuDriverUI() {
    header("MENU DRIVER");
    cout << "1. Lihat Driver\n";
<<<<<<< HEAD
    cout << "2. Tampilkan Driver Favorit\n";
    cout << "3. Tambah Driver Favorit\n";
    cout << "4. Edit Driver Favorit\n";
    cout << "5. Hapus Driver Favorit\n";
    cout << "6. Kembali\n";
=======
    cout << "2. Tambah Driver Favorit\n";
    cout << "3. Edit Driver Favorit\n";
    cout << "4. Hapus Driver Favorit\n";
    cout << "5. Kembali\n";
>>>>>>> 2f398df (revisi 2)
    garis();
    cout << "Pilih: ";
}

void menuTeamUI() {
    header("MENU TEAM");
    cout << "1. Lihat Team\n";
<<<<<<< HEAD
    cout << "2. Tampilkan Team Favorit\n";
    cout << "3. Tambah Team Favorit\n";
    cout << "4. Edit Team Favorit\n";
    cout << "5. Hapus Team Favorit\n";
    cout << "6. Kembali\n";
=======
    cout << "2. Tambah Team Favorit\n";
    cout << "3. Edit Team Favorit\n";
    cout << "4. Hapus Team Favorit\n";
    cout << "5. Kembali\n";
>>>>>>> 2f398df (revisi 2)
    garis();
    cout << "Pilih: ";
}

void menuProfilUI() {
    header("MENU PROFIL");
    cout << "1. Edit Username/Password\n";
    cout << "2. Hapus Akun\n";
    cout << "3. Lihat Profil\n";
    cout << "4. Kembali\n";
    garis();
    cout << "Pilih: ";
}

<<<<<<< HEAD
void menuSortPembalap(){
    header("LIHAT PEMBALAP");
    cout << "1. ID Pembalap Ascending\n";
    cout << "2. ID Pembalap Descending\n";
    cout << "3. Nama Pembalap Ascending\n";
    cout << "4. Nama Pembalap Descending\n";
=======
void menuSort() {
    header("LIHAT PEMBALAP");
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
>>>>>>> 2f398df (revisi 2)
    garis();
    cout << "Pilih: ";
}

<<<<<<< HEAD
void menuSortKontrak(){
    header("LIHAT KONTRAK");
    cout << "1. ID Kontrak Ascending\n";
    cout << "2. ID Kontrak Descending\n";
    cout << "3. Nama Driver Ascending\n";
    cout << "4. Nama Driver Descending\n";
    cout << "5. Tahun Ascending\n";
    cout << "6. Tahun Descending\n";
    garis();
    cout << "Pilih: ";
}

void menuSearchUI(){
    header("MENU SEARCH");
    cout << "1. Pembalap\n";
    cout << "2. Kontrak\n";
    cout << "3. Kembali\n";
    garis();
    cout << "Pilih: ";
=======
void dataDefault() {
    p[0]  = {1,  "Lewis Hamilton",       "Ferrari"};
    p[1]  = {2,  "Charles Leclerc",      "Ferrari"};
    p[2]  = {3,  "Lando Norris",         "McLaren"};
    p[3]  = {4,  "Oscar Piastri",        "McLaren"};
    p[4]  = {5,  "Max Verstappen",       "Red Bull Racing"};
    p[5]  = {6,  "Isack Hadjar",         "Red Bull Racing"};
    p[6]  = {7,  "George Russell",       "Mercedes"};
    p[7]  = {8,  "Andrea Kimi Antonelli","Mercedes"};
    p[8]  = {9,  "Sergio Perez",         "Cadillac"};
    p[9]  = {10, "Valtteri Bottas",      "Cadillac"};
    p[10] = {11, "Fernando Alonso",      "Aston Martin"};
    p[11] = {12, "Lance Stroll",         "Aston Martin"};
    p[12] = {13, "Nico Hulkenberg",      "Audi (Sauber)"};
    p[13] = {14, "Gabriel Bortoleto",    "Audi (Sauber)"};
    p[14] = {15, "Alexander Albon",      "Williams"};
    p[15] = {16, "Carlos Sainz Jr.",     "Williams"};
    p[16] = {17, "Pierre Gasly",         "Alpine"};
    p[17] = {18, "Franco Colapinto",     "Alpine"};
    p[18] = {19, "Esteban Ocon",         "Haas"};
    p[19] = {20, "Oliver Bearman",       "Haas"};
    p[20] = {21, "Liam Lawson",          "Racing Bulls"};
    p[21] = {22, "Arvid Lindblad",       "Racing Bulls"};
    jmlP  = 22;

    k[0] = {101, 1,  2026, 50000000};
    k[1] = {102, 5,  2028, 60000000};
    k[2] = {103, 7,  2027, 45000000};
    k[3] = {104, 3,  2026, 35000000};
    k[4] = {105, 11, 2026, 30000000};
    k[5] = {106, 15, 2027, 25000000};
    jmlK = 6;
}

void tambahPembalap() {
    try {
        if (jmlP >= MAX) throw "Data penuh!";
        header("TAMBAH PEMBALAP");

        int idBaru;
        cout << "ID: ";
        validasiAngka(idBaru);

        for (int i = 0; i < jmlP; i++) {
            if (p[i].id == idBaru)
                throw "ID pembalap sudah digunakan!";
        }

        p[jmlP].id = idBaru;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nama: ";
        getline(cin, p[jmlP].nama);
        if (p[jmlP].nama.empty()) throw "Nama kosong!";

        cout << "Tim: ";
        getline(cin, p[jmlP].tim);
        if (p[jmlP].tim.empty()) throw "Tim kosong!";

        jmlP++;
        cout << GREEN << "Berhasil\n" << RESET;
    } catch (const char* e) {
        cout << RED << "Error: " << e << RESET << endl;
    }
>>>>>>> 2f398df (revisi 2)
}

void tampilPembalap() {
    header("DATA PEMBALAP");

<<<<<<< HEAD
    if(jmlP == 0){
=======
    if (jmlP == 0) {
>>>>>>> 2f398df (revisi 2)
        cout << RED << "Belum ada data pembalap\n" << RESET;
        return;
    }

    cout << left
<<<<<<< HEAD
         << setw(5) << "ID"
         << setw(30) << "Nama"
         << setw(25) << "Team" << endl;

    garis();

    for(int i = 0; i < jmlP; i++){
        cout << left
             << setw(5) << p[i].id
=======
         << setw(5)  << "ID"
         << setw(30) << "Nama"
         << setw(25) << "Team"
         << endl;
    garis();

    for (int i = 0; i < jmlP; i++) {
        cout << left
             << setw(5)  << p[i].id
>>>>>>> 2f398df (revisi 2)
             << setw(30) << p[i].nama
             << setw(25) << p[i].tim
             << endl;
    }
}

<<<<<<< HEAD
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

void tambahPembalap(){
    try{
        if(jmlP >= MAX) throw "Data penuh!";

        header("TAMBAH PEMBALAP");

        cout << "ID: ";
        validasiAngka(p[jmlP].id);

        if(cariIndexPembalapById(p[jmlP].id) != -1){
            throw "ID pembalap sudah digunakan! ID harus unik.";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nama: ";
        getline(cin, p[jmlP].nama);

        if(p[jmlP].nama.empty()){
            throw "Nama kosong!";
        }

        cout << "Tim: ";
        getline(cin, p[jmlP].tim);

        if(p[jmlP].tim.empty()){
            throw "Tim kosong!";
        }

        jmlP++;
        cout << GREEN << "Pembalap berhasil ditambahkan\n" << RESET;

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void editPembalap(){
    try{
        if(jmlP == 0) throw "Data pembalap kosong!";

        tampilPembalap();

        header("EDIT PEMBALAP");

        int id;
        cout << "Masukkan ID Driver yang ingin diedit: ";
        validasiAngka(id);

        int idx = cariIndexPembalapById(id);

        if(idx == -1){
            throw "ID driver tidak ditemukan!";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nama baru: ";
        getline(cin, p[idx].nama);

        if(p[idx].nama.empty()){
            throw "Nama tidak boleh kosong!";
        }

        cout << "Tim baru: ";
        getline(cin, p[idx].tim);

        if(p[idx].tim.empty()){
            throw "Tim tidak boleh kosong!";
        }

        cout << GREEN << "Data pembalap berhasil diedit\n" << RESET;

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void sortPembalapIdAsc(){
    for(int i = 0; i < jmlP - 1; i++){
        for(int j = 0; j < jmlP - i - 1; j++){
            if(p[j].id > p[j + 1].id){
                swap(p[j], p[j + 1]);
            }
        }
    }
}

void sortPembalapIdDesc(){
    for(int i = 0; i < jmlP - 1; i++){
        for(int j = 0; j < jmlP - i - 1; j++){
            if(p[j].id < p[j + 1].id){
                swap(p[j], p[j + 1]);
            }
        }
    }
}

void sortPembalapNamaAsc(){
    for(int i = 0; i < jmlP - 1; i++){
        for(int j = 0; j < jmlP - i - 1; j++){
            if(p[j].nama > p[j + 1].nama){
                swap(p[j], p[j + 1]);
            }
        }
    }
}

void sortPembalapNamaDesc(){
    for(int i = 0; i < jmlP - 1; i++){
        for(int j = 0; j < jmlP - i - 1; j++){
            if(p[j].nama < p[j + 1].nama){
                swap(p[j], p[j + 1]);
            }
        }
    }
}

void lihatPembalapDenganSort(){
    try{
        if(jmlP == 0){
            tampilPembalap();
            return;
        }

        int s;

        menuSortPembalap();
        validasiAngka(s);

        if(s == 1){
            sortPembalapIdAsc();
        }
        else if(s == 2){
            sortPembalapIdDesc();
        }
        else if(s == 3){
            sortPembalapNamaAsc();
        }
        else if(s == 4){
            sortPembalapNamaDesc();
        }
        else{
            throw "Pilihan salah!";
        }

        tampilPembalap();

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void sortKontrakIdAsc(){
    for(int i = 0; i < jmlK - 1; i++){
        for(int j = 0; j < jmlK - i - 1; j++){
            if(k[j].idKontrak > k[j + 1].idKontrak){
                swap(k[j], k[j + 1]);
            }
        }
    }
}

void sortKontrakIdDesc(){
    for(int i = 0; i < jmlK - 1; i++){
        for(int j = 0; j < jmlK - i - 1; j++){
            if(k[j].idKontrak < k[j + 1].idKontrak){
                swap(k[j], k[j + 1]);
            }
        }
    }
}

void sortKontrakNamaAsc(){
    for(int i = 0; i < jmlK - 1; i++){
        for(int j = 0; j < jmlK - i - 1; j++){
            int idx1 = cariIndexPembalapById(k[j].idPembalap);
            int idx2 = cariIndexPembalapById(k[j + 1].idPembalap);

            string nama1 = "-";
            string nama2 = "-";

            if(idx1 != -1){
                nama1 = p[idx1].nama;
            }

            if(idx2 != -1){
                nama2 = p[idx2].nama;
            }

            if(nama1 > nama2){
                swap(k[j], k[j + 1]);
            }
        }
    }
}

void sortKontrakNamaDesc(){
    for(int i = 0; i < jmlK - 1; i++){
        for(int j = 0; j < jmlK - i - 1; j++){
            int idx1 = cariIndexPembalapById(k[j].idPembalap);
            int idx2 = cariIndexPembalapById(k[j + 1].idPembalap);

            string nama1 = "-";
            string nama2 = "-";

            if(idx1 != -1){
                nama1 = p[idx1].nama;
            }

            if(idx2 != -1){
                nama2 = p[idx2].nama;
            }

            if(nama1 < nama2){
                swap(k[j], k[j + 1]);
            }
        }
    }
}

void sortKontrakTahunAsc(){
    for(int i = 0; i < jmlK - 1; i++){
        for(int j = 0; j < jmlK - i - 1; j++){
            if(k[j].tahun > k[j + 1].tahun){
                swap(k[j], k[j + 1]);
            }
        }
    }
}

void sortKontrakTahunDesc(){
    for(int i = 0; i < jmlK - 1; i++){
        for(int j = 0; j < jmlK - i - 1; j++){
            if(k[j].tahun < k[j + 1].tahun){
                swap(k[j], k[j + 1]);
            }
        }
    }
}

void hapusPembalap(){
    try{
        if(jmlP == 0) throw "Data pembalap kosong!";

        tampilPembalap();

        header("HAPUS PEMBALAP");

        int id;
        cout << "Masukkan ID Driver yang ingin dihapus: ";
        validasiAngka(id);

        int idx = cariIndexPembalapById(id);

        if(idx == -1){
            throw "ID driver tidak ditemukan!";
        }

        for(int i = idx; i < jmlP - 1; i++){
            p[i] = p[i + 1];
        }

        jmlP--;
        cout << GREEN << "Pembalap berhasil dihapus\n" << RESET;

    }catch(const char* e){
=======
void sortAsc() {
    for (int i = 0; i < jmlP - 1; i++)
        for (int j = 0; j < jmlP - i - 1; j++)
            if (p[j].nama > p[j + 1].nama) swap(p[j], p[j + 1]);
}

void sortDesc() {
    for (int i = 0; i < jmlP - 1; i++)
        for (int j = 0; j < jmlP - i - 1; j++)
            if (p[j].nama < p[j + 1].nama) swap(p[j], p[j + 1]);
}

void hapusPembalap() {
    try {
        if (jmlP == 0) throw "Data pembalap kosong!";
        header("HAPUS PEMBALAP");

        int id;
        cout << "ID: ";
        validasiAngka(id);

        for (int i = 0; i < jmlP; i++) {
            if (p[i].id == id) {
                for (int j = i; j < jmlP - 1; j++) p[j] = p[j + 1];
                jmlP--;
                cout << GREEN << "Terhapus\n" << RESET;
                return;
            }
        }
        throw "ID tidak ditemukan!";
    } catch (const char* e) {
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void tambahKontrak() {
    try {
        if (jmlK >= MAX) throw "Data penuh!";
        header("TAMBAH KONTRAK");

        int idKontrakBaru;
        cout << "ID: ";
        validasiAngka(idKontrakBaru);

        for (int i = 0; i < jmlK; i++) {
            if (k[i].idKontrak == idKontrakBaru)
                throw "ID kontrak sudah digunakan!";
        }
        k[jmlK].idKontrak = idKontrakBaru;

        int idPembalapBaru;
        bool ditemukan = false;
        cout << "ID Pembalap: ";
        validasiAngka(idPembalapBaru);

        for (int i = 0; i < jmlP; i++) {
            if (p[i].id == idPembalapBaru) {
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan) throw "ID pembalap tidak ditemukan!";

        k[jmlK].idPembalap = idPembalapBaru;
        cout << "Tahun: "; validasiAngka(k[jmlK].tahun);
        cout << "Nilai: "; validasiAngka(k[jmlK].nilai);
        jmlK++;
        cout << GREEN << "Berhasil\n" << RESET;
    } catch (const char* e) {
>>>>>>> 2f398df (revisi 2)
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void tampilKontrak() {
    header("DATA KONTRAK");

<<<<<<< HEAD
    if(jmlK == 0){
=======
    if (jmlK == 0) {
>>>>>>> 2f398df (revisi 2)
        cout << RED << "Belum ada data kontrak\n" << RESET;
        return;
    }

    cout << left
<<<<<<< HEAD
         << setw(12) << "ID Kontrak"
         << setw(12) << "ID Driver"
         << setw(25) << "Nama Driver"
         << setw(10) << "Tahun"
         << setw(15) << "Nilai Gaji" << endl;

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
             << setw(25) << namaDriver
             << setw(10) << k[i].tahun
             << setw(15) << k[i].nilai
             << endl;
    }
}

void lihatKontrakDenganSort(){
    try{
        if(jmlK == 0){
            tampilKontrak();
            return;
        }

        int s;

        menuSortKontrak();
        validasiAngka(s);

        if(s == 1){
            sortKontrakIdAsc();
        }
        else if(s == 2){
            sortKontrakIdDesc();
        }
        else if(s == 3){
            sortKontrakNamaAsc();
        }
        else if(s == 4){
            sortKontrakNamaDesc();
        }
        else if(s == 5){
            sortKontrakTahunAsc();
        }
        else if(s == 6){
            sortKontrakTahunDesc();
        }
        else{
            throw "Pilihan salah!";
        }

        tampilKontrak();

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

        if(cariIndexKontrakById(k[jmlK].idKontrak) != -1){
            throw "ID kontrak sudah digunakan! ID kontrak harus unik.";
        }

        tampilPembalap();

        cout << "ID Pembalap: ";
        validasiAngka(k[jmlK].idPembalap);

        if(cariIndexPembalapById(k[jmlK].idPembalap) == -1){
            throw "ID pembalap tidak ditemukan!";
        }

        cout << "Tahun: ";
        validasiAngka(k[jmlK].tahun);

        if(!validasiTahun4Digit(k[jmlK].tahun)){
            throw "Tahun kontrak wajib 4 digit!";
        }

        cout << "Nilai Gaji: ";
        validasiAngka(k[jmlK].nilai);

        if(!validasiNilaiMinimal6Digit(k[jmlK].nilai)){
            throw "Nilai gaji wajib minimal 6 digit!";
        }

        jmlK++;
        cout << GREEN << "Kontrak berhasil ditambahkan\n" << RESET;

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void hapusKontrak(){
    try{
        if(jmlK == 0) throw "Data kontrak kosong!";

        tampilKontrak();

        header("HAPUS KONTRAK");

        int id;
        cout << "Masukkan ID Kontrak yang ingin dihapus: ";
        validasiAngka(id);

        int idx = cariIndexKontrakById(id);

        if(idx == -1){
            throw "ID kontrak tidak ditemukan!";
        }

        for(int i = idx; i < jmlK - 1; i++){
            k[i] = k[i + 1];
        }

        jmlK--;
        cout << GREEN << "Kontrak berhasil dihapus\n" << RESET;

    }catch(const char* e){
=======
         << setw(12) << "ID"
         << setw(30) << "Nama Pembalap"
         << setw(10) << "Tahun"
         << setw(15) << "Nilai"
         << endl;
    garis();

    for (int i = 0; i < jmlK; i++) {
        string namaDriver = "Tidak ditemukan";
        for (int j = 0; j < jmlP; j++) {
            if (k[i].idPembalap == p[j].id) {
                namaDriver = p[j].nama;
                break;
            }
        }
        cout << left
             << setw(12) << k[i].idKontrak
             << setw(30) << namaDriver
             << setw(10) << k[i].tahun
             << setw(15) << k[i].nilai
             << endl;
    }
}

void hapusKontrak() {
    try {
        if (jmlK == 0) throw "Data kontrak kosong!";
        header("HAPUS KONTRAK");

        int id;
        cout << "ID: ";
        validasiAngka(id);

        for (int i = 0; i < jmlK; i++) {
            if (k[i].idKontrak == id) {
                for (int j = i; j < jmlK - 1; j++) k[j] = k[j + 1];
                jmlK--;
                cout << GREEN << "Terhapus\n" << RESET;
                return;
            }
        }
        throw "ID tidak ditemukan!";
    } catch (const char* e) {
>>>>>>> 2f398df (revisi 2)
        cout << RED << "Error: " << e << RESET << endl;
    }
}

<<<<<<< HEAD
void editKontrak(){
    try{
        if(jmlK == 0) throw "Data kontrak kosong!";

        tampilKontrak();

        header("EDIT KONTRAK");

        int id;
        cout << "Masukkan ID Kontrak yang ingin diedit: ";
        validasiAngka(id);

        int idx = cariIndexKontrakById(id);

        if(idx == -1){
            throw "ID kontrak tidak ditemukan!";
        }

        cout << "Tahun baru: ";
        validasiAngka(k[idx].tahun);

        if(!validasiTahun4Digit(k[idx].tahun)){
            throw "Tahun kontrak wajib 4 digit!";
        }

        cout << "Nilai Gaji baru: ";
        validasiAngka(k[idx].nilai);

        if(!validasiNilaiMinimal6Digit(k[idx].nilai)){
            throw "Nilai gaji wajib minimal 6 digit!";
        }

        cout << GREEN << "Kontrak berhasil diedit\n" << RESET;

    }catch(const char* e){
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void searchPembalap(){
    header("SEARCH PEMBALAP");

    if(jmlP == 0){
        cout << RED << "Data pembalap masih kosong\n" << RESET;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string cari;
    cout << "Masukkan nama atau ID pembalap: ";
    getline(cin, cari);

    if(cari.empty()){
        cout << RED << "Keyword pencarian tidak boleh kosong\n" << RESET;
        return;
    }

    string cariLower = ubahKeLower(cari);
    bool ketemu = false;

    cout << left
         << setw(5) << "ID"
         << setw(30) << "Nama"
         << setw(25) << "Team" << endl;

    garis();

    for(int i = 0; i < jmlP; i++){
        string namaLower = ubahKeLower(p[i].nama);
        string idString = to_string(p[i].id);

        if(namaLower.find(cariLower) != string::npos ||
           idString.find(cari) != string::npos){

            cout << left
                 << setw(5) << p[i].id
                 << setw(30) << p[i].nama
                 << setw(25) << p[i].tim
                 << endl;

            ketemu = true;
        }
    }

    if(!ketemu){
        cout << RED << "Data pembalap tidak ditemukan\n" << RESET;
    }
}

void searchKontrak(){
    header("SEARCH KONTRAK");

    if(jmlK == 0){
        cout << RED << "Data kontrak masih kosong\n" << RESET;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string cari;
    cout << "Masukkan ID Kontrak / ID Driver / Nama Driver / Tahun: ";
    getline(cin, cari);

    if(cari.empty()){
        cout << RED << "Keyword pencarian tidak boleh kosong\n" << RESET;
        return;
    }

    string cariLower = ubahKeLower(cari);
    bool ketemu = false;

    cout << left
         << setw(12) << "ID Kontrak"
         << setw(12) << "ID Driver"
         << setw(25) << "Nama Driver"
         << setw(10) << "Tahun"
         << setw(15) << "Nilai Gaji" << endl;

    garis();

    for(int i = 0; i < jmlK; i++){
        int idx = cariIndexPembalapById(k[i].idPembalap);
        string namaDriver = "-";

        if(idx != -1){
            namaDriver = p[idx].nama;
        }

        string namaLower = ubahKeLower(namaDriver);
        string idKontrakStr = to_string(k[i].idKontrak);
        string idDriverStr = to_string(k[i].idPembalap);
        string tahunStr = to_string(k[i].tahun);

        if(idKontrakStr.find(cari) != string::npos ||
           idDriverStr.find(cari) != string::npos ||
           tahunStr.find(cari) != string::npos ||
           namaLower.find(cariLower) != string::npos){

            cout << left
                 << setw(12) << k[i].idKontrak
                 << setw(12) << k[i].idPembalap
                 << setw(25) << namaDriver
                 << setw(10) << k[i].tahun
                 << setw(15) << k[i].nilai
                 << endl;

            ketemu = true;
        }
    }

    if(!ketemu){
        cout << RED << "Data kontrak tidak ditemukan\n" << RESET;
    }
}

void searchData(){
    int pilih;

    do{
        try{
            menuSearchUI();
            validasiAngka(pilih);

            if(pilih == 1){
                searchPembalap();
            }
            else if(pilih == 2){
                searchKontrak();
            }
            else if(pilih != 3){
                throw "Menu search tidak tersedia!";
            }

        }catch(const char* e){
            cout << RED << "Error: " << e << RESET << endl;
        }

    }while(pilih != 3);
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
=======
void editKontrak() {
    try {
        if (jmlK == 0) throw "Data kontrak kosong!";
        header("EDIT KONTRAK");

        int id;
        cout << "ID: ";
        validasiAngka(id);

        for (int i = 0; i < jmlK; i++) {
            if (k[i].idKontrak == id) {
                cout << "Tahun baru: "; validasiAngka(k[i].tahun);
                cout << "Nilai baru: "; validasiAngka(k[i].nilai);
                cout << GREEN << "Berhasil\n" << RESET;
                return;
            }
        }
        throw "ID tidak ditemukan!";
    } catch (const char* e) {
        cout << RED << "Error: " << e << RESET << endl;
    }
}

void searchData() {
    header("SEARCH DATA");

    if (jmlP == 0) {
        cout << RED << "Data pembalap masih kosong\n" << RESET;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string cari;
    cout << "Cari Nama: ";
    getline(cin, cari);

    bool ketemu = false;
    for (int i = 0; i < jmlP; i++) {
        if (p[i].nama.find(cari) != string::npos) {
            cout << "Ditemukan: " << p[i].nama << " - " << p[i].tim << endl;
            ketemu = true;
        }
    }
    if (!ketemu) cout << RED << "Data tidak ditemukan\n" << RESET;
}

void registerUser() {
        try{
        if(jmlUser >= MAX){
            throw "User penuh!";
        }
        header("REGISTER");
        string usernameBaru;
        string passwordBaru;
        cout << "Username: ";
        getline(cin, usernameBaru);

        if(usernameBaru.empty()){
            throw "Username kosong!";
        }

        for(int i=0; i<jmlUser; i++){

            if(users[i].username == usernameBaru){
>>>>>>> 2f398df (revisi 2)
                throw "Username sudah digunakan!";
            }
        }

        cout << "Password: ";
<<<<<<< HEAD
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
=======
        getline(cin, passwordBaru);

        if(passwordBaru.empty()){
            throw "Password kosong!";
        }

        users[jmlUser].username = usernameBaru;
        users[jmlUser].password = passwordBaru;

        jmlUser++;

        cout << GREEN
             << "Registrasi berhasil!\n"
             << RESET;

    }catch(const char* e){

        cout << RED
             << "Error: "
             << e
             << RESET
             << endl;
    }
}

bool loginUser() {
    try {
        if (jmlUser == 0) throw "Belum ada akun! Silakan register dulu.";

        string u, pw;
        header("LOGIN USER");

        cout << "Username: ";
        getline(cin, u);
        if (u.empty()) throw "Username kosong!";

        cout << "Password: ";
        getline(cin, pw);
        if (pw.empty()) throw "Password kosong!";

        for (int i = 0; i < jmlUser; i++) {
            if (users[i].username == u && users[i].password == pw) {
>>>>>>> 2f398df (revisi 2)
                userAktif = i;
                cout << GREEN << "Login berhasil!\n" << RESET;
                return true;
            }
        }

        throw "Username / Password salah!";
<<<<<<< HEAD

    }catch(const char* e){
=======
    } catch (const char* e) {
>>>>>>> 2f398df (revisi 2)
        cout << RED << "Error: " << e << RESET << endl;
        return false;
    }
}

void menuDriver() {
    int pilih;
<<<<<<< HEAD

    do{
        try{
=======
    do {
        try {
>>>>>>> 2f398df (revisi 2)
            menuDriverUI();
            pilih = inputMenu();

<<<<<<< HEAD
            if(pilih == 1){
                lihatPembalapDenganSort();
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
=======
            if (pilih == 1) {
                tampilPembalap();
            } else if (pilih == 2) {
                if (jmlP == 0) throw "Data pembalap kosong!";              
                cout << "Driver favorit: ";
                getline(cin, users[userAktif].favDriver);
            } else if (pilih == 3) {              
                cout << "Edit driver favorit: ";
                getline(cin, users[userAktif].favDriver);
            } else if (pilih == 4) {
                users[userAktif].favDriver = "";
            } else if (pilih != 5) {
                throw "Menu salah!";
            }
        } catch (const char* e) {
            cout << RED << "Error: " << e << RESET << endl;
        }
    } while (pilih != 5);
>>>>>>> 2f398df (revisi 2)
}

void menuTeam() {
    int pilih;
<<<<<<< HEAD

    do{
        try{
=======
    do {
        try {
>>>>>>> 2f398df (revisi 2)
            menuTeamUI();
           pilih = inputMenu();

<<<<<<< HEAD
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
=======
            if (pilih == 1) {
                header("DATA TEAM");
                if (jmlP == 0) {
                    cout << RED << "Belum ada data team\n" << RESET;
                } else {
                    for (int i = 0; i < jmlP; i++) {
                        bool sudahAda = false;
                        for (int j = 0; j < i; j++) {
                            if (p[i].tim == p[j].tim) {
                                sudahAda = true;
                                break;
                            }
                        }
                        if (!sudahAda) cout << "- " << p[i].tim << endl;
                    }
                }
            } else if (pilih == 2) {
                if (jmlP == 0) throw "Data team kosong!";
                cout << "Team favorit: ";
                getline(cin, users[userAktif].favTeam);
            } else if (pilih == 3) {
                cout << "Edit team favorit: ";
                getline(cin, users[userAktif].favTeam);
            } else if (pilih == 4) {
                users[userAktif].favTeam = "";
            } else if (pilih != 5) {
                throw "Menu salah!";
            }
        } catch (const char* e) {
            cout << RED << "Error: " << e << RESET << endl;
        }
    } while (pilih != 5);
>>>>>>> 2f398df (revisi 2)
}

void menuProfil() {
    int pilih;
<<<<<<< HEAD

    do{
        try{
=======
    do {
        try {
>>>>>>> 2f398df (revisi 2)
            menuProfilUI();
            pilih = inputMenu();

<<<<<<< HEAD
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

=======
            if (pilih == 1) {
                cout << "Username baru: ";
                getline(cin, users[userAktif].username);
                cout << "Password baru: ";
                getline(cin, users[userAktif].password);
            } else if (pilih == 2) {
                for (int i = userAktif; i < jmlUser - 1; i++) users[i] = users[i + 1];
>>>>>>> 2f398df (revisi 2)
                jmlUser--;
                userAktif = -1;

                cout << GREEN << "Akun berhasil dihapus\n" << RESET;
                return;
<<<<<<< HEAD
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

    p[20] = {21, "Liam Lawson", "Red Bull Racing"};
    p[21] = {22, "Arvid Lindblad", "Racing Bulls"};

    jmlP = 22;

    k[0]  = {101, 5, 2028, 70000000};
    k[1]  = {102, 1, 2026, 60000000};
    k[2]  = {103, 2, 2029, 34000000};
    k[3]  = {104, 7, 2026, 34000000};
    k[4]  = {105, 3, 2027, 30000000};

    k[5]  = {106, 11, 2026, 20000000};
    k[6]  = {107, 16, 2026, 13000000};
    k[7]  = {108, 4, 2028, 13000000};

    k[8]  = {109, 17, 2026, 12000000};
    k[9]  = {110, 15, 2026, 12000000};
    k[10] = {111, 12, 2026, 12000000};

    k[11] = {112, 9, 2026, 8000000};
    k[12] = {113, 13, 2026, 8000000};
    k[13] = {114, 19, 2026, 8000000};

    k[14] = {115, 10, 2026, 5000000};
    k[15] = {116, 6, 2026, 5000000};

    k[16] = {117, 14, 2026, 2000000};
    k[17] = {118, 8, 2026, 2000000};

    k[18] = {119, 20, 2026, 1000000};
    k[19] = {120, 21, 2026, 1000000};
    k[20] = {121, 18, 2026, 1000000};
    k[21] = {122, 22, 2026, 500000};

    jmlK = 22;
=======
            } else if (pilih == 3) {
                header("DATA PROFIL");
                cout << "Username   : " << users[userAktif].username  << endl;
                cout << "Fav Driver : " << users[userAktif].favDriver << endl;
                cout << "Fav Team   : " << users[userAktif].favTeam   << endl;
            } else if (pilih != 4) {
                throw "Menu salah!";
            }
        } catch (const char* e) {
            cout << RED << "Error: " << e << RESET << endl;
        }
    } while (pilih != 4);
}
int inputMenu();
int inputMenu(){

    string input;

    getline(cin, input);
    if(input.empty()){
            throw "Input tidak boleh kosong!";
        }
    for(char c : input){

        if(!isdigit(c)){
            throw "Input harus angka!";
        }
        
    }
    

    return stoi(input);
>>>>>>> 2f398df (revisi 2)
}

int main() {
    dataDefault();

    int pilih;
<<<<<<< HEAD

    dataDefault();

    do{
        try{
=======
    do {
        try {
>>>>>>> 2f398df (revisi 2)
            menuLogin();
            pilih = inputMenu();
            if (pilih == 1) {
                bool loginBerhasil = false;
                for (int i = 0; i < 3; i++) {
                    string u, pw;
                    inputLogin("ADMIN");
                      cout << "Username: ";
                      getline(cin, u);
                      
                      cout << "Password: ";
                      getline(cin, pw);

<<<<<<< HEAD
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
=======
                    if (u == "admin" && pw == "123") {
                        loginBerhasil = true;
                        cout << GREEN << "Login berhasil!\n" << RESET;
                        break;
                    } else {
                        cout << RED << "Login gagal! Kesempatan " << (i+1) << "/3\n" << RESET;
                    }
                }

                if (!loginBerhasil) {
                    cout << RED << "Anda telah 3x gagal login!\n" << RESET;
                    continue;
                }

                int m;
                do {
                    try {
>>>>>>> 2f398df (revisi 2)
                        menuAdmin();
                        m = inputMenu();

<<<<<<< HEAD
                        if(m == 1){
                            tambahPembalap();
                        }
                        else if(m == 2){
                            lihatPembalapDenganSort();
                        }
                        else if(m == 3){
                            editPembalap();
                        }
                        else if(m == 4){
                            lihatKontrakDenganSort();
                        }
                        else if(m == 5){
                            hapusPembalap();
                        }
                        else if(m == 6){
                            hapusKontrak();
                        }
                        else if(m == 7){
                            tambahKontrak();
                        }
                        else if(m == 8){
                            editKontrak();
                        }
                        else if(m == 9){
                            searchData();
                        }
                        else if(m == 10){
                            break;
                        }
                        else{
                            throw "Menu tidak tersedia!";
                        }

                    }catch(const char* e){
=======
                        if      (m == 1) tambahPembalap();
                        else if (m == 2) {
                            int s;
                            menuSort();
                            s = inputMenu();
                            if      (s == 1) sortAsc();
                            else if (s == 2) sortDesc();
                            else throw "Pilihan salah!";
                            tampilPembalap();
                        }
                        else if (m == 3) tampilKontrak();
                        else if (m == 4) hapusPembalap();
                        else if (m == 5) hapusKontrak();
                        else if (m == 6) tambahKontrak();
                        else if (m == 7) editKontrak();
                        else if (m == 8) searchData();
                        else if (m == 9) break;
                        else throw "Menu tidak tersedia!";
                    } catch (const char* e) {
>>>>>>> 2f398df (revisi 2)
                        cout << RED << "Error: " << e << RESET << endl;
                    }
                } while (true);

<<<<<<< HEAD
                }while(true);
            }
            else if(pilih == 2){
                int u;

                do{
                    try{
=======
            } else if (pilih == 2) {
                int u;
                do {
                    try {
>>>>>>> 2f398df (revisi 2)
                        menuUserLogin();
                        u = inputMenu();

<<<<<<< HEAD
                        if(u == 1){
                            registerUser();
                        }
                        else if(u == 2){
                            if(loginUser()){
                                int m;

                                do{
                                    try{
=======
                        if (u == 1) {
                            registerUser();
                        } else if (u == 2) {
                            if (loginUser()) {
                                int m;
                                do {
                                    try {
>>>>>>> 2f398df (revisi 2)
                                        menuUser();
                                        m = inputMenu();

<<<<<<< HEAD
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
                                            searchData();
                                        }
                                        else if(m == 5){
                                            lihatKontrakDenganSort();
                                        }
                                        else if(m == 6){
                                            userAktif = -1;
                                            break;
                                        }
                                        else{
                                            throw "Menu tidak valid!";
                                        }

                                    }catch(const char* e){
=======
                                        if      (m == 1) menuDriver();
                                        else if (m == 2) menuTeam();
                                        else if (m == 3) menuProfil();
                                        else if (m == 4) break;
                                        else throw "Menu tidak valid!";
                                    } catch (const char* e) {
>>>>>>> 2f398df (revisi 2)
                                        cout << RED << "Error: " << e << RESET << endl;
                                    }
                                } while (true);
                            }
                        } else if (u == 3) {
                            break;
                        } else {
                            throw "Pilihan salah!";
                        }
<<<<<<< HEAD
                        else if(u == 3){
                            break;
                        }
                        else{
                            throw "Pilihan salah!";
                        }

                    }catch(const char* e){
=======
                    } catch (const char* e) {
>>>>>>> 2f398df (revisi 2)
                        cout << RED << "Error: " << e << RESET << endl;
                    }
                } while (true);

<<<<<<< HEAD
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
=======
            } else if (pilih == 3) {
                cout << GREEN << "Terima kasih\n" << RESET;
            } else {
                throw "Menu tidak tersedia!";
            }

        } catch (const char* e) {
            cout << RED << "Error: " << e << RESET << endl;
        }
    } while (pilih != 3);
>>>>>>> 2f398df (revisi 2)

    return 0;
}