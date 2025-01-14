#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define MAX 500000

void InsertionSort(int numbers[], int n) {
    int i, key;
    for (int j = 1; j < n; j++) {
        key = numbers[j];
        i = j - 1;
        while (i >= 0 && numbers[i] > key) {
            numbers[i + 1] = numbers[i];
            i = i - 1;
        }
        numbers[i + 1] = key;
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


    cout << endl;

    clock_t start = clock();
    InsertionSort(numbers, MAX);
    clock_t end = clock();

    double runtime = double(end - start) / CLOCKS_PER_SEC;

    ofstream sortedFile("sorted_numbers.txt");
    for (int i = 0; i < MAX; i++) {
        sortedFile << numbers[i] << " ";
    }
    cout << endl;
    sortedFile.close();

    cout << "Runtime: " << runtime << " seconds" << endl;

    return 0;
}

