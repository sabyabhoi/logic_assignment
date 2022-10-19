import string
import random
import itertools

N = 5
atoms = random.sample(string.ascii_uppercase, N)

ops = ('+', '*', '>')

exprs = []
for x in itertools.product(ops, repeat=N - 1):
    s = ""
    for i in range(0, N-1):
        s += atoms[i]
        s += x[i]
    s += atoms[N-1]
    exprs.append(s)

print((exprs))
