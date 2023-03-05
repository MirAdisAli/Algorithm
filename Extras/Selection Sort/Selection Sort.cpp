#include <iostream>
#include <ctime>
#include <fstream>

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
void swap(int *x, int *y)
{
	int temp   = *x;
    *x   = *y;
    *y   =  temp;
}
int getMinIndex(int arr[], int n, int startIdx){
	int minIdx = startIdx;
	for(int i=startIdx; i<n; i++){
		if(arr[i] < arr[minIdx]){
			minIdx = i;
		}
	}
	return minIdx;
}
void selectionSort(int arr[], int n){
	for(int left=0; left<n-1; left++){
		// Get minimium Index, including self to the right side.
		int minIdx = getMinIndex(arr, n, left);
		// Swap the elements.
		swap(&arr[left], &arr[minIdx]);
	}
}
/*
	Writing code ends here.
*/


int main(){
	long t1, t2;
	t1 = time(NULL);
	// do some work here.
	t2 = time(NULL);
	cout << "Elapsed Time " << (t2 - t1) << "s" << endl;
	
	cout << "Input size and then array\n";

	ifstream fin("Input8Nov.txt");
	ofstream fout("Output.txt");

	int n; // size
	fin >> n;
	int arr[n]; // array elements.
	for(int i=0; i<n; i++){
		fin >> arr[i];
	}

	cout << endl << "------------------" << endl;
	printArray(arr, n);

	for(int i=0; i<n; i++){
		fout << arr[i] << ", ";
	}
	fout << endl;

	fin.close();
	fout.close();
}