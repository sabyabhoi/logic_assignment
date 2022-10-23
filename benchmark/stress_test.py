from timeit import timeit

for i in range(3, 6):
    print('Input size: ', 10**i)
    print(timeit(stmt = "subprocess.call('../bin/Profiling/proParser < large.in > /dev/null', shell=True)", setup = "import subprocess", number = 10))
