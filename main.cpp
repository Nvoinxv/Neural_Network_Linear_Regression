#include "open_csv.hpp"
#include "print_output.hpp"
#include "Neural_Network.hpp"
#include "preprocessing_data.hpp"
#include "pembagian_pelatihan.hpp"
#include <iostream>
#include <string>

int main() {
    Print_Vektor printer;
    printer.Mencetak_Hasil_Output_Sama_Dengan();
    std::cout << "MEMULAI PEMROGRAMAN AI NEURAL NETWORK" << std::endl;
    printer.Mencetak_Hasil_Output_Sama_Dengan();

    // 1. Membuka dan membaca file CSV dataset
    std::string path_file = "Linear Regression - Sheet1.csv";
    std::ifstream file_csv(path_file);

    if (!file_csv.is_open()) {
        file_csv.open("/home/nvoinxv/Documents/Linear_Regression_Neural_Network_CPP/Linear Regression - Sheet1.csv");
        if (!file_csv.is_open()) {
            std::cerr << "Gagal membuka file CSV: " << path_file << std::endl;
            return 1;
        }
    }
    
    membaca_file_csv membaca;

    std::vector<float> X;
    std::vector<float> Y;

    membaca.membuka_file_csv(file_csv, X, Y);

    std::cout << "Jumlah data yang berhasil dibaca: " << X.size() << " baris." << std::endl;
    
    // 2. Preprocessing Data
    printer.Mencetak_Hasil_Output_Sama_Dengan();
    std::cout << "MEMULAI PREPROCESSING DATA" << std::endl;
    preprocessing data_preproses;
    
    std::cout << "\n[1] Pengecekan Outlier pada Fitur X:" << std::endl;
    data_preproses.penghapusan_outlier(X);

    std::cout << "\n[2] Pengecekan Outlier pada Target Y:" << std::endl;
    data_preproses.penghapusan_outlier(Y);

    // 3. Pembagian Data Pelatihan dan Pengujian
    printer.Mencetak_Hasil_Output_Sama_Dengan();
    std::cout << "MEMULAI PEMBAGIAN DATA PELATIHAN DAN PENGUJIAN" << std::endl;
    Pembagian_Pelatihan pembagian;
    float ukuran_pelatihan = 0.8f;
    float ukuran_test = 0.2f;

    pembagian_pelatihan_test hasil_pembagian = pembagian.fit_pembagian(X, Y, ukuran_test, ukuran_pelatihan);

    std::cout << "Jumlah Data Latih (Train): " << hasil_pembagian.hasil_pelatihan_x.size() << std::endl;
    std::cout << "Jumlah Data Uji (Test): " << hasil_pembagian.hasil_test_x.size() << std::endl;
    
    // 4. Inisialisasi dan Pelatihan Model Neural Network Linear Regression
    printer.Mencetak_Hasil_Output_Sama_Dengan();
    std::cout << "MEMULAI PELATIHAN MODEL" << std::endl;
    latihan_deeplearning model;
    
    int jumlah_epoch = 1000;
    model.pelatihan_model(hasil_pembagian.hasil_pelatihan_x, hasil_pembagian.hasil_pelatihan_y, jumlah_epoch);

    // 5. Evaluasi Model pada Data Uji
    model.evaluasi_model(hasil_pembagian.hasil_test_x, hasil_pembagian.hasil_test_y);

    // 6. Pembersihan Memori
    printer.Mencetak_Hasil_Output_Sama_Dengan();
    std::cout << "MEMULAI PEMBERSIHAN MEMORI" << std::endl;
    model.pembersihan_memori();

    printer.Mencetak_Hasil_Output_Sama_Dengan();
    std::cout << "PROGRAM SELESAI" << std::endl;
    printer.Mencetak_Hasil_Output_Sama_Dengan();

    return 0;
}