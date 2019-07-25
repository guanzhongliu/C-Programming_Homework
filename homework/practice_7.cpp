/**
 * 7、输入一个正整数，判断这个数是否为素数（质数）。
**/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

// Miller_Rabin 算法进行素数测定
// 可以快速判断一个 < 2^63 的数是不是素数
// 复杂度 S * log n^2

const int S = 8; // 随机算法判定次数一般8-10次即可

// 计算ret = (a * b) % c
ll mult_mod(ll a, ll b, ll c) {
    a %= c;
    b %= c;
    ll ret = 0, temp = a;
    while (b) {
        if (b & 1) {
            ret += temp;
            if (ret > c)
                ret -= c;   //直接取模慢很多
        }
        temp << 1;
        if (temp > c)
            temp -= c;
        b >>= 1;
    }
    return ret;
}

// 计算 ret = (a^n)%mod
ll pow_mod(ll a, ll n, ll mod) {
    ll ret = 1;
    ll temp = a % mod;
    while (n) {
        if (n & 1)
            ret = mult_mod(ret, temp, mod);
        temp = mult_mod(temp, temp, mod);
        n >>= 1;
    }
    return ret;
}

// 通过a^(n-1)=1(mod n)来判断n是不是素数（费马小定理）
// n - 1 = x * 2^t 中间使用二次判断
// 是合数返回true，不一定是合数返回false
bool check(ll a, ll n, ll x, ll t) {
    ll ret = pow_mod(a, x, n);
    ll last = ret;
    for (int i = 1; i <= t; ++i) {
        ret = mult_mod(ret, ret, n);
        if (ret == 1 && last != 1 && last != n - 1)
            return true;
        last = ret;
    }
    if (ret != 1)
        return true;
    else
        return false;
}

// Miller_Rabin算法
// 是素数返回true（可能是伪素数）概率 4^(-S)
// 不是素数返回 false
bool Miller_Rabin(ll n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if ((n & 1) == 0)
        return false;
    ll x = n - 1;
    ll t = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        t++;
    }
    srand(time(NULL));  //随机试数

    for (int i = 0; i < S; i++) {
        ll a = rand() % (n - 1) + 1;
        if (check(a, n, x, t))
            return false;
    }
    return true;
}

int main() {
    ll n;
    cout << "Please input a number and I'll tell you if it's a prime number or not: " << endl;
    cout << "Warning! If it's larger than 2 ^ 63, it may cause error." << endl;
    cin >> n;
    bool flag = Miller_Rabin(n);
    if (flag)
        cout << "Yes! " << n << " is a prime number." << endl;
    else
        cout << "No, " << n << " is not a prime number." << endl;
    return 0;
}
