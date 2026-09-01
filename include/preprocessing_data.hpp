#ifndef PREPROCESSING_DATA_HPP
#define PREPROCESSING_DATA_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "print_output.hpp"

class preprocessing {
    private:
    std::vector<float> x;
    float u;
    float s;
    std::vector<float> Q1;
    std::vector<float> Q3;
    Print_Vektor printer;

    public:
    preprocessing();

    float median(std::vector<float>& x);

    void penghapusan_outlier(std::vector<float>& x);

    void standard_scaler(
        std::vector<float>& x
    );

};

#endif