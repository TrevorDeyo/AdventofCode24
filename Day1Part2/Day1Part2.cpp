#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>

int main()
{
    // Open the input file
    std::fstream newfile;
    newfile.open("input.txt", std::ios::in); // Open the file in read mode

    // Check if the file was successfully opened
    if (newfile.is_open())
    {
        // Initialize vectors to store data from the file
        std::vector<int> list1;
        std::vector<int> list2;

        // Read each line from the file
        std::string line;
        while (getline(newfile, line))
        {
            std::istringstream ss(line); // Parse integers from the line
            int num1, num2;
            ss >> num1 >> num2;         // Extract two integers
            list1.push_back(num1);      // Add to list1
            list2.push_back(num2);      // Add to list2
        }

        // Close the file after reading
        newfile.close();

        // Sort both vectors in ascending order
        std::sort(list1.begin(), list1.end());
        std::sort(list2.begin(), list2.end());

        // Create a map to store the frequency of numbers from list1 in list2
        std::unordered_map<int, int> numCounts;

        // Count occurrences of each number in list1 within list2
        for (int num1 : list1)
        {
            int numCount = 0; // Track occurrences of num1 in list2
            for (int num2 : list2)
            {
                if (num2 > num1) // Exit early for sorted lists
                    break;
                if (num1 == num2) // Count matches
                    numCount++;
            }
            numCounts[num1] = numCount; // Store count in the map
        }

        // Calculate the total similarity score
        int totalSimilarityScore = 0;
        for (const auto& pair : numCounts)
        {
            totalSimilarityScore += pair.first * pair.second;
        }

        // Print the similarity score
        std::cout << totalSimilarityScore;
    }
    return 0;
}
