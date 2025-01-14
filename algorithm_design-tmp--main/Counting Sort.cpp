#include<iostream>
using namespace std;

void Counting_sort(int a[], int b[], int k, int n) {
    int c[k] = {0};

    for(int j = 0; j < n; j++) {
        c[a[j]]++;
    }

    for(int i = k - 2; i >= 0; i--) {
        c[i] += c[i + 1];
    }

    for(int j = n - 1; j >= 0; j--) {
        b[c[a[j]] - 1] = a[j];
        c[a[j]]--;
    }

    cout << "The sorted array is: ";
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    int a[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Your array is here: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int k;
    cout << "Enter the range (maximum element value + 1): ";
    cin >> k;

    int b[n];
    Counting_sort(a, b, k, n);

    return 0;
}

