"""."""
import string
import random
import sys

N = int(sys.argv[1])
atoms = random.choices(string.ascii_uppercase, k=N)

OPS = ('+', '*', '>')


def gen_expr(atoms):
    """Return a random logical expression."""
    n = len(atoms)
    ops = random.choices(OPS, k=n-1)
    ans = ""
    for i in range(n-1):
        ans += atoms[i]
        ans += ops[i]
    ans += atoms[n-1]
    return ans


def gen_input(atoms):
    n = len(atoms)
    s = gen_expr(atoms) + '\n'
    for i in range(min(n, 26)):
        s += str(random.choice([0, 1])) + ' '
    return s

print(gen_expr(atoms))
for i in range(min(N, 26)):
    print(random.choice([0, 1]), end=' ')
print()
