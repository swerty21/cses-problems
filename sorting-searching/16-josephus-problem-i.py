from collections import deque

n = int(input().strip())
q = deque()

for i in range(1,n+1):
    q.append(i)

ans=[]
while q:
    q.append(q.popleft());
    ans.append(q.popleft());

print(*ans)
