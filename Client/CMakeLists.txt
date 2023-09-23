cmake_minimum_required(VERSION 3.23)
project(Networking_Project_Client)

set(CMAKE_CXX_STANDARD 14)

add_executable(Networking_Project_Client main.cpp)

# Link the required libraries for sockets (on Linux)
target_link_libraries(Networking_Project_Client pthread)
