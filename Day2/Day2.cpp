#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

bool isReportUnsafe(const std::vector<int>& report) 
{
    if (report.size() < 2) {
        return true; // Not enough data to determine a trend
    }

    bool shouldIncrease = report[0] < report[1]; // Determine the initial trend

    for (size_t i = 0; i < report.size() - 1; ++i) {
        int difference = report[i + 1] - report[i];

        // Check if the trend or difference is violated
        if ((shouldIncrease && (difference < 1 || difference > 3)) ||  // Increasing but not within range
            (!shouldIncrease && (difference > -1 || difference < -3))) { // Decreasing but not within range
            return true; // Unsafe report
        }

        // Ensure the direction remains consistent
        if ((shouldIncrease && difference <= 0) || (!shouldIncrease && difference >= 0)) {
            return true; // Trend violation
        }
    }

    return false; // Safe report
}

void runTestCases()
{
    struct TestCase {
        std::vector<int> report;
        bool expectedUnsafe;
        std::string description;
    };

    // Define test cases
    std::vector<TestCase> testCases = {
        {{1, 2, 3, 5}, false, "Safe increasing sequence"},
        {{1, 2, 6}, true, "Unsafe increasing (jump > 3)"},
        {{5, 3, 2, 1}, false, "Safe decreasing sequence"},
        {{5, 3, 7}, true, "Unsafe decreasing (trend violation)"},
        {{1, 3, 2}, true, "Unsafe mixed trend (trend reversal)"},
        {{3, 3}, true, "Unsafe equal values"},
        {{1}, true, "Unsafe single element (not enough data)"},
        {{}, true, "Unsafe empty sequence"}
    };

    std::cout << "Running test cases...\n";

    // Execute test cases
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        bool result = isReportUnsafe(testCase.report);
        std::cout << "Test " << i + 1 << ": " << testCase.description << "\n";
        std::cout << " Report: ";
        for (int num : testCase.report) {
            std::cout << num << " ";
        }
        std::cout << "\n Expected: " << (testCase.expectedUnsafe ? "Unsafe" : "Safe")
            << ", Got: " << (result ? "Unsafe" : "Safe") << "\n";

        if (result == testCase.expectedUnsafe) {
            std::cout << "  Result: PASS\n";
        }
        else {
            std::cout << "  Result: FAIL\n";
        }
        std::cout << "--------------------------------\n";
    }
}

int main()
{
    // Test Cases
    runTestCases();

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

    int unsafeCount = 0; // store unsafe count
    for (const auto& report : allLines) {
        if (isReportUnsafe(report)) {
            ++unsafeCount;
        }
    }

    std::cout << "There are " << unsafeCount << " unsafe reports.\n";

    return 0;
}