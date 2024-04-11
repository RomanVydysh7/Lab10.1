#include <iostream>
#include <fstream>
#include <string>

// Функція для пошуку третьої коми у текстовому файлі
void findThirdComma(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 0;
    while (std::getline(file, line)) {
        lineNumber++;
        int commaCount = 0;
        for (size_t i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                commaCount++;
                if (commaCount == 3) {
                    std::cout << "three dots in " << lineNumber
                        << ", on position " << i + 1 << std::endl;
                    return;
                }
            }
        }
    }

    std::cout << "dont have dot`s." << std::endl;
}

int main() {
    std::string filename = "t.txt"; // замініть на шлях до вашого файлу
    findThirdComma(filename);
    return 0;
}