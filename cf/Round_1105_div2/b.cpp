// Problem - https://codeforces.com/contest/2240/problem/B
#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

long long func(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = res * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;
        long long rows = n - r + 1;
        long long cols = m - c + 1;
        long long empty = n * m - rows * cols;
        cout << func(2, empty) << '\n';
    }
    return 0;
}
