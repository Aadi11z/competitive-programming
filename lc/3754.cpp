#include<bits/stdc++.h>
using namespace std;

long long sumAndMultiply1(int n) {
    int sum = 0;
    long long concat_num = 0;
    long long rev = 0;

    while(n != 0) {
        int digit = n % 10;
        if (digit != 0) {
            concat_num = concat_num * 10 + digit;
            sum += digit;
        }
        n /= 10;
    }

    while(concat_num != 0) {
        int digit = concat_num % 10;
        rev = rev * 10 + digit;
        concat_num /= 10;
    }
    return rev * sum;
}

long long sumAndMultiply2(int n) {
    long long divisor = 1;
    long long concat_num = 0;
    int sum = 0;
    while (n / divisor >= 10) {
        divisor *= 10;
    }
    while (divisor > 0) {
        int digit = (n / divisor) % 10;
        if (digit != 0) {
            concat_num = concat_num * 10 + digit;
            sum += digit;
        }
        divisor /=10;
    }
    return concat_num * sum;
}

long long sumAndMultiply3(int n) {
    string s = to_string(n);
    long long x = 0;
    int sum = 0;

    for (char c : s) {
        if (c != '0') {
            int digit = c - '0';
            x = x * 10 + digit;
            sum += digit;
        }
    }
    return x * sum;
}

template <typename Func>
void benchmark(const string& name, Func func) {
    const int iterations = 1000000;
    volatile long long sink = 0;
    vector<int> nums = {
      0, 1, 1000, 10203004, 999999999, 1000000000, 908070605, 123456789, 100200300, 909090909
    };

    auto start = chrono::steady_clock::now();
    for (int i = 0; i < iterations; i++) {
        sink += func(nums[i % nums.size()]);
    }
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << name << ": " << duration << " microseconds\n";
}

int main() {
    int n1 = 10203004;
    long long ans1 = sumAndMultiply1(n1);

    int n2 = 10203004;
    long long ans2 = sumAndMultiply2(n2);

    int n3 = 10203004;
    long long ans3 = sumAndMultiply3(n3);

    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
    
    benchmark("1: ", sumAndMultiply1);
    benchmark("2: ", sumAndMultiply2);
    benchmark("3: ", sumAndMultiply3);

    return 0;
}