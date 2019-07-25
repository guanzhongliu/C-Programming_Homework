#include <bits/stdc++.h>

using namespace std;

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

int main() {
    cout<< "Please input an increasing array and I'll show you the magic of binary search:\nFirst, tell me it's length:"
        << endl;
    int n, t, res;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);  //防止输入的不是升序
    cout << "Please input a number and I'll locate it for you:" << endl;
    cin >> t;
    res = binary_search(a, 0, n, t);
    if (res == -1)
        cout << "Sorry, " << t << " is not in the array." << endl;
    else
        cout << "The location of " << t << " is " << res + 1 << "." << endl;

    return 0;
}