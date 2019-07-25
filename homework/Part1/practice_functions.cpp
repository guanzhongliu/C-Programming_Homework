//
// Created by Septieme on 2019/7/23.
//
#include <bits/stdc++.h>

#define ll long long

/**
 * 1、输入一个长度小于100的字符串，判断其是否为回文串。
 **/
bool judge_reversal(std::string a) {
    for (int i = 0; i < (a.length() - 1) / 2; i++) {
        if (a[i] != a[a.length() - 1 - i]) {
            std::cout << a << " is not a palindrome." << std::endl;
            return false;
        }
    }
    std::cout << a << " is a palindrome." << std::endl;
    return true;
}

/**
 * 2、输入长度为 n 的整形数组，分别使用选择和冒泡排序进行排序。
 **/
// 选择排序
void selection_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        std::swap(arr[i], arr[min]);
    }
}

// 冒泡排序
void bubble_sort(int *arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

/**
 * 3、输入长度为n的整形数组，使用快速排序或者归并排序进行排序。
**/
// 快速排序
void quick_sort(int *arr, int l, int r) {
    if (l < r) {
        int i = l, j = r, x = arr[l];
        while (i < j) {
            while (i < j && arr[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j)
                arr[i++] = arr[j];

            while (i < j && arr[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                arr[j--] = arr[i];
        }
        arr[i] = x;
        quick_sort(arr, l, i - 1); // 递归调用
        quick_sort(arr, i + 1, r);
    }
}


// 归并排序
void merge(int *A, int *L, int leftCount, int *R, int rightCount) {
    int i = 0, j = 0, k = 0;

    while (i < leftCount && j < rightCount) {
        if (L[i] < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while (i < leftCount) A[k++] = L[i++];
    while (j < rightCount) A[k++] = R[j++];
}   // 将排序完的序列进行归并

void merge_sort(int *A, int n) {
    int mid;
    if (n < 2)
        return;
    mid = n / 2;
    int *L = new int[mid];
    int *R = new int[n - mid];

    for (int i = 0; i < mid; i++)
        L[i] = A[i]; // 创建左侧子序列
    for (int i = mid; i < n; i++)
        R[i - mid] = A[i]; // 创建右侧子序列

    merge_sort(L, mid);  // 对左侧子序列排序
    merge_sort(R, n - mid);  // 对右侧子序列排序
    merge(A, L, mid, R, n - mid);
    delete[] R;
    delete[] L;
}

/**
 * 5、实现二进制转10进制的转换器（输入二进制数，输出十进制数）
**/
ll get_length(ll a) {
    ll length = 0;
    while (a) {
        a /= 10;
        length++;
    }
    return length;
}

ll get_value(ll a, ll i) {
    ll value;
    value = a % (ll) pow(10, i) / pow(10, i - 1);
    return value;
}

ll toDec(ll a) {
    ll val = 0;
    for (int i = 1; i <= get_length(a); i++) {
        val += get_value(a, i) * (ll) pow(2, i - 1);
    }
    return val;
}

/**
 * 7、输入一个正整数，判断这个数是否为素数（质数）。
**/
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
    srand(time(NULL));

    for (int i = 0; i < S; i++) {
        ll a = rand() % (n - 1) + 1;
        if (check(a, n, x, t))
            return false;
    }
    return true;
}

/**
 * 10、对一个长度为n的升序数列，用二分法进行查询。
 **/
int binary_search(int *array, int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (array[mid] > target)
        return binary_search(array, low, mid - 1, target);
    if (array[mid] < target)
        return binary_search(array, mid + 1, high, target);

    return mid;
}
