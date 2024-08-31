def get_center_plus_sign(picture, h, w):
    pattern = ['.*.', '***', '.*.']
    for i in range(h - 2):
        for j in range(w - 2):
            area = [row[j:j + 3] for row in picture[i: i + 3]]
            if area == pattern:
                return i + 1, j + 1
    return None


def solve():
    h, w = map(int, input().split())
    picture = [input() for _ in range(h)]

    center = get_center_plus_sign(picture, h, w)

    if center is None:
        return 'NO'

    coord_plus_sign = set(center)

    i, j = center
    while i >= 0 and picture[i][j] == '*':
        if (i, j) not in coord_plus_sign:
            coord_plus_sign.add((i, j))
        i -= 1

    i, j = center
    while i < h and picture[i][j] == '*':
        if (i, j) not in coord_plus_sign:
            coord_plus_sign.add((i, j))
        i += 1

    i, j = center
    while j >= 0 and picture[i][j] == '*':
        if (i, j) not in coord_plus_sign:
            coord_plus_sign.add((i, j))
        j -= 1

    i, j = center
    while j < w and picture[i][j] == '*':
        if (i, j) not in coord_plus_sign:
            coord_plus_sign.add((i, j))
        j += 1

    for i1 in range(h):
        for j1 in range(w):
            if picture[i1][j1] == '*' and (i1, j1) not in coord_plus_sign:
                return 'NO'

    return 'YES'


if __name__ == '__main__':
    print(solve())
