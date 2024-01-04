import random as rng

rng.seed(43)
operators = [["+", "-"], ["+"], ["-"]]
nums = [["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"],
    ["0"],
    ["1"],
    ["1", "2", "3", "4", "5", "6", "7", "8", "9"]]
dump = ""

chose_nums = 2
chose_op = 2

for i in range(81):
    if i % 9 == 0: dump += '\"'
    num = rng.choice(nums[chose_nums])
    op = "+" if num == '0' else rng.choice(operators[chose_op])
    dump += num + op
    if i % 9 == 8: dump += '\"\n'

print(dump)
