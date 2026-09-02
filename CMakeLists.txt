cmake_minimum_required(VERSION 3.23)

project(LINEAR_REGRESSION_NEURAL_NETWORK VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    main.cpp
    src/open_csv.cpp
    src/preprocessing_data.cpp
    src/print_output.cpp
    src/linear_layer.cpp
    src/mean_squared_error.cpp
    src/Neural_Network.cpp
    src/optimisasi_neuron.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)