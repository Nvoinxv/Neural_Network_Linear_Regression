#include "open_csv.hpp"

membaca_file_csv::membaca_file_csv() : file_csv(), line() {
    // Isi konstruktor jika ada
}

void membaca_file_csv::membuka_file_csv(
    std::ifstream& file_csv,
    std::vector<float>& X,
    std::vector<float>& Y
) {
    while (std::getline(file_csv, line)) {
        std::stringstream ss(line);
        std::string cell;
        
        std::getline(ss, cell, ',');

        if (cell == "X") {
            continue;
        }

        float nilai_x = std::stof(cell);

 

        std::getline(ss, cell, ',');

        if (cell == "Y") {
            continue;
        }

        float nilai_Y = std::stof(cell);

        X.push_back(nilai_x);
        Y.push_back(nilai_Y);

    }
    file_csv.close();
}

