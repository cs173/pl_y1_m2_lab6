set(PROJECT_NAME pl_y1_m2_lab6)
set(SOURCE_FILES
        main.cpp)
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(${PROJECT_NAME} LANGUAGES CXX)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)