#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Function to check if a sequence is safe or can be made safe by removing one level
bool isReportSafe(const std::vector<int>& report) {
    if (report.size() < 2) {
        return false; // Not enough data to determine a trend
    }

    // Lambda function to check if a sequence follows the rules
    auto isSequenceSafe = [](const std::vector<int>& seq) {
        if (seq.size() < 2) return false; // Still unsafe if less than 2 levels

        bool shouldIncrease = seq[0] < seq[1]; // Determine the initial trend

        for (size_t i = 0; i < seq.size() - 1; ++i) {
            int difference = seq[i + 1] - seq[i];

            // Check if the trend or difference is violated
            if ((shouldIncrease && (difference < 1 || difference > 3)) ||  // Increasing but not within range
                (!shouldIncrease && (difference > -1 || difference < -3))) { // Decreasing but not within range
                return false; // Unsafe sequence
            }

            // Ensure the direction remains consistent
            if ((shouldIncrease && difference <= 0) || (!shouldIncrease && difference >= 0)) {
                return false; // Trend violation
            }
        }
        return true; // Safe sequence
        };

    // Check if the sequence is safe without modifications
    if (isSequenceSafe(report)) {
        return true;
    }

    // Try removing one level at a time to see if it becomes safe
    for (size_t i = 0; i < report.size(); ++i) {
        std::vector<int> modifiedReport = report;
        modifiedReport.erase(modifiedReport.begin() + i); // Remove one level

        if (isSequenceSafe(modifiedReport)) {
            return true; // Safe by removing one level
        }
    }

    return false; // Unsafe if no single-level removal makes it safe
}

// Function to run test cases
void runTestCases() {
    struct TestCase {
        std::vector<int> report;
        bool expectedUnsafe;
        std::string description;
    };

    // Define test cases
    std::vector<TestCase> testCases = {
        {{1}, true, "Unsafe single element (not enough data)"},
        {{}, true, "Unsafe empty sequence"},
        {{7, 6, 4, 2, 1}, false, "Safe without removing any level"},
        {{1, 2, 7, 8, 9}, true, "Unsafe regardless of which level is removed, jump > 3"},
        {{9, 7, 6, 2, 1}, true, "Unsafe regardless of which level is removed"},
        {{1, 3, 2, 4, 5}, false, "Safe by removing the second level, 3"},
        {{8, 6, 4, 4, 1}, false, "Safe by removing the third level, 4"},
        {{1, 3, 6, 7, 9}, false, "Safe without removing any level"}
    };

    std::cout << "Running test cases...\n";

    // Execute test cases
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        bool result = isReportSafe(testCase.report);

        std::cout << "Test " << i + 1 << ": " << testCase.description << "\n";
        std::cout << "  Report: ";
        for (int num : testCase.report) {
            std::cout << num << " ";
        }
        std::cout << "\n  Expected: " << (testCase.expectedUnsafe ? "Unsafe" : "Safe")
            << ", Got: " << (result ? "Unsafe" : "Safe") << "\n";

        if (result == !testCase.expectedUnsafe) {
            std::cout << "  Result: PASS\n";
        }
        else {
            std::cout << "  Result: FAIL\n";
        }
        std::cout << "--------------------------------\n";
    }
}

int main() {
    // Run predefined test cases
    runTestCases();

    // Read input file and process reports
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> allReports;
    std::string line;

    // Read and parse the input file
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::vector<int> report;
        int num;

        while (ss >> num) {
            report.push_back(num); // Store each integer in the vector
        }
        allReports.push_back(report); // Store the report in the collection
    }

    file.close(); // Close the input file

    // Count unsafe reports
    int unsafeCount = 0;
    for (const auto& report : allReports) {
        if (isReportSafe(report)) {
            ++unsafeCount;
        }
    }

    std::cout << "There are " << unsafeCount << " unsafe reports.\n";

    return 0;
}