#include <iostream>
#include <string>

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "       Halo Dunia dari C++!             " << std::endl;
    std::cout << "========================================" << std::endl;

    std::string nama;
    std::cout << "Masukkan nama kamu: ";
    std::getline(std::cin, nama);

    if (nama.empty()) {
        nama = "Kawan";
    }

    std::cout << "\nSelamat datang, " << nama << "!" << std::endl;
    std::cout << "Program C++ berhasil dijalankan dengan sukses!" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}
