#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main()
{
    std::ifstream file("input.txt"); // Open File

    if (!file) { // Check if file opened successfully
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> allLines; // vector of vectors to store all lines

    std::string line;
    while (std::getline(file, line)) { // Read file line by line
        std::istringstream ss(line); // Use stringstream to parse the line
        std::vector<int> report;
        int num;

        while (ss >> num) { // Extract integers from the string
            report.push_back(num); // Store each integer in the vector
        }

        allLines.push_back(report); // Store report Vector into the allLines vector
    }
    file.close(); // close the file

    int unsafeCount = 0; // store unsafe count
    for (std::vector<int> report : allLines) {
        bool increasing;
        for (int i = 0; i < report.size() - 1; i++) {
            if (report[i] < report[i + 1] + 1 && report[i] < report[i + 1] + 4 || report[i] < report[i + 1] - 1 && report[i] > report[i + 1] - 4) {
                
            }
        }
    }
    return 0;
}
