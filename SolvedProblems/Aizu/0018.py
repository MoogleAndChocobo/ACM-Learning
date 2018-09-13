a, b, c, d, e = (input().strip().split())
s = [(int)(a), (int)(b), (int)(c), (int)(d), (int)(e)]
s.sort()
print(s[4], s[3], s[2], s[1], s[0], end = '\n')