from sys import stdin

n = int(input().strip())
ranges = []
for (i,lines) in enumerate(stdin):
    a,b = map(int,lines.strip().split())
    ranges.append((a,-b,i))

ranges.sort()

ans = [0]*n
min_end = int(2e9)
for i in range(n-1,-1,-1):
    if -ranges[i][1] >= min_end:
        ans[ranges[i][2]] = 1
    min_end = min(min_end,-ranges[i][1])

print(*ans)

ans = [0] * n
max_end = 0
for i in range(n):
    if -ranges[i][1] <= max_end:
        ans[ranges[i][2]] = 1
    max_end = max(max_end,-ranges[i][1])

print(*ans)