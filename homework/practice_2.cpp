/**
 * 2、输入长度为 n 的整形数组，分别使用选择和冒泡排序进行排序。
 **/
#include <bits/stdc++.h>

using namespace std;

// 选择排序
void selection_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(arr[i], arr[min]);
    }
}

// 冒泡排序
void bubble_sort(int *arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
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
    selection_sort(a, n);
    bubble_sort(b, n);
    cout << "This is the answer from selection sort: \n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl << "This is the answer from bubble sort: \n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    delete[] a;
    delete[] b;
    return 0;
}