#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct item{
    int weight;
    int value;
};

bool com(item j,  item k)
{
    double r1 = (double)j.value / (double)j.weight;
    double r2 = (double)k.value / (double)k.weight;
    return r1 > r2;
}

double fractionalKnapsack(int weights[], int values[], int n, int maxCapacity){
    
    item arr[n];
    for(int i = 0; i<n ; i++){    
        arr[i].value = values[i];
        arr[i].weight = weights[i];            
    }
    sort(arr, arr + n, com);

    int currCapacity = maxCapacity;
    double totalValue = 0;

    for(int i = 0; i<n; i++){

        if(arr[i].weight <= currCapacity){
            totalValue = totalValue + arr[i].value;
            currCapacity = currCapacity - arr[i].weight;
        }
        else{

            totalValue = totalValue + arr[i].value * (double)currCapacity / (double)arr[i].weight;
            currCapacity = 0;

            break;
        }
    }

    return totalValue;
}

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