#include<iostream>
using namespace std;

void merger(int arr[], int l, int m, int h){
    int i,j,k;
    int t[h-l+1];
    i=l;
    k=0;
    j=m+1;
    while(i<=m && j<=h){
        if(arr[i]<arr[j]){
                t[k]=arr[i];
                k++;
                i++;
        }
        else{
            t[k]= arr[j];
            k++;
            j++;
        }
    }
    while(i<=m){
        t[k]=arr[i];
        k++;
        i++;
    }
    while(j<=h){
        t[k]=arr[j];
        k++;
        j++;
    }
    for(i=l; i<=h;i++){
        arr[i]= t[i-l];
    }
}

void mergest(int arr[], int l, int r){
    if(l<r){
        int m= (l+r)/2;
        mergest(arr,l,m);
        mergest(arr, m+1, r);
        merger(arr,l,m,r);
    }
}

void print(int arr[],int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array element: ";
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    cout<<"Array element before sorting: ";
    print(arr,n);
    mergest(arr,0,n-1);
    cout<<"\nArray sorted: ";
    print(arr,n);
    return 0;
}
