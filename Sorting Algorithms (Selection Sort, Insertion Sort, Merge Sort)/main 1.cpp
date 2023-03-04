#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int i = i + 1; i < size; i++) {

            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(array[min_idx], array[i]);
    }
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void merge(int arr[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {

    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int *getRandomArray(int size) {

    int *arr = new int[size];
    for (int i = 0; i < size; ++i)

        arr[i] = rand() % 1000;
    return arr;
}

int main() {

    fstream infile;
    infile.open("Input-Assignment1-Problem-1.txt", ios_base:: in );

    int n;
    infile >> n;
    int sizes[n];
    for (int i = 0; i < n; i++){
      infile >> sizes[i];
    }

    fstream outfile;
    outfile.open("182014015-Output-Assignment-1-Problem-1.txt", ios_base:: out);

    for (int i = 0; i < n; i++) {
        outfile << "Test Case #" << (i + 1) << "\n";
        outfile << "Size " << sizes[i] << "\n";

        long t1 = clock();
        int *arr = getRandomArray(sizes[i]);
        selectionSort(arr, sizes[i]);
        long t2 = clock();
        long t_elapsed = t2 - t1;
        outfile << "Technique: Selection, Time: " << t_elapsed << "ms\n";

        t1 = clock();
        arr = getRandomArray(sizes[i]);
        insertionSort(arr, sizes[i]);
        t2 = clock();
        t_elapsed = t2 - t1;
        outfile << "Technique: Insertion, Time: " << t_elapsed << "ms\n";

        t1 = clock();
        arr = getRandomArray(sizes[i]);
        mergeSort(arr, 0, sizes[i]);
        t2 = clock();
        t_elapsed = t2 - t1;
        outfile << "Technique: Merge,\t Time: " << t_elapsed << "ms\n";
    }
    infile.close();
    outfile.close();

    return 0;
}
