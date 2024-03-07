MOD = 100000000 + 7

def mypow(a, b):
    res = 1
    while b > 0:
        if b & 1:
            res = (res * a) % MOD
        a = (a * a) % MOD
        b >>= 1
    return res

def f(x, a, b):
    if x == 1:
        return 1
    ans = 0
    ans += mypow(a, x - 1) % MOD
    ans += (b % MOD) * ((mypow(a, x - 1) - 1) * pow(a - 1, MOD - 2, MOD)) % MOD
    return ans % MOD

if __name__ == "__main__":
    x, a, b = map(int, input().split())
    print(f(x, a, b))
