import os
import re

with open(r'C:\Code\AdventofCode24\Day 3\input.txt', 'r') as f:
    data = f.read()

running_total = 0
is_mul_enabled = True

#Group 1: (do\(\)) - This group captures the literal string "do()"
#Group 2: (don\'t\(\)) - This group captures the literal string "don't()"
#Group 3: (mul\((\d{1,3}),(\d{1,3})\)) - This group captures the entire "mul(...)" string (e.g., "mul(123,456)")
#Group 4: (\d{1,3}) - This group captures the first number inside mul()
#Group 5: (\d{1,3}) - This group captures the second number inside mul()

valid_data_iterator = re.finditer(r'(do\(\))|(don\'t\(\))|(mul\((\d{1,3}),(\d{1,3})\))', data)

for match in valid_data_iterator:

    if match[0] == 'do()':
        is_mul_enabled = True
    elif match[0] == "don't()":
        is_mul_enabled = False
    elif is_mul_enabled:
        num1 = int(match.group(4))
        num2 = int(match.group(5))
        running_total += num1 * num2

print(running_total)