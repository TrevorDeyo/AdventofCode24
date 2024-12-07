#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

bool isReportUnsafe(const std::vector<int>& report) {
    // Handle the special case where the first two elements are equal
    if (report[0] == report[1]) {
        return true;
    }

    bool shouldIncrease = report[0] < report[1]; // Determine the trend

    for (size_t i = 0; i < report.size() - 1; ++i) {
        int difference = report[i + 1] - report[i];

        // Check if the trend is violated or the difference is out of bounds
        if ((shouldIncrease && difference <= 0) ||
            (!shouldIncrease && difference >= 0) ||
            (std::abs(difference) > 3)) {
            return true; // Unsafe report
        }
    }

    return false; // Safe report
}

int main()
{
    std::ifstream file("input.txt"); // Open File
    if (!file) { // Check if file opened successfully
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> allLines; // vector of vectors to store all lines
    std::string line;

    // Read and parse the input file
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

    // Start timing the unsafe report calculation because im just curious
    auto start = std::chrono::high_resolution_clock::now();

    int unsafeCount = 0; // store unsafe count
    for (const auto& report : allLines) {
        // check if each increment are within limits +1 to +3
            for (int i = 0; i < report.size() - 1; i++) {
                // make sure were increasing each step
                if (report[i] >= report[i + 1]) {
                    reportUnsafe = true;
                    break;
                }
                // make sure the difference is within limits
                int difference = abs(report[i] - report[i + 1]);
                if (difference > 3) {
                    reportUnsafe = true;
                    break;
                }
            }
        }
        else { //should be decreasing
            for (int i = 0; i < report.size() - 1; i++) {
                // make sure were decreasing each step
                if (report[i] >= report[i + 1]) {
                    reportUnsafe = true;
                    break;
                }
                // make sure the difference is within limits
                int difference = abs(report[i] - report[i + 1]);
                if (difference > 3) {
                    reportUnsafe = true;
                    break;
                }
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
