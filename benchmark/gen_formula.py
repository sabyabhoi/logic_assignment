"""."""
import string
import random
import itertools

N = 5
atoms = random.sample(string.ascii_uppercase, N)

OPS = ('+', '*', '>')


def gen_exprs(n, atoms):
    """Generate all possible expressions."""
    exprs = []

    for x in itertools.product(OPS, repeat=n - 1):
        s = ""
        for i in range(0, n-1):
            s += atoms[i]
            s += x[i]
        s += atoms[N-1]
        exprs.append(s)
    return exprs


def add_parens(s):
    """Add parenthesis to given string."""
    if len(s) <= 1:
        return
    open_ix = random.randint(0, len(s) - 1)
    if s[open_ix] in OPS:
        open_ix -= 1
    s = s[:open_ix] + '(' + s[open_ix:]

    close_ix = random.choice([x for x in range(open_ix+1, len(s), 2)]) + 1
    s = s[:close_ix] + ')' + s[close_ix:]
    return s


parens = 2
for i in range(1, 100):
    s = gen_exprs(N, atoms)[0]
    for _ in range(parens):
        s = add_parens(s)
    print(s)
