#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {

 for (int j = 0; j < size - 1; ++j) {
   for (int i = 0; i < size - j - 1; ++i) {

     if (arr[i] > arr[i + 1]) {

       int temp = arr[i];
       arr[i] = arr[i + 1];
       arr[i + 1] = temp;
     }
   }
 }
}

void optimizedbubbleSort(int a[]) {
 int rounds = 0;
 for (int i = 0; i < 5; i++) {
   rounds++;
   int flag = false;
   for (int j = 0; j < (5 - i - 1); j++) {
     if (a[j] > a[j + 1]) {
       flag = true;
       int temp = a[j];
       a[j] = a[j + 1];
       a[j + 1] = temp;
     }
   }
   if (flag == false) {
     break;
   }
 }
 cout << "No of rounds : " << rounds << endl;
}

void display(int arr[], int size) {
 for (int i = 0; i < size; ++i) {
   cout << "  " << arr[i];
 }
 cout << "\n";
}

int main() {
     int arr[] = {2, 45, 0, 11, 9};
 int size = sizeof(arr) / sizeof(arr[0]);
 bubbleSort(arr, size);
 cout << "Sorted array :\n";
 display(arr, size);
 int myarray[5];
 cout << "Enter 5 integers in any order: " << endl;
 for (int i = 0; i < 5; i++) {
   cin >> myarray[i];
 }
 cout << "Before Sorting" << endl;
 for (int i = 0; i < 5; i++) {
   cout << myarray[i] << " ";
 }
 cout << endl;
 optimizedbubbleSort(myarray);

 cout << "After Sorting" << endl;
 for (int i = 0; i < 5; i++) {
   cout << myarray[i] << " ";
 }

 return 0;
}
