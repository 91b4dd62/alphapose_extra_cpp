cmake_minimum_required(VERSION 3.18)

project(test)

set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_TOOLCHAIN_FILE "C:/Program Files/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_executable(main main.cpp)

find_package(OpenCV REQUIRED)

target_link_libraries(main ${OpenCV_LIBS})

