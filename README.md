# 🔐 Password Manager

A simple command-line interface (CLI) Password Manager written in C++ that allows users to store, encrypt, and decrypt passwords securely. This project uses OpenSSL for encryption and decryption of passwords and a text file for storing the encrypted data.

## ✨ Features

- **🔒 Save Passwords**: Save usernames and encrypted passwords to a file.
- **🔓 Load Passwords**: Load and decrypt passwords from the file.
- **🔑 Encryption and Decryption**: Uses AES-256-CBC encryption for secure password management.
- **💻 CLI Interface**: Simple command-line interface for ease of use.

## 📋 Prerequisites

- C++11 or later
- OpenSSL library

## ⚙️ Installation

1. **📥 Clone the repository:**

```bash
git clone https://github.com/pkprajapati7402/Password-manager.git
cd Password-manager
```

2. **🔧 Install OpenSSL:**

Follow the installation guide on the [OpenSSL website](https://www.openssl.org/).

3. **🏗️ Build the project:**

Create a `CMakeLists.txt` file with the following content:

```cmake
cmake_minimum_required(VERSION 3.10)
project(PasswordManager)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(PasswordManager main.cpp encryptor.cpp storage.cpp)
target_link_libraries(PasswordManager ${OPENSSL_LIBRARIES})
```

Run the following commands to build the project:

```bash
mkdir build
cd build
cmake ..
make
```

4. **🚀 Run the Password Manager:**

```bash
./PasswordManager
```

## 🛠️ Usage

When you run the Password Manager, you will see a simple menu:

```
Password Manager CLI
1. Save Password
2. Load Password
3. Exit
Choose an option:
```

### 📝 Saving a Password

1. Choose option `1` to save a password.
2. Enter the username and password when prompted.
3. The password is encrypted and saved to the `passwords.txt` file.

### 🔍 Loading a Password

1. Choose option `2` to load a password.
2. Enter the username when prompted.
3. If the username exists, the encrypted password is decrypted and displayed.

### ❌ Exiting the Program

1. Choose option `3` to exit the program.

## 🗂️ File Structure

- `main.cpp`: The entry point of the application and main logic.
- `encryptor.cpp` and `encryptor.h`: Functions for encryption and decryption.
- `storage.cpp` and `storage.h`: Functions for storing and retrieving data.
- `CMakeLists.txt`: CMake build configuration file.

## 🤝 Contributing

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit them (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

## 📄 License

This project is licensed under the MIT License.

## 🙏 Acknowledgements

- OpenSSL for providing the encryption and decryption library.

---

Feel free to update or customize this README as per your project's requirements.
