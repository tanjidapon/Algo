#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define MAX 450000

void merge(int numbers[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = numbers[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = numbers[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            numbers[k] = L[i];
            i++;
        } else {
            numbers[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        numbers[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        numbers[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int numbers[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(numbers, left, mid);
        mergeSort(numbers, mid + 1, right);

        merge(numbers, left, mid, right);
    }
}

int main() {
    int numbers[MAX];

    ofstream outFile("unsorted_numbers.txt");
    srand(time(0));
    for (int i = 0; i < MAX; i++) {
        int num = rand();
        outFile << num << " ";
    }
    outFile.close();

    ifstream inFile("unsorted_numbers.txt");
    for (int i = 0; i < MAX; i++) {
        inFile >> numbers[i];
    }
    inFile.close();

    clock_t start = clock();
    mergeSort(numbers, 0, MAX - 1);
    clock_t end = clock();
    double runtime = double(end - start) / CLOCKS_PER_SEC;

    ofstream sortedFile("sorted_numbers.txt");
    for (int i = 0; i < MAX; i++) {
        sortedFile << numbers[i] << " ";
    }
    sortedFile.close();

    cout << "Runtime: " << runtime << " seconds" << endl;

    return 0;
}

