#include <iostream>
#include <unordered_map>
using namespace std;

#define BASE_CASES 4

unordered_map<int, int>cache;
int base[BASE_CASES];

int recursiveTopDown(int n) {
        if (n == 0 || n == 1 || n == 2 || n == 3)
                return base[n];

        if (cache.find(n) != cache.end())
                return cache[n];

        if (cache.find(n - 1) == cache.end())
                cache[n - 1] = recursiveTopDown(n - 1);

        if (cache.find(n - 2) == cache.end())
                cache[n - 2] = recursiveTopDown(n - 2);

        if (cache.find(n - 3) == cache.end())
                cache[n - 3] = recursiveTopDown(n - 3);

        cache[n] = cache[n - 1] + 8 * cache[n - 2] + cache[n - 3];

        return cache[n];
}

int bottomUp(int n) {
        int arr[n + 1][n + 1];

        for (int i=0; i<BASE_CASES; i++)
                for (int j=0; j<BASE_CASES; j++)
                        arr[i][j] = base[i];

        for (int i=4; i<=n; i++)
                for (int j=4; j<=n; j++)
                        arr[i][j] = arr[i - 1][j - 1] + 8 * arr[i - 2][j - 2] + arr[i - 3][j - 3];

        return arr[n][n];

}

int bottomUpOptimizedSpace(int n) {
        int arr[n + 1];

        for (int i=0; i<BASE_CASES; i++)
                arr[i] = base[i];

        for (int i=4; i<=n; i++)
                arr[i] = arr[i - 1] + 8 * arr[i - 2] + arr[i - 3];

        return arr[n];

}

int main() {

        string roll;
        cout << "Enter the last " << BASE_CASES << " digits of your roll no: ";
        cin >> roll;

        int i = 0;
        for (char c: roll)
                base[i++] = c - '0';

        int n;
        cout << "Enter value of n: ";
        cin >> n;

        cout << recursiveTopDown(n) << " " << bottomUp(n) << " " << bottomUpOptimizedSpace(n) << "\n";

        return 0;
}


//4. a) Both O(n)

//   b) Both O(n2)

//   c) Both O(n)

