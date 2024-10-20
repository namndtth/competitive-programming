s = input()
hello = 'hello'

ans = True
for ch in hello:
    if (pos := s.find(ch)) == -1:
        ans = False
        break
    s = s[pos + 1:]

print('YES' if ans else 'NO')
