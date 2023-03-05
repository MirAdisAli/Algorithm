#include <iostream>
#include <map>
#include <iterator>

using namespace std;

map<int, int> cache;
int recursion(int n){
    // if(n == 0) return 0;
    // if(n == 1) return 1;

    // base case
    if(n <= 1) return n;

    // check the cache, if ans exists, return
    auto itr = cache.find(n);
    if(itr != cache.end()){ // 'key' exists.
        return itr->second; // ->second is the value
    }

    // recrusion
    int ans = recursion(n - 1) + recursion(n - 2);

    // enter into cache
    cache.insert(pair<int, int>(n, ans));

    return ans;
}


map<int, int> myMap;
int recursiveTopDownWithMap(int n){
    // base cases
    if(n == 0) return 0;
    if(n == 1) return 1;
    // if(n <= 1) return n;
    // Check if already exists in cache/result array -> simply return
    auto itr = myMap.find(n);
    if(itr != myMap.end()){ // exists.
        return itr->second; // return the value for this 'key'
    }

    // recursion
    int ans =   recursiveTopDownWithMap(n - 1) + 
                recursiveTopDownWithMap(n - 2);


    // insert into cache/result array before returning the ans
    myMap.insert(pair<int, int>(n, ans));

    return ans;
}


int recursiveTopDownWithArray(int n, int dp[]){
    return -1;
}

int topDownWithArray(int n){
    int dp[n + 1];
    for(int i=0; i<=n; i++){
        dp[i] = -1; // -1 -> UNASSIGNED
    }

    return recursiveTopDownWithArray(n, dp);
}

int bottomUp(int n){
    int dp[n + 1];
    // base cases.
    dp[0] = 0;
    dp[1] = 1;
    // iterate until 'n'
    // recursion was: recursion(n - 1) + recursion(n - 2);
    for(int i=2; i<=n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int bottomUpOptimizedSpace(int n){
    int onePrev = 1; // dp[1]
    int twoPrev = 0; // dp[0]
    int ans = -1; // dp[i]

    for(int i=2; i<=n; i++){
        // dp[2] = dp[1] + dp[0]
        ans = onePrev + twoPrev; 
        
        // dp[0] <- dp[1]
        twoPrev = onePrev;
        // dp[1] <- dp[2]
        onePrev = ans;
    }

    return ans;
}

//////////////////////////////////////////////
// Edit this function
int fib(int n){
    return bottomUpOptimizedSpace(n);
    // return bottomUp(n);
    // return recursion(n);
    // return recursiveTopDownWithMap(n);
    // return topDownWithArray(n);
}

int main() {
    int n = 30;
    int ans = fib(n);
    cout << "n = " << n << ", ans = " << ans << endl;
} 