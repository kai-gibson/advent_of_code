#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ifstream ifs ("day1.txt");
    std::string line;
    std::vector<int> data, sums;

    while (std::getline(ifs, line)) data.push_back(            
            (line.empty() ? 0 : std::stoi(line)));

    int sum = 0;
    for (int i=0; i<data.size(); i++) {
        if (data[i] == 0 || i == data.size()-1) {
            sums.push_back(sum);
            sum = 0;
        } else {
            sum += data[i];
        }
    }

    std::sort(sums.begin(), sums.end(), std::greater<int>());
    std::cout << sums[0] << std::endl;
    std::cout << sums[0] + sums[1] + sums[2] << std::endl;
}
