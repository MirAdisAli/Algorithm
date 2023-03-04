#include <iostream>
#include <fstream>

using namespace std;

// Edit this function. Use additional functions/data structures as needed.
// DO NOT change arguments of the function.
int selectMaxActivities(int start_times[], int end_times[], int n){


    return 0;
}


// DO NOT EDIT CODE BELOW THIS LINE.
int main() {
    ifstream fin("Input-ActivitySelection.txt");
    ofstream fout("Output-ActivitySelection.txt");

    int T; // num of test cases
    fin >> T;

    for(int t=1; t<=T; t++){
        int n;
        fin >> n;
        
        int start_times[n];
        for(int i=0; i<n; i++){
            fin >> start_times[i];
        }

        int end_times[n];
        for(int i=0; i<n; i++){
            fin >> end_times[i];
        }

        int ans = selectMaxActivities(start_times, end_times, n);
        cout << "Test Case #" << t << ", # Max Activities = " << ans << endl;

        fout << "Test Case #" << t << ", # Max Activities = " << ans << endl;
    }

    fin.close();
} 