#include <iostream>
#include <fstream>

using namespace std;

// Complete this function.
// Use additional data structures/functions however you see fit
double fractionalKnapsack(int weights[], int values[], int n, int maxCapacity){



    return 0;
}



/*
DO NOT EDIT CODE BELOW THIS LINE
*/
int main() {
    ifstream fin("Input-FractionalKnapsack.txt");
    ofstream fout("Output-FractionalKnapsack.txt");

    int T;
    fin >> T;
    for(int t=1; t<=T; t++){
        int n;
        fin >> n;

        int maxCapacity;
        fin >> maxCapacity;

        int weights[n];
        for(int i=0; i<n; i++){
            fin >> weights[i];
        }

        int values[n];
        for(int i=0; i<n; i++){
            fin >> values[i];
        }

        double profitTotal = fractionalKnapsack(weights, values, n, maxCapacity);

        cout << "Test Case #" << t << ", Profit Total = " << profitTotal << endl;
    
        fout << "Test Case #" << t << ", Profit Total = " << profitTotal << endl;
    }



    fin.close();
}
