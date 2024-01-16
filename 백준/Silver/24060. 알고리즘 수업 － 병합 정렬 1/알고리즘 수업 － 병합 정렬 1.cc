#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_value;  // 찾아야 하는 값
int count_value;  // 찾은 횟수

void merge(vector<int>& A, int p, int q, int r, int k) {
    int i = p, j = q + 1, t = 0;
    vector<int> tmp(r - p + 1);

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        }
        else {
            tmp[t++] = A[j++];
        }
    }

    while (i <= q) {
        tmp[t++] = A[i++];
    }

    while (j <= r) {
        tmp[t++] = A[j++];
    }

    i = p; t = 0;

    while (i <= r) {
        A[i++] = tmp[t++];
        if (++count_value == k) {
            find_value = A[i - 1];
        }
    }
}

void merge_sort(vector<int>& A, int p, int r, int k) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q, k);
        merge_sort(A, q + 1, r, k);
        merge(A, p, q, r, k);
    }
}

int main(void) {
    int size, k;
    cin >> size >> k;

    vector<int> v;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }

    merge_sort(v, 0, v.size() - 1, k);

    if (count_value < k) {
        cout << -1 << endl;
        return 0;
    }

    cout << find_value << endl;

    return 0;
}