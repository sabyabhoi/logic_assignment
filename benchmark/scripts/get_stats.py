from gen_formula import gen_input
import random
import string
import subprocess
from timeit import timeit 

base = 100000

for i in range(3, 6):
    print('Input size: ', base*i)
    atoms = random.choices(string.ascii_uppercase, k=base*i)

    with open('large.in', 'w') as f:
        f.write(gen_input(atoms))

    print('Time taken: ', end='')
    time = timeit(stmt = "subprocess.call('../bin/Profiling/proParser < large.in > /dev/null', shell=True)", setup = "import subprocess", number = 10)
    print(time / 10)
