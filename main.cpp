#include "open_csv.hpp"
#include "print_output.hpp"
#include "Neural_Network.hpp"
#include "preprocessing_data.hpp"
#include "pembagian_pelatihan.hpp"
#include <iostream>

int main() {
    std::cout << "MEMULAI PEMROGRAMAN AI NEURAL NETWORK" << std::endl;
    std::ifstream file_csv("/home/nvoinxv/Documents/Linear_Regression_Neural_Network_CPP/Linear Regression - Sheet1.csv");
    
    membaca_file_csv membaca;

    file_csv.clear();
    file_csv.seekg(0);

    std::vector<float> X;
    std::vector<float> Y;

    std::vector<float> y_pred;
    std::vector<float> y_actual;
    
    float nilai;

    membaca.membuka_file_csv(file_csv, X, Y);
    
    std::cout << "MEMULAI PREPROCESSING DATA" << std::endl;
    preprocessing data_preproses;
    
    data_preproses.penghapusan_outlier(X);
    data_preproses.standard_scaler(X);

    data_preproses.penghapusan_outlier(Y);

    Pembagian_Pelatihan(x, y, ukuran_pelatihan = 0.8);
    
    pelatihan_model(x, y);

    pembersihan_memori(x, y);

    std::cout << "PROGRAM SELESAI" << std::endl;
    return 0;
}