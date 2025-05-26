import os
import re

with open(r'C:\Code\AdventofCode24\Day 3\input.txt', 'r') as f:
    data = f.read()

matches = re.findall('mul\(\d{1,3},\d{1,3}\)', data)

for match in matches:
    