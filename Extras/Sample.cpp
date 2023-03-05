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
    int a = 1;
    switch(el){
        case 1:
            break;
        case 2:
            break;
    }
}

void do_something(int arr[], int n){
	// int a = 1  => O(1)
	
	// O(n * T_f1) => O(n)
	for(int i=0; i<n; i++){
		// int el = arr[i];
		f1(arr, n, i); // O(T_f1), 
            // T_f1 -> O(1)
	}
	
}



int main(){
	int n = 100000; // 100k
	int arr[n];
	do_something(arr, n);
	
	return 0;
}

