cmake_minimum_required(VERSION 3.10)
project(PasswordManager)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(PasswordManager main.cpp encryptor.cpp storage.cpp)
target_link_libraries(PasswordManager ${OPENSSL_LIBRARIES})
