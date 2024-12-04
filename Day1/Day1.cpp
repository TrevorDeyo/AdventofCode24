#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int main()
{
    std::fstream newfile;
    newfile.open("input.txt", std::ios::in);
    if (newfile.is_open())
    {
        std::string line;
        std::vector<int> list1;
        std::vector<int> list2;
        while (getline(newfile, line))
        {
            std::istringstream ss(line);
            int num1, num2;
            ss >> num1 >> num2;
            list1.push_back(num1);
            list2.push_back(num2);
        }
        /* MY CODE
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
        /* Example Testing
        std::vector<int> list1 = {3, 4, 2, 1, 3, 3};
        std::vector<int> list2 = {4, 3, 5, 3, 9, 3};
        */

        std::sort(list1.begin(), list1.end()); // Sort Ascensding Order
        std::sort(list2.begin(), list2.end());

        int n = list1.size();

        // DEBUG
        for (int i = 0; i < n; i++) {
            std::cout << list1[i] << " " << list2[i] << "\n";
        }

        // Does the math
        int totalDistance = 0;
        for (int i = 0; i < n; i++) {
            totalDistance += abs(list1[i] - list2[i]);
        }
        std::cout << totalDistance << "\n";
    }
    newfile.close();
}