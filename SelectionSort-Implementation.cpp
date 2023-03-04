#include <iostream>
using namespace std; 
void swap(int *x, int *y)

{

    int temp = *x;

    *x = *y;

    *y = temp;

}
void selectionSort(int arr[], int n)
{

    int min_idx;

    for (int i = 0; i < n-1; i++)

    {

        min_idx = i;

        for (int j = i+1; j < n; j++)

        if (arr[j] < arr[min_idx])

            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()

{

    int n;

    cout<<"Enter the number of elements: ";

    cin>>n;

    int A[n];

    cout<<"Enter the elements: ";

    for(int i=0;i<n;i++){

        cin>>A[i];

    }

    selectionSort(A,n);

    cout<<"Sorted Array: "<<endl;

    for(int i=0;i<n;i++){

        cout<<A[i]<<" ";

    }

    return 0;

}