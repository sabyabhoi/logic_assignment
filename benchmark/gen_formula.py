"""."""
import string
import random
import sys

N = int(sys.argv[1])
atoms = random.choices(string.ascii_uppercase, k=N)

OPS = ('+', '*', '>')


def gen_expr(atoms):
    """Return a random logical expression."""
    ops = random.choices(OPS, k=N-1)
    ans = ""
    for i in range(N-1):
        ans += atoms[i]
        ans += ops[i]
    ans += atoms[N-1]
    return ans


print(gen_expr(atoms))
for i in range(N):
    print(random.choice([0, 1]), end=' ')
print()
