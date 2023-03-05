#include<iostream>

using namespace std;

void f1(int arr[], int n, int idx){
    // O(1), Constant work
    int el = arr[idx];
	if(el < 18){
		cout << "Can't vote" << endl;
	}else{
		cout << "Can vote" << endl;
	}
    
}

void do_something(int arr[], int n, int element){	
	// linear search => O(n)
	// for(int i=0; i<n; i++){
    //     if(arr[i] == element){
    //         cout << "Element found at idx: " << i << endl;
    //         break;
    //     }
    // }

    // Nested Loop  => O(n * T) => O(n * n) => O(n^2)
    // for(int i=0; i<n; i++){     // -> O(n)
        
    //     for(int j=0; j<n; j++){ // -> O(T) --> O(n)

    //     }
    
    // }

    // Selection Sort
    // O(n * T) -> O(n * n) = O(n ^ 2)
    for(int left=0; left<n; left++){    // O(n)
        // find the minimum from itself+1'th index
        // O(T) -> O(n)
        int idx_min = get_minimum_idx(arr, n, left+1);
        
        // swap
        swap(arr[left], arr[idx_min]); // -> O(1)
    }


}

int get_minimum_idx(int arr[], int n, int idx){
    int min_idx = idx;
    for(int i=idx; i<n; i++){   // O(n)
        if(arr[i] < arr[min_idx]){
            min_idx = i;
        }
    }
    return min_idx;
}



int main(){
	int n = 100000; // 100k
	int arr[n];
	do_something(arr, n);
	
	return 0;
}