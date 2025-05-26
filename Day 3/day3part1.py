import os
import re

with open(r'C:\Code\AdventofCode24\Day 3\input.txt', 'r') as f:
    data = f.read()

matches = re.findall(r'mul\((\d{1,3}),(\d{1,3})\)', data)

#print(matches)

running_total = 0

for match in matches:
    # extract each number from the matches
    num1_str = match[0]
    num2_str = match[1]

    # convert to int
    num1 = int(num1_str)
    num2 = int(num2_str)

    # add the product to the running total
    running_total += num1 * num2

print(running_total)