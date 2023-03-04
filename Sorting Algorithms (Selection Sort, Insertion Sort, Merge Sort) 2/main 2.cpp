#include <iostream>
#include <fstream>

using namespace std;

bool comp(int first,int second,int ascending){
    if(ascending)
        return first > second;

    return first < second;
}

void selectionSort(int array[], int size,int ascending) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {

            if (comp(array[j] , array[min_idx],ascending)){
                min_idx = j;
            }
        }

        swap(array[min_idx], array[i]);
    }
}
void insertionSort(int array[], int size,int ascending) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        while (comp(key , array[j],ascending) && j >= 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void merge(int arr[], int p, int q, int r,int ascending) {

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
        if (comp(L[i] , M[j],ascending)) {
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

void mergeSort(int arr[], int l, int r,int ascending) {

    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m,ascending);
        mergeSort(arr, m + 1, r,ascending);

        merge(arr, l, m, r,ascending);
    }
}
int main() {

    fstream infile;
    infile.open("Input-Assignment1-Problem-2.txt", ios_base:: in);

    int n, ascending, algo, size, *arr;
    infile >> n;

    fstream outfile;
    outfile.open("182014015-Output-Assignnment1-Problem2.txt", ios_base:: out);

    for (int i = 0; i < n; i++) {
        infile>>size>>ascending>>algo;
        outfile << "Test Case #" << (i + 1) << "\n";
        outfile << "Size " << size<<" ";
        arr = new int[size];
        for (int i = 0; i < size; i++)
            infile>>arr[i];

        outfile<<"Order: "<<((ascending == 0)?"Ascending; ":"Descending; ");
        outfile<<"Technique: ";
        switch(algo){

            case 0:
                    outfile<<"Selection\n";
                    selectionSort(arr,size,ascending);
                    break;
            case 1:
                    outfile<<"Insertion\n";
                    insertionSort(arr,size,ascending);
                    break;
            case 2:
                    outfile<<"Merge\n";
                    mergeSort(arr,0,size,ascending);
                    break;
        }
        for (int i = 0; i < size; i++)
        {
            outfile<<arr[i]<<" ";
        }
        outfile<<"\n";
    }
    infile.close();
    outfile.close();

    return 0;
}
