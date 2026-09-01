#include "open_csv.hpp"
#include "print_output.hpp"
#include "mean_squaered_error.hpp"
#include "linear_layer.hpp"
#include "preprocessing_data.hpp"
#include <iostream>

int main() {
    std::cout << "MEMULAI PEMROGRAMAN AI NEURAL NETWORK" << std::endl;
    std::ifstream file_csv("/home/nvoinxv/Documents/Linear_Regression_Neural_Network_CPP/Linear Regression - Sheet1.csv");
    
    membaca_file_csv membaca;

    file_csv.clear();
    file_csv.seekg(0);

    std::vector<float> X;
    std::vector<float> Y;
    float nilai;

    membaca.membuka_file_csv(file_csv, X, Y);
    
    std::cout << "MEMULAI PREPROCESSING DATA" << std::endl;
    preprocessing data_preproses;
    
    data_preproses.penghapusan_outlier(X);
    data_preproses.standard_scaler(X);

    data_preproses.penghapusan_outlier(Y);

    std::cout << "PROGRAM SELESAI" << std::endl;
    return 0;
}