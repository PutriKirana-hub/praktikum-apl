#include <iostream>
#include <string>

using namespace std;

int main() {

    string nama;
    string password;
    string passwordBenar = "057";

    int kesempatan = 0;
    int loginBerhasil = 0;

    // ====== PROSES LOGIN ======
    while (kesempatan < 3 && loginBerhasil == 0) {

        cout << "===== LOGIN =====" << endl;
        cout << "Masukkan Nama : ";
        cin >> nama;
        cout << "Masukkan Password (3 digit terakhir NIM): ";
        cin >> password;

        if (nama == "Ihsan" && password == passwordBenar) {
            cout << "Login Berhasil!" << endl;
            loginBerhasil = 1;
        } else {
            cout << "Nama atau Password Salah!" << endl;
            kesempatan = kesempatan + 1;

            if (kesempatan == 3) {
                cout << "Anda sudah 3 kali salah. Program berhenti." << endl;
                return 0;
            }
        }
    }

    // ====== MENU UTAMA ======
    int pilihan = 0;

    while (pilihan != 4) {

        cout << endl;
        cout << "===== MENU KONVERSI WAKTU =====" << endl;
        cout << "1. Konversi Jam ke Menit dan Detik" << endl;
        cout << "2. Konversi Menit ke Jam dan Detik" << endl;
        cout << "3. Konversi Detik ke Jam dan Menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih Menu: ";
        cin >> pilihan;

        if (pilihan == 1) {

            int jam;
            int menit;
            int detik;

            cout << "Masukkan jumlah jam: ";
            cin >> jam;

            menit = jam * 60;
            detik = jam * 3600;

            cout << jam << " jam = " << menit << " menit dan "
                 << detik << " detik" << endl;

        } 
        else if (pilihan == 2) {

            int menit;
            int jam;
            int detik;

            cout << "Masukkan jumlah menit: ";
            cin >> menit;

            jam = menit / 60;
            detik = menit * 60;

            cout << menit << " menit = " << jam << " jam dan "
                 << detik << " detik" << endl;

        } 
        else if (pilihan == 3) {

            int detik;
            int jam;
            int menit;

            cout << "Masukkan jumlah detik: ";
            cin >> detik;

            jam = detik / 3600;
            menit = detik / 60;

            cout << detik << " detik = " << jam << " jam dan "
                 << menit << " menit" << endl;

        } 
        else if (pilihan == 4) {
            cout << "Terima kasih Bos. Program selesai." << endl;
        } 
        else {
            cout << "Ngelem aja Bos!" << endl;
        }

    }

    return 0;
}