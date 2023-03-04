#include <iostream>
#include <map>
#include <iterator>

using namespace std;

// map<int, int> cache; // you can use other data structures as well for caching.

int recursiveTopDown(int n){
    // base cases

    // Check if already exists in cache/result array -> simply return

    // recursion

    // insert into cache/result array before returning the ans

	return -1; // return answer here, instead of -1
}


int bottomUp(int n){
	return -1; // return answer here, instead of -1
}

int bottomUpOptimizedSpace(int n){
    return -1; // return answer here, instead of -1
}


//////////////////////// MAIN FUNCTION FOR TESTING \\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int main() {
    int n = 20;
    int ans;

	ans = recursiveTopDown(n);
    cout << "recursiveTopDown, n = " << n << ", ans = " << ans << endl;

	ans = bottomUp(n);
    cout << "bottomUp, n = " << n << ", ans = " << ans << endl;
	
	ans = bottomUpOptimizedSpace(n);
    cout << "bottomUpOptimizedSpace, n = " << n << ", ans = " << ans << endl;
} 