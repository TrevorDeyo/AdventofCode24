#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    /*
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
    */

    std::vector<int> list1 = {3, 4, 2, 1, 3, 3};
    std::vector<int> list2 = {4, 3, 5, 3, 9, 3};

    std::sort(list1.begin(), list1.end()); // Sort Ascensding Order
    std::sort(list2.begin(), list2.end());

    auto last1 = std::unique(list1.begin(), list1.end()); // Find Duplicates
    auto last2 = std::unique(list2.begin(), list2.end());

    list1.erase(last1, list1.end()); // Remove Duplicates
    list2.erase(last2, list2.end());

    // Finds how long to loop for
    int loopCount = 0;
    if (list1.size() > list2.size()) {
        loopCount = list2.size();
    }
    else {
        loopCount = list1.size();
    }

    // DEBUG
    for (int i = 0; i < loopCount; i++) {
        std::cout << list1[i] << " " << list2[i] << "\n";
    }

    // Does the math
    int totalDistance = 0;
    for (int i = 0; i < loopCount; i++) {
        totalDistance += list2[i] - list1[i];
        if (i <= 10) {
            std::cout << totalDistance << "\n";
        }
    }
    std::cout << totalDistance << "\n";
}
