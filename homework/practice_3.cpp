#include <bits/stdc++.h>

using namespace std;

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


int main() {
    cout << "Please input an array and I'll sort it up for you:\nFirst, tell me it's length:" << endl;
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];        // 用于展示两种排序
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    quick_sort(a, 0, n);
    merge_sort(b, n);
    cout << "This is the answer from quick sort: \n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl << "This is the answer from merge sort: \n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    delete[] a;
    delete[] b;

    return 0;
}
