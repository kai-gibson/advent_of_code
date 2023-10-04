#include "ElfFood.h"
#include <iostream>

// constructor
ElfFood::ElfFood(uint8_t intCount) {
    line = "";
    tmp_num = 0;
    count = 0;
    m_intCount = intCount;
    maxList = { 0 };
    elfNum = { 0 };
}

// private methods
void ElfFood::checkMax() {
    for (int i=0; i<m_intCount; i++) {
        if (tmp_num > maxList[i]) {
            maxList[i] = tmp_num;
            elfNum[i] = count;
            break;
        }
    }
}

void ElfFood::readFile() {
    // Try and open file for reading
    calorie_list.open("file");
    if (not calorie_list.is_open()) { 
        std::cout << "Could not open file" << std::endl; 
        return;
    }

    while (getline(calorie_list, line)) {
        if (line != "") { tmp_num += stoi(line); }
        else {
            checkMax();
            count++;
            tmp_num = 0;
        }
    }
    checkMax();
}


// public methods
void ElfFood::getMax() {
    readFile();

    if (m_intCount > 1) { 
        std::cout << "Top " << unsigned(m_intCount) << ":" << std::endl;
    }

    for (int i=0; i<m_intCount; i++) {
        std::cout << "Number " << i + 1 << ": " <<
            " Elf number " << unsigned(elfNum[i]) << 
            " with " << unsigned(maxList[i]) << 
            " calories" << std::endl;
    }
    return;
}

void ElfFood::getTotal() {
    tmp_num = 0;
    for (int i=0; i<m_intCount; i++) {
        tmp_num += maxList[i];
    }

    std::cout << std::endl << "Total Calories: " << unsigned(tmp_num) << std::endl;
}

