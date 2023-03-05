#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Student{
public:
    int id;
    double cgpa;
    Student(int i, double cg)
    {
        id = i;
        cgpa = cg;
    }

    void printStudent(){
        cout << "id = " << id << ", cgpa = " << cgpa << endl;
    }
};

class ComparatorStudent {
public:
    bool operator()(Student l, Student r)
    {
        return (l.id < r.id); // 10, 20 -> false
    }
};

int selectMaxActivities(int start_times[], int end_times[], int n){

    return 0;
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printVector(vector<int> v){
    int n = v.size();
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


void printStudents(vector<Student> v){
    int n = v.size();
    for(int i=0; i<n; i++){
        v[i].printStudent();
    }
}

int main() {
    
    // vector<int> integers;
    // // {10, 20, 7, 22, 31} // [10, 20, 7, 22, 31]
    // integers.push_back(10); // v.add(10); 
    // integers.push_back(20);
    // integers.push_back(7);
    // integers.push_back(22);
    // integers.push_back(31);
    // cout << integers[0] << endl;
    // // print
    // printVector(integers);
    
    // sort(integers.begin(), integers.end());

    // printVector(integers);

    
    vector<Student> students;   
    students.push_back(Student(10, 3.51));
    students.push_back(Student(20, 3.61));
    students.push_back(Student(7, 3.73));
    students.push_back(Student(22, 3.93));
    students.push_back(Student(31, 3.91));


    // print
    printStudents(students);

    ComparatorStudent comparator;
    sort(students.begin(), students.end(), comparator);

    cout << "-----------------------\n";

    printStudents(students);
    
}