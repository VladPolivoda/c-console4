#include <locale>
#include <iostream>
#include <bitset>
#include <iomanip>

int main() {
    system("chcp 65001");
    int userByte;
    std::locale::global(std::locale(""));
    std::cout << "Введіть значення байта: ";
    std::cin >> userByte;

    if (userByte > 255) {
        userByte = userByte % 256;
    }
    else if (userByte < 0) {
        userByte = 100;  
    }

    std::cout << "Значення у десятковому вигляді: " << userByte << std::endl;
    std::bitset<8> binaryByte(userByte);
    std::cout << "Значення у бінарному вигляді: " << binaryByte << std::endl;

    std::cout << "\033[1;31mВиділені біти: " << binaryByte[7] << binaryByte[0] << "\033[0m" << std::endl;

    std::bitset<8> shiftedByte(userByte >> 1 | (userByte & 1) << 7);

    std::cout << "Результат циклічного зсуву: " << shiftedByte << " (" << static_cast<int>(shiftedByte.to_ulong()) << ")" << std::endl;

    int resultByte = userByte - 200;

    std::cout << "Результат віднімання 200: ";
    std::bitset<8> resultBinaryByte(resultByte);
    if (resultByte < 0) {
        std::cout << "00000000 " << resultBinaryByte;
    }
    else {
        std::cout << resultBinaryByte;
    }
    std::cout << " (" << resultByte << ")" << std::endl;

    return 0;
}
