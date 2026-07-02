// Problem - https://codeforces.com/contest/2238/problem/A
// arrays (a,b) with length 'n'
// cost: 1(reduction by 1), c(redordering)
// convert a -> b with minimum cost
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n), b(n);
        int sum_a = 0, sum_b = 0;

        for (auto& val : a) {
            cin >> val;
            sum_a += val;
        }

        for (auto& val : b) {
            cin >> val;
            sum_b += val;
        }

        // If we dont consider reordering for now, then that means that every element a[i] > b[i], and just needs to be reduced. Instead of calculating reduction at every stage, we can just take array sum and subtract it from array sum of target array.

        bool no_reorder = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) no_reorder = false;
        }
        if (no_reorder) {
            cout << (sum_a - sum_b) << endl;
            continue;
        }

        // In order to consider redordering, first we can sort both the arrays, to check if the smallest element in a is bigger than smallest element in b, if it is then fine otherwise reordering is pointless.

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool can_reorder = true; //assume reordering is meaningful
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                can_reorder = false;
                break;
            }
        }

        if (can_reorder) cout << sum_a - sum_b + c << endl;
        else cout << -1 << endl;
    }
    return 0;
}