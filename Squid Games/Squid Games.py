n = int(input())
i = 0
a = [None]*n
for num in list(map(int, input().split())):
    a[i] = num
    i += 1
i = 0
s = [None]*n
for num in list(input()):
    s[i] = num
    i += 1

tmp = []
v = []
for i in range(n):
    tmp.append(a[i])
    if s[i] == '0':
        tmp.sort()
        v.append(tmp)
        tmp = []

b = []
for i in range(len(v)):
    for j in range(len(v[i])):
        b.append(v[i][j])

if b == sorted(b):
    print("YES")
else:
    print("NO")
