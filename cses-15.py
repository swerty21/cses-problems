from sys import stdin
from itertools import permutations

for line in stdin:
    ans = [ ''.join(x) for x in permutations(line.strip()) ]
    ans = sorted(list(set(ans)))
    print(len(ans))
    for x in ans: print(x)
