#ifndef ELFFOOD_H
#define ELFFOOD_H

#include <string>
#include <cstdint>
#include <vector>
#include <fstream>

class ElfFood {
    private:
        // Vars
        std::string line;
        uint32_t tmp_num;
        uint8_t count;
        uint8_t m_intCount;
        std::vector<uint32_t> maxList;
        std::vector<uint8_t> elfNum;
        std::fstream calorie_list;

        // Methods
        void checkMax();
        void readFile();

    public:
        ElfFood(uint8_t intCount);
        void getMax();
        void getTotal();
};

#endif
