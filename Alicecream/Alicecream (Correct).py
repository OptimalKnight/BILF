import sys
from collections import defaultdict

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    A = list(map(int, input().split()))

    bad = set()
    for i in range(M):
        x, y = map(int, input().split())
        bad.add((x, y))

    frequency = defaultdict(int)
    visited = defaultdict(bool)
    mp = defaultdict(set)

    for x in A:
        frequency[x] += 1

    for i in range(N):
        if not visited[A[i]]:
            mp[frequency[A[i]]].add(A[i])
            visited[A[i]] = True

    ST = set()
    for fx in mp:
        ST.add(fx)

    ans = -sys.maxsize
    for fx in sorted(ST, reverse=True):
        for x in sorted(mp[fx], reverse=True):
            for fy in sorted(ST, reverse=True):
                if fy > fx:
                    break
                flag = False
                for y in sorted(mp[fy], reverse=True):
                    if x == y or (x, y) in bad or (y, x) in bad:
                        continue
                    ans = max(ans, (fx + fy) * (x + y))
                    flag = True
                    break            
    print(ans)