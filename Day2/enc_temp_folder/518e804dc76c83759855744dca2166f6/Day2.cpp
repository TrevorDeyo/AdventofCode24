#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <iomanip> // For formatting output

bool isReportUnsafe(const std::vector<int>& report) {
    // Handle the special case where the first two elements are equal
    if (report[0] == report[1]) {
        return true;
    }

    bool shouldIncrease = report[0] < report[1]; // Determine the trend

    for (size_t i = 0; i < report.size() - 1; ++i) {
        int difference = report[i + 1] - report[i];

        // Check if the trend is violated or the difference is out of bounds
        if ((shouldIncrease && difference < 1) ||
            (!shouldIncrease && difference > -1) ||
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
        if (isReportUnsafe(report)) {
            ++unsafeCount;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = end - start;


    // Output results with different time units
    std::cout << std::fixed << std::setprecision(6); // Formatting for clarity
    std::cout << "Time taken:\n";
    std::cout << "  Seconds: " << std::chrono::duration<double>(duration).count() << " s\n";
    std::cout << "  Milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << " ms\n";
    std::cout << "  Microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(duration).count() << " µs\n";
    std::cout << "  Nanoseconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count() << " ns\n";

    std::cout << "There are " << unsafeCount << " unsafe reports.\n";

    return 0;
}