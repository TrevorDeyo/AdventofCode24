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

        // figure out how many times a number in list 1 appears in list 2
        // Calculate a total similarity score by adding up each number in
        // the left list after multiplying it by the number of times that
        // number appears in the right list.
    
        // create a hashmap to store the occurrence of each numbers
        std::unordered_map<int, int> numCounts;
        // for each number in list 1
        for (int num1 : list1) {
            // varible to count the occurrences
            int numCount = 0;
            // for each number in list 2
            for (int num2 : list2) {
                // since the vectors are sorted low to high, we can break out of the loop
                // if the list2 num is bigger than list1 num to save some computation
                if (num2 > num1) {
                    break;
                }
                // add each occurrence
                if (num1 == num2) {
                    numCount++;
                }
            }
            // add the count to the map
            numCounts[num1] = numCount;
        }
        // var to store the total simularity score
        int totalSimularityScore = 0;
        // multiply the numCounts pairs and add them together
        for (const auto& pair : numCounts) {
            totalSimularityScore += pair.first * pair.second;
        }
        // print score
        std::cout << totalSimularityScore;
    }
    return 0;
}