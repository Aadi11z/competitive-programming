// Problem - https://codeforces.com/contest/2240/problem/A
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long ans = 0;
        for (long long i = 1; i <= n; i <<= 1) {
            long long j = min(k, n / i);
            ans += j;
            n -= j * i;
        }
        cout << ans << '\n';
    }
    return 0;
}
