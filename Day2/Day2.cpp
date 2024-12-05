#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

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

    auto start = std::chrono::high_resolution_clock::now();

    int unsafeCount = 0; // store unsafe count
    for (std::vector<int> report : allLines) {
        // for tracking unsafe status
        bool reportUnsafe = false;
        // check if each increment are within limits + or - | 1 to 3
        for (int i = 0; i < report.size() - 1; i++) {
            if (report[i] - report[i + 1] > 3 || report[i] - report[i + 1] < 1) {
                reportUnsafe = true;
            }
        }
        // Check if its all increasing or decreasing
        bool increasing;
        if (report[0] < report[1]) {
            increasing = true;
        }
        else {
            increasing = false;
        }
        // Check if all follow the pattern
        for (int i = 1; i < report.size() - 1 ; i++) {
            if (!(increasing == true && report[i + 1] > report[i])) {
                reportUnsafe = true;
            }
            if (!(increasing == false && report[i + 1] < report[i])) {
                reportUnsafe = true;
            }
        }
        if (reportUnsafe == true) {
            unsafeCount++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration in milliseconds, microseconds, or nanoseconds
    std::chrono::duration<double> duration = end - start;

    // Print the time taken in seconds (duration.count() gives the value in seconds)
    std::cout << "Time taken: " << duration.count() << " seconds\n";

    // Speed test doing <= >= and test storing .size() in a variable

    std::cout << "There are " << unsafeCount << " unsafe reports.\n";

    return 0;
}
