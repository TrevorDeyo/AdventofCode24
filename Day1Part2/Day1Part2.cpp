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

        //figure out how many times a number in list 1 appears in list 2
        // 
    }
    return 0;
}