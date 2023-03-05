#include <iostream>
#include <queue>


using namespace std;


void printPriorityQueue(priority_queue<int> pq)
{
    priority_queue<int> copy = pq;
    while (!copy.empty()) {
        cout << '\t' << copy.top(); // get the top
        copy.pop(); // remove the top
    }
    cout << '\n';
}

// Polymorphism
void printPriorityQueue(priority_queue <int, vector<int>, greater<int>> pq)
{
    priority_queue <int, vector<int>, greater<int>> copy = pq;
    while (!copy.empty()) {
        cout << '\t' << copy.top(); // get the top
        copy.pop(); // remove the top
    }
    cout << '\n';
}

int main() {

    // By default max priority_queue
    priority_queue<int> pq;
    pq.push(20);
    pq.push(22);
    pq.push(1);
    pq.push(7);
    pq.push(10);
    pq.push(31);
    printPriorityQueue(pq);
    pq.pop(); // remove the top element
    printPriorityQueue(pq);

    cout << "----------------------" << endl;

    // Min Priority Queue
    priority_queue <int, vector<int>,  greater<int>> min_pq;
    min_pq.push(20);
    min_pq.push(22);
    min_pq.push(1);
    min_pq.push(7);
    min_pq.push(10);
    min_pq.push(31);
    printPriorityQueue(min_pq);
    min_pq.pop(); // remove the top element
    printPriorityQueue(min_pq);
} 