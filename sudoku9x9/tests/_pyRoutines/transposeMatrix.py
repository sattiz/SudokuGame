import random as rng

rng.seed(42)
operators = ["+", "-"]
strings = [
    "123456789",
    "123456789",
    "123456789",
    "123456789",
    "123456789",
    "123456789",
    "123456789",
    "123456789",
    "123456789"
]
matrix = []

for string in strings:
    chars = [int(c) for c in string]
    nums = [int(char) for char in chars]
    matrix.append(nums)

matrix = list(list(x) for x in zip(*matrix))

for row in matrix:
    print("\"", end="")
    for elem in row:
        print(elem, rng.choice(operators), sep="", end="")
    print("\"")




