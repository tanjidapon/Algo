#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define MAX 150000

#include <iostream>
using namespace std;


int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j) {

        while (arr[i] <= pivot && i < high) i++;

        while (arr[j] > pivot) j--;

        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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
    quickSort(numbers, 0, MAX - 1);
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


