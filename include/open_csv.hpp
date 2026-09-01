#ifndef OPEN_CSV
#define OPEN_CSV

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

class membaca_file_csv {
    private:
    std::ifstream file_csv;
    std::string line;

    public:
    membaca_file_csv();

    void membuka_file_csv(
        std::ifstream& file_csv,
        std::vector<float>& X,
        std::vector<float>& Y
    );

};

#endif

