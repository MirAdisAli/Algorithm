#include<iostream>

using namespace std;

void printArray(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << ", ";
	}
	cout << endl;
}


/*
	Writing code begins here.
*/

// For Selection Sort
void selectionSort(int arr[], int n){

}
/*
	Writing code ends here.
*/




int main(){
	int arr[] = {5, 4, 1, 2, 3, 22, 10, 31, 25, 26};
	int n = sizeof(arr)/sizeof(int); // number of elements.

	cout << "n = " << n << endl;

	cout << "BEFORE SORTING" << endl;
	printArray(arr, n);

	selectionSort(arr, n);
	// insertionSort(arr, n);
	// bubbleSort(arr, n);
	
	cout << "AFTER SORTING" << endl;
	printArray(arr, n);

}