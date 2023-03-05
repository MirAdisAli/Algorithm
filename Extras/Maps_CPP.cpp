#include <iostream>
#include <iterator>
#include <map>

using namespace std;



void printMap(map<int, string> my_mapping){
    map<int, string>::iterator itr;
    cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = my_mapping.begin(); itr != my_mapping.end(); itr++) {
        cout << '\t' << itr->first  // key
             << '\t' << itr->second << '\n';    // value
    }
    cout << endl;
}

int main() {
    map<int, string> my_mapping; // declaration

    // insertion syntax
    my_mapping.insert(pair<int, string>(1, "Name-1"));
    my_mapping.insert(pair<int, string>(2, "Val-2"));
    my_mapping.insert(pair<int, string>(4, "Val-4"));
    my_mapping.insert(pair<int, string>(5, "Val-5"));
    my_mapping.insert(pair<int, string>(7, "ADASDASDSA"));
    
    printMap(my_mapping);


    auto itr = my_mapping.find(7);
    if(itr == my_mapping.end()){ 
        // doesn't exist -> returns map.end()
        cout << "itr doesn't exist\n";
    }else{
        cout << "EXISTS\n";
        cout << "key = " << itr->first << endl; // key
        cout << "val = " << itr->second << endl; // value
    }


} 
