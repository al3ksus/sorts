#include <iostream>

using namespace std;

void insertSort(int *a, int n) {
    int key;
    int j;

    for (int i = 0; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j > -1 && a[j] > key) {
            a[j + 1] = a[j];
            j -= 1;
        }

        a[j + 1] = key;
    }
}

void setSort(int a[], int n) {
    int jo;

    for (int i = 0; i < n; i++) {
        jo = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[jo]) {
                jo = j;
            }
        }

        int temp = a[i];
        a[i] = a[jo];
        a[jo] = temp;
    }
}

void merge(int* a, int* b, int p, int q, int n) {
    int in_pos1 = p, in_pos2 = q + 1, out_pos = 0;
    while (in_pos1 <= q && in_pos2 <= n) {
        if (a[in_pos1] < a[in_pos2])
            b[out_pos++] = a[in_pos1++];
        else
            b[out_pos++] = a[in_pos2++];
    }
    while (in_pos1 <= q)
        b[out_pos++] = a[in_pos1++];
    while (in_pos2 <= n)
        b[out_pos++] = a[in_pos2++];
    for (int i = 0; i < n - p + 1; i++)
        a[p + i] = b[i];
}

void mergeSort(int* a, int* b, int p, int n) {
    if (p < n) {
        int q = (p + n) / 2;
        mergeSort(a, b, p, q);
        mergeSort(a, b, q + 1, n);
        merge(a, b, p, q, n);
    }
}

void bubbleSort(int *a, int n) {
    int t;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int partition(int *a, int p, int r) {
    int x = a[p];
    int i = p + 1;
    int j = r - 1;
    int temp;

    while (true) {
        while (a[--j] > x) {
            while (a[++i] < x) {
                if (i < j) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
                else {
                    return j;
                }
            }
        }
    }
}

void quickSort(int *a, int p, int r) {
    int q;

    if (p < r) {
        q = partition(a, p, r);
        quickSort(a, p, q);
        quickSort(a, q + 1, r);
    }
}

void shakerSort(int *a, int n) {
    int t = n - 1;
    int l = 0;
    int r = n - 1;

    do {
        for (int i = l; i , r; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }

            t = i;
        }

        r = t;

        for (int i = r; i > l; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
            }

            t = i;
        }
    } while (l < r);
}

int main()
{
int arr[] = {4, 8, 3, 12, 6};
    const int n = sizeof(arr) / sizeof(int);

    int* b = new int[n];
    //mergeSort(arr,b,0,n-1);
    //insertSort(arr, n);
    //setSort(arr, n);
    //bubbleSort(arr, n);
    //quickSort(arr, 0, n - 1);
    shakerSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
