a = [0, 3, 4, 8, 9, 14, 23]
s = input()

x = s[0]
y = s[2]

x = int(ord(x) - ord("A"))
y = int(ord(y) - ord("A"))
print(abs(a[x] - a[y]))