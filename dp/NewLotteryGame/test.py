def work(D):

    def dfs(i, x, L):
        if i == L:
            return 1 if x < D and abs(str(x).count('4') - str(x).count('7')) <= 1 else 0
        r = 0
        for d in [4, 7]:
            r += dfs(i + 1, x * 10 + d, L)
        return r

    r = 0
    for i in range(len(str(D))):
        r += dfs(0, 0, i + 1)
    return r


if __name__ == '__main__':
    D = int(raw_input())
    print work(D)
