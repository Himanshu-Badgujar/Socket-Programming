cmake_minimum_required(VERSION 3.23)
project(Networking_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server server.cpp)

# Link the required libraries for sockets (on Linux)
target_link_libraries(Server pthread)