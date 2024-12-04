#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int main()
{
    // Open the input file
    std::fstream newfile;
    newfile.open("input.txt", std::ios::in); // Open the file in read mode

    // Check if the file was successfully opened
    if (newfile.is_open())
    {
        // Initialize variables to store input lines and vectors for data
        std::string line;
        std::vector<int> list1;
        std::vector<int> list2;

        // Read each line from the file
        while (getline(newfile, line))
        {
            // Use a stringstream to parse integers from the line
            std::istringstream ss(line);
            int num1, num2;

            // Extract two integers from the current line
            ss >> num1 >> num2;

            // Add the integers to their respective vectors
            list1.push_back(num1);
            list2.push_back(num2);
        }

        // Close the file after reading
        newfile.close();

        // Sort both vectors in ascending order
        std::sort(list1.begin(), list1.end());
        std::sort(list2.begin(), list2.end());

        // Get the size of the vectors (they should be the same)
        int n = list1.size();

        // Debugging: Print the sorted vectors (Optional)
        std::cout << "Sorted Lists:\n";
        for (int i = 0; i < n; i++) {
            std::cout << list1[i] << " " << list2[i] << "\n";
        }

        // Calculate the total distance between corresponding elements
        int totalDistance = 0;
        for (int i = 0; i < n; i++) {
            totalDistance += abs(list1[i] - list2[i]); // Use abs to calculate absolute difference
        }

        // Print the total distance
        std::cout << "Total Distance: " << totalDistance << "\n";
    }
    else
    {
        // Error message if the file couldn't be opened
        std::cerr << "Error: Could not open the file.\n";
    }

    return 0; // End of the program
}
