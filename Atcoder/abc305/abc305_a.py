a = int(input())
k = a // 5
l = k * 5
r = (k + 1) * 5
if a - l < r - a: print(l)
else: print(r)