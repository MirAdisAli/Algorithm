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

void swap(int *x, int *y)
{
   int temp = *x;
*x = *y;
*y = temp;
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

       int minIdx = getMinIndex(arr, n, left);
       swap(&arr[left], &arr[minIdx]);
   }
}
int main(){
    long t1, t2;
   t1 = time(NULL);
   cout << "Input size and then array\n";

   ifstream fin("Input8Nov.txt");
   ofstream fout("Output.txt");

   int n,n1;
   fin >> n;
   for(int i=0;i<n;i++){
   fin>>n1;
   int arr[n1];
   for(int j=0; j<n1; j++){
       fin >> arr[j];
   }
    selectionSort(arr,n1);
    for(int i=0; i<n1; i++){
       fout << arr[i] << ", ";
   }
   fout << endl;
   fout << endl << "------------------" << endl;
   printArray(arr, n1);
   }
   t2 = time(NULL);
   cout << "Elapsed Time " << (t2 - t1) << "s" << endl;

   fin.close();
   fout.close();
}
