#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int tahunLahir, tahunTujuan; // variabel tahun

    // Mengimputkan tahun kelahiran
    cout << "Masukkan tahun kelahiran Anda: ";
    cin >> tahunLahir; // contoh: 2006

    // Mengimputkan tahun tujuan untuk menghitung umur
    cout << "Masukkan tahun tujuan: ";
    cin >> tahunTujuan; // contoh: 2035 

    // Mendapatkan tahun saat ini
    time_t now = time(0);
    tm* saatIni = localtime(&now);
    int tahunSaatIni = 1900 + saatIni->tm_year;

    // Menghitung umur
    int umur = tahunTujuan - tahunLahir;

    // Memeriksa apakah sudah melewati hari ulang tahun di tahun tujuan
    if ((saatIni->tm_mon + 1) < saatIni->tm_mon ||
        ((saatIni->tm_mon + 1) == saatIni->tm_mon && saatIni->tm_mday < saatIni->tm_mday)) {
        umur--;
    }

    // Output hasil
    cout << "Umur Anda pada tahun " << tahunTujuan << " adalah: " << umur << " tahun" << endl;

    return 0;
}

