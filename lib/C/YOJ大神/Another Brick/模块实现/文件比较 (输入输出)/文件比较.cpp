#include <fstream>
#include <string>
#include <iostream>

int main() {
    std::ifstream file1("output1.out");
    std::ifstream file2("output2.out");

    std::string line1, line2;
    int lineNum = 1;

    while (std::getline(file1, line1) && std::getline(file2, line2)) {
        if (line1 != line2) {
            std::cout << "no\n";
            std::cout << "Line " << lineNum << " differs.\n";
            std::cout << "File1: " << line1 << "\n";
            std::cout << "File2: " << line2 << "\n";
            return 0;
        }
        lineNum++;
    }

    // 检查是否有一个文件还有剩余的行
    if (std::getline(file1, line1) || std::getline(file2, line2)) {
        std::cout << "no\n";
        std::cout << "One file has more lines than the other.\n";
        return 0;
    }

    std::cout << "yes\n";
    return 0;
}