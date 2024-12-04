#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::string word;
    
    int id = 0;
    std::vector<int> list1;
    std::vector<int> list2;
    while (file >> word) {
        if (id % 2 == 0) {
            list1.push_back(std::stoi(word));
        }
        else {
            list2.push_back(std::stoi(word));
        }
        id++;
    }
    
    file.close();

    //std::cout << list1[0] << " " << list2[0] << "\n";

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    for (int i = 0; i < 10; i++) {
        std::cout << list1[i] << " " << list2[i] << "\n";
    }
    
    int totalDistance = 0;
    for (int i = 0; i < list1.size(); i++) {
        totalDistance += (list1[i] - list2[i]);
        if (i <= 10) {
            std::cout << totalDistance << "\n";
        }
    }
    std::cout << totalDistance << "\n";
}
